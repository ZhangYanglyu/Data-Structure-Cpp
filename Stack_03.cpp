#include <iostream>
#include <stack>
#include <cstring>

//todo string reversal using stack

void Reverse(char *C, int n)
{
    std::stack<char> S;

    //? loop for push
    for (size_t i = 0; i < n; i++)
    {
        S.push(C[i]);
    }
    
    //? loop for pop
    for (size_t i = 0; i < n; i++)
    {
        C[i] = S.top();
        S.pop();
    }
}

int main()
{
    char C[] = "hello";

    std::cout << "Input: " << C << std::endl;
    Reverse(C, strlen(C));
    std::cout << "Output: " << C << std::endl;

    return 0;
}