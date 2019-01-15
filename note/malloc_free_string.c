//
// Created by ruby on 2019/1/15.
//

#include <stdlib.h>
#include <string.h>

/*
 * 指针人为的更改了原来的指向地址, 会导致程序出错.
 * 1. free() 只用于释放动态分配的内存, 即 malloc()/calloc()/realloc() 函数分配的空间, 否则不会成功
 *    下面例子 test = "123" 运行的时候, test 的指向发生了改变
 * 2. 要想将 "123" 字符串放在 test 数组中, 应该用 strcpy 函数完成, 或者对 test 数组的每个元素进行单独赋值.
 *    就是说要用 memcpy 或者 strcpy 将字符串赋给 test, 而不能直接给 test 赋值
 *
 * 总结:
 * 1. malloc 与 free 配套使用. 不要跨进程分配和释放
 * 2. 指向 malloc 申请的堆内存指针, 在运行过程中千万不要另外赋值, 否则同样导致内存泄漏
 * 3. malloc 后, 实际使用时指针长度超过了你申请的范围. 再去 free 时肯定出问题
 * 4. 改变指针的初始指向地址
 */
int main()
{
    char* test = malloc(100);

    // 给 malloc 分配的内存写入字符串
    // wrong: 指向了一个常量的地址, 而不再是 malloc 分配的地址, 因此下面再调用 free(test) 会出错
//    test = "123";
    // correct: 若想把字符串写入这段内存, 则需要使用内存复制类函数, 如 strcpy
    strcpy(test, "123");

    free(test);
    test = NULL;

    return 0;
}