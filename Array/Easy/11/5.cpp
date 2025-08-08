class Solution
{
    // https://takeuforward.org/plus/dsa/problems/longest-subarray-with-sum-k
public:
    int longestSubarray(vector<int> &nums, int k)
    {
        int left = 0, right = 0;
        int sum = nums[0];
        int n = nums.size();
        int len = 0;
        while (right < n)
        {
            while (sum > k)
            {
                left++;
            }
            if (sum == k)
            {
                len = max(len, right - left + 1);
            }
            right++;
            if (right < n)
            {
                sum += nums[right];
            }
        }
        return len;
    }
};
