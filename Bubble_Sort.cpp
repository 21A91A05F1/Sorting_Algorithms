/*
Bubble Sort :
=============
Algorithm:  Pushes the largest to the last, by adjacent swaps.
Example:
=========
  nums=  13  46  24  52  20  9
         0    1   2  3   4   5
         Check the adjacent elements.
         13 > 46 false
         46 > 24 true  swap;
         46 > 52 false
         52 > 20 true swap;
         52 > 9 true swap;
         On , one complete round of adjacent swapping you can observe that largest element will moves to the last of the array.
         Then do we need to check the last element aain and again?? No 
         In the next step it would be
         13  24  46  20  9  52
         0   1  2  3  4  5  6
         Now again do the adjacent swaps , but we do until n-2 th index then our array becomes:
         13  24  20  9  46  52
         Now again do the adjacent swaps , but we do until n-3 th index then our array becomes:
         13  20  9  24  46  52
         Now again do the adjacent swaps , but we do until n-4 th index then our array becomes:
         13  9  20  24  46  52
         Now again do the adjacent swaps , but we do until n-5 th index then our array becomes:
         9  13  20  24  46  52
         This is the required sorted array.
*/
void bubbleSort(int a[], int n)
{
        // Your code here  
  for(int i=n-1;i>=1;i--)
	{
		for(int j=0;j<=i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}
/*
Time complexity:o(n^2) in worst case.
What if my array is already sorted????
    Then do I need to do the same traversal?? No
      We can optimise our code..
void bubbleSort(int a[], int n)
{
        // Your code here  
  for(int i=n-1;i>=1;i--)
	{
    int didswap=0;
		for(int j=0;j<=i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
        didswap=1;
			}
		}
    if(diswap==0) break;
	}
}
By executing the above program, the time complexiy taken by the above program is o(n) in the best case.
*/
