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

class Solution {
public:
    bool isPalindrome(ListNode* head) 
    {
        if(head==null || head->next==null)
        {return true;}

        ListNode *slow = head; ListNode *fast = head;
        ListNode *reverse = null;
        while(true)     // 反转链表
        {
            fast = fast->next->next;
            ListNode *next = slow->next;
            slow->next = reverse;
            reverse = slow;
            slow =next;
            if(fast==null)           // 偶数个节点
            {
                break;
            }
            if(fast->next==null)  // 奇数个节点
            {
                slow = slow->next;
                break;
            }
        }

        while(slow!=null)
        {
            if(reverse->val!=slow->val)
            {return false;}
            slow = slow->next;
            reverse = reverse->next;
        }
        return true;
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

    Solution *s = new Solution();
    bool flag = s->isPalindrome(node0);

    return 0;
}