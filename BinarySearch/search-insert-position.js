class Solution {
    public:
        //https://leetcode.com/problems/search-insert-position/
        int checkSarch(vector<int>& nums, int low, int high, int target) {
    if (low > high)
        return low;
        int mid = (low + high) / 2;
    if (nums[mid] == target) {
        return mid;
    } else if (nums[mid] > target) {
        return checkSarch(nums, low, mid - 1, target);
    }
    return checkSarch(nums, mid + 1, high, target);
}
    int searchInsert(vector < int >& nums, int target) {
    return checkSarch(nums, 0, nums.size() - 1, target);
}
};

//////////////////////////////
class Solution {
    public:
        int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int idx;
        int low = 0;
        int high = n - 1;
    while (low <= high) {
            int mid = (low + high) / 2;
        if (nums[mid] >= target) {
            idx = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return idx;
}
};