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

struct ListNode* append(struct ListNode* cursor, int val) {
    struct ListNode *node = (struct ListNode *) malloc(sizeof(struct ListNode));
    node->val = val;
    cursor->next = node;
    return node;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode result = { .next = NULL }, *cursor = &result;

    int carry = 0, val1, val2, sum;
    while (l1 != NULL || l2 != NULL || carry == 1) {
        val1 = val2 = sum = 0;

        if (l1 != NULL) {
            val1 = l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            val2 = l2->val;
            l2 = l2->next;
        }

        sum = val1 + val2 + carry;
        carry = sum > 9 ? 1 : 0;
        cursor = cursor->next = malloc(sizeof(struct ListNode));
        cursor->val = sum > 10 ? sum - 10 : sum;
        cursor->next = NULL;
    }

    return result.next;
}

#endif //LEETCODE_STACK_H

#pragma clang diagnostic pop