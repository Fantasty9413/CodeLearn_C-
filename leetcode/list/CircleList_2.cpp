/*
    问题：环形链表，给定一个链表的头节点head，判断链表中环的位置。
    解决方案：快慢指针寻找相遇节点，两慢指寻找入口节点。
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
    ListNode *detectCycle(ListNode *head)
    {
        if((head==null)||(head->next==null))        // 头节点为空或者头节点指向空
        {
            return null;
        }

        ListNode *fast = head;
        ListNode *low = head;
        while((fast!=null)&&(fast->next!=null))     // 寻找是否有快慢指针相遇点（不管相遇否都会退出循环）
        {
            fast = fast->next->next;
            low = low->next;
            if(fast==low)                           // 相遇即有环
            {
                break;
            }
        }

        if((fast!=null)&&(fast->next!=null))        // 判断是否有相遇节点
        {
            low = head;
            while(low!=fast)                        // 寻找相遇节点
            {
                low = low->next;
                fast = fast->next;
            }
            return low;
        }
        else
        {
            return null;
        }

    }
};