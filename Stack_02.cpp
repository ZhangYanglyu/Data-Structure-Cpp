#include <iostream>

//todo Stack - Linked List implementation

struct Node
{
    int data;
    Node* link;
};

Node* stackPush(Node* top, int x)
{
    Node* temp = new Node();
    temp->data = x;
    temp->link = top;
    top = temp;

    return top;
}

Node* stackPop(Node* top)
{
    if (top == nullptr)
    {
        return nullptr;
    }
    
    Node* temp = top;
    top = top->link;
    delete temp;
    
    return top;
}

int stackTop()
{
    return ;
}

void stackPrint(Node* top)
{
    if (top == nullptr)
    {
        std::cerr << "Error: No element to pop" << std::endl;
    }
    
    Node* temp = top;
    std::cout << "Stack: ";
    while (temp != nullptr)
    {
        std::cout << temp->data << " ";
        temp = temp->link;
    }
    std::cout << std::endl;
}

int main()
{
    Node* top = nullptr;

    top = stackPush(top, 2);  
    stackPrint(top);
    top = stackPush(top, 4);
    stackPrint(top);
    top = stackPush(top, 6);
    stackPrint(top);
    top = stackPop(top);
    stackPrint(top);
    top = stackPush(top, 8);

    return 0;
}