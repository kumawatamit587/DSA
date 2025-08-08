class Solution
{
public:
    // https://leetcode.com/problems/rotate-array/
    void rotatedArr(vector<int> &nums, int start, int end)
    {
        while (start <= end)
        {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }
    void rotate(vector<int> &nums, int k)
    {
        k = k % nums.size();
        if (nums.size() == 0 || k == 0)
        {
            return;
        }
        // this code time limit exceeded for large array
        //  if(k>nums.size()){
        //      k=k%nums.size();
        //  }
        //  while(k>0){
        //      int temp=nums[nums.size()-1];
        //      int i=nums.size()-1;
        //      while(i>0){
        //          nums[i]=nums[i-1];
        //          i--;
        //      }
        //      nums[i]=temp;
        //      k--;
        //  }

        // first rotate 0->n-1-k then n-k -> n-1
        // now rotate whole 0->n-1
        rotatedArr(nums, 0, nums.size() - 1 - k);
        rotatedArr(nums, nums.size() - k, nums.size() - 1);
        rotatedArr(nums, 0, nums.size() - 1);
    }
};