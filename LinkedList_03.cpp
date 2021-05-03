#include <iostream>

//todo Linked List: Delete a node at nth position

struct Node
{
    int data;
    Node* next;
};

Node* head; //? global variable

void insertList(int data)
{
    Node* temp1 = new Node();
    temp1->data = data;
    temp1->next = nullptr;

    if (head == nullptr)
    {
        head = temp1;
        return;
    }
    
    Node* temp2 = head;
    while (temp2->next != nullptr)
    {
        temp2 = temp2->next;
    }
    //? temp2 points to end node
    temp2->next = temp1;    

    // Node* temp2 = head;
    // if (temp2 != nullptr)
    // {
    //     while (temp2->next != nullptr)
    //     {
    //         temp2 = temp2->next;
    //     }
    //     //? temp2 points to end node
    //     temp2->next = temp1;
    // }
    // else
    // {
    //     head = temp1;   //? modify head pointer
    // }
}

void printList()
{
    Node* temp = head;

    std::cout << "List: ";
    while (temp != nullptr)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

void deleteList(int n)
{
    Node* temp1 = head;

    if (n == 1)
    {
        head = temp1->next; //? head now points to second node
        delete temp1;
        return;
    }

    for (size_t i = 0; i < n-2; i++)
    {
        temp1 = temp1->next;
    }
    //? temp1 points to (n-1)th Node

    Node* temp2 = temp1->next;  //? nth Node
    temp1->next = temp2->next;

    delete temp2;   //? delete temp2
}

int main()
{
    head = nullptr;

    insertList(2);
    insertList(4);
    insertList(6);
    insertList(5);
    printList();

    std::cout << "Enter a position" << std::endl;
    int n;
    std::cin >> n;
    deleteList(n);
    printList();

    return 0;
}