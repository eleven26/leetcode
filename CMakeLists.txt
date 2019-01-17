cmake_minimum_required(VERSION 3.12)
project(leetcode C)

set(CMAKE_C_STANDARD 99)

add_executable(leetcode two-sum/two-sum-1.c two-sum/hash_table.h two-sum/hash_table-1.h two-sum/hash_table-2.h stack/stack.h stack/stack_test.c)