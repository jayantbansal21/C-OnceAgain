#include<iostream>
using namespace std;

void swap(int arr[],int a,int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void wave(int arr[],int n){
    for(int i = 1 ; i <n;i+=2){
        if(arr[i]>arr[i-1]){
            swap(arr,i,i-1);
        }
        if(arr[i]>arr[i+1] && i<n-1){
            swap(arr,i,i+1);
        }
    }



}

int main(){
    int arr[]={5,9,2,1,6,11,14,13};
    wave(arr,8);
    for(int i =0;i<8;i++){
        cout<<arr[i]<<endl;
    }
}