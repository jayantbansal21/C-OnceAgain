#include <iostream>
#include <stack>
using namespace std;

bool isvalid(string s)
{
    int n = s.size();
    stack<char> st;
    bool ans = true;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '{' || s[i] == '(' || s[i] == '[')
        {
            st.push(s[i]);
        }
        else
        {
            switch (s[i])
            {
            case '}':
                if (st.top() == '{')
                {
                    st.pop();
                }
                ans = false;
                break;
            case ']':
                if (st.top() == '[')
                {
                    st.pop();
                }
                ans = false;
                break;
            case ')':
                if (st.top() == '(')
                {
                    st.pop();
                }
                ans = false;
                break;
            default:
                ans = false;
                break;
            }
        }
    }
}

int main()
{
    string s = "{([])}";
    if (isvalid(s))
    {
        cout << true;
    }
    else
    {
        cout << false;
    }
    return 0;
}