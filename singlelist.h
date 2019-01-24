#ifndef SINGLELIST_H_INCLUDED
#define SINGLELIST_H_INCLUDED
typedef struct Node
{
    int data;
    struct Node * pnext;
}*PNODE,NODE;
int traverse_list(PNODE phead);


#endif // SINGLELIST_H_INCLUDED
