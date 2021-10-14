/* Linked List Operations */

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int i;
    struct node* ptr;
}node_t;

node_t* head = NULL;

void addnode()
{
    node_t* newnode = malloc(sizeof(node_t));
    if (newnode == NULL)
    {
        printf("%s", "Error allocating memory !!");
        exit(-1);
    }
    newnode->ptr = NULL;

    printf("Enter a number: \t");
    scanf(" %d",&newnode->i);
    if (head == NULL)
        head = newnode;
    else
    {
        node_t* cur = head;
        while (cur->ptr != NULL)
            cur = cur->ptr;
        cur->ptr = newnode;
    }
}

void printnodes()
{
    node_t* cur = head;
    while(cur != NULL)
    {
       printf("%d -> ",cur->i);
       cur = cur->ptr;
    }
    printf("NULL\n");
}

void deletenode()
{
    if (head == NULL)
    {
       printf("\nThe list is empty, no nodes to delete!");
    }
    else
    {
        node_t* cur = head;
        node_t* prv = NULL;
        while (cur->ptr != NULL)
        {
            prv = cur;
            cur = cur->ptr;
        }
        free(cur);
        if (prv) // if only one node
            prv->ptr = NULL;
        else
            head = NULL;
        printnodes();
    }
}

void deletefront()
{
    if (head != NULL)
    {
        node_t* temp = head->ptr;
        free(head);
        head = temp;
        printf("List head deleted\n");
        printnodes();
    }
    else
       printf("\nThe list is empty, no nodes to delete!");
}


void deletevalue(int val)
{
    int delcount = 0;

    if (head == NULL)
    {
        printf("List is Empty!");
        return;
    }
    while (head != NULL && head->i == val)
    {
        node_t* temp = head->ptr;
        free(head);
        head = temp;
        delcount++;
    }
    node_t* prv = head;
    node_t* cur = head->ptr;
    while (cur != NULL)
    {
        if (cur->i == val)
        {
            prv->ptr = cur->ptr;
            free(cur);
            cur = prv->ptr;
            delcount++;
        }
        else
        {
            prv = cur;
            cur = cur->ptr;
        }
    }
    printf("\nNumber of nodes deleted %d\n", delcount);
    printnodes();
}

//cleanup routine before exit
void clearmem()
{
    node_t* temp = NULL;
    while (head != NULL)
    {
        temp = head->ptr;
        free(head);
        head = temp;
    }
}

void revlist()
{
    node_t* prv = NULL , *nxt;
    while (head != NULL)
    {
        nxt = head->ptr;
        head->ptr = prv;
        prv = head;
        head = nxt;
    }
    head = prv;
    printnodes();
}

void recursion_print_fw(node_t* p)
{
	if (p == NULL) return;
	printf("%d ", p->i ); // changing the order changes the recursion
	recursion_print_fw(p->ptr);
}

void recursion_print_rv(node_t* p)
{
	if (p == NULL) return;
	recursion_print_rv(p->ptr); // note that statement just changed order
	printf("%d ", p->i );

}

int main(void)
{
    char ch;
    int val;
    printf("Simple Linked List program in C\n");
    printf("Add(a) - Print(p) - Delete(d) - Reverse(r) - DeleteHead(h) - DeleteValues(v)");
    printf("\nRecursively Print(c) - Quit(q/x)\n");
    do
    {
        printf("\nEnter your choice (a,p,d,r,h,v): ");
        scanf(" %c",&ch); // space before %c to scan inputs with leading blank spaces
        switch(ch)
        {
            case 'a':
                addnode();
                break;
            case 'p':
                printnodes();
                printf("\n");
                break;
            case 'd':
                deletenode();
                break;
            case 'r':
                revlist();
                break;
            case 'h':
                deletefront();
                break;
             case 'v':
                printf("\nEnter value to delete: ");
                scanf(" %d",&val);
                deletevalue(val);
                break;
             case 'c':
                printf("\nFwd Print: ");
            	recursion_print_fw(head);
            	printf("\nRev Print: ");
            	recursion_print_rv(head);
                break;
            case 'q':
            case 'x':
                printf("\nQuitting the application\n");
                ch = 'q';
                break;
            default:
                printf("\nInvalid option, re-enter the option: ");
                scanf(" %c",&ch);
        }
    } while(ch != 'q' && ch != 'x');
    clearmem(); //free all the allocated memory
    return 0;
}
