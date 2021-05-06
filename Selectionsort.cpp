#include <iostream>
using namespace std;
void swap(int arr[],int l,int r){
    int temp;
    temp = arr[l];
    arr[l] = arr[r];
    arr[r] = temp;
}
void selectionSort(int arr[], int size)
{
    
    for (int j = 0; j < size; j++)
    {
        int s;
        int small = arr[j];
        s=j;
        for (int i = j+1; i < size; i++)
        {
            if (arr[i] < small)
            {
                small = arr[i];
                s = i;
            }
        }
        swap(arr,j,s);
        
    }
 
}

int main()
{
    int arr[] = {5,2,7,3,8,9,10};
    selectionSort(arr,7);
    for (int i = 0; i < 7; i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}