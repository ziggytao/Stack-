//
//  stack.h
//  Stack
//
//  Created by 陶越 on 17/4/8.
//  Copyright © 2017年 陶越. All rights reserved.
//

#ifndef stack_h
#define stack_h

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef int Type;
typedef struct _stack
{
    Type stack[MAXSIZE];
    int top;
}SeqStack;
void Init(SeqStack*s);//初始化栈
void Push(SeqStack*s,Type item);//进栈
void Pop(SeqStack*s,Type* item);//出栈
void Top(SeqStack*s,Type* item);//读栈顶元素
int  StackEmpty(SeqStack*s);//判空 空则返回1
int StackFull(SeqStack*s);//判满 满则返回1
void Trans(char str[],char exp[]);//转换为后缀表达式
double ComputeValue(char exp[]);//计算后缀表达式
#endif /* stack_h */
