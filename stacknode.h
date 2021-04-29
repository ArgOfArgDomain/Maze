#ifndef STACKNODE_H
#define STACKNODE_H

template <class T>
class StackNode
{
    public:
        StackNode();
        virtual ~StackNode() {}
        
        T data;
        StackNode* nextNode;
        StackNode* previousNode;
};

// purpose: construct new stack node
// parameters: none
// returns: none
template <class T>
StackNode<T>::StackNode()
{
    nextNode = NULL;
    previousNode = NULL;
}

#endif
