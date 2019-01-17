cmake_minimum_required(VERSION 3.12)
project(leetcode C)

set(CMAKE_C_STANDARD 99)

add_executable(leetcode "1. two-sum/two-sum-1.c" "1. two-sum/hash_table.h" "1. two-sum/hash_table-1.h" "1. two-sum/hash_table-2.h" "2. add-two-numbers/stack.h" "2. add-two-numbers/add-two-numbers.c" note/stack/array_stack.c note/stack/linked_stack.c)