#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <malloc.h>
#include <string.h>

enum { 
    IFL = 257, THENL, WHILEL, DOL, RETRL, READL, PRITL, INTL, 
    CONSTL, IDEN, NUMB 
};

int nst = 0;
int lval, lex;
static char nch = '\n';
FILE* PF, * padres;

void get(void);
void number(void);
void word(void);
char* add(char* nm);

int main() {

    system("chcp 65001");
    
    PF = fopen("var2.s", "r");
    padres = fopen("getrez.dan", "w");
    
    if (!PF) {
        perror("Помилка відкриття файлу");
        return 1;
    }
    
    get();
    
    fclose(PF);
    fclose(padres);
    return 0;
}

void get() {
    while (nch != EOF) {
        while (isspace(nch)) {
            if (nch == '\n') nst++;
            nch = getc(PF);
        }
        if (nch == EOF) break;

        if (isdigit(nch)) {
            number();
        }
        else if (isalpha(nch)) {
            word();
        }
        else if (nch == '(' || nch == ')' || nch == ',' || nch == ';' || 
                 nch == '=' || nch == '+' || nch == '-' || nch == '*' || 
                 nch == '/' || nch == '%' || nch == '{' || nch == '}' ||
                 nch == '>' || nch == '<') {
            lex = nch;
            nch = getc(PF);
        }
        else {
            printf("Невідомий символ: %c\n", nch);
            exit(1);
        }
    }
    lex = EOF;
}

void number() {
    for (lval = 0; isdigit(nch); nch = getc(PF)) {
        lval = lval * 10 + (nch - '0');
    }
    lex = NUMB;
}

void word() {
    static int cdl[] = {IFL, THENL, WHILEL, DOL, RETRL, READL, PRITL, INTL, CONSTL};
    static char* serv[] = {"if", "then", "while", "do", "return", "read", "print", "int", "const"};
    
    char tx[40];
    char* p = tx;
    
    while (isalpha(nch) || isdigit(nch)) {
        *p++ = nch;
        nch = getc(PF);
    }
    *p = '\0';

    for (int i = 0; i < 9; i += 1) {
        if (strcmp(tx, serv[i]) == 0) {
            lex = cdl[i];
            return;
        }
    }
    
    lex = IDEN;
    lval = (int)add(tx);
}

char TNM[400];
char* ptn = TNM;

char* add(char* nm) {
    for (char* p = TNM; p < ptn; p += strlen(p) + 1) {
        if (strcmp(p, nm) == 0) {
            return p;
        }
    }
    
    int len = strlen(nm) + 1;
    if (ptn + len > TNM + 400) {
        printf("Переповнення таблиці ідентифікаторів!\n");
        exit(1);
    }
    
    char* new_addr = strcpy(ptn, nm);
    printf("Адреса для %s = %p\n", nm, new_addr);
    fprintf(padres, "Адреса для %s = %p\n", nm, new_addr);
    
    ptn += len;
    return new_addr;
}