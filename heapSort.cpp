head.h
#include<iostream>

using namespace std;

void heapSort(int[],int);
void heap(int[],int,int);
void display(int[],int);


imp.cpp
#include"head.h"
void heap(int arr[],int n,int i)
{
  int temp;
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  if (left < n && arr[left] > arr[largest])
    largest = left;
  if (right < n && arr[right] > arr[largest])
    largest = right;
  if (largest != i) {
    temp = arr[i];
    arr[i] = arr[largest];
    arr[largest] = temp;
    heap(arr, n, largest);
  }
}

void heapSort(int arr[],int n)
{
  int temp;
  for (int i = n / 2 - 1; i >= 0; i--)
    heap(arr, n, i);
  for (int i = n - 1; i >= 0; i--) {
    temp = arr[0];
    arr[0] = arr[i];
    arr[i] = temp;
    heap(arr, i, 0);
 }
}

void display(int arr[],int n)
{
  for(int i = 0;i<n;i++)
  cout<<arr[i]<<" ";
  cout<<"\n";
}


app.cpp
#include"head.h"

#include<iostream>
using namespace std;

int main()
{
  int arr[10],i,n;
  cout<<"Enter the capcity of the array\n";
  cin>>n;
  cout<<"Enter the elements\n";
  for(i=0;i<n;i++)
   {
     cin>>arr[i];
   }
  heapSort(arr,n);
  cout<<"Sorted Heap\n";
  display(arr,n);
}
