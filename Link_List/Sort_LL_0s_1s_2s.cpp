/*

/https://takeuforward.org/plus/dsa/problems/sort-a-ll-of-0's-1's-and-2's
Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};
*/

class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode *zeroNode = new ListNode(-1);
        ListNode *oneNode = new ListNode(-1);
        ListNode *twoNode = new ListNode(-1);
        ListNode *zeroTemp = zeroNode;
        ListNode *oneTemp = oneNode;
        ListNode *twoTemp = twoNode;
        ListNode *temp = head;
        while (temp)
        {
            if (temp->val == 0)
            {
                zeroTemp->next = temp;
                zeroTemp = zeroTemp->next;
            }
            else if (temp->val == 1)
            {
                oneTemp->next = temp;
                oneTemp = oneTemp->next;
            }
            else
            {
                twoTemp->next = temp;
                twoTemp = twoTemp->next;
            }
            temp = temp->next;
        }
        zeroTemp->next = oneNode->next ? oneNode->next : twoNode->next;
        oneTemp->next = twoNode->next;
        twoTemp->next = NULL;
        ListNode *newHead = zeroNode->next;
        delete zeroNode;
        delete oneNode;
        delete twoNode;
        return newHead;
    }
};