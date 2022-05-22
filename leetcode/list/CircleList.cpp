/*
    问题：环形链表，给定一个链表的头节点head，判断链表中是否有环。
    解决方案：快慢指针。
        慢指针每次走一步，快指针每次走两步。如果相遇说明有环，如果快指针为空了说明没有环。
    状态：Accpted
*/

# include <iostream>
# define null nullptr

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(null){}
};

class Solution
{
    public:
    bool hasCycle(ListNode *head)
    {
        if((head==null)||(head->next==null))    // 先判断是否未空链表或者只有一个节点
        {
            return false;
        }
        ListNode *fast = head->next;
        ListNode *low = head;
        while((fast!=null)&&(fast->next!=null)) // 快慢指针相比较，快指针为空即无环
        {
            if(fast==low)                       // 快指针相遇即有环
            {
                return true;
            }
            fast = fast->next->next;
            low = low->next;
        }
        return false;
    }
};