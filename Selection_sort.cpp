/*
  Selection Sort:
  ==============
              Name it selfs suggest you to select.
              What should we select??
              We should select the minimum number and then swap it. -> Algorithm
            nums[]= [ 13 46 52 20 9 ]
                      0  1  2  3  4
                      What is my minimum in this array?? My minimum is 9.
                      Where should I place it ?? I should place it in the position of 1st element.
                      So I should swap 13 and 9 .
            Step1:    9 |  46  52  20  13
                      9 is sorted , since it's a single element.
                      What's my next minimum element ??
                      Do I need to search from begining of my array ?? Nonoo.
                      We should check our minimum from index 1 to the end of the array i.e, n-1.
                      Then my minimum will be 13 and it should be swapped with the element at index 1.
            Step2:    9  13  |  52  20  46
                      9,13 are sorted , now I should check my minimum from index 2 to the end of the array i.e, n-1.
                      Then my minimum will be 20 and it should be swapped with the element at index 2.
            Step3:    9  13  20  |  52  46
                      9,13,20 are sorted , now I should check my minimum from index 3 to the end of the array i.e, n-1.
                      Then my minimum will be 46 and it should be swapped with the element at index 3.
            Step4:    9  13  20  46  52
                      We can observe that , the complete array is sorted.
                      There are 5 elements in the array , and in step4 my array is sorted.
          We can observe that , we are moving to til index 3 , at that index my array is sorted.
          This indicates that , my outer loop iterates till (n-2)th index.
          And to find my minimum element in the array we are moving from (i+1)th index to last element of my array.
Pseudocode:
===========
        for(int i=0;i<=n-2;i++)
        {
            mini=i;
            for(int j=i;j<=n-1;j++)
            {
                if(arr[j]<arr[mini])
                {
                    mini=j;
                }
             
            }
            swap(arr[min],arr[i]);
        }                                   
*/
void selectionSort(vector<int>&arr) {
    // Write your code here.
    int n=arr.size();
    int min;
	    for(int i=0;i<=n-2;i++)
	    {
		    min=i;
		    for(int j=i;j<=n-1;j++)
		    {
			    if(arr[j]<arr[min])
			    {
				    min=j;
			    }
		    }
		    int temp=arr[i];
		    arr[i]=arr[min];
		    arr[min]=temp;
	}
}
