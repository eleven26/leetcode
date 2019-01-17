//
// Created by ruby on 2019/1/17.
//

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wint-conversion"

#ifndef LEETCODE_STACK_H
#define LEETCODE_STACK_H

#include <stdlib.h>
#include <stdbool.h>

struct Stack {
    struct ListNode *top;
};

struct ListNode {
    int val;
    struct ListNode *next;
};

struct Stack *createStack() {
    struct Stack *stack = (struct Stack *) malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

void push(struct Stack *stack, int val) {
    struct ListNode *node = (struct ListNode *) malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = stack->top;
    stack->top = node;
}

int isEmpty(struct Stack *stack) {
    if (stack->top == NULL) {
        return 1;
    }

    return 0;
}

int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        return NULL;
    } else {
        int temp = stack->top->val;
        stack->top = stack->top->next;
        return temp;
    }
}

void displayList(struct ListNode *cursor, char *name) {
    if (name != NULL) {
        printf("%s: ", name);
    }

    while (cursor) {
        printf("%d", cursor->val);
        if (cursor->next != NULL) {
            printf(" -> ");
        }
        cursor = cursor->next;
    }
    printf("\n");
}

/**
 * 显示栈所有内容, 调试使用
 */
void display(struct Stack *stack, char *name) {
    struct ListNode *cursor;
    cursor = stack->top;
    displayList(cursor, name);
}

struct Stack* reverseStack(struct Stack* stack) {
    int size = 0;

    // 计算 stack 长度
    struct ListNode* cursor = stack->top;
    while (cursor) {
        size++;
        cursor = cursor->next;
    }

    int vals[size];
    for (int i = 0; i < size; ++i) {
        vals[i] = pop(stack);
    }

    for (int i = 0; i < size; ++i) {
        push(stack, vals[i]);
    }

    return stack;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
    struct Stack *result = createStack();

    displayList(l1, "l1");
    displayList(l2, "l2");

    int l1Value = 0, l2Value = 0, sum = 0, remainder = 0;
    while (l1 && l2) {
        l1Value = l1->val;
        l2Value = l2->val;
        // 加上上一次计算的余数
        sum = l1Value + l2Value + remainder;

        // 进位
        if (sum >= 10) {
            sum -= 10;
            remainder = 1;
        } else {
            remainder = 0;
        }

        push(result, sum);
        l1 = l1->next;
        l2 = l2->next;
    }

    while (l1) {
        l1Value = l1->val;
        sum = l1Value + remainder;

        // 进位
        if (sum >= 10) {
            sum -= 10;
            remainder = 1;
        } else {
            remainder = 0;
        }

        l1 = l1->next;
        push(result, sum);
    }
    while (l2) {
        l2Value = l2->val;
        sum = l2Value + remainder;

        // 进位
        if (sum >= 10) {
            sum -= 10;
            remainder = 1;
        } else {
            remainder = 0;
        }

        l2 = l2->next;
        push(result, sum);
    }

    // 余数
    if (remainder > 0) {
        push(result, remainder);
    }

    reverseStack(result);

    return result->top;
}

#endif //LEETCODE_STACK_H

#pragma clang diagnostic pop