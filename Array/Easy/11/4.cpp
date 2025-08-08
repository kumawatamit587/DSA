class Solution
{
public:
    // this code if array contains zero also
    int longestSubarray(vector<int> &nums, int k)
    {
        map<int, int> preSum;
        int sum = 0;
        int len = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (sum == k)
            {
                // initial 0 to i sum
                int len = max(len, i + 1);
            }
            int rem = sum - k;
            if (preSum.find(rem) != preSum.end())
            {
                int lenAtstage = i - preSum[rem];
                len = max(len, lenAtstage);
            }
            if (preSum.find(sum) == preSum.end())
            {
                preSum[sum] = i;
            }
        }
        return len;
    }
};
