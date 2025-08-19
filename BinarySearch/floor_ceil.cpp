class Solution
{
public:
    vector<int> getFloorAndCeil(vector<int> nums, int x)
    {
        // https://takeuforward.org/plus/dsa/problems/floor-and-ceil-in-sorted-array
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int floor = -1, ceil = -1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] <= x)
            {
                floor = nums[mid];
                low = mid + 1;
            }
            if (nums[mid] >= x)
            {
                ceil = nums[mid];
                high = mid - 1;
            }
        }
        vector<int> vec;
        vec.push_back(floor);
        vec.push_back(ceil);
        return vec;
    }
};