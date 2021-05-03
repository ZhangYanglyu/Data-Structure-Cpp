#include <iostream>
#include <vector>

//todo Linked List: Inserting a node at begining

struct Node
{
    int data;
    Node* next;
};

// Node* head;

Node* insertLink(Node* head, int x);
void printLink(Node* head);

int main()
{
    Node* head = nullptr; //? empty list;
    
    std::cout << "How many numbers?" << std::endl;
    int number;
    std::cin >> number;

    for (size_t i = 0; i < number; i++)
    {
        std::cout << "Enter the number:" << std::endl;
        int x;
        std::cin >> x;

        head = insertLink(head, x);
        printLink(head);
    }

    return 0;
}

Node* insertLink(Node* head, int x)
{
    Node* temp = new Node();
    temp->data = x;
    //! way1
    temp->next = head;

    //! way2
    // temp->next = nullptr;

    // if (head->next != nullptr)
    //     temp->next = head;

    head = temp;

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