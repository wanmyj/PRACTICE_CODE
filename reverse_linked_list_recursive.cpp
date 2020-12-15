
// 什么是链表的翻转:给定链表 head–>4—>3–>2–>1，将其翻转成 head–>1–>2–>3–>4 ，由于翻转链表是如此常见，如此重要
// 所以我们分别详细讲解下如何用递归和非递归这两种方式来解题

// 递归翻转
#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

struct NODE {
    int data;// 结点的数组域，值
    NODE* next = nullptr;// 节点的引用，指向下一个节点
    NODE(int inData) 
    {
        data = inData;
    }
};

class LINKED_LIST {
private:
    NODE* head;
public:
    LINKED_LIST() {
         head = new NODE(0);
    }
    void PrintLink()
    {
        NODE* tmp = head->next;
        while (tmp != nullptr) {
            cout << tmp->data << ' ';
            tmp = tmp->next;
        }
        cout << endl;
    }

    void AddNode(int data)
    {
        NODE* tmp = head;
        while (tmp->next != nullptr) {
            tmp = tmp->next;
        }
        tmp->next = new NODE(data);
    }

    void HeadInsert(int data)
    {
        NODE* tmp = new NODE(data);
        tmp->next = head->next;
        head->next = tmp;
    }

    NODE* ReturnNode(int pos)
    {
        int i = 0;
        NODE* tmp = head->next;
        while (i < pos) {
            i++;
            tmp = tmp->next;
        }
        return tmp;
    }

    void DelNode(NODE* delNode)
    {
        if (delNode->next == nullptr) {
            NODE* beforeDelNode = head;
            while (beforeDelNode->next != delNode) {
                beforeDelNode = beforeDelNode->next;
            }
            beforeDelNode->next = nullptr;
            // delete delNode;
            free(delNode);
        } else {
            NODE* nextNode = delNode->next;
            delNode->data = nextNode->data;
            delNode->next = nextNode->next;
            // delete nextNode;
            free(nextNode);
        }
    }
    void PrintNodePos()
    {
        NODE* tmp = head->next;
        while (tmp != nullptr) {
            printf("%d %p\n", tmp->data, tmp);
            tmp = tmp->next;
        }
        printf("FINAL NEXT: %p\n", tmp);
    }
    NODE* ReverseLinkedListRecur(NODE *node)
    {
        NODE* tmp = nullptr;
        if (node->next != nullptr) {
            tmp = ReverseLinkedListRecur(node->next);
            node->next->next = node;
            node->next = nullptr;
            return tmp;
        } else {
            return node;
        }
    }
};
int main()
{
    LINKED_LIST oneLink;
    // LINKED_LIST* oneLink1 = new LINKED_LIST();
    // printf("the oneLink1 is %p\n", &oneLink1);
    oneLink.AddNode(1);
    oneLink.AddNode(2);
    oneLink.AddNode(3);
    oneLink.HeadInsert(0);
    oneLink.PrintLink();
    NODE* tmp = oneLink.ReturnNode(0);
    NODE* tmp2 = oneLink.ReverseLinkedListRecur(tmp->next);
    oneLink.ReturnNode(0)->next = tmp2;
    // h 0 1 2 3
    // h 0 3 2 1
    oneLink.PrintLink();

    return 0;
}
