#include <iostream>

//todo print linked list using recursion

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

void reversePrintList(Node* head)
{
    if (head == nullptr)
    {
        std::cout << std::endl;
        return; //? exit condition
    }

    reversePrintList(head->next);       //? recursive call
    std::cout << head->data << " ";     //? first print the value in the node
}

int main()
{
    Node* head = nullptr;   //? local variable

    head = insertList(head, 2);
    head = insertList(head, 4);
    head = insertList(head, 6);
    head = insertList(head, 5);

    printList(head);

    reversePrintList(head);

    return 0;
}