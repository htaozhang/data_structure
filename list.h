#ifndef __list_h
#define __list_h



struct list_head
{
    struct list_head *prev;
    struct list_head *next;
};


static inline void __list_add(struct list_head *new, struct list_head *prev, struct list_head *next)
{
    next->prev = new;
    new->next = next;

    new->prev = prev;
    prev->next = new;
}

static inline void init_list_head(struct list_head *list)
{
    list->prev = list;
    list->next = list;
}

// Insert a new entry after the specified head. 
static inline void list_add(struct list_head *new, struct list_head *head)
{
    __list_add(new, head, head->next);
}

// Insert a new entry before the specified head.
static inline void list_add_tail(struct list_head *new, struct list_head *head)
{
    __list_add(new, head->prev, head);
}

#endif /* __list_ */
