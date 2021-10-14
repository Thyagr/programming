#include <stdio.h>
#include <iostream>
using namespace std;

#define rightdir 1
#define leftdir -1

typedef struct Node
{
    int value;
    Node* left;
    Node* right;

}node_t;


class DoublyLink
{
private:
    node_t* head;
public:
    DoublyLink()
    {
        head = NULL;
    }
    ~DoublyLink()
    {
        if(head != NULL)
        {
            while (head->right != NULL)
            {
                head = head->right;
                delete head->left;
            }
            delete head;
        }
    }
    void insertnode(int,int);
    void printlist(void);
};


void DoublyLink::insertnode(int val,int dir)
{
    node_t* newnode = new node_t;
    newnode->value = val;

    if (head == NULL)
    {
        newnode->right = NULL;
        newnode->left = NULL;
        head = newnode;
    }
    else
    {
        node_t* cur = head;
        if (dir == 1)
        {
            while(cur->right != NULL)
                cur = cur->right;
            cur->right = newnode;
            newnode->left = cur;
            newnode->right = NULL;
        }
        else if (dir == -1)
        {
            newnode->left = NULL;
            newnode->right = head;
            head->left = newnode;
            head = newnode;
        }
    }

}

void DoublyLink::printlist()
{
    cout << endl;
    node_t* cur = head;
    while(cur != NULL)
    {
        cout << cur->value << "->";
        cur = cur->right;
    }
    cout << "NULL";
}
int main(void)
{
    DoublyLink dlink1;
    dlink1.insertnode(10,rightdir);
    dlink1.insertnode(20,rightdir);
    dlink1.insertnode(30,leftdir);
    dlink1.printlist();

    return 0;
}
