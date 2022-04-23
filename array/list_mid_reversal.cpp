/*
Reverse array by mid.
For example:
 arr = 1, 2, 3, 4 , 5
 Result = 1, 2, 5, 4, 3
*/

#include <iostream>
using namespace std;

void partial_reverse(int *arr, int n)
{
    int mid = n / 2;
    int end = n-1;
    while(mid < end)
    {
        swap(arr[mid], arr[end]);
        mid += 1;
        end -= 1 ;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    cout<<"Before partial reverse: ";
    for(int i=0; i<n; i++)
    cout<<arr[i]<<" ";
    partial_reverse(arr, n);
    cout<<"\nAfter partial reverse: ";
    for(int i=0; i<n; i++)
    cout<<arr[i]<<" ";
    cout<<endl;

    return 0;

}