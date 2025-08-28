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
    // https://takeuforward.org/linked-list/delete-the-middle-node-of-the-linked-list
    // https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/
public:
    ListNode *deleteMiddle(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return NULL;
        }
        if (head->next->next == NULL)
        {
            head->next = NULL;
            return head;
        }
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *delNode = slow->next;
        slow->val = slow->next->val;
        slow->next = slow->next->next;
        return head;
    }
};

///////////////////////////////////////////////////////////////
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
    ListNode *deleteMiddle(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return NULL;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        fast = fast->next->next;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *middle = slow->next;
        slow->next = slow->next->next;
        delete (middle);
        return head;
    }
};