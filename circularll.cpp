#include <iostream>
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
void insertathead(node *&head, int val)
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
void Insert(node *&head, int val)
{

    if (head == NULL)
    {
        insertathead(head, val);
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
void display(node *head)
{
    node *temp = head;
    do
    {
        cout << temp->data << "->";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}
void deletion(node *&head, int pos)
{
    if (pos == 1)
    {
        node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        node *todel = head;
        temp->next = temp->next->next;
        head=head->next;
        delete todel;

        return;
    }
    node *temp = head;
    int count = 1;
    while (count != pos - 1)
    {
        temp = temp->next;
        count++;
    }
    node *todele = temp->next;
    temp->next = temp->next->next;
    delete todele;
}
int main()
{
    node *head = NULL;
    Insert(head, 1);
    Insert(head, 2);
    Insert(head, 3);
    Insert(head, 4);
    Insert(head, 5);
    display(head);
    insertathead(head, 6);
    display(head);
    deletion(head,3);
    display(head);
    deletion(head,1);
    display(head);
    return 0;
}