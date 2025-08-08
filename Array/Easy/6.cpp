class Solution
{
public:
    // https://leetcode.com/problems/move-zeroes/
    // First check edge cases
    // second check if at p == 0 and q !=0 then p = q and q=0 and p++,q++
    // other condition that p!=0 the p++,q++
    void moveZeroes(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0 || n == 1)
        {
            return;
        }
        int p = 0, q = 1;
        while (q < n)
        {
            if (nums[p] == 0 && nums[q] != 0)
            {
                nums[p] = nums[q];
                nums[q] = 0;
                p++;
            }
            else if (nums[p] != 0)
            {
                p++;
            }
            q++;
        }
    }
};