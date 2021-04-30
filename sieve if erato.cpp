#include<iostream>
using namespace std;
int main(){
    int n,k=50;
    //cin>>k;
    n = k+1;
    int arr[n];

    for(int i =1;i<=n;i++) arr[i] =1;

    for(int i = 2; i <=n;i++){
        int end = n/i;
        if(arr[i]){
            for(int j =2 ; j<=end;j++){
                arr[i*j]=0;
            }
        }

    }

    for(int i=2;i<n;i++){
        if(arr[i]){
            cout<<i;
        }
    }


    return 0;
}