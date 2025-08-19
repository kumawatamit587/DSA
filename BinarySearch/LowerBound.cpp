class Solution
{
public:
    int checkLowerBound(vector<int> &nums, int low, int x, int high)
    {
        if (low > high)
            return -1;

        int res;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] >= x)
            {
                res = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return res;
    }
    int lowerBound(vector<int> &nums, int x)
    {
        // O(N)
        //  for(int i=0;i<nums.size();i++){
        //      if(nums[i]>=x){
        //          return i;
        //      }
        //  }
        //  return nums.size();

        return checkLowerBound(nums, 0, x, nums.size() - 1);
    }
};