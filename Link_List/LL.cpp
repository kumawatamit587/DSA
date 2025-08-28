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
Node *insertHead(Node *head, int val)
{
    Node *temp = new Node(val, head);
    return temp;
}
Node *deletefirstNode(Node *head)
{
    if (head == NULL)
        return head;
    Node *temp = head;
    head = head->next;
    return head;
}
Node *deleteLastNode(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return nullptr;
    }
    Node *temp = head;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}

Node *deleteK_Node(Node *head, int k)
{
    if (head == nullptr)
    {
        return nullptr;
    }
    if (k == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node *prev = nullptr;
    Node *delNode = head;
    int count = 0;

    while (delNode)
    {
        count++;
        if (count == k)
        {
            prev->next = prev->next->next;
            break;
        }
        prev = delNode;
        delNode = delNode->next;
    }
    delete delNode;
    return head;
}

Node *insertLast(Node *head, int ele)
{
    if (head == NULL)
        return nullptr;
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    Node *newNodeEle = new Node(ele);
    temp->next = newNodeEle;
    return head;
}

Node *insertAt_Kth(Node *head, int ele, int k)
{
    if (head == NULL)
    {

        if (k == 1)
        {
            return new Node(ele);
        }
        return nullptr;
    }

    if (k == 1)
    {
        Node *newNodeEle = new Node(ele);
        newNodeEle->next = head;
        head = newNodeEle;
        return head;
    }
    Node *temp = head;
    int count = 0;

    while (temp != NULL)
    {
        count++;
        if (count == (k - 1))
        {
            Node *newNodeEle = new Node(ele);
            newNodeEle->next = temp->next;
            temp->next = newNodeEle;
            break;
        }
        temp = temp->next;
    }
    // Node *prev = nullptr;
    // while (temp || temp == NULL)
    // {
    //     count++;
    //     if (count == k)
    //     {
    //         Node *newNodeEle = new Node(ele);
    //         prev->next = newNodeEle;
    //         newNodeEle->next = temp;
    //         break;
    //     }
    //     prev = temp;
    //     temp = temp->next;
    // }
    return head;
}

Node *insertBeforeValue(Node *head, int ele, int value)
{
    if (head == NULL)
    {
        return nullptr;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->next->data == value)
        {
            Node *newNodeEle = new Node(ele, temp->next);
            temp->next = newNodeEle;
            break;
        }
        temp = temp->next;
    }
    // Node *prev = nullptr;

    // while (temp != NULL)
    // {
    //     if (temp->data == value)
    //     {
    //         Node *newNodeEle = new Node(ele);
    //         newNodeEle->next = temp;
    //         prev->next = newNodeEle;
    //         break;
    //     }
    //     prev = temp;
    //     temp = temp->next;
    // }
    return head;
}
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
    vector<int> arr = {12, 8, 5, 7};
    int val = 100;

    // Creating a linked list with initial elements from the array
    Node *head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);

    // Inserting a new node at the head of the linked list
    // head = insertHead(head, val);
    // head = deletefirstNode(head);
    // head = deleteLastNode(head);
    // head = deleteK_Node(head, 2);
    // head = insertLast(head, 16);
    // head = insertAt_Kth(head, 16, 5);
    // head = insertBeforeValue(head, 16, 5);
    head = reverseLL(head);

    // Printing the linked list
    printLL(head);

    return 0;
}