class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // https://leetcode.com/problems/two-sum/

        // this will give me TC=O(N) and in worst case O(N^2) because if we use map instance of ordered_map
        // SC=O(N)
        unordered_map<int, int> mpp;
        vector<int> vec;
        int i = 0, n = nums.size() - 1;
        while (i <= n)
        {
            int y = target - nums[i];
            if (mpp.find(y) != mpp.end())
            {
                vec.push_back(mpp[y]);
                vec.push_back(i);
                return vec;
            }
            mpp[nums[i]] = i;
            i++;
        }
        return vec;
    }
};

//////////////////////////////////////

#include <bits/stdc++.h>

class Solution
// TC=O(N*log(n));
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> vec;
        int left = 0, right = n - 1;
        while (left < right)
        {
            int sum = nums[left] + nums[right];
            if (sum == target)
            {
                vec.push_back(left);
                vec.push_back(right);
                return vec;
            }
            else if (sum < target)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return vec;
    }
};