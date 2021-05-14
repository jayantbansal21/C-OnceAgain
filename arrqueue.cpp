#include <iostream>

using namespace std;
#define n 10
class queue
{
    int *arr;
    int front;
    int back;

public:
    queue()
    {
        arr = new int[n];
        front = back = -1;
    }
    void push(int x)
    {
        if (back == n - 1)
        {
            cout << "overflow";
            return;
        }
        back++;
        arr[back] = x;
        if (front == -1)
        {
            front++;
        }
    }
    void pop()
    {
        if (front == -1 || front > back)
        {
            cout << "empty";
            return;
        }
        front++;
    }
    int peek()
    {
        if (front == -1 || front > back)
        {
            cout << "empty";
            return -1;
        }
        return arr[front];
    }
    bool empty()
    {
        if (front == -1 || front > back)
        {
            cout << "empty";
            return true;
        }
        else
            return false;
    }
};

int main()
{
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.peek()<<endl;
    q.pop();
    q.pop();
    q.pop();
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.peek()<<endl;
    return 0;
}