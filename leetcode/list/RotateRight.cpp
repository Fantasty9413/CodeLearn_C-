# define null nullptr

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution
{
public:
    ListNode* rotateRight(ListNode* head, int k)
    {
        if(head==null)
        {return head;}

        // 寻找尾节点并获取链表长度
        ListNode *cur = head;
        int ListLength = 1;
        while(cur->next!=null)
        {
            ListLength ++;
            cur = cur->next;
        }
        // 链表成环
        cur->next = head;
        // 链表断开
        ListNode *pre = head;       // 断开处的前节点
        k = k%ListLength;
        for(int i=0; i<ListLength-k-1; i++)   // 定位至断开处
        {pre = pre->next;}
        cur = pre->next;
        pre->next = null;                     // 断开连接
        return cur;
    }
};