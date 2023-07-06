/*
Quick sort: - Divide and conquer algorithm ->T.c-(o(nlogn)) -> S.c -(o(1))
============
1.Pick a pivot element :
    pivot element may be a 1st element/last element/middle element / random element of an array
2.Place the pivot element in it's correct place of the sorted array.
3.Smaller on the left , larger on the right .
4.Repeat steps 1,2,3.
-> whenever an array has one element,then we don't do anything and that element is in sorted order.
Approach:
===========
    1.let's consider pivot element as arr[low]->first element of the given array.
    2.a=Find the element which is greater than my pivot element , from the inital arrray , and increment i.
    3.b=Find the element which is lower than my pivot element , from the back of the array , and decrement j.
    4.swap both the elements i.e,(a,b) 
    5.continue above steps until all the elements of pivot element which are lower than that would comes toright of the pivot and all 
      the greater numbers will come to left of the pivot element -> (i>j).
    6.We have to set the pivot element place to the original place when it was sorted , this can be done by swapping the element
      which is in jth position to the first element.
    7.By this 1st pivot element that we considered will be placed in the correct position
    8.To get all the pivot elements in their exact position the above mentioned steps should be done.
Dry Run:
========
    index 0 1 2 3 4 5 6 7
          4 6 2 5 7 9 1 3
      ->  4 3 2 5 7 9 1 6 -> 6 is swapped with 3
      ->  4 3 2 1 7 9 5 6 -> 5 is swapped with 1
      Now i>j
      ->  1 3 2 4 7 9 5 6  ->pivot element is swapped with arr[j]
      ->  1 3 2 || 4 || 7 9 5 6
      ===============================================
      ->  1 3 2 
         pivot =1
      ->  1 2 3  -> 3 is swapped with 2
      ================================================
      -> 7 9 5 6
         pivot=7
         7 6 5 9 ->9 is swapped with 6.
         5 6 7 9 ->pivot is swapped with j.
      ===============================================
      From both the partitions we get : 1 2 3 4 5 6 7 9
*/
#include<bits/stdc++.h>
using namespace std;
long long mod=10e9+7;
void maincode()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
}
int partition(vector<int>&arr,int low,int high)
{
	int pivot=arr[low];
	int i=low;
	int j=high;
	while(i<j)
	{
		while(arr[i]<=pivot && i<=high-1)
		{
			i++;
		}
		while(arr[j]>pivot && j>=low+1)
		{
			j--;
		}
		if(i<j)
		{
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[low],arr[j]);
	return j;
}
void qs(vector<int>&arr,int low,int high)
{
	if(low<high)
	{
		int p_index=partition(arr,low,high);
		qs(arr,low,p_index-1);
		qs(arr,p_index+1,high);
	}
}
vector<int> quicksort(vector<int>arr)
{
	qs(arr,0,arr.size()-1);
	return arr;
	
}
int main()
{
	maincode();
	vector<int>ve={4,6,2,5,7,9,1,3};
	vector<int>res;
	res=quicksort(ve);
	for(auto it:res)
	{
		cout<<it<<" ";
	}
}
