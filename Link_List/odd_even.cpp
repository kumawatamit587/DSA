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
public:
    /// https://takeuforward.org/data-structure/segregate-even-and-odd-nodes-in-linkedlist
    // https://leetcode.com/problems/odd-even-linked-list/

    // even index always ahead to odd index that's why we apply condition on even

    // TC : O(N)
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode *evenHead = head->next;
        ListNode *odd = head;
        ListNode *even = head->next;

        while (even && even->next)
        {
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        cout << even;
        odd->next = evenHead;
        return head;
    }
};
