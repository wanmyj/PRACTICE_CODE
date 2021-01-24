#include <queue>
#include <stack>

using namespace std;

template<class T>
class Stack : public stack<T>
{
public:
    T pop() {
        T tmp = top();
        stack<T>::pop();
        return tmp;
    }
};

template<class T>
class Queue : public queue<T>
{
public:
    T dequeue() {
        T tmp = front();
        queue<T>::pop();
        return tmp;
    }
    void enqueue(const T& el) {
        push(el);
    }
};

template<class T>
class BSTNode
{
public:
    BSTNode() {
        left = right = 0;
    }
    BSTNode(const T& e, BSTNode<T> *l = nullptr, BSTNode<T> *r = nullptr) {
        el = e;
        left = l;
        right = r;
    }
    T el;
    BSTNode left, right;
};

template<class T>
class BST
{
protected:
    BSTNode<T> root;
    void clear(BSTNode<T>*);
    virtual void visit(BSTNode<T> *p) {
        cout << p->el << ' ';
    }
public:
    BST() {
        root = 0;
    }
    ~BST() {
        clear();
    }
    void clear() {
        clear(root);
        root = nullptr;
    }
    bool isEmpty() const {
        return root == nullptr;
    }
    void preorder() {
        preorder(root);
    }
    void inorder() {
        inorder(root);
    }
    void postorder() {
        postorder(root);
    }
    T* search(const T& el) const {
        return search(root, el);
    }
    void breadthFirst();
    void iterativePreorder();
    void iterativeInorder();
    void iterativePostorder();
    void MorrisInorder();
    void insert(const T&);
private:
    T* search(BSTNode<T>* p, const T& el);
    void inorder(BSTNode<T> *p);
    void preorder(BSTNode<T> *p);
    void postorder(BSTNode<T> *p);
};

template<class T>
T* BST<T>::search(BSTNode<T>* p, const T& el) {
    while (p != nullptr)
        if (el == p->el)
            return p;
        else if (el > p->el)
            p = p->right;
        else
            p = p->left;
    return nullptr;
}


template<class T>
void BST<T>::breadthFirst() {
    Queue<BSTNode<T>*> queue;
    BSTNode<T> *p = root;
    if (p != nullptr) {
        queue.enqueue(p);
        while (!queue.empty()) {
            p = queue.dequeue();
            visit(p);
            if (p->left != nullptr)
                queue.enqueue(p->left);
            if (p->right != nullptr)
                queue.enqueue(p->right);
        }
    }
}

template<class T>
void BST<T>::inorder(BSTNode<T> *p) {
    if (p != nullptr) {
        inorder(p->left);
        visit(p);
        inorder(p->right);
    }
}
template<class T>
void BST<T>::preorder(BSTNode<T> *p) {
    if (p != nullptr) {
        visit(p);
        preorder(p->left);
        preorder(p->right);
    }
}
template<class T>
void BST<T>::postorder(BSTNode<T> *p) {
    if (p != nullptr) {
        postorder(p->left);
        postorder(p->right);
        visit(p);
    }
}
template<class T>
void BST<T>::iterativePreorder() {
    Stack<BSTNode<T>*> travStack;
    BSTNode<T> *p = root;
    if (p != nullptr) {
        travStack.push(p);
        while (!travStack.empty()) {
            p = travStack.pop();
            visit(p);
            if (p->right != nullptr)
                travStack.push(p->right);
            if (p->left != nullptr)
                travStack.push(p->left);
        }
    }
}
template<class T>
void BST<T>::iterativePostorder() {
    Stack<BSTNode<T>*> travStack;
    BSTNode<T> *p = root;
    BSTNode<T> *q = root;
    while (*p != nullptr) {
        for (; p->left != nullptr; p = p->left)
            travStack.push(p);
        while (p->right == nullptr || p->right == q) {
            visit(p);
            q = p;
            if (travStack.empty())
                return;
            p = travStack.pop();
        }
        travStack.push(p);
        p = p->right;
    }
    
}