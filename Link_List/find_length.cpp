class Solution
{
public:
    int getLength(ListNode *head)
    {
        // Your code goes here
        int count = 0;
        while (head)
        {
            count++;
            head = head->next;
        }
        return count;
    }
};