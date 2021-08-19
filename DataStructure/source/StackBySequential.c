/*************************************************************************
    > File Name       : StackBySequential.c
    > Author          : Ther
    > Created Time    : 2021年08月19日 星期四 13时53分46秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
#define OK 1
#define ERROR 0
typedef int elem;
typedef int Status;

typedef struct Stack {
    elem* base;     //Stack base
    elem* top;      //Stack top
    int stacksize;  //Stack capacity
} Stack;

//Initialization
Status CreatStack(Stack* s) {
    s->base = (elem*)malloc(sizeof(elem) * MAXSIZE);
    if (!s->base) return ERROR;
    s->top = s->base;
    s->stacksize = MAXSIZE;

    return OK;
}

//Push
Status PushStack(Stack* s, elem e) {
    if (s->top - s->base >= s->stacksize) {
        s->base = (elem*)realloc(s->base, sizeof(elem) * MAXSIZE);
        if (!s->base) return ERROR;

        s->top = s->base + s->stacksize;
        s->stacksize += MAXSIZE;
    }

    *(s->top) = e;
    s->top++;

    return OK;
}

//Out of stack
Status PopStack(Stack* s, elem* e) {
    if (s->top == s->base) return ERROR;
    *e = *--(s->top);

    return OK;
}

//Empty
Status CleanStack(Stack* s) {
    s->top = s->base;
    return OK;
}

//Destory
Status DestroyStack(Stack* s) {
    free(s->base);
    s->top = s->base = NULL;
    s->stacksize = 0;

    return OK;
}

//Get current capacity
int GetSize(Stack* s) {
    return s->stacksize;
}

int main(int argc, char const* argv[]) {
    Stack s;
    CreatStack(&s);
    for (int i = 0; i < 10; ++i) {
        PushStack(&s, i);
    }

    printf("The capacity of the stack is：%d.\n", GetSize(&s));

    for (int i = 0; i < 10; ++i) {
        elem e;
        PopStack(&s, &e);  //Print out of stack
        printf("%d ", e);
    }

    return 0;
}