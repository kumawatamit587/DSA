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
    // https://leetcode.com/problems/reverse-linked-list/
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL)
            return NULL;
        if (head->next == NULL)
            return head;
        ListNode *prev = NULL;
        ListNode *q = head;
        while (q)
        {
            ListNode *temp = q;
            q = q->next;
            temp->next = prev;
            prev = temp;
        }
        return prev;
    }
};

////
ListNode *reverseLL(ListNode *head)
{
    // https://www.youtube.com/watch?v=D2vI2DNJGd8
    // https://takeuforward.org/data-structure/reverse-a-linked-list/
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    ListNode *newNode = reverseLL(head->next);
    ListNode *front = head->next;
    front->next = head;
    head->next = nullptr;
    return newNode;
}