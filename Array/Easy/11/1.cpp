class Solution
{
public:
    // Time complexity O(N^3)
    int subarraySum(vector<int> &nums, int k)
    {
        int len = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i; j < nums.size(); j++)
            {
                long long sum = 0;
                for (int l = i; l <= j; l++)
                {
                    sum += nums[l];
                }
                if (sum == k)
                {
                    len = max(len, j - i + 1);
                }
            }
        }
        return len;
    }
};