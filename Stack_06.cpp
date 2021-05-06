#include <iostream>
#include <vector>
#include<string>
#include <stack>
#include <sstream>

//todo evaluation of Postfix expressions

bool isNumber(const std::string &str)
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

int stringToNumber(const std::string &str)
{
    int number;
    if (!(std::istringstream(str) >> number))
        number = 0;

    return number;
}

std::string numberToString(int number)
{
    std::ostringstream stringConvert;
    stringConvert << number;

    return stringConvert.str();
}

int perform(const std::string &oper, int op1, int op2)
{
    switch (oper.front())
    {
    case '+':
        return (op1 + op2);
        break;
    case '-':
        return (op1 - op2);
        break;
    case '*':
        return (op1 * op2);
        break;
    case '/':
        return (op1 / op2);
        break;
    
    default:
        return INT32_MAX;
        break;
    }
}

int evaluatePostfix(std::vector<std::string> exp)
{
    std::stack<std::string> S;

    for (std::string elem : exp)
    {
        if (isNumber(elem))
        {
            S.push(elem);
        }
        else if (isOperator(elem))
        {
            int operand2 = stringToNumber(S.top());
            S.pop();
            int operand1 = stringToNumber(S.top());
            S.pop();
            int res = perform(elem, operand1, operand2);
            S.push(numberToString(res));
        }
    }
    
    return stringToNumber(S.top());
}

int main()
{

    std::vector<std::string> exp;
    exp.push_back("2");
    exp.push_back("3");
    exp.push_back("*");
    exp.push_back("5");
    exp.push_back("4");
    exp.push_back("*");
    exp.push_back("+");
    exp.push_back("9");
    exp.push_back("-");

    std::cout << "Postfix: ";
    for (auto &&i : exp)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::cout << evaluatePostfix(exp) << std::endl; 

    return 0;
}