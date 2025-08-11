class Solution
{
public:
    // https://leetcode.com/problems/majority-element/submissions/1729901524/
    int majorityElement(vector<int> &nums)
    {
        // TC=O(Nlog(N))
        // SC=O(N)
        map<int, int> mpp;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            mpp[nums[i]]++;
        }
        int major = 0;
        int ele;
        for (auto it : mpp)
        {
            if (major < it.second)
            {
                ele = it.first;
            }
        }
        return ele;
    }
};

///////////////////////
// TC=O(N)
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int count = 1;
        int ele = nums[0];
        int n = nums.size();

        for (int i = 1; i < nums.size(); i++)
        {
            if (ele != nums[i] && count > 0)
            {
                count--;
            }
            else if (ele == nums[i])
            {
                count++;
            }
            else if (count == 0)
            {
                ele = nums[i];
                count++;
            }
        }
        return ele;
    }
};