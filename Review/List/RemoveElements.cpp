// leetcode -- 203

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr){}
    ListNode(int x): val(x), next(nullptr){}
};

class Solution 
{
    public:
    ListNode* removeElements(ListNode* head, int val) 
    {
        // ListNode* fakehead;                  // ！错误写法
        ListNode* fakehead = new ListNode();    // ！新的虚拟节点必须新创建（new一个），然后指针指向这个节点。
        fakehead->next = head;
        ListNode* pre = fakehead;
        ListNode* cur = head;
        while(cur!=nullptr)
        {
            // cur->val == val; 删除
            if(cur->val == val)
            {
                pre->next = cur->next;
                delete cur;
                cur = pre->next;
            }
            // cur->val != val; 不删除
            else if(cur->val != val)
            {
                pre = cur;
                cur = pre->next;
            }
        }
        return fakehead->next;
    }
};