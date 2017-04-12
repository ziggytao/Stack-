//
//  main.c
//  Stack
//
//  Created by 陶越 on 17/4/8.
//  Copyright © 2017年 陶越. All rights reserved.
//

#include <stdio.h>
#include "stack.h"
#define MAX 50
int main(int argc, const char * argv[])
{
    SeqStack s;
    Init(&s);
    Push(&s, 3);
    int i;
    printf("%d\t%d\n",StackEmpty(&s),StackFull(&s));
    Top(&s,&i);
    printf("%d\n",i);
    char str[MAX],exp[MAX];
    printf("表达式：");
    fgets(str,MAX,stdin);
    Trans(str, exp);
    printf("后缀表达式：%s\n",exp);
    printf("表达式计算结果为：%.2lf\n",ComputeValue(exp));
    return 0;
}
