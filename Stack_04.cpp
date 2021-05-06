#include <iostream>
#include <stack>

//todo Reverse a Linked List

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

Node* Reverse(Node *head)
{
    if (head == nullptr)
    {
        return nullptr;
    }
    
    //? loop for push
    std::stack<Node*> S;
    Node* temp = head;
    while (temp != nullptr)
    {
        S.push(temp);
        temp = temp->next;
    }

    //? loop for pop
    temp = S.top(); head = temp;
    S.pop();
    while (!S.empty())
    {
        temp->next = S.top();
        S.pop();
        temp = temp->next;
    }
    temp->next = nullptr;

    return head;
}


int main()
{
    Node* head = nullptr;   //? local variable

    head = insertList(head, 2);
    head = insertList(head, 4);
    head = insertList(head, 6);
    head = insertList(head, 5);
    printList(head);

    head = Reverse(head);
    printList(head);

    return 0;
}