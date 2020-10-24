#include "list.h"
#include "bubble_sort.h"

void list_print(struct list_head* list)
{
    struct list_head *pos = NULL;
    list_of_each(pos, list)
    {
        mynode *ptr_node = container_of(pos, mynode, list);
        printf("%d->", ptr_node->val);
    }
    printf("\n");
}

int main()
{
    LIST_HEAD(new_head);
    mynode node1, node2, node3;
    node1.val = 1;
    node2.val = 2;
    node3.val = 3;
    list_add(&(node1.list), &new_head);
    list_add(&(node2.list), &(node1.list));
    list_add(&(node3.list), &(node2.list));
    list_print(&new_head);
    bubble_sort(&new_head);
    list_print(&new_head);
    return 0;
}