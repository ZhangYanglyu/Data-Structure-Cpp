#include <iostream>

//todo LinkedList: Inserting a node at nth position

struct Node
{
    int data;
    Node* next;
};

Node* head;

void InsertList(int data, int n)
{
    Node* temp1 = new Node();
    temp1->data = data;
    temp1->next = nullptr;

    if (n == 1)
    {
        temp1->next = head;
        head = temp1;
        return;
    }

    Node* temp2 = head;
    for (size_t i = 0; i < n-2; i++)
    {
        temp2 = temp2->next;
    }
    
    temp1->next = temp2->next;
    temp2->next = temp1;
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

int main()
{
    head = nullptr;

    InsertList(2, 1);
    InsertList(3, 2);
    InsertList(4, 1);
    InsertList(5, 2);

    printList();

    return 0;
}