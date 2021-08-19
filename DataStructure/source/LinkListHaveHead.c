/*************************************************************************
    > File Name       : LinkListHaveHead.c
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
    Node *s;
    List head = (List)malloc(sizeof(Node));  //Generate header node
    head->next = NULL;
    for (int i = 0; i < n; i++) {
        s = (List)malloc(sizeof(Node));
        s->data = i;
        s->next = head->next;
        head->next = s;
        //The pointer field of the head node next points to the s node, making s a node
    }
    return head;
}

//Tail interpolation
List TailCreatList(int n) {
    Node *s, *r;
    List head = (List)malloc(sizeof(Node));
    head->next = NULL;
    r = head;
    for (int i = 0; i < n; i++) {
        s = (List)malloc(sizeof(Node));
        s->data = i;
        r->next = s;
        r = s;
    }

    if (r->next != NULL) {
        r->next = NULL;
    }

    return head;
}

List CreatHNode() {
    List head = (List)malloc(sizeof(Node));
    head->next = NULL;
    return head;
}

//Push head
Status HeadList(List head, int n) {
    Node *s;
    for (int i = 0; i < n; i++) {
        s = (List)malloc(sizeof(Node));
        s->data = i;
        s->next = head->next;
        head->next = s;  //The pointer field of the head node next points to the s node, making s a node
    }
    return OK;
}

//Push tail
Status TailList(List head, int n) {
    Node *s, *r;
    r = head;
    for (int i = 0; i < n; i++) {
        s = (List)malloc(sizeof(Node));
        s->data = i;
        r->next = s;
        r = s;
    }

    if (r->next != NULL) {
        r->next = NULL;
    }
    return OK;
}

//Print
Status PrintList(List head) {
    Node *t = head->next;
    while (t != NULL) {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");

    return OK;
}

//Add elements to linked list (Head)
Status HeadInsertList(List head, Node a) {
    Node *p = (List)malloc(sizeof(Node));
    p->data = a.data;
    p->next = head->next;
    head->next = p;
    return OK;
}

//Add elements to linked list (Tail)
Status TailInsertList(List head, Node a) {
    Node *p, *t, *s;
    t = head->next;
    p = (List)malloc(sizeof(Node));
    p->data = a.data;
    while (t != NULL) {
        s = t;
        t = t->next;
    }
    s->next = p;
    p->next = NULL;
    return OK;
}

//Insertion of linked list (before)
Status InsertIndexFront(List head, int i) {
    Node *p, *q, *r;
    int j = 0;
    p = head;
    while (p && j < i) {
        r = p;
        p = p->next;
        j++;
    }

    if (!p || j > i) {
        return ERROR;
    }

    q = (List)malloc(sizeof(Node));
    scanf("%d", &q->data);
    q->next = p;
    r->next = q;

    return OK;
}

//Insertion of linked list (after)
Status InsertIndexBack(List head, int i) {
    Node *p, *q;
    int j = 0;
    p = head;
    while (p && j < i) {
        p = p->next;
        j++;
    }

    if (!p || j > i) {
        return ERROR;
    }

    q = (List)malloc(sizeof(Node));
    scanf("%d", &q->data);
    q->next = p->next;
    p->next = q;

    return OK;
}

//Deletion of linked list elements
Status DeleteList(List head, int index) {  //Deletion of single linked list
    //In the single linked list L of the leading node, delete the ith position
    Node *p, *q;
    int j;
    p = head;
    j = 0;
    while ((p->next) && (j < index - 1)) {  //Find the i-1 node, and p points to it
        p = p->next;
        j++;
    }
    if (!(p->next) || (j > index - 1))  //When i > n or i < 1, the deletion position is unreasonable
        return ERROR;
    q = p->next;        //Temporarily save the address of the deleted node for free space
    p->next = q->next;  //Change the pointer field of the precursor node of the deleted node
    free(q);            //Free up space for deleted nodes
    return OK;
}

//Search of linked list elements
elem GetElem(List head, int index) {  //by index
    int j;
    Node *p;
    p = head->next;           //p points to the first data node
    j = 1;                    //j is a counter
    while (p && j < index) {  //Scan backward along the linked list until p points to the ith element or p is empty
        p = p->next;          //p points to the next node
        j++;                  //Counter j is incremented by 1 accordingly
    }
    if (!p || j > index)
        return -1;   //Illegal i value i > n or i < = 0
    return p->data;  //Returns the data field of the ith node
}

elem GetIndex(List head, int e) {  //by value
    //Find the element with value e in the single linked list L of the leading node
    Node *p;
    int index = 1;
    p = head->next;

    while (p && p->data != e) {
        //Scan the chain domain backward until p is empty or the data domain of the node referred to by p is equal to e
        p = p->next;  //p points to the next node
        ++index;
    }
    if (!p)
        return -1;  //Lookup failed. p is null

    return index;
}

//Modification of linked list elements
Status ReverseElem(List head, int index, int e) {
    int j;
    Node *p;
    p = head->next;           //p points to the first data node
    j = 1;                    //j is a counter
    while (p && j < index) {  //Scan backward along the linked list until p points to the ith element or p is empty
        p = p->next;          //p point to the next node
        j++;                  //Counter j is incremented by 1 accordingly
    }
    if (!p || j > index)
        return ERROR;  //Illegal i value i > n or i < = 0
    p->data = e;
    return OK;  //Returns the data field of the ith node
}

//Empty linked list
Status ClearList(List head) {
    Node *p, *q;
    if (head == NULL)
        return ERROR;
    p = head->next;
    while (p != NULL) {
        q = p->next;
        free(p);
        p = q;
    }
    head->next = NULL;
    return OK;
}

//Sorting of linked lists
Status SwapElem(int *i, int *j) {  //Swap data
    int temp = *i;
    *i = *j;
    *j = temp;
    return OK;
}

void SortList(List head) {  //Bubble sorting
    Node *p = NULL;
    Node *q = NULL;
    Node *t = NULL;
    if (head->next == NULL) {
        return;
    }

    for (p = head->next; p != NULL; p = p->next) {
        for (q = head->next; q->next != NULL; q = q->next) {
            if (q->data > q->next->data) {
                SwapElem(&q->data, &q->next->data);
            }
        }
    }
}
void test() {
    List head;
    head = HeadCreatList(10);

    PrintList(head);

    SortList(head);

    PrintList(head);

    return;
}

int main() {
    test();
    system("pause");
    return 0;
}