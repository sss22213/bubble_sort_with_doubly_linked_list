#include "bubble_sort.h"
void bubble_sort(struct list_head *list)
{
    int32_t swap_flag = 1;
    do
    {
        struct list_head **pos = &(list->next);
        swap_flag = 0;
        while((*pos)->next != list && (*pos) != list)
        {
            mynode *ptr_node = container_of(*pos, mynode, list);
            mynode *ptr_node_next = container_of((*pos)->next, mynode, list);
            if(ptr_node->val < ptr_node_next->val)
            {
                swap(*pos, (*pos)->next);
                swap_flag = 1;
            }
            pos = &(*pos)->next;
        }
    }while(swap_flag);
    
}