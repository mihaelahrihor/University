

#include "Stack.h"
#define NULL_TELEM -11111
//save pointer 
Stack::Stack() {
    this->head = nullptr;
}

void Stack::push(TComp element , int left , int right) {
    Node *auxNode = new Node();
    TreeNode auxTreeNode = TreeNode();
    auxTreeNode.value = element;
    auxTreeNode.left = left;
    auxTreeNode.right = right;
    auxNode->element = auxTreeNode;
    auxNode->next = nullptr;
    if(this->head == nullptr){
        this->head = auxNode;
        return;
    }

    //add to front
    auxNode->next = this->head;
    this->head = auxNode;
}

TreeNode Stack::top() {
    return this->head->element;
}

TreeNode Stack::pop() {
    if(this->head == nullptr){
        TreeNode returnNode = TreeNode();
        returnNode.value = NULL_TELEM;
        return returnNode;
    }
    TreeNode value = this->head->element;
    Node *auxNode = this->head;
    this->head = this->head->next;
    delete auxNode;
    return value;
}


Stack::~Stack() {
    Node* current = this->head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

bool Stack::isEmpty() const {
    if(this->head == nullptr){
        return true;
    }
    return false;
}
