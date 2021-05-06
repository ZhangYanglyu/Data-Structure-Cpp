#include <iostream>
#include <stack>
#include <cstring>

//? check for balanced parentheses

bool checkBalancedParenthesis(char *C, int n)
{
    std::stack<char> S;

    for (size_t i = 0; i < n; i++)
    {
        if (C[i] == '{' or C[i] == '(' or C[i] == '[')
        {
            S.push(C[i]);
        }
        else if (C[i] == '}' or C[i] == ')' or C[i] == ']')
        {
            if (S.empty())
            {
                return false;
            }
            if (C[i] == '}')
            {
                if (S.top() != '{')
                    return false;
            }
            if (C[i] == ')')
            {
                if (S.top() != '(')
                    return false;
            }
            if (C[i] == ']')
            {
                if (S.top() != '[')
                    return false;
            }
            
            S.pop();
        } 
    }

    return (S.empty() ? true : false);
}

int main()
{
    char C[] = ")]";

    std::cout << (checkBalancedParenthesis(C, strlen(C)) ? "ture" : "false" ) << std::endl;
    return 0;
}