
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Stack {
    int top; // 记录栈顶位置
    int capacity; // 记录栈容量
    int* array; // 栈数据保存数组
};

struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*)malloc(capacity * sizeof(int));
    return stack;
}

int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, int item) {
    if (isFull(stack)) {
        printf("stack is full\n");
        return;
    }
    stack->array[++stack->top] = item;
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("stack is empty\n");
        return INT_MIN;
    }
    return stack->array[stack->top--];
}

int main() {
    struct Stack* stack = createStack(3);

    push(stack, 11);
    push(stack, 22);
    push(stack, 33);

    printf("popped from stack: %d\n", pop(stack));
}