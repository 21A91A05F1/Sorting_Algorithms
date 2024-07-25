/*
1.consider an array
2.consider the maximum element of the array
3.find the hashtable of the array
4.Find prefix sum of hash map array
5.Now we have to find the output array.

We traverse from the back of the given array and then we find the element of that index in hash array
and we decrement the value of hash array and we place the element in the output by considering hashmap value-1 th index.
*/
class Solution {
public:
    vector<int>countSort(vector<int>&nums)
    {
        int maxi=*max_element(nums.begin(),nums.end());
        vector<int>hash(maxi+1);
       for(int i=0;i<nums.size();i++)
       {
          hash[nums[i]]++;
       }
        vector<int>prefix(maxi+1,0);
        prefix[0]=hash[0];
        for(int i=1;i<maxi+1;i++)
        {
            prefix[i]=prefix[i-1]+hash[i];
        }
        vector<int>op(nums.size(),0);
        for(int i=nums.size()-1;i>=0;i--)
        {
            op[prefix[nums[i]]-1]=nums[i];
            prefix[nums[i]]--;
        }
        return op;
    }
    vector<int> sortArray(vector<int>& nums) {
        return countSort(nums);
    }
};

========================
  But this gives unpredictable results , when we deal with negative numbers
so inorder to get the accurate results for negative numbers
To handle negative numbers, we need to shift all numbers in the array so that the smallest number starts from 0.
  This can be done by finding the minimum value in the array, adjusting all 
elements by adding the absolute value of the minimum number, and then applying Counting Sort.


  class Solution {
public:
    vector<int>countSort(vector<int>&nums)
    {
        if(nums.empty()) return nums;
        int maxi=*max_element(nums.begin(),nums.end());
        int mini=*min_element(nums.begin(),nums.end());

        int a=(mini<0)? -mini:0;
        int b=maxi+a+1;
        vector<int>hash(b,0);
       for(int i=0;i<nums.size();i++)
       {
          hash[nums[i]+a]++;
       }
        vector<int>prefix(b,0);
        prefix[0]=hash[0];
        for(int i=1;i<b;i++)
        {
            prefix[i]=prefix[i-1]+hash[i];
        }
        vector<int>op(nums.size(),0);
        for(int i=nums.size()-1;i>=0;i--)
        {
            op[prefix[nums[i]+a]-1]=nums[i];
            prefix[nums[i]+a]--;
        }
        return op;
    }
    vector<int> sortArray(vector<int>& nums) {
        return countSort(nums);
    }
};
