/*************************************************************************
    > File Name       : StackByChain.c
    > Author          : Ther
    > Created Time    : 2021年08月19日 星期四 14时53分46秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
typedef int elem;
typedef int Status;

typedef struct Node  //Define linked list structure
{
    elem data;          //Data domain
    struct Node *next;  //Pointer field
} Node, *LNode;

typedef struct Stack {
    LNode top;
    LNode base;
} Stack, *Pstack;

//Create an empty stack
Pstack CreatStack() {
    Pstack stack = (Pstack)malloc(sizeof(Stack));
    if (stack == NULL) {
        return NULL;
    }

    stack->top = stack->base = NULL;

    return stack;
}

//Push stack
Status PushStack(Pstack *stack, elem e) {
    Node *p = (LNode)malloc(sizeof(Node));
    if (p == NULL) {
        return ERROR;
    }
    p->data = e;
    p->next = (*stack)->top;
    (*stack)->top = p;

    return OK;
}

//Out of stack
Status PopStack(Pstack *stack) {
    Node *p = (*stack)->top;
    if (p == (*stack)->base) {
        printf("栈已空");
        return ERROR;
    }
    (*stack)->top = p->next;
    printf("%d ", p->data);
    free(p);

    return OK;
}

//Judge whether it is an empty stack
Status IsEmptyStack(Pstack stack) {
    return (stack->top == stack->base);
}

//Empty stack
Status CleanStack(Pstack *stack) {
    Node *p = (*stack)->top;
    while (p) {
        (*stack)->top = p->next;
        free(p);
        p = (*stack)->top;
    }
    return OK;
}

//Destory stack
Status DestroyStack(Pstack *stack) {
    CleanStack(stack);

    free(*stack);

    return OK;
}

void test() {
    Pstack stack = CreatStack();

    printf("%d\n", IsEmptyStack(stack));

    for (int i = 0; i < 10; ++i) {
        PushStack(&stack, i);
    }

    printf("%d\n", IsEmptyStack(stack));

    /*Out of stack*/
    // for (int i = 0; i < 10; ++i){
    // 	PopStack(&stack);
    // }
    // printf("%\n");
    // printf("%d\n", IsEmptyStack(stack));

    /*Empty*/
    CleanStack(&stack);

    printf("%d\n", IsEmptyStack(stack));
    printf("%p\n", stack);

    DestroyStack(&stack);

    printf("%d\n", IsEmptyStack(stack));
    printf("%p\n", stack);
}

int main(int argc, char const *argv[]) {
    test();
    return 0;
}