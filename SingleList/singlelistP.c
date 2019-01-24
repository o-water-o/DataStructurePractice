#include <stdio.h>
#include "singlelist.h"

int test()
{
    int t[] = {55,66};
    PNODE L = create_list(t,sizeof(t)/sizeof(int));
    traverse_list(L);
}
