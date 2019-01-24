#include "singlelist.h"
#include <stdio.h>

int traverse_list(PNODE phead)
{
    PNODE p = phead;
    if(phead == NULL)
    {
        printf("链表不存在 \n");
        return 0;
    }
    if(phead->pnext == NULL)
    {
        printf("链表为空 \n");
        return 0;
    }
    while(p->pnext != NULL)
    {
        printf("%d\t",p->pnext->data);
        p = p->pnext;
    }
}
int create_list(int *arr,int len)
{
    PNODE phead = (PNODE)malloc(sizeof(NODE));
    PNODE p = phead;
    //int arr[] = {1,2,3,4,5,6,7,8,9,};
    //int len = sizeof(arr)/sizeof(int);
    for (int i=0;i<len;i++)
    {
        PNODE pnew = (PNODE)malloc(sizeof(NODE));
        pnew->data = arr[i];
        pnew->pnext = NULL;
        p->pnext = pnew;
        p = pnew;
    }
    return phead;

}
