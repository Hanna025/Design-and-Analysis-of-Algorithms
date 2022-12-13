head.h

#include<iostream>
using namespace std;

int divide(int [],int,int);
void swap(int*,int*);
void quickSort(int [],int,int);
void display(int [],int);

imp.cpp

#include"head.h"
void quickSort(int arr[],int low,int high)
{
 if(low >= high)
 return;
  {
    int pivot;
    pivot = divide(arr,low,high);
    quickSort(arr,low,pivot);
    quickSort(arr,pivot+1,high);
  }

}

int divide(int arr[],int low,int high)
{
  int pivot;
  pivot = arr[low];
  int x = low - 1;
  int y = high + 1;
  while(true)
   {
     do
       {
         x++;
       }
     while(arr[x] < pivot);
     do
      {
        y--;
      }
     while(arr[y] > pivot);
     if(x >= y)
     return y;
     swap(arr[x],arr[y]);
  }
}


void swap(int* a,int* b)
{
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}


void display(int arr[],int size)
{
  int i;
  cout<<"Sorted Array:\n";
  cout<<"| ";
  for(i=0;i<size;i++)
   {
     cout<<arr[i];
     cout<<" | ";
   }

}

app.cpp
#include"head.h"

#include<iostream>
using namespace std;

int main()
{
   int arr[10],i,n,j;
   cout<<"Enter the capacity of the array\n";
   cin>>n;
   cout<<"Enter the elements\n";
   for(i=0;i<n;i++)
   {
      cin>>arr[i];
   }
    cout<<"Original Array:\n";
    cout<<"| ";
    for(j=0;j<n;j++)
    {
       cout<<arr[j];
       cout<<" | ";
    }
    quickSort(arr,0,n-1);
    cout<<"\n";
    display(arr,n);
    cout<<"\n";
}
