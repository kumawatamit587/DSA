class Solution
{
public:
    // https://takeuforward.org/plus/dsa/problems/count-occurrences-in-a-sorted-array
    int firstOccure(const vector<int> &arr, int target)
    {
        int low = 0, high = arr.size() - 1;
        int fisrt = -1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (arr[mid] == target)
            {
                fisrt = mid;
                high = mid - 1;
            }
            else if (arr[mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return fisrt;
    }

    int LastOccure(const vector<int> &arr, int target)
    {
        int low = 0, high = arr.size() - 1;
        int last = -1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (arr[mid] == target)
            {
                last = mid;
                low = mid + 1;
            }
            else if (arr[mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return last;
    }
    int countOccurrences(const vector<int> &arr, int target)
    {
        // Your code goes here
        int fisrt = firstOccure(arr, target);
        int last = LastOccure(arr, target);
        return last - fisrt + 1;
    }
};