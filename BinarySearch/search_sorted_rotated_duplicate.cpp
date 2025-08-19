class Solution
{
public:
    // [1,1,1,1,1,1,1,1,1,13,1,1,1,1,1,1,1,1,1,1,1,1]
    // https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/

    // Check if fisrt sorted part so if mid=low=high the we ever time shrink the size low++,high--.
    // the we check whether it will be lie in array
    // O(log(N))

    bool search(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] == target)
            {
                return true;
            }
            if (nums[mid] == nums[low] && nums[mid] == nums[high])
            {
                low++;
                high--;
                continue;
            }
            if (nums[mid] <= nums[high])
            {
                if (nums[mid] < target && nums[high] >= target)
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
            else
            {
                if (nums[mid] > target && nums[low] <= target)
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
        }
        return false;
    }
};