class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        // https://leetcode.com/problems/max-consecutive-ones/
        int conj = 0, count = 0;
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]==1){
        //         count++;
        //     }else if(nums[i]!=1){
        //             if(conj<count){
        //                 conj=count;
        //             }
        //             count=0;
        //         }
        // };
        // return conj<count?count:conj;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                count++;
                if (count > conj)
                {
                    conj = count;
                }
            }
            else
            {
                count = 0;
            }
        }
        return conj;
    }
};