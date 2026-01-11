class Solution
{
public:
    // TC:O(N);
    double myPow(double x, int n)
    {
        double ans = 1.0;
        int nn = n;
        if (n < 0)
        {
            nn = -1 * n;
        }
        while (nn > 0)
        {
            ans = ans * x;
            nn--;
        }
        if (n < 0)
        {
            return double(1.0) / double(ans);
        }
        return ans;
    }
};

///////////////////////////////

class Solution
{
public:
    // TC:O(log(N));

    double myPow(double x, int n)
    {
        double ans = 1.0;
        long long nn = n;
        if (n < 0)
        {
            nn = -1 * nn;
        }
        while (nn)
        {
            if (nn % 2)
            {
                ans = ans * x;
                nn--;
            }
            else
            {
                x = x * x;
                nn /= 2;
            }
        }
        if (n < 0)
        {
            return double(1.0) / double(ans);
        }
        return ans;
    }
};