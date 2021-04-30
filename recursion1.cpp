#include<iostream>
using namespace std;
int ans(int a , int b){
    if(b==0) return 1;

    return a* ans(a,b-1);
}
int main(){
    int x,y;
    x=2 ;
    y=3;
//'    cin>>x>>y;
    cout<<ans(x,y)<<endl;
    return 0;
}