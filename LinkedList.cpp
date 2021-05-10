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

void insertAtTail(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}
void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
}
bool search(node *head, int key)
{
    node *n = head;
    while (n != NULL)
    {
        if (n->data == key)
        {
            return true;
        }
        n = n->next;
    }
    return false;
}
void display(node *head)
{
    node *n = head;
    while (n != NULL)
    {
        cout << n->data << " -> ";
        n = n->next;
    }
    cout << "NULL \n";
}
//There is no need for temp but just to be on safer side we take another varible
void deletehead(node *head)
{
    node *temp = head;
    node *todelete = temp->next;
    head = temp->next;  //or just head=head->next;
    delete todelete;
}
void deletion(node *head, int val)
{   
    if(head==NULL){
        return;
    }
    if(head->next==NULL){
        deletehead(head);
        return;
    }

    node *temp = head;
    while (temp->next->data != val)
    {
        temp = temp->next;
    }
    node *todelete = temp->next; //This because after the next line node will be deleted but we need to deallocate it too , so this will have the address
    temp->next = temp->next->next;
    delete todelete;
}
int main()
{
    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    display(head);
    cout << search(head, 2) << endl;
    deletion(head, 3);
    display(head);
    return 0;
}