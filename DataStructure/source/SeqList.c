/*************************************************************************
    > File Name       : SeqList.c
    > Author          : Ther
    > Created Time    : 2021年08月19日 星期四 13时53分14秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXSIZE 100  // Capacity of sequence table
#define OK 1
#define ERROR 0
typedef int Status;
typedef int elem;

typedef struct Sqlist {
    elem *e;     // The address of the storage space
    int length;  // The length of the SeqList
} Sqlist;

// Initialization
Status InitArray(Sqlist *L) {
    if (L->e) {  // Judge whether the pointer is empty
        free(L->e);
        L->e = NULL;
    }

    L->e = (elem *)malloc(sizeof(int) * MAXSIZE);  // Request memory space (capacity)

    if (L->e == NULL) {  // Judge whether the application for memoryspace is successful
        printf("Application for memoryspace is filed!\n");
        exit(0);
    }

    L->length = 0;
    return OK;
}

// Add element
Status PushBackArray(Sqlist *L, elem value) {
    if (L->e == NULL) {
        printf("Please initialize the sequence table.\n");
        return ERROR;
    }

    if (L->length == MAXSIZE) {
        return ERROR;
    }
    L->e[L->length] = value;
    ++L->length;
    return OK;
}

// Insert element
Status InsertArray(Sqlist *L, int index, elem value) {
    if (index > L->length + 1 || index < 1) {  // Judge whether the index is legal
        return ERROR;
    }

    for (int i = L->length; i >= index; i--) {  // Move back one position to make room
        L->e[i] = L->e[i - 1];
    }

    L->e[index] = value;  // insert

    ++L->length;  // Number of elements plus one
    return OK;
}

// Find by location
elem FindByIndex(Sqlist *L, int index) { return L->e[index]; }

// Find by value
Status FindByValue(Sqlist *L, elem value) {
    for (int i = 0; i < L->length; i++) {
        if (L->e[i] == value) {
            return i;
        }
    }
    return -1;
}

// Delete by value
Status RemoveByValue(Sqlist *L, elem value) {
    for (int i = 0; i < L->length; i++) {
        if (L->e[i] == value) {
            for (; i < L->length; i++) {
                L->e[i - 1] = L->e[i];
            }

            --L->length;
            return OK;
        }
    }
}

// Dele by location
Status RemoveByIndex(Sqlist *L, int index) {
    if (index > L->length + 1 || index < 1) {
        return ERROR;
    }

    for (int i = index; i < L->length; i++) {
        L->e[i - 1] = L->e[i];
    }

    --L->length;
    return OK;
}

// Destruction sequence table
Status FreeArray(Sqlist *L) {
    if (L->e != NULL) {
        free(L->e);
        L->e = NULL;
    }

    L->length = 0;

    return OK;
}

// Gets the length of the sequence table
int GetLength(Sqlist *L) {
    if (L->e == NULL) return -1;
    return L->length;
}

// Judge whether the sequence table is empty
Status IsEmptyArray(Sqlist *L) { return L->length = 0; }

// Empty sequence table
Status CleanArray(Sqlist *L) {
    if (L->e == NULL) {
        printf("Sequence table not initialized.\n");
        return ERROR;
    }

    L->length = 0;
    return OK;
}

// Merge sequence table
Status CombineArray(Sqlist *L1, Sqlist *L2) {
    if (L1->length + L2->length > MAXSIZE) {
        printf("The capacity of the first sequential table is insufficient and the merge failed!\n");
        return ERROR;
    }

    for (int i = 0; i < L2->length; i++) {
        L1->e[L1->length + i] = L2->e[i];
    }
    L1->length += L2->length;

    free(L2->e);
    L2->length = 0;

    return OK;
}

//Print sequence table
void PrintArray(Sqlist *L) {
    for (int i = 0; i < L->length; i++) {
        printf("%d ", L->e[i]);
    }
    printf("\n");
}

void test() {
    Sqlist L, L2;

    /********Initialize the sequence table and add elements********/
    InitArray(&L);  //Initialize the sequence table
    InitArray(&L2);
    // srand(time(NULL));
    for (int i = 0; i < 10; i++) {  //Add element
        PushBackArray(&L, i);
        PushBackArray(&L2, i);
    }
    printf("Init...\n");
    PrintArray(&L);                 //Print sequence table
    printf("%d\n", GetLength(&L));  //Gets the length of the sequence table

    /************Insert element***********/
    InsertArray(&L, 5, 100);  //Insert element
    printf("Insert...\n");
    PrintArray(&L);                 //Print sequence table
    printf("%d\n", GetLength(&L));  //Gets the length of the sequence table

    printf("Find by location...\n");
    printf("%d ", FindByIndex(&L, 10));  //Find by location
    printf("Find by value...\n");
    printf("%d ", FindByValue(&L, 4));  //Find by value

    /************Delete element***********/
    RemoveByIndex(&L, 3);  //Delete by location
    RemoveByValue(&L, 9);  //Delete by value
    printf("Delete...\n");
    PrintArray(&L);                 //Print sequence table
    printf("%d\n", GetLength(&L));  //Gets the length of the sequence table

    /***********Merge sequence table**********/
    CombineArray(&L, &L2);  //Merge
    printf("Merge...\n");
    PrintArray(&L);                 //Print sequence table
    printf("%d\n", GetLength(&L));  //Gets the length of the sequence table

    /***********Empty data table**********/
    CleanArray(&L);  //Empty
    printf("Empty...\n");
    PrintArray(&L);                 //Print sequence table
    printf("%d\n", GetLength(&L));  //Gets the length of the sequence table

    /***********Destroy data sheet**********/
    FreeArray(&L);  //Destroy
    printf("Destroy...\n");
    printf("%d", PushBackArray(&L, 1));
}

int main() {
    test();
    // system("pause");
    return 0;
}
