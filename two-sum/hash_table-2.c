//
// Created by ruby on 2019/1/15.
//

#include "hash_table-2.h"

int main() {
    insert(1, 20);
    insert(2, 70);
    insert(42, 80);
    insert(4, 25);
    insert(12, 44);
    insert(14, 32);
    insert(17, 11);
    insert(13, 78);
    insert(74, 80);
    insert(37, 97);

    display();
    struct DataItem* item = search(37);

    if (item != NULL) {
        printf("Element found: %d\n", item->data);
    } else {
        printf("Element not found\n");
    }

    delete(item);
    item = search(74);

    display();
    if (item != NULL) {
        printf("Element found: %d\n", item->data);
    } else {
        printf("Element not found\n");
    }
}