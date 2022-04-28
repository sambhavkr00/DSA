#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *prev;
    node *next;
    node(int d)
    {
        data = d;
        prev = NULL;
        next = NULL;
    }
};

void insertBeg(node *&head, int x)
{
    node *newNode = new node(x);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    newNode->next = head;
    newNode->prev = NULL;
    head->prev = newNode;
    head = newNode;
}

void insertEnd(node *&head, int x)
{
    node *newNode = new node(x);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    newNode->prev = temp;
    temp->next = newNode;
    temp = NULL;
}

void insertPos(node *&head, int x, int pos)
{
    node *newNode = new node(x);
    node *c = head;
    int cnt = 1;
    while (c != NULL)
    {
        c = c->next;
        cnt++;
    }
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
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }
}

void del(node* &head, int key)
{
    node *temp = head;
    if (temp->data == key)
    {
        head = temp->next;
        delete temp;
        return;
    }
    
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
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void display(node *head)
{
    node *temp = head;
    if (head == NULL)
    {
        return;
    }
    
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    node *head = NULL;
    insertBeg(head, 5);
    insertBeg(head, 3);
    insertBeg(head, 10);
    insertEnd(head, 1);
    insertEnd(head, 155);
    display(head);
    insertPos(head, 15, 4);
    display(head);
    cout << search(head, 10) << endl;
    del(head, 155);
    display(head);
    return 0;
}