/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SingleList.h
 * Author: luculent
 *
 * Created on 2019年1月22日, 下午6:56
 */

#ifndef SINGLELIST_H
#define SINGLELIST_H
typedef struct Node
{
    int data; //数据域
    struct Node * pnext; //指针域
}NODE, *PNODE;

void traverse_list(PNODE phead)
{
    PNODE p=phead;
    while(p->pnext != NULL)
    {
        printf("%d\t",p->pnext->data);
        p = p->pnext;
    }
}


#endif /* SINGLELIST_H */

