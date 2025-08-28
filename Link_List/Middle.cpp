/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
    // https://leetcode.com/problems/middle-of-the-linked-list/
public:
    ListNode *middleNode(ListNode *head)
    {
        if (head == NULL)
            return NULL;
        if (head->next == NULL)
            return head;
        ListNode *middle = head;
        ListNode *fast = head;
        while (fast && fast->next)
        {
            middle = middle->next;
            fast = fast->next->next;
        }
        return middle;
    }
};