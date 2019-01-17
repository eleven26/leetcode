//
// Created by ruby on 2019/1/17.
//

#include <stdio.h>
#include <time.h>
#include "stack.h"
//#include "stack-1.h"

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

    __darwin_clock_t start, end;
    double cpu_time_used;
    start = clock();

//    struct ListNode* result;
    for (int i = 0; i < 300000; ++i) {
        addTwoNumbers(l1->top, l2->top);
    }

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("%f\n", cpu_time_used);

//    displayList(result, "result");

    return 0;
}
