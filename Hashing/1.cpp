// Check frequency of number in Array
// assume size of array for hashing 12
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
    int hasharr[12] = {0};
    for (int i = 0; i < s; i++)
    {
        hasharr[arr[i]]++;
    }
    int q;
    cin >> q;
    while (q--)
    {
        int c;
        cin >> c;
        cout << c << " frequency " << hasharr[c] << endl;
    }
    return 0;
}
