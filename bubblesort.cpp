#include<iostream>
using namespace std;

void bubble(int arr[], int n)
{
    int temp;
    for (int j = n-1; j >=0; j--)
    {
        for (int i = 0; i <=j; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }
}

int main()
{
    int arr[] = {1, 5, 2, 9, 2, 4, 6};
    bubble(arr, 7);
    for (int i = 0; i < 7; i++)
    {
        cout<< arr[i] << " " <<endl;
    }
}