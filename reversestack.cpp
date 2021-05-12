#include <iostream>
#include <stack>
using namespace std;
void insertatbottom(stack<int> &st, int ele)
{
    if (st.empty())
    {
        st.push(ele);
    }
    int topele = st.top();
    st.pop();
    insertatbottom(st, ele);
    st.push(topele);
}
void Reverse(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }
    int el = st.top();
    st.pop();
    Reverse(st);
    insertatbottom(st, el);
}
int main()
{

    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    stack<int> temp = st;
    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
    Reverse(st);
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}