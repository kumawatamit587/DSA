#include <bits/stdc++.h>
using namespace std;
// Find the Largest element in an array
void sortArr(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    cout << "largest Element " << arr[arr.size() - 1] << endl;
}

int main()
{
    vector<int> arr = {8471, 87, 1, 4, 5, 7};
    // Using this time Time Complexity: O(N*log(N))
    sortArr(arr);
    //////////////////////////////////////////////

    vector<int> arr2 = {841, 87, 1, 4, 5, 7};
    int maxEle = arr2[0];
    for (auto i : arr2)
    {
        maxEle = max(maxEle, i);
    }
    cout << "Largest Element " << maxEle;

    return 0;
}
