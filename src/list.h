#ifndef __LIST__H__
#define __LIST__H__
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
typedef struct mynode mynode;

#define LIST_HEAD_INIT(name) { &(name), &(name) }
#define LIST_HEAD(name) \
	struct list_head name = LIST_HEAD_INIT(name)
#define list_of_each(pos, head) \
	for((pos) = (head)->next; (pos) != (head); (pos) = (pos)->next)
#define offsetof(type, member) ((size_t) &((type*)0)->member)
#define container_of(ptr, type, member) ({			\
	const __typeof__(((type *)0)->member) * __mptr = (ptr);	\
	(type *)((char *)__mptr - offsetof(type, member)); })

struct list_head
{
	struct list_head *next, *prev;
};

typedef struct mynode
{
    int val;
    struct list_head list;
}mynode;

void INIT_LIST_HEAD(struct list_head*);
int list_empty(struct list_head*);
void __list_add(struct list_head*, struct list_head*, struct list_head*);
void __list_del(struct list_head*, struct list_head*);
void list_add(struct list_head*, struct list_head*);
void list_del(struct list_head*);
void list_replace(struct list_head*, struct list_head *);
void swap(struct list_head*, struct list_head*);

#endif
