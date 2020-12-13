#include <iostream>

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
    void AddNode(int data)
    {
        NODE* tmp = head;
        while (tmp->next != nullptr) {
            tmp = tmp->next;
        }
        tmp->next = new NODE(data);
    }
};
