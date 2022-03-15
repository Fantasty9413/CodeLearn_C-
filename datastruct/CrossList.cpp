/*
    问题：相交连边，寻找相交节点。
    解决方案：双指针，两层暴力循环。
        指针1走A表，到底后转B表；指针2走B表，到底后转A表。
        若有相交点，中途会出现指针内容相等。若没有相交点，则最后都指向空。
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *List_A = headA, *List_B = headB;
        if((List_A==null)||(List_B==null))
        {
            return null;
        }

        while(List_A != List_B)     // 重点：变轨后走完两条链表，两指针都必定指向空
        {
            List_A = List_A==null ? headB : List_A->next;
            List_B = List_B==null ? headA : List_B->next;
        }

        return List_A;
    }
};