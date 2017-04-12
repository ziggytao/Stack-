//
//  stack.c
//  Stack
//
//  Created by 陶越 on 17/4/8.
//  Copyright © 2017年 陶越. All rights reserved.
//
//=============================================
//计算表达式的值
//首先转换成后置表达式
//计算后置表达式 采用进栈的方式
//=============================================
#include "stack.h"
#define MAX 50
void Trans(char str[],char exp[])//转换为后缀表达式
{
    int i,j;
    char ch;
    struct//定义用于存放符号的栈
    {
        char data[MAX];
        int top;
    }opStack;
    i = j = 0;//数组下标置零
    opStack.top = -1;//栈置空
    ch = str[i++];
    while(ch != '\n')
    {
        switch(ch)//对ch进行判断
        {
            case '(':
                opStack.data[++opStack.top] = ch;
                break;
            case ')':
                while (opStack.data[opStack.top] != '(')
                    exp[j++] = opStack.data[opStack.top--];
                opStack.top--;
                break;
            case '+':
            case '-':
                while (opStack.top != -1 && opStack.data[opStack.top] != '(')
                    exp[j++] = opStack.data[opStack.top--];
                opStack.data[++opStack.top] = ch;
                break;
            case'*':
            case '/':
                while (opStack.data[opStack.top] == '*' || opStack.data[opStack.top] == '/')
                    exp[j++] = opStack.data[opStack.top--];
                opStack.data[++opStack.top] = ch;
                break;
            case ' ':
                break;
            default:
                while(ch >='0' && ch <= '9')
                {
                    exp[j++] = ch;
                    ch = str[i++];
                }
                i--;
                exp[j++] = '#';
        }
        ch = str[i++];
    }
    while(opStack.top != -1)
        exp[j++] = opStack.data[opStack.top--];
    exp[j] = '\0';//后置表达式末尾加上结束符
}
double ComputeValue(char exp[])
{
    double value;
    struct
    {
        double data[MAX];
        int top;
    }stack;
    int i = 0;//作为exp数组下标
    stack.top = -1;
    char ch ;
    ch = exp[i++];
    while(ch != '\0')//扫描后置表达式未结束时
    {
        switch(ch)//对ch进行判断
        {
            case '+':
                stack.data[stack.top - 1] += stack.data[stack.top];
                stack.top--;
                break;
            case '-':
                stack.data[stack.top - 1] -= stack.data[stack.top];
                stack.top--;
                break;
            case '*':
                stack.data[stack.top - 1] *= stack.data[stack.top];
                stack.top--;
                break;
            case '/':
                if(stack.data[stack.top] != 0)//分母不为零时
                {
                    stack.data[stack.top - 1] /= stack.data[stack.top];
                    stack.top--;
                }
                else
                {
                    printf("分母非法！\n");
                    return 0;
                }
                break;
            default:
                value = 0;
                while(ch >='0' && ch <= '9')
                {
                    value = (double)value * 10 + ch - '0';
                    ch = exp[i++];
                }
                stack.data[++stack.top] = value;
        }
        ch = exp[i++];
    }
    return stack.data[stack.top];
}
void Init(SeqStack*s)//初始化栈
{
    s->top = -1;
}
void Push(SeqStack*s,Type item)//进栈
{
    if(StackFull(s))
    {
        printf("栈满！\n");
        return;
    }
    s->stack[++s->top] = item;
}
void Pop(SeqStack*s,Type* item)//出栈
{
    if(StackEmpty(s))
    {
        printf("栈空！\n");
        return;
    }
    *item = s->stack[s->top--];
}
void Top(SeqStack*s,Type* item)//读栈顶元素
{
    if(StackEmpty(s))
    {
        printf("栈空！\n");
        return;
    }
    *item = s->stack[s->top];
}
int  StackEmpty(SeqStack*s)//判空
{
    return s->top == -1;
}
int StackFull(SeqStack*s)//判满
{
    return s->top == MAXSIZE - 1;
}
