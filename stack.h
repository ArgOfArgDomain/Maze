#ifndef STACK_H
#define STACK_H

#include "stacknode.h"

template <class T>
class Stack
{    
    public:
        Stack(T errorReturn = T());        
        virtual ~Stack();
        void clear();
        void push(T value);        
        T pop();
        bool isEmpty();

    private:
        StackNode<T>* firstNode;
        StackNode<T>* lastNode;
        T errorReturn;
};

// purpose: initialize stack
// parameters: (optional) value to return on pop if no more values
// returns: none
template <class T>
Stack<T>::Stack(T errorReturn)
{
    // set first node and last node to NULL
    firstNode = NULL;
    lastNode = NULL;
    this->errorReturn = errorReturn;
}

// purpose: deallocate memory used by stack
// parameters: none
// returns: none
template <class T>
Stack<T>::~Stack()
{
    // delete all nodes
    clear();
}

// purpose: empty the stack
// parameters: none
// returns none
template <class T>
void Stack<T>::clear()
{
    StackNode<T>* currentNode = firstNode;

    // delete all the nodes
    while(currentNode != NULL) {
        StackNode<T>* targetNode = currentNode;
        currentNode = currentNode->nextNode;
        delete targetNode;
    }
    
    // set first node and last node to NULL
    firstNode = NULL;
    lastNode = NULL;
}

// purpose: push a value on to the stack
// parameters: value to push on to the stack
// returns: nothing
template <class T>
void Stack<T>::push(T value)
{
    StackNode<T>* newNode = new StackNode<T>();
    
    // store data in new node
    newNode->data = value;
    newNode->nextNode = NULL;
    newNode->previousNode = lastNode;

    // place node on stack
    if(firstNode == NULL) {
        firstNode = newNode;
    } else {
        lastNode->nextNode = newNode;
    }

    // set us as the last node
    lastNode = newNode;
}

// purpose: pop a value off the stack
// parameters: none
// returns: the value that was popped
template <class T>
T Stack<T>::pop()
{
    T value = errorReturn;
 
    // make sure we have atleast one item in the stack   
    if (firstNode != NULL) {
        // get the last value in the stack
        value = lastNode->data;
        
        // store new last node
        StackNode<T>* currentNode = lastNode;
        lastNode = lastNode->previousNode;

        // if we still have a valid last node, set its next node to null
        if (lastNode != NULL) {
            lastNode->nextNode = NULL;
        }

        // if we don't have any nodes, set first node to null
        if(currentNode == firstNode) {
            firstNode = NULL;
        }

        // delete the node we just popped
        delete currentNode;
    }

    // return the value
    return value;
}

// purpose: check if the stack is empty
// parameters: none
// returns: true/false
template <class T>
bool Stack<T>::isEmpty()
{
    // return whether stack is empty
    return (firstNode == NULL);
}


#endif
















