// Check frequency of number in Array
// assume size of array for hashing using unordered map
#include <bits/stdc++.h>

using namespace std;
int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // !ONLINE_JUDGE
    int s;
    cin >> s;
    int arr[s];
    for (int i = 0; i < s; i++)
    {
        cin >> arr[i];
    }
    unordered_map<int, int> mpp;
    for (int i = 0; i < s; i++)
    {
        mpp[arr[i]]++;
    }
    for (auto it : mpp)
    {
        cout << it.first << "->" << it.second << endl;
    }
    int q;
    cin >> q;
    while (q--)
    {
        int c;
        cin >> c;
        cout << c << " frequency " << mpp[c] << endl;
    }
    return 0;
}
