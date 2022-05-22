# include <iostream>
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)   // 递归算法
    {
        if(list1==null)
        {return list2;}
        if(list2==null)
        {return list1;}

        if(list1->val < list2->val)
        {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else
        {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};