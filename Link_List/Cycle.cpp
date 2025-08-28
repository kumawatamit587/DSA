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
    // TC:O(N)
public:
    bool hasCycle(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return false;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                return true;
            }
        }
        return false;
    }
};

///////////////
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
    // YC:O(N*2*log(N))
    // https://leetcode.com/problems/linked-list-cycle/description/
    // https://takeuforward.org/data-structure/detect-a-cycle-in-a-linked-list/
    bool hasCycle(ListNode *head)
    {
        ListNode *temp = head;
        unordered_map<ListNode *, int> mmp;
        while (temp != NULL)
        {
            if (mmp.find(temp) != mmp.end())
            {
                return true;
            }
            mmp[temp] = 1;
            temp = temp->next;
        }
        return false;
    }
};