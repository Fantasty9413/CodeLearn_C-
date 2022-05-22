# include <iostream>
# define null nullptr

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(): val(0), next(null){}
    ListNode(int x): val(x), next(null){}
    ListNode(int x, ListNode *next): val(x), next(next){}
};

class solution
{
    public:
    ListNode* oddEvenList(ListNode* head) 
    {
        if(!head || !head->next) return head;
        ListNode* evenHead = head->next;//even链表的头节点，需要后续拿来拼接到odd链末尾
        ListNode* odd = head, *even = odd->next;//两个指针分别用来指向odd节点和even节点
        while(even!=null && even->next!=null){//结束条件
            odd->next = even->next;//odd的下一个节点在even节点的后面
            odd = odd->next;//odd指向下一个节点
            even->next = odd ->next;//even节点的下一个节点在odd后面
            even = even->next;//even指向下一个节点
        }
        odd->next = evenHead;//链接两个链
        return head;//返回
    }
};

int main()
{
    ListNode * node3 = new ListNode(3);
    ListNode * node2 = new ListNode(2);
    ListNode * node1 = new ListNode(1);
    ListNode * node0 = new ListNode(0);
    node0->next = node1;
    node1->next = node2;
    node2->next = node3;
    ListNode * head;

    solution *s = new solution();
    head = s->oddEvenList(node1);

    return 0;
}