/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   list.h
 * Author: factoid
 *
 * Created on 2018年9月29日, 下午9:21
 */

#ifndef LIST_H
#define LIST_H
typedef struct Node
{
    int date;//数据域
    struct Node * pNext;//指针域
}NODE,*PNODE;//NODE等价于struct Node, PNODE等价于struct Node * 
PNODE create_list();
void traverse_list(PNODE pHead);
void output_list();
bool is_empty(PNODE pHead);
int length_list(PNODE);
bool insert_list(PNODE,int,int);
bool delete_list(PNODE,int,int *);
void sort_list(PNODE);


#endif /* LIST_H */

