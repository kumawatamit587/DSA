class Solution
{
public:
    // https://leetcode.com/problems/remove-duplicates-from-sorted-array/

    // checkwhen element did not same then p+1 element should be assign q and p++ and q++
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() <= 1)
            return true;
        int p = 0, q = 1;
        while (q < nums.size())
        {
            if (nums[p] == nums[q])
            {
                q++;
            }
            else if (nums[p] != nums[q])
            {
                nums[p + 1] = nums[q];
                p++;
                q++;
            }
        }
        return p + 1;
    }
};