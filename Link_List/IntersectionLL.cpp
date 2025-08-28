/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    // Time Complexity: O(n+m)

    // Reason: Iterating through list 1 first takes O(n), then iterating through list 2 takes O(m).

    // Space Complexity: O(n)

    // Reason: Storing list 1 node addresses in unordered_set.
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == NULL || headB == NULL)
        {
            return NULL;
        }
        unordered_map<ListNode *, int> mpp1;
        ListNode *tempA = headA;
        ListNode *tempB = headB;
        while (tempA)
        {
            mpp1[tempA] = 1;
            tempA = tempA->next;
        }

        while (tempB)
        {
            if (mpp1.find(tempB) != mpp1.end())
            {
                return tempB;
            }
            tempB = tempB->next;
        }
        return NULL;
    }
};
///////////////////////////////////////////////////////

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    // https://leetcode.com/problems/intersection-of-two-linked-lists/description/?source=submission-noac
    // https://takeuforward.org/data-structure/find-intersection-of-two-linked-lists/
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        // Time Complexity: O(2*max(length of list1,length of list2))

        if (headA == NULL || headB == NULL)
        {
            return NULL;
        }
        ListNode *tempA = headA;
        ListNode *tempB = headB;
        while (tempA != tempB)
        {
            if (tempA == NULL)
            {
                tempA = headB;
            }
            if (tempB == NULL)
            {
                tempB = headA;
            }
            tempA = tempA->next;
            tempB = tempB->next;

            // tempA=tempA==NULL?headB:tempA->next;
            // tempB=tempB==NULL?headA:tempB->next;
        }
        return tempA;
    }
};