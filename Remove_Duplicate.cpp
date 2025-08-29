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

void insert_at_tail(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
};

void delete_after(Node *prev)
{
    if (prev == NULL || prev->next == NULL)
    {
        return;
    }
    Node *deleteNode = prev->next;
    prev->next = deleteNode->next;
    delete deleteNode;
};

void print_linked_list(Node *head)
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
};

void remove_duplicates(Node *&head)
{
    Node *current = head;
    int index = 0;
    while (current != NULL)
    {
        Node *runner = current;
        int runnerIndex = index;
        while (runner->next != NULL)
        {
            if (runner->next->val == current->val)
            {
                delete_after(runner);
            }
            else
            {
                runner = runner->next;
                runnerIndex++;
            }
        }
        current = current->next;
        index++;
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int val;

    while (cin >> val && val != -1)
    {
        insert_at_tail(head, tail, val);
    }

    remove_duplicates(head);
    print_linked_list(head);

    return 0;
}
