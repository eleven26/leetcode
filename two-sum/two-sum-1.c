#include <stdio.h>
#include <stdlib.h>
#include "hash_table.h"

int* twoSum(int* nums, int numsSize, int target) {
    struct hash_table* table = create_hash_table(numsSize);
    int i = 0, j = 0, rest, *reval = (int*) malloc(2 * sizeof(int));

    for (i = 0; i < numsSize; ++i) {
        rest = target - nums[i];
        if ((j = lookup(table, rest)) != -1) {
            reval[0] = j;
            reval[1] = i;
            break;
        } else {
            insert(table, nums[i], i);
        }
    }

    return reval;
}

/**
 * 使用 hash table 存储比较过的值
 * @return
 */
int main() {
    int nums[4] = {2, 7, 9, 11};
    int *reval = twoSum(nums, 4, 9);
    printf("[%d, %d]", reval[0], reval[1]);
    return 0;
}