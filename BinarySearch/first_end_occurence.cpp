class Solution
{
public:
    int checkFirst(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1;
        int first = -1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] == target)
            {
                first = mid;
                high = mid - 1;
            }
            else if (nums[mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return first;
    }
    int checkLast(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1;
        int last = -1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] == target)
            {
                last = mid;
                low = mid + 1;
            }
            else if (nums[mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return last;
    }
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> vec;
        int fisrt = checkFirst(nums, target);
        if (fisrt == -1)
            return {-1, -1};
        int end = checkLast(nums, target);
        vec = {fisrt, end};
        return vec;
    }
};