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
    ListNode* removeElements(ListNode* head, int val)
    {
        if(head==null)
        {return null;}

        ListNode* pre = head;
        ListNode* cur = head->next;

        while (cur!=null)       // 非头节点
        {
            if(cur->val==val)
            {
                pre->next = cur->next;
                delete cur;
                // pre = pre->next;
                cur = pre->next;
            }
            else
            {
                pre = pre->next;
                cur = pre->next;
            }
        }
        
        if(head->val==val)
        {
            pre = head;
            head = pre->next;
            delete pre;
        }
        return head;
    }

    ListNode* removeElements_2(ListNode* head, int val)
    {
        ListNode* fakehead = new ListNode(val+1, head);
        ListNode* pre = fakehead;
        ListNode* cur = pre->next;

        while(cur!=null)
        {
            if(cur->val==val)
            {
                pre->next = cur->next;
                delete cur;
                cur = pre->next;
            }
            else
            {
                pre = pre->next;
                cur = pre->next;
            }
        }

        return fakehead->next;
    }
};