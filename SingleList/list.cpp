/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include<stdlib.h>
#include<stdio.h>
typedef struct Node
{
    int date;//数据域
    struct Node * pNext;//指针域
}NODE,*PNODE;//NODEµÈ¼ÛÓÚstruct Node, PNODEµÈ¼ÛÓÚstruct Node *
PNODE create_list();
void traverse_list(PNODE pHead);
bool is_empty(PNODE pHead);
int length_list(PNODE);
bool insert_list(PNODE,int,int);//posµÄÖµ´Ó1¿ªÊ¼
bool delete_list(PNODE,int,int *);
void sort_list(PNODE);

void output_list()
{
    PNODE pHead = NULL;
    pHead = create_list();//´´½¨Ò»¸ö·ÇÑ­»·µ¥Á´±í,²¢½«¸ÃÁ´±íµÄÍ·½ÚµãµÄµØÖ·¸³¸øpHead
    traverse_list(pHead);
    int x;
    delete_list(pHead,4,&x);
    traverse_list(pHead);
}
PNODE create_list()
{
    int len;
    int i;
    int val;

    PNODE pHead=(PNODE)malloc(sizeof(NODE));
    if (NULL == pHead)
    {
        printf("动态内存分配失败！\n");
        exit(-1);
    }

    PNODE pTail=pHead;
    pTail->pNext=NULL;

    printf("请输入需要生成的节点的长度： len = ");
    scanf("%d",&len);
    for(i=0;i<len;i++)
    {
        printf("请输入第%d个节点的值： ",i+1);
        scanf("%d",&val);
        PNODE pNew =(PNODE)malloc(sizeof(NODE));
        if (NULL == pNew)
        {
            printf("动态内存分配失败\n");
            exit(-1);
        }
        pNew->date=val;
        pTail->pNext=pNew;
        pNew->pNext=NULL;
        pTail=pNew;
    }
    return pHead;
}

void traverse_list(PNODE pHead)
{
    PNODE p=pHead->pNext;
    while (NULL != p)
    {
        printf("%d\t",p->date);
        p=p->pNext;

    }
    printf("\n");
    return;
}

//ÅÐ¶ÏÁ´±íÊÇ·ñÎª¿Õ
bool is_empty(PNODE pHead)
{
    if (NULL == pHead->pNext)
        return true;
    else
        return false;
}

//ÅÐ¶ÏÁ´±í³¤¶È
int length_list(PNODE pHead)
{
    PNODE p = pHead->pNext;
    int len=0;
    while(NULL != p)
    {
        len++;
        p=p->pNext;
    }
    return len;
}


//ÅÅÐò
void sort_list(PNODE pHead)
{
    int i,j,t;
    int len = length_list(pHead);
    PNODE p,q;
    for(i=0,p=pHead->pNext;i<len-1;i++,p=p->pNext)
        for(j=i+1,q=p->pNext;j<len;j++,q=q->pNext)
            if(p->date > q->date)
            {
                t = p->date;
                p->date = q->date;
                q->date = t;
            }

}

//ÔÚpHeadËùÖ¸ÏòµÄÁ´±íµÄµÚpos¸ö½ÚµãµÄÇ°Ãæ²åÈëÒ»¸öÐÂµÄ½Úµã£¬¸Ã½ÚµãµÄÖµÊÇval,²¢ÇÒposµÄÖµÊÇ´Ó1¿ªÊ¼
bool insert_list(PNODE pHead,int pos,int val)
{
    int i=0;
    PNODE p=pHead;

    while (NULL!=p && i<pos-1)//Ê¹pÖ¸ÏòµÚpos¸ö½Úµã
    {
        p=p->pNext;
        i++;
    }
    if (i>pos-1||p==NULL)
    {
        return false;
    }
    PNODE pNew=(PNODE)malloc(sizeof(NODE));
    if (NULL == pNew)
    {
        printf("动态内存分配失败！");
        exit(-1);
    }
    pNew->date = val;
    pNew->pNext = p->pNext;
    p->pNext = pNew;

}




bool delete_list(PNODE pHead,int pos ,int * pVal)
{
    PNODE p = pHead;
    int i=0;
    while (NULL != p->pNext && i < pos-1)
    {
        p=p->pNext;
        i++;
    }
    if (i > pos-1 || p->pNext == NULL)
    {
        return false;
    }
    PNODE q=p->pNext;
    *pVal = q->date;

    p->pNext = p->pNext->pNext;
    free(q);

}
