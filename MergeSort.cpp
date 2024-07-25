class Solution {
public:
    void merge(int low,int mid,int high,vector<int>&nums)
    {
        int start=low,end=mid+1;
        vector<int>temp;
        while(start<=mid and high>=end)
        {
            if(nums[start]<nums[end])
            {
                temp.push_back(nums[start]);
                start++;
            }
            else
            {
                temp.push_back(nums[end]);
                end++;
            }
        }
        while(start<=mid)
        {
            temp.push_back(nums[start]);
            start++;
        }
        while(end<=high)
        {
            temp.push_back(nums[end]);
            end++;
        }
        for(int i=low,k=0;i<=high;i++,k++)
        {
            nums[i]=temp[k];
        }
    }
    void mergesort(int low,int high,vector<int>&nums)
    {
        if(low<high)
        {
            int mid=(low+high)/2;
            mergesort(low,mid,nums);
            mergesort(mid+1,high,nums);
            merge(low,mid,high,nums);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
       mergesort(0,nums.size()-1,nums);
       return nums;
    }
};
