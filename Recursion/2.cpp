#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int cnt = 0;
    void printNumbers(int n)
    {
        // Your code goes here
        if (cnt > n)
        {
            return;
        }
        cnt++;
        cout << cnt << endl;
        printNumbers(n);
    }

    int main()
    {
        #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        #endif // !ONLINE_JUDGE
        int n;
        cin >> n;
        printNumbers(n);
        return 0;
    }
};