#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char item) {
    if (top >= MAX - 1) {
        printf("Stack Overflow.\n");
    } else {
        stack[top++] = item;
    }
}

char pop() {
    if (top < 0) {
        printf("Stack Underflow.\n");
        return '\0';
    } else {
        return stack[top--];
    }
}

char peek() {
    if (top < 0) {
        printf("Stack is empty.\n");
        return '\0';
    } else {
        return stack[top];
    }
}

int isOperator(char symbol) {
    return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '^');
}

int precedence(char symbol) {
    switch (symbol) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, j = 0;
    char item, x;

    while (infix[i] != '\0') {
        item = infix[i];

        if (isdigit(item) || isalpha(item)) {
            postfix[j++] = item;
        } else if (item == '(') {
            push(item);
        } else if (item == ')') {
            while ((x = pop()) != '(') {
                postfix[j++] = x;
            }
        } else if (isOperator(item)) {
            while (top != -1 && precedence(peek()) >= precedence(item)) {
                postfix[j++] = pop();
            }
            push(item);
        }

        i++;
    }

    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    gets(infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}