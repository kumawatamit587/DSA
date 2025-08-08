class Solution
{
public:
    // https://leetcode.com/problems/single-number/
    int singleNumber(vector<int> &nums)
    {
        // map<int,int> mp;
        // for(int i=0;i<nums.size();i++){ //M==size of map
        //     mp[nums[i]]++;                   //O(N*log(M))+O(M);
        // }
        // int number;
        // for(int i=0;i<nums.size();i++){
        //     if(mp[nums[i]]==1){
        //         number=nums[i];
        //         break;
        //     }
        // }
        // return number;
        int xorr = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            xorr = xorr ^ nums[i]; // O(N)
        }
        return xorr;
    }
};