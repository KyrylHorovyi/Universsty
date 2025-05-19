#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void enqueue(Node** front, Node** rear, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Err\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    if (*rear == NULL) {
        *front = *rear = newNode;
    } else {
        (*rear)->next = newNode;
        *rear = newNode;
    }
}

int sumQueue(Node* front) {
    int sum = 0;
    while (front != NULL) {
        sum += front->data;
        front = front->next;
    }
    return sum;
}

void freeQueue(Node* front) {
    Node* temp;
    while (front != NULL) {
        temp = front;
        front = front->next;
        free(temp);
    }
}

int main() {

    system("chcp 65001");

    Node* front = NULL;
    Node* rear = NULL;
    int num;
    char ch;

    while (1) {
        printf("Введіть число: ");
        scanf("%d", &num);
        enqueue(&front, &rear, num);

        printf("Будь яка клавіша для продовження вводу (Esc для припинення)\n");
        ch = _getch();
        if (ch == 27)
            break;
    }

    int total = sumQueue(front);
    printf("Сума всіх елементів черги: %d\n", total);

    freeQueue(front);
    return 0;
}