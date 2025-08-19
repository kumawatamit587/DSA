class Solution
{
public:
    // https://takeuforward.org/arrays/find-out-how-many-times-the-array-has-been-rotated/
    int findKRotation(vector<int> &nums)
    {
        int low = 0;
        int high = nums.size() - 1;
        int minEle = INT_MAX;
        int index;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            // search space is already sorted
            // then arr[low] will always be
            // the minimum in that search space:
            if (arr[low] <= arr[high])
            {
                if (arr[low] < ans)
                {
                    index = low;
                    minEle = arr[low];
                }
                break;
            }

            // if right part is sorted:

            // keep the minimum:
            if (nums[mid] < nums[high])
            {
                minEle = min(minEle, nums[mid]);
                if (minEle == nums[mid])
                {
                    index = mid;
                }
                // Eliminate right half:

                high = mid - 1;
            }
            else
            // if left part is sorted:
            {
                minEle = min(minEle, nums[low]);
                // keep the minimum:

                if (minEle == nums[low])
                {
                    index = low;
                }
                // Eliminate left half:
                low = mid + 1;
            }
        }
        return index;
    }
};