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
void Insert(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = new node(val);
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
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
node *Merge(node *&head1, node *&head2)
{
    node *temp1 = head1;
    node *temp2 = head2;
    node *mer = NULL;
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data < temp2->data)
        {
            Insert(mer, temp1->data);
            temp1 = temp1->next;
        }
        else
        {
            Insert(mer, temp2->data);
            temp2 = temp2->next;
        }
    }
    if (temp1 != NULL) //No need of this if
    {
        while (temp1 != NULL)
        {
            Insert(mer, temp1->data);
            temp1 = temp1->next;
        }
    }
    if (temp2 != NULL) //condition has been already being checked in while loop
    {
        while (temp2 != NULL)
        {
            Insert(mer, temp2->data);
            temp2 = temp2->next;
        }
    }
    return mer;
}

node *anothermerge(node *&head1, node *&head2)
{
    node *temp1 = head1;
    node *temp2 = head2;
    node *dummynode = new node(-1);
    node *p = dummynode;
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data < temp2->data)
        {
            p->next = temp1;
            temp1 = temp1->next;
        }
        else
        {
            p->next = temp2;
            temp2 = temp2->next;
        }
        p = p->next;
    }

    while (temp1 != NULL)
    {
        p->next = temp1;
        temp1 = temp1->next;
        p = p->next;
    }

    while (temp2 != NULL)
    {
        p->next = temp2;
        temp2 = temp2->next;
    }

    return dummynode->next;
}

node *mergerecursive(node *&head1, node *&head2)
{   
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }

    node *result;
    if (head1->data < head2->data)
    {
        result = head1;
        result->next = mergerecursive(head1->next, head2);
    }
    else
    { result = head2;
    result->next = mergerecursive(head1, head2->next);
    }
    return result;
   
}


int main()
{
    node *head1 = NULL;
    node *head2 = NULL;
    int arr1[] = {2, 4, 5, 6};
    int arr2[] = {1, 3, 7, 9};
    for (int i = 0; i < 4; i++)
    {
        Insert(head1, arr1[i]);
    }
    for (int i = 0; i < 4; i++)
    {
        Insert(head2, arr2[i]);
    }
    display(head1);
    display(head2);
    //node *mer = mergerecursive(head1, head2);//from the video
    // node *mer =anothermerge(head1, head2);//technique from the video
    node *mer = Merge(head1, head2); //by me
    display(mer);
    return 0;
}