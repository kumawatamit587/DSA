class Solution
{
    // https://leetcode.com/problems/single-element-in-a-sorted-array/

public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int u;
        if (nums.size() == 1)
            return nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            if (i == 0)
            {
                if (nums[i] != nums[i + 1])
                {
                    return nums[i];
                }
            }
            else if (i == (nums.size() - 1))
            {
                if (nums[i] != nums[i - 1])
                {
                    return nums[i];
                }
            }
            else if (nums[i] != nums[i - 1] && nums[i] != nums[i + 1])
            {
                u = nums[i];
                break;
            }
        }
        return u;
    }
};
//////////////////////////////////////////////////////////////////////
// https://takeuforward.org/data-structure/search-single-element-in-a-sorted-array/
class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];
        int u;
        int low = 1;
        int high = nums.size() - 2;
        if (nums[low] != nums[0])
        {
            return nums[0];
        }
        else if (nums[high] != nums[nums.size() - 1])
        {
            return nums[nums.size() - 1];
        }

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] != nums[mid + 1] && nums[mid - 1] != nums[mid])
            {
                u = nums[mid];
                break;
            }
            if ((mid % 2 == 1 && nums[mid] == nums[mid - 1]) || (mid % 2 == 0 && nums[mid + 1] == nums[mid]))
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return u;
    }
};

By observing the above image, we can clearly notice a striking distinction between the index sequences of the left and right halves of the single element in the array.

                              The index sequence of the duplicate numbers in the left half is
                              always(even, odd)
                                  .That means one of the following conditions will be satisfied if we are in the left half : If the current index is even,
    the element at the next odd index will be the same as the current element.

    Similarly,
    If the current index is odd, the element at the preceding even index will be the same as the current element.

                                 The index sequence of the duplicate numbers in the right half is always(odd, even)
                                     .That means one of the following conditions will be satisfied if we are in the right half : If the current index is even,
    the element at the preceding odd index will be the same as the current element.

    Similarly,
    If the current index is odd, the element at the next even index will be the same as the current element.Now, we can easily identify the left and right halves, just by checking the sequence of the current index, i, like the following :

    If(i % 2 == 0 and arr[i] == arr[i + 1]) or
    (i % 2 == 1 and arr[i] == arr[i - 1]),
    we are in the left half.If(i % 2 == 0 and arr[i] == arr[i - 1]) or (i % 2 == 1 and arr[i] == arr[i + 1]), we are in the right half.Note : In our case, the index i refers to the index ‘mid’.

                                                                                                                                                           How to eliminate the halves:

If we are in the left half of the single element, we have to eliminate this left half(i.e.low = mid + 1).Because our single element appears somewhere on the right side.If we are in the right half of the single element, we have to eliminate this right half(i.e.high = mid - 1).Because our single element appears somewhere on the left side.Now, we have resolved the problems and we can use the binary search accordingly.