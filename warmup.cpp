// 既然我们要用链表解题，那我们首先就构造一个链表吧 题目：给定数组 1，2，3，4 构造成如下链表 head–>4—->3—->2—->1

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

class LINKED_LIST
{
private:
    NODE* head = new NODE(0);
public:
    LINKED_LIST() {}
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
};

int main()
{
    LINKED_LIST oneLink;
    oneLink.AddNode(1);
    oneLink.AddNode(2);
    oneLink.AddNode(3);
    oneLink.HeadInsert(4);
    oneLink.PrintLink();
    LINKED_LIST warmUp;
    array<int, 5> arr = {1, 2, 3, 4, 5};
    for_each(arr.begin(), arr.end(), [warmUp](int i) mutable {
        warmUp.HeadInsert(i);
    } );
    warmUp.PrintLink();
    
    return 0;
}
