#include "iostream"
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        n->next = n;
        head = n;
        return;
    }

    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
    head = n;
}

void insertAtEnd(node *&head, int val)
{

    if (head == NULL)
    {
        insertAtHead(head, val);
        return;
    }

    node *n = new node(val);
    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
}

void deleteAtHead(node *&head)
{
    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = head->next;
    node *todelete = head;
    head = head->next;
    delete todelete;
}

void deletion(node *&head, int pos)
{
    if (pos == 1)
    {
        deleteAtHead(head);
        return;
    }

    node *temp = head;
    int count = 1;
    while (count != pos - 1)
    {
        temp = temp->next;
        count++;
    }
    node *todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}

void Display(node *&head)
{
    node *temp = head;
    do
    {
        cout << temp->data << "->";
        temp = temp->next;
    } while (temp != head);
    cout << "HEAD\n";
}

int main()
{
    node *head = NULL;
    insertAtEnd(head, 10);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 4);
    insertAtHead(head, 6);
    Display(head);
    deletion(head, 5);
    Display(head);
}