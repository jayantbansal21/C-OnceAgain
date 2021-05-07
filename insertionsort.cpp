#include<iostream>
using namespace std;
void sort(int arr[],int n){
    int j;
    for(int i =0;i<n;i++){
        int current = arr[i];
        j = i-1;
        while (j >= 0 && arr[j] > current) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = current;
    }
}

int main(){
    int arr[]={5,2,6,2,22,21};
    sort(arr,6);
    for(int i = 0; i < 6; i++){
        cout<<arr[i]<<endl;
    }
}