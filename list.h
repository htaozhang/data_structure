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

static inline void __list_del(struct list_head *prev, struct list_head *next)
{
    next->prev = prev;
    prev->next = next;
}

static inline void __list_del_entry(struct list_head *entry)
{
    __list_del(entry->prev, entry->next);
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

static inline void list_del(struct list_head *entry)
{
    __list_del(entry->prev, entry->next);

}

/**
 * @list: the entry to move
 * @head: the head that will precede our entry
 */
static inline void list_move(struct list_head *list, struct list_head *head)
{
    __del_entry(list);
    list_add(list, head);
}

/**
 * @list: the entry to move
 * @head the head that will follow our entry
 */
static inline void list_move_tail(struct list_head *list, struct list_head *head)
{
    __del_entry(list);
    list_add_tail(list, head);
}


#define list_for_each(pos, head) \
    for (pos = (head)->next; pos != (head); pos = pos->next)


#endif /* __list_ */




