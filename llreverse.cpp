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

node *reverse(node *&head)
{
    node *pre = NULL;
    node *cur = head;
    node *nex;
    while (cur != NULL)
    {
        nex = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nex;
    }
    return pre; //bcoz its head now
}
node *reverserecursive(node *&head)
{

    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    node *newhead = reverserecursive(head->next);
    head->next->next = head;
    head->next=NULL;
    return newhead;
}

node* reversek(node* &head,int k) {
    node* prev=NULL;
    node* curr=head;
    node* nextptr;

    int count=0;
    while(count<k && curr!=NULL) {
        nextptr = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextptr;
        count++;
    }
    if(nextptr!=NULL){
    head->next = reversek(nextptr, k);
    }
    return prev;
}
int main()
{
    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    display(head);
    node *newhead = reverserecursive(head);
    display(newhead);
    newhead = reverserecursive(newhead);
    display(newhead);
    newhead = reversek(newhead,2);
    display(newhead);
    return 0;
}