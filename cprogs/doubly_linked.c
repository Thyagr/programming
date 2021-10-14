#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* prev;
    struct Node* next;
}node_t;

node_t* head = NULL;

void PrintNodes()
{
    node_t* temp = head;
    while(temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
    printf("\n");
}

void AddNodeNext(int data)
{
    node_t* node = malloc(sizeof(node_t));
    node->data = data;
    node->next = NULL;

    if (head == NULL)
    {
        node->prev = NULL;
        head = node;
        return;
    }

    node_t* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    node->prev = temp;
    temp->next = node;
}

void AddNodePrev(int data)
{
    node_t* node = malloc(sizeof(node_t));
    node->data = data;
    node->prev = NULL;

    if (head == NULL)
    {
        node->next = NULL;
        head = node;
        return;
    }

    node->next = head;
    head->prev = node;
    head = node;
}

void Reverse_list()
{
    // implementation 
    node_t* temp = NULL;

    while (head != NULL)
    {
       // swap the pointers
       temp = head->prev;
       head->prev = head->next;
       head->next = temp;      

       head = head->prev;    
    }

    // if list not empty
    if (temp != NULL) head = temp->prev;
}

void Remove_Front()
{
    if (head == NULL) return;

    node_t* temp = head->next;
    temp->prev = NULL;
    free(head);

    head = temp;
}

void Remove_End()
{
    if (head == NULL) return;

    node_t * cur = head;
    while (cur->next != NULL) 
    {
        cur = cur->next;
    }

    node_t* prev = cur->prev;
    prev->next = NULL;
    free(cur);
}

int main()
{
    AddNodeNext(1);
    AddNodeNext(2);
    AddNodeNext(3);
    AddNodePrev(4);
    PrintNodes();
    Reverse_list();
    PrintNodes();
    Remove_Front();
    Remove_End();
    PrintNodes();

    return 0;
}
