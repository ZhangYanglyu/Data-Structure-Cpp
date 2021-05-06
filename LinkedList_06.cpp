#include <iostream>

//todo Reverse a linked list using recursion

struct Node
{
    int data;
    Node* next;
};

Node* insertList(Node* head, int data)
{
    Node* temp1 = new Node();
    temp1->data = data;
    temp1->next = nullptr;

    if (head == nullptr)
    {
        head = temp1;
    }
    else
    {
        Node* temp2 = head;
        while (temp2->next != nullptr)
        {
            temp2 = temp2->next;
        }
        //? temp2 points to end node
        temp2->next = temp1;
    } 
    return head;
}

void printList(Node* head)
{
    if (head == nullptr)
    {
        std::cout << std::endl;
        return; //? exit condition
    }
    
    std::cout << head->data << " ";     //? first print the value in the node
    printList(head->next);              //? recursive call
}

Node* reverseList(Node* p)
{
    if (p == nullptr or p->next == nullptr)     //? Exit condition 
    {
        return p;
    }
    
    Node* head = reverseList(p->next);

    Node* q = p->next;    //? 1
    q->next = p;          //? 2
    //* 1 and 2 can be rewrriten
    // p->next->next = p
    p->next = nullptr;

    return head;
}

int main()
{
    Node* head = nullptr;
    head = insertList(head, 2);
    head = insertList(head, 4);
    head = insertList(head, 6);
    head = insertList(head, 8);
    printList(head);

    head = reverseList(head);
    printList(head);

    return 0;
} 