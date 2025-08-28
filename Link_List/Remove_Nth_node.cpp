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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        /// Time Complexity: O(L)+O(L-N), We are calculating the length of the linked list and then iterating up to the (L-N)th node of the linked list, where L is the total length of the list.
        // https://takeuforward.org/data-structure/remove-n-th-node-from-the-end-of-a-linked-list/
        if (head == NULL || head->next == NULL)
        {
            return NULL;
        }
        ListNode *temp = head;
        int count = 0;
        while (temp)
        {
            count++;
            temp = temp->next;
        }
        if (count == n)
        {
            head = head->next;
            return head;
        }
        temp = head;
        int res = count - n;
        while (temp)
        {
            res--;
            if (res == 0)
            {
                break;
            }
            temp = temp->next;
        }
        ListNode *deleteNode = temp->next;
        temp->next = temp->next->next;
        delete (deleteNode);

        return head;
    }
};

////////////////
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head == NULL || head->next == NULL)
        {
            return NULL;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        int fastmove = 1;
        while (fastmove <= n)
        {
            fast = fast->next;
            fastmove++;
        }
        if (fast == NULL)
        {
            return head->next;
        }
        while (fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode *deleteNode = slow->next;
        slow->next = slow->next->next;
        delete (deleteNode);
        return head;
    }
};