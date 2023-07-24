/*
Insertion sort:
===============  
            Takes an element and place it in correct position.
            Example: arr[]= 14  9  15  12  6  8  13
                             0  1   2   3  4  5   6
                                i   i   i  i
            At index 0, go to the next element, and ask on the leftside , where should the next element should be placed.
                            9  14  15  12  6  8  13
            Does 15 is placed in the correct place?? Yes it is.then no swaps needed move to 12.
                          9  14  12  15  6  8  13
                          9  12  14  15  6  8  13
            Does 6 is placed in the correct place?? No
                          9  12  14  6  15  8  13
                          9  12  6  14  15  8  13
                          9  6  12  14  15  8  13
                          6  9  12  14  15  8  13
            Does 8 is placed in the correct place ?? No
                          6  9  12  14  8  15  13
                          6  9  12  8  14  15  13
                          6  9  8  12  14  15  13
                          6  8  9  12  14  15  13
            Does 13 is placed in correct place?? No.
                          6  8  9  12  14  13  15
                          6  8  9  12  13  14  15.
            Every element is placed in their respective place and the array got sorted.                           
*/
#include<bits/stdc++.h>
using namespace std;
void maincode()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}
void insertion_sort(int n,int arr[])
{
	for(int i=0;i<n;i++)
	{
		int j=i;
		while(j>0 &&(arr[j-1]>arr[j]))
		{
			swap(arr[j-1],arr[j]);
			j--;
		}
	}
}
int main()
{
	maincode();
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	insertion_sort(n,arr);
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}
