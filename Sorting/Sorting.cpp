#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/sort-an-array/description/
class Solution
{
public:
    void merge(vector<int> &nums, int low, int mid, int high)
    {
        vector<int> temp;
        int left = low;
        int right = mid + 1;
        while (left <= mid && right <= high)
        {
            if (nums[left] <= nums[right])
            {
                temp.push_back(nums[left]);
                left++;
            }
            else
            {
                temp.push_back(nums[right]);
                right++;
            }
        }
        while (left <= mid)
        {
            temp.push_back(nums[left]);
            left++;
        }
        while (right <= high)
        {
            temp.push_back(nums[right]);
            right++;
        }
        for (int i = low; i <= high; i++)
        {
            nums[i] = temp[i - low];
        }
    }
    void mergenums(vector<int> &nums, int low, int high)
    {
        if (low == high)
        {
            return;
        }
        int mid = (low + high) / 2;
        mergenums(nums, low, mid);
        mergenums(nums, mid + 1, high);
        merge(nums, low, mid, high);
    }
};
int main()
{
    Solution myObj;

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // !ONLINE_JUDGE
    int s;
    cin >> s;
    vector<int> nums;
    for (int i = 0; i < s; i++)
    {
        cin >> nums[i];
    }
    //-------Selection Sort
    // for(int i=0;i<nums.size()-1;i++){
    //     int minIndex=i;
    //     for(int j=i;j<nums.size();j++){
    //         if(nums[minIndex]>nums[j]){
    //             minIndex=j;
    //         }
    //     }
    //     swap(nums[minIndex],nums[i]);
    // }

    //-----------Bubble Sort
    // for(int i=nums.size()-1;i>=1;i--){
    //     bool swaped=false;
    //     for(int j=0;j<i;j++){
    //         if(nums[j+1]<nums[j]){
    //             swap(nums[j],nums[j+1]);
    //             swaped=true;
    //         }
    //     }
    //     if(swaped==false){
    //         break;
    //     }
    // }

    //-----------Insertion Sort
    // for(int i=0;i<nums.size();i++){
    //     int j=i;
    //     while(j>0 && nums[j]<nums[j-1]){
    //             swap(nums[j],nums[j-1]);
    //             j--;
    //     }
    //     // for(int j=i;j>0;j--){
    //     //     int check=j-1;
    //     //     if(nums[j]<nums[check]){
    //     //         swap(nums[j],nums[check]);
    //     //     }
    //     // }
    // }

    // Merge Sort
    myObj.mergenums(nums, 0, nums.size() - 1);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i];
    }
    return 0;
}