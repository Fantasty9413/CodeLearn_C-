# include <iostream>
# define null nullptr

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(): val(0), next(null){};
    ListNode(int x): val(x), next(null){};
    ListNode(int x, ListNode *next): val(x), next(next){};
};

class solution
{
    public:
    ListNode* reverseList(ListNode* head)
    {
        if(head==null || head->next==null)      // 只有头节点
        {
            return head;
        }

        ListNode* fakehead = new ListNode(-1, head);
        ListNode* pre = head;
        ListNode* cur = head->next;
        while(cur!=null)
        {
            pre->next = cur->next;
            cur->next = fakehead->next;
            fakehead->next = cur;
            // pre = pre->next;
            cur = pre->next;
        }
        return fakehead->next;
    }
};