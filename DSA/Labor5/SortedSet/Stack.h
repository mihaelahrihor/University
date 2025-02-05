

typedef int TElem;
typedef TElem TComp;
struct TreeNode{
    TElem value;
    int left;
    int right;
    int currentIndex;
};
struct Node{
    TreeNode element;
    Node *next;
};
class Stack {
private:
    Node *head;

public:
    Stack();

    void push(TComp element , int left,  int right);

    TreeNode top();

    TreeNode pop();

    bool isEmpty() const;
    ~Stack();
};


