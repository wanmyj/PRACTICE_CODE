
// 给定一个链表的头结点 head,以及两个整数 from 和 to ,在链表上把第 from 个节点和第 to 个节点这一部分进行翻转。 
// 例如：给定如下链表，from = 2, to = 4 head–>5–>4–>3–>2–>1 将其翻转后，链表变成 head–>5—>2–>3–>4–>1

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
    // head -> 1 -> 2 -> 3 -> 4 -> 5
    // from 2 to 4
    // head -> 1 -> 4 -> 3 -> 2 -> 5
    void iterationInvertLinkedList(int from, int to)
    {
        NODE* preFrom = head;
        NODE* fromNode = nullptr;
        NODE* toNode = head;
        NODE* afterTo = nullptr;
        for (int i = 0; i < to; i++) {
            if (i < from - 1) {
                preFrom = preFrom->next;
            }
            if (i == from - 1) {
                fromNode = preFrom->next;
            }
            toNode = toNode->next;
            afterTo = toNode->next;
        }
        NODE* tmp;
        NODE* pre = fromNode;
        NODE* cur = fromNode->next;
        pre->next = afterTo;
    // head -> 1 -> 2  3 -> 4 -> 5
    //               ↘---------↗
    //              
        while (cur != afterTo ) {
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
    // head -> 1 -> 2 <- 3 <- 4  5
    //               ↘---------↗
    preFrom->next = pre;
    //          ↗---------↘
    // head -> 1  2 <- 3 <- 4  5
    //               ↘---------↗
    }
    void DeleteMidNode() {
        NODE* fast = head->next;
        NODE* slow= head->next;
        NODE* preSlow = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            preSlow = slow;
            slow = slow->next;
        }
        preSlow->next = slow->next;
        delete slow;
    }
    void DeleteReverseKthNode(int k) {
        NODE* preSlow = head;
        NODE* slow= head->next;
        NODE* fast = slow;
        while(k--) {
            fast = fast->next;
        }
        while (fast != nullptr) {
            fast = fast->next;
            preSlow = slow;
            slow = slow->next;
        }
        preSlow->next = slow->next;
        delete slow;
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
    oneLink.AddNode(4);
    oneLink.AddNode(5);
    oneLink.PrintLink();
    oneLink.DeleteReverseKthNode(1);
    oneLink.PrintLink();

    return 0;
}
