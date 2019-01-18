//
// Created by ruby on 2019/1/18.
//

#include <stdio.h>

#define MAX_SIZE 6

struct component {
    int data;
    int cur;
};

// 将结构体数组中所有分量链接到备用链表中
void reverseArr(struct component* array);

// 初始化链表
int initArr(struct component* array);

// 输出函数
void displayArr(struct component* array, int body);

// 从备用链表上摘下空闲节点的函数
int mallocArr(struct component* array);

int main() {
    struct component array[MAX_SIZE];
    int body = initArr(array);
    printf("静态链表为:\n");
    displayArr(array, body);
    return 0;
}

// 创建备用链表
void reverseArr(struct component* array) {
    for (int i = 0; i < MAX_SIZE; ++i) {
        array[i].cur = i + 1; // 将每个数组分量链接到一起
    }
    array[MAX_SIZE - 1].cur = 0; // 将最后一个结点的游标值为0
}

// 提取分配空间
int mallocArr(struct component* array) {
    // 若备用链表非空, 则返回分配的结点下标, 否则返回 0 (当分配最后一个结点时, 该结点的游标值为 0)
    int i = array[0].cur;
    if (array[0].cur) {
        array[0].cur = array[i].cur;
    }
    return i;
}

// 初始化静态链表
int initArr(struct component* array) {
    reverseArr(array);
    int body = mallocArr(array);

    // 声明一个变量, 把它当指针使, 指向链表的最后的一个结点, 因为链表为空, 所以和头结点重合
    int temBody = body;
    for (int i = 1; i < 4; ++i) {
        int j = mallocArr(array); // 从备用链表中拿出空闲的分量
        array[temBody].cur = j; // 将申请的空闲分量链接在链表的最后一个结点后面
        array[j].data = i; // 给新申请的分量的数据域初始化
        temBody = j;
    }

    array[temBody].cur = 0; // 新的链表最后一个结点的指针设置为 0
    return body;
}

void displayArr(struct component* array, int body) {
    int tempBody = body; // tempBody 准备做遍历使用
    while (array[tempBody].cur) {
        printf("%d, %d ", array[tempBody].data, array[tempBody].cur);
        tempBody = array[tempBody].cur;
    }
    printf("%d, %d\n", array[tempBody].data, array[tempBody].cur);
}

