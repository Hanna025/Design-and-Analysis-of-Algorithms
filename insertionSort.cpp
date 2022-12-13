head.h
#include<iostream>
using namespace std;

void insertionSort(int[],int);
void displayArray(int[],int);

imp.cpp
#include"head.h"

void insertionSort(int arr[],int n)
{
int j , temp;
for(int i=0;i<n;i++)
 {
   temp = arr[i];
   j = i - 1;
   while(j>=0 && arr[j] > temp)
    {
     arr[j+1] = arr[j];
     j = j-1;
    }
arr[j+1] = temp;
 }
}

void displayArray(int arr[],int n)
{
 for(int i=0;i<n;i++)
 cout<<arr[i]<<" ";
}

app.cpp
#include"head.h"
#include<iostream>
using namespace std;

int main()
{
 	int size,arr[50];
 	cout<<"Enter the size of the array\n";
 	cin>>size;
 	cout<<"Enter the array elements\n";
 	for(int i=0;i<size;i++)
  	{
    	cin>>arr[i];
  	}
  	insertionSort(arr,size);
  	displayArray(arr,size);
 	cout<<"\n";
}
