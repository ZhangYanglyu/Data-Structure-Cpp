#include <iostream>
#include <vector>
#include<string>
#include <stack>
#include <sstream>

//todo Infix expressions to Postfix expressions

bool isOperand(const std::string &str)
{
    for (char const &c : str)
    {
        if (std::isdigit(c) == 0)
            return false;
    }

    return true;
}

bool isOperator(const std::string &str)
{
    switch (str.front())
    {
    case '+':
        /* code */
    case '-':
        /* code */
    case '*':
        /* code */
    case '/':
        /* code */
        return true;
        break;
    
    default:
        return false;
        break;
    }
}

bool hasHigherPrec(std::string str1, std::string str2)
{
    switch (str1.front())
    {
    case '+':

    case '-':
        return false;
        break;

    case '*':
        /* code */
    case '/':
        if (str2.front() == '+' or str2.front() == '-')
        {
            return true;
            break;
        }

    default:
        return false;
        break;
    }
}

std::vector<std::string> infixToPostfix(std::vector<std::string> exp)
{
    std::stack<std::string> S;
    std::vector<std::string> res;

    for (std::string &elem : exp)
    {
        if (isOperand(elem))
        {
            res.push_back(elem);
        }
        else if (isOperator(elem))
        {
            while ((!S.empty()) and hasHigherPrec(S.top(), elem))
            {
                res.push_back(S.top());
                S.pop();
            }

            S.push(elem);
        }
    }

    while (!S.empty())
    {
        res.push_back(S.top());
        S.pop();
    }
    
    return res;
}

int main()
{
    std::vector<std::string> exp;
    exp.push_back("11");
    exp.push_back("+");
    exp.push_back("2");
    exp.push_back("*");
    exp.push_back("3");

    std::cout << "InFix: ";
    for (auto &&elem : exp)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    
    std::vector<std::string> res = infixToPostfix(exp);
    
    std::cout << "PostFix: ";
    for (auto &&elem : res)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}