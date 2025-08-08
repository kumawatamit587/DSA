class Solution
{
public:
    // O(N^2)
    int longestSubarray(vector<int> &nums, int k)
    {
        int len = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int sum = 0;
            for (int j = i; j < nums.size(); j++)
            {
                sum += nums[j];
                if (sum == k)
                {
                    len = max(len, j - i + 1);
                }
            }
        }
        return len;
    }
};
