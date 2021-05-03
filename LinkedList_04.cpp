#include <iostream>

//todo Reverse a linked list

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

Node* reverse(Node* head)
{
    Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr)
    {
        Node* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
    return head;
}

void printLink(Node* head)
{
    std::cout << "List is: ";
    while (head != nullptr)
    {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << "\n";
}

int main()
{
    Node* head = nullptr;

    head = insertList(head, 2);
    // head = insertList(head, 4);
    // head = insertList(head, 6);
    // head = insertList(head, 8);
    printLink(head);

    head = reverse(head);
    printLink(head);
    return 0;
}