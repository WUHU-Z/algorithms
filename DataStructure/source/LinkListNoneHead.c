/*************************************************************************
    > File Name       : LinkListNoneHead.c
    > Author          : Ther
    > Created Time    : 2021年08月19日 星期四 13时53分39秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
typedef int elem;
typedef int Status;

typedef struct LNode {
    elem data;           //Data domain
    struct LNode *next;  //Pointer field
} Node, *List;

//Head insertion
List HeadCreatList(int n) {
    List head = NULL;
    Node *p;
    while (n--) {
        p = (List)malloc(sizeof(Node));
        p->data = n;
        if (head == NULL) {
            p->next = NULL;
            head = p;
        } else {
            p->next = head;
            head = p;
        }
    }
    return head;
}

//Tail interpolation
List TailCreatList(int n) {
    List head = NULL;
    Node *p, *q;
    while (n--) {
        p = (List)malloc(sizeof(Node));
        p->data = n;
        if (head == NULL) {
            head = p;
        } else {
            q->next = p;
        }
        p->next = NULL;
        q = p;
    }
    return head;
}

//Push head
Status HeadPushList(List *head, int n) {
    Node *p = (List)malloc(sizeof(Node));
    p->data = n;
    if (head == NULL) {
        p->next = NULL;
        *head = p;
    } else {
        p->next = *head;
        *head = p;
    }
    return OK;
}

//Push tail
Status TailPushList(List *head, int n) {
    Node *p = (List)malloc(sizeof(Node));
    Node *q = *head;
    p->data = n;
    p->next = NULL;
    while (q->next != NULL) {
        q = q->next;
    }
    q->next = p;
    return OK;
}

//Insert before index
Status InsertFront(List *head, int index, int n) {
    Node *p, *q, *r;
    int i = 1;
    p = *head;
    while (p && i < index) {
        r = p;
        p = p->next;
        i++;
    }

    if (!p || i > index) {
        return ERROR;
    }

    q = (List)malloc(sizeof(Node));
    q->data = n;

    q->next = p;
    r->next = q;

    return OK;
}

//Insert after index
Status InsertBack(List *head, int index, int n) {
    Node *p = *head;
    Node *q;
    int i = 1;
    while (i < index && p) {
        i++;
        p = p->next;
    }

    if (i > index || !p) {
        return ERROR;
    }

    q = (List)malloc(sizeof(Node));
    q->data = n;
    q->next = p->next;
    p->next = q;
    q = (List)malloc(sizeof(Node));

    return OK;
}

//Find by index
elem FindIndex(List head, int index) {
    int i;
    Node *p;
    p = head;                 //p points to the first data node
    i = 1;                    //i is a counter
    while (p && i < index) {  //Scan backward along the linked list until p points to the ith element or p is empty
        p = p->next;          //p points to the next node
        i++;                  //Counter i is incremented by 1 accordingly
    }
    if (!p || i > index)
        return -1;   //Illegal i value i > n or i < = 0
    return p->data;  //Returns the data field of the ith node
}

//Find by value
int FindValue(List head, elem e) {
    //Find the element with value e in the single linked list L of the leading node
    Node *p;
    int index = 0;
    p = head;

    while (p && p->data != e) {
        //Scan the chain domain backward until P is empty or the data domain of the node referred to by p is equal to e
        p = p->next;  //p points to the next node
        ++index;
    }
    if (!p)
        return -1;  //Lookup failed. p is null

    return index;
}

//Modify element
Status ReverseElem(List *head, int index, int e) {
    int j;
    Node *p;
    p = *head;                //p points to the first data node
    j = 1;                    //j is the counter
    while (p && j < index) {  //Scan backward along the linked list until p points to the ith element or p is empty
        p = p->next;          //p points to the next node
        j++;                  //Counter  is incremented by 1 accordingly
    }
    if (!p || j > index)
        return ERROR;  //Illegal i value i > n or i < = 0
    p->data = e;
    return OK;  //Returns the data field of the ith node
}

//Print linklist element
Status PrintList(List head) {
    if (head == NULL) {
        return ERROR;
    } else {
        Node *t = head;
        while (t != NULL) {
            printf("%d ", t->data);
            t = t->next;
        }
    }
    printf("\n");
    return OK;
}

void test() {
    List head;
    head = HeadCreatList(10);

    PrintList(head);

    printf("%d\n", FindIndex(head, 5));
    printf("%d\n", FindValue(head, 5));

    //PrintList(head);
    return;
}

int main(int argc, char const *argv[]) {
    test();
    return 0;
}
