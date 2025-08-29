#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void insert_at_head(Node *&head, int val)
{
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
};

void insert_at_any_pos(Node *&head, int index, int val)
{
    Node *newNode = new Node(val);
    Node *temp = head;
    for (int i = 1; i < index; i++)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
};
void insert_at_tail(Node *&head, Node *&tail, int val)
{

    Node *newNode = new Node(val);

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = tail->next;
};

int size_linked_list(Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
};

void print_linked_list(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
};

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    int val;
    while (true)
    {
        cin >> val;
        if (val == -1)
        {
            break;
        }
        insert_at_tail(head, tail, val);
    }
    int index;
    while (cin >> index >> val)
    {
        int sz = size_linked_list(head);
        if (index > sz)
        {
            cout << "Invalid\n";
        }
        else if (index == sz)
        {
            insert_at_tail(head, tail, val);
            print_linked_list(head);
        }
        else if (index == 0)
        {
            insert_at_head(head, val);
            print_linked_list(head);
        }
        else
        {
            insert_at_any_pos(head, index, val);
            print_linked_list(head);
        }
    }

    return 0;
}