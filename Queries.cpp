#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    long long val;
    Node *next;
    Node(long long val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void insert_at_head(Node *&head, Node *&tail, long long val)
{
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
    if (tail == NULL)
        {tail = head;}
}

void insert_at_tail(Node *&head, Node *&tail, long long val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

void delete_at_index(Node *&head, Node *&tail, int index)
{
    if (head == NULL)
        return;
    if (index == 0)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        if (head == NULL)
            tail = NULL;
        return;
    }
    Node *prev = head;
    int idx = 0;
    while (prev != NULL && idx < index - 1)
    {
        prev = prev->next;
        idx++;
    }
    if (prev == NULL || prev->next == NULL)
        return;
    Node *delNode = prev->next;
    prev->next = delNode->next;
    if (delNode == tail)
        tail = prev;
    delete delNode;
}

void print_list(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val;
        if (temp->next != NULL)
            cout << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int Q;
    cin >> Q;

    while (Q--)
    {
        int X;
        long long V;
        cin >> X >> V;

        if (X == 0)
        {
            insert_at_head(head, tail, V);
        }
        else if (X == 1)
        {
            insert_at_tail(head, tail, V);
        }
        else if (X == 2)
        {
            delete_at_index(head, tail, V);
        }

        print_list(head);
    }

    return 0;
}
