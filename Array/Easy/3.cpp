class Solution
/*
https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
*/
{
public:
    bool check(vector<int> &nums)
    {
        int count = 0;
        // first check how much time array break the cycle
        // if it's only one then check first and last element that should last<=first
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i - 1] > nums[i])
            {
                count++;
            }
        }
        if (count == 1 && nums[0] < nums[nums.size() - 1])
        {
            count++;
        }
        return count <= 1;
    }
};