#include <iostream>
using namespace std;

class node
{
public:
    node *prev;
    int data;
    node *next;
    node(int val)
    {
        data = val;
        prev = NULL;
        next = NULL;
    }
};
void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    if (head != NULL)
    {
        head->prev = n;
    }
    head = n;
    //n->prev=NULL; no need bcoz of constructor abouve
}
void insertAtTail(node *&head, int val)
{
    if (head == NULL)
    {
        insertAtHead(head, val);
    }
    node *n = new node(val);
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}
void deleteathead(node* &head)
{
    node *temp = head;
    head = head->next;
    head->prev = NULL;
    delete temp;
}
void Delete(node *&head, int pos)
{
    if (pos == 1)
    {
        deleteathead(head);
        return;
    }

    node *temp = head;
    int count = 1;
    while (temp != NULL & count != pos)
    {
        temp = temp->next;
        count++;
    }
    temp->prev->next = temp->next;
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }
    delete temp;
}
void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int main()
{
    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    display(head);
    insertAtHead(head, 7);
    display(head);
    Delete(head,3);
    display(head);
    Delete(head,1);
    display(head);
}