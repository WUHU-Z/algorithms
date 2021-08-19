/*************************************************************************
    > File Name       : Queue.c
    > Author          : Ther
    > Created Time    : 2021年08月19日 星期四 13时53分53秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
typedef int elem;
typedef int Status;

typedef struct QNode {
    elem data;           //Data domain
    struct QNode *next;  //Pointer field
} QNode, *PNode;

typedef struct {
    PNode front;  //Queue head pointer
    PNode rear;   //Queue tail pointer
} LinkQueue;

//Create queue
Status CreatQueue(LinkQueue *q) {
    q->front = q->rear = (PNode)malloc(sizeof(QNode));

    if (q->front == NULL) {
        return ERROR;
    }

    q->front->next = NULL;

    return OK;
}

//Join the team
Status PushQueue(LinkQueue *q, elem e) {
    QNode *p = (PNode)malloc(sizeof(QNode));
    if (p == NULL) {
        return ERROR;
    }
    p->data = e;
    p->next = NULL;
    q->rear->next = p;
    q->rear = p;

    return OK;
}

//Out of the queue
Status PopQueue(LinkQueue *q) {
    if (q->front == q->rear) {
        return ERROR;
    }

    QNode *p = q->front->next;
    printf("%d ", p->data);
    q->front->next = p->next;
    if (q->rear == p) q->rear = q->front;

    return OK;
}

//Destroy queue
Status DestroyQueue(LinkQueue *q) {
    while (q->front) {
        q->rear = q->front->next;
        free(q->front);
        q->front = q->rear;
    }
    return OK;
}

//some test
void test() {
    LinkQueue q;
    CreatQueue(&q);

    for (int i = 0; i < 10; ++i) {
        PushQueue(&q, i);
    }

    for (int i = 0; i < 10; ++i) {
        PopQueue(&q);
    }

    DestroyQueue(&q);
}

int main(int argc, char const *argv[]) {
    test();
    return 0;
}
