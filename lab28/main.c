#include <stdio.h>
#include <stdlib.h>
#define SIZE 12

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("err\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void push(Node** top, int value) {
    Node* newNode = createNode(value);
    newNode->next = *top;
    *top = newNode;
}

void printStack(Node* top) {
    Node* current = top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void freeStack(Node* top) {
    Node* temp;
    while (top != NULL) {
        temp = top;
        top = top->next;
        free(temp);
    }
}

int main() {

    system("chcp 65001");
    
    Node* posStack = NULL;
    Node* negStack = NULL;
    int number;

    printf("Введіть 12 чисел:\n");

    for (int i = 0; i < SIZE; i += 1) {
        scanf("%d", &number);
        if (number > 0) {
            push(&posStack, number);
        } else if (number < 0) { // else if бо 0 не треба в стеки пхати за умовою
            push(&negStack, number);
        }
    }

    printf("\nСтек додатніх: ");
    printStack(posStack);

    printf("Стек від'ємних: ");
    printStack(negStack);

    freeStack(posStack);
    freeStack(negStack);

    return 0;
}