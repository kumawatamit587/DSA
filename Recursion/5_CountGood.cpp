class Solution
{
public:
    // https://leetcode.com/problems/count-good-numbers/description/
    // TC:O(log(N))
    int MOD = 1e9 + 7;
    long fastPowerCheck(long basevalue, long exp)
    {
        long result = 1;
        while (exp > 0)
        {
            if (exp % 2 == 1)
            {
                result = (result * basevalue) % MOD;
            }
            basevalue = (basevalue * basevalue) % MOD;
            exp /= 2;
        }
        return result;
    }
    int countGoodNumbers(long long n)
    {
        long totalEvenPos = (n + 1) / 2;
        long totalOddPos = n / 2;
        long evenPosAnswer = fastPowerCheck(5, totalEvenPos);
        long oddPosAnswer = fastPowerCheck(4, totalOddPos);

        return (int)((evenPosAnswer * oddPosAnswer) % MOD);
    }
};
//////

class Solution
{
public:
    int MOD = 1e9 + 7;
    long fastPowerCheck(long basevalue, long exp)
    {
        if (exp == 0)
            return 1;
        long ans = fastPowerCheck(basevalue, exp / 2);
        ans *= ans;
        if (exp % 2 == 1)
            ans *= basevalue;
        ans %= MOD;
        return ans;
    }
    int countGoodNumbers(long long n)
    {
        long totalEvenPos = (n + 1) / 2;
        long totalOddPos = n / 2;
        long evenPosAnswer = fastPowerCheck(5, totalEvenPos);
        long oddPosAnswer = fastPowerCheck(4, totalOddPos);

        return (int)((evenPosAnswer * oddPosAnswer) % MOD);
    }
};