#include <iostream>

//todo  Implementation of Queues by Array

#define MAX_SIZE 10

int A[MAX_SIZE];
int front = -1;
int rear = -1;

bool isEmpty()
{
    if (front == -1 and rear == -1)
    {
        // std::cout << "Queue is empty" << std::endl;
        return true;
    }
    else
    {
        return false;
    }
}

bool isFull()
{
    if (rear == MAX_SIZE - 1)
    {
        std::cout << "Queue is full!" << std::endl;
        return true;
    }

    return false;
}

void enQueue(int x)
{
    if (isFull())
    {
        return;
    }
    else if (isEmpty())
    {
        front = 0;
        rear = 0;
    }
    else
    {
        ++rear;
    } 

    A[rear] = x;
}

void deQueue()
{
    if (isEmpty())
    {
        return;
    }
    else if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        ++front;
    }
}

int main()
{
    std::cout << "Array: ";
    for (size_t i = 0; i < MAX_SIZE; i++)
    {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;

    enQueue(2);
    enQueue(5);
    enQueue(7);

    std::cout << "Modify Array: ";
    for (size_t i = 0; i < MAX_SIZE; i++)
    {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}