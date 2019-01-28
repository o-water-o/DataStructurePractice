/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"list.h"
#include<malloc.h>
#include<typeinfo>

int test()
{
    char x[100];
    printf("请输入字符串：");
    scanf("%c",&x);
    printf(x);
    return 0;
}


int func_23_21()
{
    //生成不带头结点的非循环单链表
    PNODE pTail,L,p;
    L=(PNODE)malloc(sizeof(NODE));
    pTail=L;
    printf("请输入生成单链表的长度(整型)： ");
    int len=0;
    scanf("%d",&len);
    if (len==0)
    {
        printf("输入的数据类型有误,意外退出...\n");
        return 0;
    }
    while(len<1)
    {

        printf("输入有误，请重新输入\n");
        printf("请输入生成单链表的长度(整型)： ");
        scanf("%d",&len);
    }

    int i;
    for(i=0;i<len;i++)
    {
        int val;
        printf("请输入第%d个节点的值（整型）： ",i+1);
        scanf("%d",&val);
        PNODE s = (PNODE)malloc(sizeof(NODE));
        if(NULL==s)
            printf("内存分配失败\n");
        s->date=val;
        pTail->pNext=s;
        pTail=s;
        pTail->pNext=NULL;
        //printf("success\n");
    }
    if (i==0)
        free(L);
    traverse_list(L);
    p=L;
    printf("请输入需要删除的值x: ");
    int x;
    scanf("%d",&x);
    while(p->pNext != NULL)
    {
        if (p->pNext->date == x)
        {
            PNODE t=p->pNext;
            p->pNext=p->pNext->pNext;
            free(t);
        }
        else
        {
            p=p->pNext;
        }
    }
    //判断首节点的数据域是否符合删除条件
    if(L->date==x)
    {
        PNODE t=L;
        L=L->pNext;
        free(t);
    }

    traverse_list(L);
    return 0;
}

int func_23_22()
{
    PNODE L=create_list(),p;
    traverse_list(L);
    printf("请输入需要删除节点的值 :");
    int x;scanf("%d",&x);
    p=L;//p 指针为当前节点的一节点
    while(p->pNext!=NULL)
    {
        if(p->pNext->date == x)
        {
            PNODE temp=p->pNext;
            p->pNext=p->pNext->pNext;
            free(temp);
        }
        else
        {
            p=p->pNext;//printf("success!\n");
        }
    }
    traverse_list(L);
    return 0;
}

int func_23_23()
{
    PNODE L=create_list(),p=L;traverse_list(L);
    PNODE M;
    M=(PNODE)malloc(sizeof(NODE));
    PNODE k=M;
    while(p->pNext!=NULL)
    {
        insert_list(M,1,p->pNext->date);
        p=p->pNext;
    }
    traverse_list(M);
}


int func_23_24()
{
    printf("func_23_24(): \n");
    PNODE L=create_list();
    PNODE M=(PNODE)malloc(sizeof(NODE)),k,g;
    memcpy(M,L,sizeof(NODE));
    k=M->pNext;
    traverse_list(M);
    int minimun;
    for(int i=0;i<length_list(M)-1;i++)///指针g指向当前节点
    {
        g = k;
        for(int j=0;j<length_list(M)-1-i;j++,g=g->pNext)
        {
            if(g->date > g->pNext->date)///最大值放在后面
            {
                int temp;
                temp = g->date;
                g->date = g->pNext->date;
                g->pNext->date = temp;
            }
        }
    }

    traverse_list(M);
    minimun = M->pNext->date;
    printf("");
    //free(M);
    PNODE p=L;
    printf("原始链表L： \n");
    traverse_list(L);
    while(p->pNext!=NULL)
    {
        if(p->pNext->date == minimun)
        {
            PNODE temp;
            temp =p->pNext;
            p->pNext = p->pNext->pNext;
            free(temp);
            break;//continue;
        }
        p=p->pNext;

    }
    //traverse_list(M);
    traverse_list(L);

}

int func_23_25()
{
    printf("func_23_25: \n");
    PNODE L = create_list(),p=L->pNext,q;
    traverse_list(L);
    int len=0;
    while(p != NULL)
    {
        len+=1;
        p=p->pNext;
    }
    p= L->pNext;
    printf("单链表的长度为：%d \n",len);
    for(int i=0;i<len/2;i++,p=p->pNext)
    {
        q=L->pNext;
        int j = 0;
        while(j != len-i-1)
        {
            q=q->pNext;
            j++;
            //printf("q->date=%d ",q->date);printf("j=%d \n",j);
        }
//        printf("i=%d j=%d\n",i,j);
        int temp;
//        printf("p->date=%d  \n",p->date);
//        printf("q->date=%d \n",q->date);
        temp = p->date;
        p->date = q->date;
        q->date = temp;
    }
    traverse_list(L);
    return 0;
}

int func_23_26()
{
    PNODE L = create_list(),p;
    int len = length_list(L);
    for(int i=0;i<len-1;i++)
        {
            p=L->pNext;
            for(int j=0;j<len-i-1;j++,p=p->pNext)
                {
                    if(p->date > p->pNext->date)
                    {
                        int temp;
                        temp = p->date;
                        p->date = p->pNext->date;
                        p->pNext->date = temp;
                    }

                }


        }
        traverse_list(L);
        return 0;
}

int func_23_27(int x,int y)
{
    PNODE L = (PNODE)malloc(sizeof(NODE)),p=L;
    if(NULL == L)
    {
        printf("内存分配失败，异常退出!\n");
        exit(-1);
    }
    int arr[]={1,2,3,4,5,6};
    int len = sizeof(arr)/sizeof(int);
    for(int i=0;i<len;i++)
    {
        PNODE pNew = (PNODE)malloc(sizeof(NODE));
        if(NULL == pNew)
        {
            printf("内存分配失败，异常退出!\n");
            exit(-1);
        }
        pNew->date = arr[i];
        p->pNext = pNew;
        p = pNew;
        p->pNext = NULL;
    }
    traverse_list(L);

    ///function start
    p = L;
    if (x ==y)
        {
            printf("引用参数有误，异常退出！\n");
            return 0;
        }
    else
        if(x > y)
        {
            int temp = x;
            x = y;
            y = temp;
        }
    //for(int i=0;i<length_list(L);i++)
    while(p->pNext != NULL)
    {
        //printf("%d\n",p->pNext->date);
        if(p->pNext->date >= x && p->pNext->date <= y)
        {
            PNODE temp = p->pNext;
            p->pNext = p->pNext->pNext;
            free(temp);
        }
        else
        {
            p=p->pNext;
        }

    }
    traverse_list(L);
    return 0;
}

int func_23_28()
{
    ///构造数据
    PNODE L = (PNODE)malloc(sizeof(NODE)),p=L;
    PNODE M = (PNODE)malloc(sizeof(NODE)),q=M;
    if(NULL == L)
    {
        printf("内存分配失败，异常退出!\n");
        exit(-1);
    }
    int arr[]={1,2,3,4,5,6};
    int arr2[]={1,3,6,8,5,-6,10,-41};
    int len = sizeof(arr)/sizeof(int);
    for(int i=0;i<len;i++)
    {
        PNODE pNew = (PNODE)malloc(sizeof(NODE));
        if(NULL == pNew)
        {
            printf("内存分配失败，异常退出!\n");
            exit(-1);
        }
        pNew->date = arr[i];
        p->pNext = pNew;
        p = pNew;
        p->pNext = NULL;
    }
    traverse_list(L);
    len = sizeof(arr2)/sizeof(int);
    for(int i=0;i<len;i++)
    {
        PNODE pNew = (PNODE)malloc(sizeof(NODE));
        if(NULL == pNew)
        {
            printf("内存分配失败，异常退出!\n");
            exit(-1);
        }
        pNew->date = arr2[i];
        q->pNext = pNew;
        q = pNew;
        q->pNext = NULL;
    }
    traverse_list(M);

    ///function start
    PNODE S = (PNODE)malloc(sizeof(NODE)),s=S;
    s->pNext = NULL;///小s此时为头节点
    p=L;
    while(p->pNext != NULL)
    {
        q=M;
        while(q->pNext != NULL)
        {
            if(p->pNext->date == q->pNext->date)
            {
                PNODE pNew = (PNODE)malloc(sizeof(NODE));
                pNew->date = p->pNext->date;
                s->pNext = pNew;
                s = pNew;
                s->pNext=NULL;
            }
            q=q->pNext;
        }
        p=p->pNext;
    }
    printf("两个链表的公共节点为： \t");
    traverse_list(S);

}
