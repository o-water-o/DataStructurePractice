/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include<stdio.h>
#include<malloc.h>
#include"SingleList.h"

int test()
{
    PNODE A=(PNODE)malloc(sizeof(NODE));
    int u[] = {1,2,3,4,5};
    int len = sizeof(u)/sizeof(int);
    printf("%d\n",len);
    return 0;
}

