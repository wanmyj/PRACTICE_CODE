#include <iostream>
#include <array>
#include <algorithm>
#include <string>
using namespace std;

// 先定义一个函数，明确这个函数的功能，由于递归的特点是问题和子问题都会调用函数自身，所以这个函数的功能一旦确定了， 之后只要找寻问题与子问题的递归关系即可
// 接下来寻找问题与子问题间的关系（即递推公式），这样由于问题与子问题具有相同解决思路，只要子问题调用步骤 1 定义好的函数，问题即可解决。所谓的关系最好能用一个公式表示出来，比如 f(n) = n * f(n-) 这样，如果暂时无法得出明确的公式，用伪代码表示也是可以的, 发现递推关系后，要寻找最终不可再分解的子问题的解，即（临界条件），确保子问题不会无限分解下去。由于第一步我们已经定义了这个函数的功能，所以当问题拆分成子问题时，子问题可以调用步骤 1 定义的函数，符合递归的条件（函数里调用自身）
// 将第二步的递推公式用代码表示出来补充到步骤 1 定义的函数中
// 最后也是很关键的一步，根据问题与子问题的关系，推导出时间复杂度,如果发现递归时间复杂度不可接受，则需转换思路对其进行改造，看下是否有更靠谱的解法

// 反转二叉树 将左边的二叉树反转成右边的二叉树
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
};

struct Trunk
{
    Trunk *prev;
    string str;
    Trunk(Trunk *prev, string str)
    {
        this->prev = prev;
        this->str = str;
    }
    void showTrunks(Trunk *p)
    {
        if (p == nullptr)
            return;
        showTrunks(p->prev);
        cout << p->str;
    }
    void printTree(TreeNode *root, Trunk *prevRoot, bool isRight)
    {
        if (root == nullptr)  
            return;
    
        string prev_str = "    ";
        Trunk *thisTrunk = new Trunk(prevRoot, prev_str);
    
        printTree(root->right, thisTrunk, true);
    
        if (prevRoot == nullptr)
            thisTrunk->str = "root";
        else if (isRight) {
            thisTrunk->str = ".---";
            prev_str = "   |";
        } else {
            thisTrunk->str = "`---";
            prevRoot->str = prev_str;
        }
    
        showTrunks(thisTrunk);

        cout << root->val << endl;
    
        if (prevRoot != nullptr)
            prevRoot->str = prev_str;
        thisTrunk->str = "   |";
    
        printTree(root->left, thisTrunk, false);
    }
};

class Tree {
private:
    static Tree* instance;
    TreeNode* root;
    Trunk* trunk;
    Tree(): root(nullptr) {};
    void add(int num, TreeNode *rootNode)
    {
        if (num == rootNode->val) 
            return;
        if (num < rootNode->val) {
            if (rootNode->left == nullptr) {
                rootNode->left = new TreeNode(num);
                return;
            } else {
                add(num, rootNode->left);
            }
        } else if (num > rootNode->val) {
            if (rootNode->right == nullptr) {
                rootNode->right = new TreeNode(num);
                return;
            } else {
                add(num, rootNode->right);
            }
        }
    }
    bool search(int num, TreeNode *rootNode)
    {
        if (rootNode == nullptr)
            return false;
        if (rootNode->val == num)
            return true;
        if (rootNode->val > num)
            return search(num, rootNode->left);
        if (rootNode->val < num)
            return search(num, rootNode->right);
    }
public:
    static Tree* GetInstance()
    {
        if (!instance) {
            instance = new Tree;
        }
        return instance;
    }
    void add(int num)
    {
        if (root != nullptr)
            add(num, root);
        else {
            root = new TreeNode(num);
        }
    }
    void del(int num)
    {}
    void inorder()
    {}
    int height(TreeNode* rootNode)
    {
        if (rootNode == nullptr)
            return 0;
        return 1 + max(height(rootNode->left), height(rootNode->right));
    }
    void inorder(TreeNode*)
    {}
    bool search(int num)
    {
        return search(num, root);
    }
    void printTree()
    {
        trunk->printTree(root, nullptr, true);
    }
    // invert(root) = invert(root->left) + invert(root->right)
    void InvertTree()
    {
        InvertTree(root);
    }
    void InvertTree(TreeNode* rootNode)
    {
        if (rootNode == nullptr) {
            return;
        }
        InvertTree(rootNode->left);
        InvertTree(rootNode->right);
        TreeNode* tmp = rootNode->left;
        rootNode->left = rootNode->right;
        rootNode->right = tmp;
    }
};

Tree* Tree::instance = nullptr;
int main()
{
    Tree* tree = tree->GetInstance();
    array<int, 9> arr {6, 2,4,3,5,1, 8, 7, 9};
    // for (auto& i : arr) {
    //     i = rand();
    //     cout << i << ' '; 
    // }
    // cout << endl;
    for (auto& i : arr) {
        tree->add(i);
    }
    tree->printTree();
    tree->InvertTree();
    tree->printTree();
    return 0;   
}