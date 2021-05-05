#include<iostream>
using namespace std;
int swap(int arr[],int a, int b){
    int temp;
    temp = arr[a];
    arr[a] = arr[b];
    arr[b]=temp;


}
int partition(int arr[],int l,int r){
     int pivot = arr[r];
     int i = l-1;
     for(int j =l , j<r;j++){
         if(arr[j]<pivot){
            i++;
            swap(arr,i,j);
         }


     }
     swap(arr,i+1,r);
     return i+1;
}


void QuickS(int arr[],int l,int r){
    if(l<r){

        int pi = partition(arr,l,r);
        QuickS(arr,l,pi-1);
        QuickS(arr,pi+1,r);
    }


}


int main(){
    int arr[5]= {3,6,2,6,1};
    QuickS(arr,0,4);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}