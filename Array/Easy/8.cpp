class Solution
{
public:
    // n=n*(n+1)/2 method also work
    // https://takeuforward.org/arrays/find-the-missing-number-in-an-array/
    int missingNumber(vector<int> &nums)
    {
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        int mis;
        for (int i = 0; i <= nums.size(); i++)
        {
            if (!mp[i])
            {
                mis = i;
            }
        }
        return mis;
    }
};