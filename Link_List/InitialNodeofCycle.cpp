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
    ListNode *detectCycle(ListNode *head)
    {
        if (head == NULL)
            return NULL;
        unordered_map<ListNode *, int> mpp;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next)
        {
            if (mpp.find(fast) != mpp.end())
            {
                return fast;
            }
            mpp[fast] = 1;
            fast = fast->next;
        }
        return NULL;
    }
};

/////////////////////////

// Tortoise and Hare approach

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
    // https://takeuforward.org/data-structure/starting-point-of-loop-in-a-linked-list/
    // https://leetcode.com/problems/linked-list-cycle-ii/
    ListNode *detectCycle(ListNode *head)
    {
        if (head == NULL)
            return NULL;
        unordered_map<ListNode *, int> mpp;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                slow = head;
                while (slow != fast)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};