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
    // https://leetcode.com/problems/add-two-numbers/
    // https://takeuforward.org/data-structure/add-two-numbers-represented-as-linked-lists/
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if (l1 == NULL || l2 == NULL)
        {
            return NULL;
        }
        ListNode *temp1 = l1;
        ListNode *temp2 = l2;
        int carry = 0;
        ListNode *dummyHead = new ListNode(-1);
        ListNode *dummyNode = dummyHead;
        while (temp1 || temp2)
        {
            int sum = 0;
            if (temp1)
            {
                sum += temp1->val;
                temp1 = temp1->next;
            }
            if (temp2)
            {
                sum += temp2->val;
                temp2 = temp2->next;
            }
            sum += carry;
            int value = sum % 10;
            carry = sum / 10;
            ListNode *newNode = new ListNode(value);
            dummyNode->next = newNode;
            dummyNode = dummyNode->next;
        }
        if (carry)
        {
            ListNode *newNode = new ListNode(carry);
            dummyNode->next = newNode;
            dummyNode = dummyNode->next;
        }
        return dummyHead->next;
    }
};
// Time Complexity: O(max(m,n)). Assume that m and n represent the length of l1 and l2 respectively, the algorithm above iterates at most max(m,n) times.

// Space Complexity: O(max(m,n)). The length of the new list is at most max(m,n)+1.
