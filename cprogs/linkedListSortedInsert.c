#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node
{
    int data;
    struct node* ptr;
}node_t;
node_t* head = NULL;

void InsertOrdered(int num)
{
    node_t* newnode = (node_t*)malloc(sizeof(node_t));
    newnode->data = num;
    if (head == NULL)
    {
        head = newnode;
        head->ptr = NULL;
    }
    else if (head->data > num)
    {
        newnode->ptr = head;
        head = newnode;
    }
    else
    {
        node_t* cur1 = head;
        node_t* cur2 = cur1->ptr;
        while (cur2 != NULL)
        {
            if (cur2->data > num) break;
            cur1 = cur2;
            cur2 = cur2->ptr;
        }
        newnode->ptr = cur2;
        cur1->ptr = newnode;
    }
}

void PrintList()
{
    node_t* cur = head;
    while (cur != NULL)
    {
        printf("%d -> ", cur->data);
        cur = cur->ptr;
    }
    printf("NULL\n");
}

int main(void)
{
    int num;
    char ch;
    srand(time(NULL));
    do
    {
        printf("\nEnter choice (I)nsert (P)rint: ");
        scanf(" %c", &ch);
        switch (ch)
        {
        case 'i':
            //printf("Enter number: ");
            //scanf(" %d", &num);
            //InsertOrdered(num);
            for (int j=0; j < 10; j++)
                InsertOrdered(rand() % 100); //generates random number < 100
            break;

        case 'p':
            PrintList();
            break;
        }

    } while (ch == 'i' || ch == 'p');

    return 0;
}
