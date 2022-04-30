#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
    node(int d)
    {
        data = d;
        next = NULL;
    }
};

void insertBeg(node *&head, int x)
{
    node *newNode = new node(x);
    if (head == NULL)
    {
        newNode ->next = newNode;
        head = newNode;
        return;
    }
    node *temp = head;
    do
    {
        temp = temp->next;
    } while (temp->next != head);

    temp->next = newNode;
    newNode->next = head;
    head = newNode;
}

void insertEnd(node *&head, int x)
{
    node *newNode = new node(x);
    if (head == NULL)
    {
        newNode ->next = newNode;
        head = newNode;
        return;
    }
    node *temp = head;
    do
    {
        temp = temp->next;
    } while (temp->next != head);

    temp->next = newNode;
    newNode->next = head;
    temp = NULL;
}

void insertPos(node *&head, int x, int pos)
{
    node *newNode = new node(x);
    node *c = head;
    int cnt = 1;
    do
    {
        c = c->next;
        cnt++;
    } while (c != head);
    
    if (pos < 1 || pos > cnt)
    {
        cout << "Invalid position" << endl;
    }
    else if (pos == 1)
    {
        insertBeg(head, x);
    }
    else if (pos == cnt)
    {
        insertEnd(head, x);
    }
    else
    {
        node *temp = head;
        pos = pos-2;
        while (pos--)
        {
            temp = temp ->next; 
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void del(node* &head, int key)
{
    node *temp = head;
    while (temp->next->data != key)
    {
        temp = temp->next;
    }
    node *p = temp->next;
    temp ->next = temp ->next ->next;
    delete p;
}

bool search(node *head, int key)
{
    node *temp = head;

    do
    {
        if (temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    } while (temp != head);

    return false;
}

void display(node *head)
{
    node *temp = head;
    if (head == NULL)
    {
        return;
    }
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main()
{
    node *head = NULL;
    insertEnd(head, 5);
    insertEnd(head, 10);
    display(head);
    insertPos(head, 15, 2);
    display(head);
    cout << search(head, 10) << endl;
    del(head, 10);
    display(head);
    return 0;
}