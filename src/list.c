#include "list.h"

void INIT_LIST_HEAD(struct list_head* list)
{
    list->next = list;
    list->prev = list;
}

int list_empty(struct list_head* list)
{
    return list->next == list;
}

void __list_add(struct list_head* new_list,
                struct list_head* prev, 
                struct list_head* next)
{
    new_list->next = next;
    next->prev = new_list;
    new_list->prev = prev;
    prev->next = new_list;
}

void list_add(struct list_head* new_list, struct list_head* head)
{
   __list_add(new_list, head, head->next);
}

void __list_del(struct list_head* prev, struct list_head* next)
{
    prev->next = next;
    next->prev = prev;
}

void list_del(struct list_head* entry)
{
    __list_del(entry->prev, entry->next);
    entry->next = (void*)0;
    entry->prev = (void*)0;
}

void swap(struct list_head* node_1, struct list_head* node_2)
{
    struct list_head *pos = node_2->prev;
    list_del(node_2);
    list_replace(node_1, node_2);
    // avoid node_2->prev = node_1
    if(pos == node_1)
        pos = node_2;
    list_add(node_1, pos);
}

void list_replace(struct list_head *old_node, struct list_head *target_node)
{
    target_node->next = old_node->next;
    target_node->prev = old_node->prev;
    old_node->prev->next = target_node;
    old_node->next->prev = target_node;
}