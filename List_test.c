#include <stdio.h>
#include <stdlib.h>

struct List_Node {
    int value;
    struct List_Node *next;
};

struct List_Node *Init_List(void)
{
    struct List_Node *Head = malloc(sizeof(struct List_Node));
    if (Head == NULL) {
        return NULL;
    }
    Head->value = 0;
    Head->next = NULL;
    return Head;
}

void Free_List(struct List_Node *Head)
{
    struct List_Node *p = Head;
    struct List_Node *tmp = NULL;
    while(p->next) {
        tmp = p->next;
        p = p->next;
        free(tmp);
    }
    free(Head);
    Head = NULL;
}

void Print_List(struct List_Node *Head)
{
    struct List_Node *p = Head;
    struct List_Node *tmp = NULL;
    int count = 0;
    while(p->next) {
        tmp = p->next;
        printf("%d %d\n",++count ,tmp->value);
        p = tmp;
    }
}

int Init_Array(struct List_Node *Head,int *value,int size)
{
    struct List_Node *tmp;
    tmp = Head;
    while(size--) {
        struct List_Node *p = malloc(sizeof(struct List_Node));
        if (p == NULL) {
            Free_List(Head);
            return -1;
        }
        tmp->next = p;

        p->value = *value;
        value++;
        p->next = NULL;
        tmp = p;
    }

}
struct List_Node * Reverse(struct List_Node *Head)
{
    struct List_Node *p = NULL;
    struct List_Node *pr = NULL;
    struct List_Node *tmp = NULL;
    p = Head->next;
    Head->next = NULL;

    while(p) {
        pr = p->next;
        p->next = tmp;
        tmp = p;
        p = pr;
    }
    Head->next = tmp;

    return Head;
}
int main()
{
    int array[] ={23,45,67,34,32,23,45,28,49};
    int size = sizeof(array)/sizeof(array[0]);
    struct List_Node *Head = Init_List();
    if (Head ==NULL) {
        return -1;
    }
    Init_Array(Head,array,size);
    Print_List(Head);
    Reverse(Head);
    Print_List(Head);


    return 0;
}
