//
// Created by ruby on 2019/1/15.
//

/*
 * 没有处理 hash 冲突的情况, 当插入的数据数量比 SIZE 大就会有问题, 死循环, 因为找不出空闲节点
 */

#ifndef LEETCODE_HASH_TABLE_1_H
#define LEETCODE_HASH_TABLE_1_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 20

struct DataItem {
    int key;
    int data;
};

struct DataItem* hashArray[SIZE];
struct DataItem* dummyItem;
struct DataItem* item;

int hashCode(int key) {
    return (key > 0 ? key : -key) % SIZE;
}

struct DataItem* search(int key) {
    // get the hash
    int hashIndex = hashCode(key);

    // move in array until an empty
    while (hashArray[hashIndex] != NULL) {
        if (hashArray[hashIndex]->key == key) {
            return hashArray[hashIndex];
        }

        // go to next cell
        ++hashIndex;

        // wrap around the table
        hashIndex %= SIZE;
    }

    return NULL;
}

void insert(int key, int data) {
    struct DataItem* item = (struct DataItem*) malloc(sizeof(struct DataItem));
    item->key = key;
    item->data = data;

    // get the hash
    int hashIndex = hashCode(key);

    // move in array until an empty or deleted cell
    while (hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1) {
        // go to next cell
        ++hashIndex;

        // wrap around the table
        hashIndex %= SIZE;
    }

    hashArray[hashIndex] = item;
}

struct DataItem* delete(struct DataItem* item) {
    int key = item->key;

    // get the hash
    int hashIndex = hashCode(key);

    // move in array until an empty
    while (hashArray[hashIndex] != NULL) {
        if (hashArray[hashIndex]->key == key) {
            struct DataItem* temp = hashArray[hashIndex];

            // assign a dummy item at deleted position.
            hashArray[hashIndex] = dummyItem;
            return  temp;
        }

        // go to next cell
        ++hashIndex;

        // wrap around the table
        hashIndex %= SIZE;
    }

    return NULL;
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

#endif //LEETCODE_HASH_TABLE_1_H
