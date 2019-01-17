//
// Created by ruby on 2019/1/15.
//

#ifndef LEETCODE_HASH_TABLE_2_H
#define LEETCODE_HASH_TABLE_2_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 4

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

    /*
     * hash table 结构
     * key1 => (k1, v1) -> (k2, v2)
     * key2 => (k3, v3) -> (k4, v4)
     */
    while (cursor) {
        // 1. 如果有多个元素 hash code 相同, 需要以链表的写法移除该元素
        // 2. 释放内存
        if (cursor->key == item->key) {
            if (prev == cursor) {
                // 该 hash key 上只有一个节点
                hashArray[hashIndex] = cursor->next;
            } else {
                prev->next = cursor->next;
            }
            free(cursor);
            break;
        }

        prev = cursor;
        cursor = cursor->next;
    }
}

void display() {
    for (int i = 0; i < SIZE; ++i) {
        if (hashArray[i] != NULL) {
            int hashKey = hashCode(hashArray[i]->key);
            printf("hash key = %d\n\t(%d, %d)", hashKey, hashArray[i]->key, hashArray[i]->data);

            struct DataItem* temp = hashArray[i]->next;
            while (temp) {
                printf(" -> (%d, %d)", temp->key, temp->data);
                temp = temp->next;
            }
            if (i != SIZE - 1) printf("\n");
        }
        else
            printf(" ~~ ");
    }

    printf("\n");
}

#endif //LEETCODE_HASH_TABLE_2_H
