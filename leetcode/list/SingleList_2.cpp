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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* fast = head;
        ListNode* low = head;

        for(int i=0; i<n; i++)      // 快指针走n步
        {fast = fast->next;}

        while(fast!=null && fast->next != null)   // 定位至pre节点或头节点
        {
            low = low->next;
            fast = fast->next;
        }

        if(fast==null){head = head->next;}        // 删除头节点
        else{low->next = low->next->next;}        // 删除中间节点
        return head;
    }
};
