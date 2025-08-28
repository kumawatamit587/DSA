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
    // https://takeuforward.org/data-structure/check-if-given-linked-list-is-plaindrome/
    // https://leetcode.com/problems/palindrome-linked-list/description/
    bool isPalindrome(ListNode *head)
    {
        vector<int> vec;
        ListNode *fast = head;
        while (fast)
        {
            vec.push_back(fast->val);
            fast = fast->next;
        }
        int n = vec.size() - 1;
        int i = 0;
        while (i <= n)
        {
            if (vec[i] != vec[n])
            {
                return false;
            }
            i++;
            n--;
        }
        return true;
    }
};

///////////////////////////

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
    // Time Complexity: O (2* N) The algorithm traverses the linked list twice, dividing it into halves. During the first traversal, it reverses one-half of the list, and during the second traversal, it compares the elements of both halves. As each traversal covers N/2 elements, the time complexity is calculated as O(N/2 + N/2 + N/2 + N/2), which simplifies to O(2N), ultimately representing O(N).

public:
    ListNode *reverseLL(ListNode *temp)
    {
        if (temp == NULL || temp->next == NULL)
        {
            return temp;
        }
        ListNode *newRevHalf = reverseLL(temp->next);
        ListNode *front = temp->next;
        front->next = temp;
        temp->next = NULL;
        return newRevHalf;
    }
    bool isPalindrome(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *NewsecondHalf = reverseLL(slow);

        ListNode *firstHalf = head;
        ListNode *secondHalf = NewsecondHalf;
        while (firstHalf && secondHalf)
        {
            if (firstHalf->val != secondHalf->val)
            {
                reverseLL(NewsecondHalf);
                return false;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
        reverseLL(NewsecondHalf);
        return true;
    }
};