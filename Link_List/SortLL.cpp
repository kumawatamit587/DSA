// https://leetcode.com/problems/sort-li

// https://takeuforward.org/linked-list/sort-a-linked-list

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
    ListNode *findMidLL(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode *mergeLL(ListNode *leftNode, ListNode *rightNode)
    {
        ListNode *dummyNode = new ListNode(-1);
        ListNode *temp = dummyNode;
        while (leftNode != NULL && rightNode != NULL)
        {
            if (leftNode->val < rightNode->val)
            {
                temp->next = leftNode;
                temp = leftNode;
                leftNode = leftNode->next;
            }
            else
            {
                temp->next = rightNode;
                temp = rightNode;
                rightNode = rightNode->next;
            }
        }
        if (leftNode)
        {
            temp->next = leftNode;
        }
        else
        {
            temp->next = rightNode;
        }
        return dummyNode->next;
    }
    ListNode *sortList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode *middleNode = findMidLL(head);
        ListNode *rightNode = middleNode->next;
        middleNode->next = NULL;
        ListNode *leftNode = head;
        ListNode *left = sortList(leftNode);
        ListNode *right = sortList(rightNode);
        return mergeLL(left, right);
    }
};

// Time Complexity for the best and average case: O(N*logN)

// Space Complexity: O(1) + O(N) auxiliary stack space.
