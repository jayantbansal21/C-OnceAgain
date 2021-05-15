#include <iostream>
#include <deque>
using namespace std;

int main()
{
    deque<int> dq;
    dq.push_back(1);
    dq.push_back(2);
    dq.push_front(3);
    dq.push_front(4);
    dq.push_back(5);
    for (auto i : dq)
    {
        cout << i << " ";
    }
    dq.pop_back();
    dq.pop_front();
    cout << endl;
    for (auto i : dq)
    {
        cout << i << " ";
    }
    cout<<dq.size() ;
    return 0 ;
}