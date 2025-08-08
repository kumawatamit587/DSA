#include <bits/stdc++.h>
using namespace std;
// Find Second Largest element in an array
int main()
{
    vector<int> arr = {8471, 87, 1, 4, 5, 7};
    /// This approch is two traversal
    // int maxEle = INT_MIN;
    // int minEle = INT_MAX;
    // for (auto i : arr)
    // {
    //     maxEle = max(maxEle, i);
    //     minEle = min(minEle, i);
    // }
    // int secondLargest = INT_MIN;
    // int secondsmall = INT_MAX;
    // ;

    // for (auto i : arr)
    // {
    //     if (i != maxEle && secondLargest < maxEle)
    //     {
    //         secondLargest = max(secondLargest, i);
    //     }
    //     if (i != minEle && secondsmall > minEle)
    //     {
    //         secondsmall = min(secondsmall, i);
    //     }
    // }

    //// One traversal
    int secondLargest = INT_MIN;
    int secondsmall = INT_MAX;
    int Largest = INT_MIN;
    int minimum = INT_MAX;

    for (auto i : arr)
    {
        if (Largest < i)
        {
            secondLargest = Largest;
            Largest = i;
        }
        else if (i != Largest && i > secondLargest)
        {
            secondLargest = i;
        }
    }
    for (auto i : arr)
    {
        if (minimum > i)
        {
            secondsmall = minimum;
            minimum = i;
        }
        else if (i != minimum && secondsmall > i)
        {
            secondsmall = i;
        }
    }
    cout << "Second Largest Element " << secondLargest << endl;
    cout << "Second MIN Element " << secondsmall << endl;
    return 0;
}
