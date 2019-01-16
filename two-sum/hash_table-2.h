//
// Created by ruby on 2019/1/15.
//

#ifndef LEETCODE_HASH_TABLE_2_H
#define LEETCODE_HASH_TABLE_2_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 1

struct DataItem {
    int key;
    int data;
    struct DataItem *next; // 存储 hash 冲突的数据(链表结构), 新插入的 item, list 为 NULL
};

struct DataItem *hashArray[SIZE];

int hashCode(int key) {
    return (key > 0 ? key : -key) % SIZE;
}

struct DataItem *search(int key) {
    // 计算 key 的 hash
    int hashIndex = hashCode(key);

    struct DataItem *cursor = hashArray[hashIndex];
    while (cursor) {
        if (cursor->key == key) {
            return cursor;
        }
        cursor = cursor->next;
    }

    return NULL;
}

void insert(int key, int data) {
    struct DataItem *item = (struct DataItem *) malloc(sizeof(struct DataItem));
    item->key = key;
    item->data = data;
    item->next = NULL;

    // 计算 key 的 hash
    int hashIndex = hashCode(key);

    // 插入到对应 index
    if (hashArray[hashIndex] != NULL) {
        struct DataItem *temp = hashArray[hashIndex];
        item->next = temp;
    }

    hashArray[hashIndex] = item;
}

void delete(struct DataItem *item) {
    int hashIndex = hashCode(item->key);

    struct DataItem *cursor = hashArray[hashIndex]; // 指向当前元素
    struct DataItem *prev = cursor;   // 指向前一个元素

    while (cursor) {
        // 1. 如果有多个元素 hash code 相同, 需要以链表的写法移除该元素
        // 2. 释放内存
        if (cursor->key == item->key) {
            if (prev != cursor) {  // 相同 hash key 多个值
                prev->next = NULL;
            } else { // 该 hash key 下只有一个值
                hashArray[hashIndex] = NULL;
            }

            prev->next = cursor->next;
            cursor = NULL; // 这里只是指针的值为 NULL 了, 指针指向的地方并没有被置为 NULL
            free(cursor);
            break;
        }
        prev = cursor;
        cursor = cursor->next;
    }
}

void display() {
    for (int i = 0; i < SIZE; ++i) {
        if (hashArray[i] != NULL)
            printf(" (%d, %d)", hashArray[i]->key, hashArray[i]->data);
        else
            printf(" ~~ ");
    }

    printf("\n");
}

#endif //LEETCODE_HASH_TABLE_2_H
