//
// Created by ruby on 2019/1/14.
//
#include <stdlib.h>
#include <string.h>

#ifndef LEETCODE_HASH_TABLE_H
#define LEETCODE_HASH_TABLE_H

/**
 * key   保存节点键
 * value 保存节点值
 * *next 保存相同 hash key 的值列表
 */
struct node {
    int key;
    int value;
    struct node *next;
};

/**
 * size hash_table 长度
 * list 存储的节点列表(一个节点可能会有多个值, 也是一个数组(node->next))
 */
struct hash_table {
    int size;
    struct node **list;
};

struct hash_table* create_hash_table(int size) {
    struct hash_table *table = (struct hash_table*) malloc(sizeof(struct hash_table));
    table->size = size;
    table->list = (struct node**) malloc(sizeof(struct node*) * size);

    for (int i = 0; i < size; ++i) {
        table->list[i] = NULL;
    }
    return table;
}

int hash_code(int key, int size) {
    if (key < 0)
        return - (key % size);
    return key % size;
}

void insert(struct hash_table* table, int key, int val) {
    int pos = hash_code(key, table->size);
    struct node *list = table->list[pos];
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    struct node *temp = list;

    while (temp) {
        if (temp->key == pos) {
            temp->value = val;
            return;
        }
        temp = temp->next;
    }

    newNode->key = key;
    newNode->value = val;
    newNode->next = list;
    table->list[pos] = newNode;
}

int lookup(struct hash_table* table, int key) {
    int pos = hash_code(key, table->size);
    struct node *list = table->list[pos];
    struct node *temp = list;

    while (temp) {
        if (temp->key == key) {
            return temp->value;
        }
        temp = temp->next;
    }

    return -1;
}

#endif //LEETCODE_HASH_TABLE_H
