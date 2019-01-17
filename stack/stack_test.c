//
// Created by ruby on 2019/1/17.
//

#include <stdio.h>
#include "stack.h"

int main() {
    struct Stack* stack = createStack();
    push(stack, 1);
    push(stack, 20);
    push(stack, 14);

    while (!isEmpty(stack)) {
        printf("val=%d\n", pop(stack));
    }

    struct Stack* l1 = createStack();
    struct Stack* l2 = createStack();

    push(l1, 3);
    push(l1, 1);
    push(l1, 3);
    push(l1, 4);
    push(l1, 2);

    push(l2, 7);
    push(l2, 5);
    push(l2, 5);

    struct ListNode* result = addTwoNumbers(l1->top, l2->top);
    displayList(result, "result");

    return 0;
}
