#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    string s="aabbcccdddd";
    
    int fre[26];
    for(int i =0;i<26;i++){
        fre[i]=0;
    }
    for(int i = 0 ; i< s.size();i++)
        fre[s[i]-'a']++;
    
    char ans = 'a';
    int max = 0;

    for(int i = 0 ; i<26;i++){
        if(fre[i]>=max){
            max = fre[i];
            ans = 'a' + i;
        }

    }
    cout<<max<<endl<<ans;
    return 0;


}