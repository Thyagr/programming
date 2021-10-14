#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
}node_t;
node_t* top = NULL;

void Stack_push(int d)
{
    node_t* temp = (node_t*)malloc(sizeof(node_t));
    temp->data = d;
    temp->next = top;
    top = temp;
}

int Stack_size()
{
    node_t* temp = top;
    int size = 0;
    while (temp != NULL)
    {
        size++;
        temp = temp->next;
    }
    return size;
}

int Stack_peek(int* d)
{
    if (top != NULL)
    {
        *d = top->data;
        return 0;
    }
    else
        return -1;
}

int Stack_pop(int* d)
{
    if (top != NULL)
    {
        *d = top->data;
        node_t* temp = top->next;
        free(top);
        top = temp;
        return 0;
    }
    else
        return -1;
}

void Stack_clear()
{
    node_t* temp;
    while (top != NULL)
    {
        temp = top->next;
        free(top);
        top = temp;
    }
}

int main(void)
{
    char choice;
    printf("Stack implementation in C\n");
    printf("(P)ush P(o)p Pe(e)k (S)ize\n");
    int d;
    do
    {
        printf("Enter choice: ");
        scanf(" %c", &choice); // space before %c for newline
        switch (choice)
        {
            case 'p':
                printf("Enter data: ");
                scanf("%d", &d);
                Stack_push(d);
//                for (d=0; d<10; d++)
//                    Stack_push(d);
                break;

            case 's':
                printf("Size of stack =  %d\n", Stack_size());
                break;

            case 'e':
                if (Stack_peek(&d) == 0)
                    printf("Top Element = %d\n", d);
                else
                    printf("Stack is empty!\n");
                break;

            case 'o':
                if (Stack_pop(&d) == 0)
                    printf("Popped element = %d\n", d);
                else
                    printf("Stack is empty!\n");
                break;

            default:
                printf("Invalid choice, cleaning up stack");
                Stack_clear(); //program termination should reclaim heap
        }

    } while (choice == 'p' || choice == 'o'
                           || choice == 'e'
                           || choice == 's');

    return 0;
}
