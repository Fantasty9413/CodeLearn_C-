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
    ListNode* addTwoNumbers(ListNode* list1, ListNode* list2)
    {
        ListNode* answer = new ListNode(0, null);
        ListNode *l1 = list1;
        ListNode *l2 = list2;
        ListNode *cur = answer;
        int sum = 0;    // 和数
        int flag = 0;   // 进位标志
        while(l1!=null || l2!=null || flag!=0)      // 进位不为0时继续添加节点
        {
            sum = 0;
            if(l1!=null)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2!=null)
            {
                sum += l2->val;
                l2 = l2->next;
            }

            sum += flag;
            flag = sum/10;  // 先获取进位标志
            sum = sum%10;   // 再改动和数
            cur->next = new ListNode(sum, null);
            cur = cur->next;
        }
        return answer->next;
    }
};