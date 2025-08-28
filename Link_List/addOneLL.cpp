#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    // Constructor with both data and next node
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

    // Constructor with only data (assuming next is initially null)
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

// Function to print the linked list
void printLL(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

// Function to insert a new node at the head of the linked list
Node *reverseLL(Node *head)
{
    // https://www.youtube.com/watch?v=D2vI2DNJGd8
    // https://takeuforward.org/data-structure/reverse-a-linked-list/
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *newNode = reverseLL(head->next);
    Node *front = head->next;
    front->next = head;
    head->next = nullptr;
    return newNode;
}
int main()
{
    // Sample array and value for insertion
    vector<int> arr = {1, 2, 3};
    int val = 100;

    // Creating a linked list with initial elements from the array
    Node *head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    // head->next->next->next = new Node(arr[3]);

    // TC=O(3N)
    head = reverseLL(head);
    Node *temp = head;
    int carry = 1;
    while (temp)
    {
        temp->data = temp->data + carry;
        carry %= 10;
        if (temp->data < 10)
        {
            carry = 0;
            break;
        }
        else
        {
            carry = 1;
            temp->data = 0;
        }
        temp = temp->next;
    }
    if (carry == 1)
    {
        Node *newNode = new Node(carry);
        head = reverseLL(head);
        newNode->next = head;

        printLL(newNode);
        return 0;
    }
    head = reverseLL(head);
    // Printing the linked list
    printLL(head);

    return 0;
}

///////////////////////////////

/*
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
    //    TC=O(N)
    //    SC=O(N)
    int checkLLCarry(ListNode *temp)
    {
        if (temp == NULL)
        {
            return 1;
        }
        int carry = checkLLCarry(temp->next);
        temp->val = temp->val + carry;
        if (temp->val < 10)
        {
            return 0;
        }
        temp->val = 0;
        return 1;
    }
    ListNode *addOne(ListNode *head)
    {
        if (head == NULL)
        {
            return head;
        }
        int carry = checkLLCarry(head);
        if (carry == 1)
        {
            Node *newNode = new Node(carry);
            newNode->next = head;
            return newNode;
        }
        return head;
    }
};