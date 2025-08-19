class Solution
{
public:
    // first I have to check which part is sorted then pick minimum from that then elimate sorted part
    //  https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/submissions/1733438958/
    // https://takeuforward.org/data-structure/minimum-in-rotated-sorted-array/
    int findMin(vector<int> &nums)
    {
        int low = 0;
        int high = nums.size() - 1;
        int minEle = INT_MAX;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] < nums[high])
            {
                minEle = min(minEle, nums[mid]);
                high = mid - 1;
            }
            else
            {
                minEle = min(minEle, nums[low]);
                low = mid + 1;
            }
        }
        return minEle;
    }
};