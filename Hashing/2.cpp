// Check frequency of char in String

#include <bits/stdc++.h>

using namespace std;
int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // !ONLINE_JUDGE
    string s;
    cin >> s;
    int charArr[25] = {0};
    for (int i = 0; i < s.size(); i++)
    {
        charArr[s[i] - 'a']++;
    }
    int q;
    cin >> q;
    while (q--)
    {
        char c;
        cin >> c;
        cout << c << " frequency " << charArr[c - 'a'] << endl;
    }
    return 0;
}
