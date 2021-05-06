#include <iostream>

//todo Stack - Array based implementation

#define MAX_SIZE 101
int A[MAX_SIZE];
int top = -1;

void stackPush(int x)
{
    if (top == MAX_SIZE - 1)
    {
        std::cerr << "Error: stack overfolw" << std::endl;
        return;
    }
    
    A[++top] = x;
}

void stackPop()
{
    if (top == -1)
    {
        std::cerr << "Error: No element to pop" << std::endl;
        return;
    }
    
    top--;
}

int stackTop()
{
    return A[top];
}

void stackPrint()
{
    std::cout << "Stack: ";
    for (size_t i = 0; i <= top; i++)
    {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    stackPush(2); stackPrint();
    stackPush(5); stackPrint();
    stackPush(10); stackPrint();
    stackPop(); stackPrint();
    stackPush(12); stackPrint();

    return 0;
}