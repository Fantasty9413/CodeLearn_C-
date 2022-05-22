# include <iostream>
# define null nullptr


class MyLinkedList {
public:
    struct node
    {
        int val;
        node *next;
        node(int x):val(x),next(null){}
    };

    MyLinkedList() {
        head = new node(0);
        size = 0;
    }
    
    int get(int index) {
        if((index<0)||(index>size-1))
        {
            return -1;
        }
        node *cur = head;
        while(index--)
        {
            cur = cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        node *newnode = new node(val);
        newnode->next = head->next;
        head->next = newnode;
        size++;
    }
    
    void addAtTail(int val) {
        node *newnode = new node(val);
        node *cur = head;
        int i = size;
        while(i--)      // 寻找尾节点
        {
            cur = cur->next;
        }
        cur->next = newnode;
        newnode->next = null;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        node *cur = head;
        node *pre = head;
        node *next = null;
        node *newnode = new node(val);
        if(index<=0)
        {
            newnode->next = head;
            head = newnode;
            size = size + 1;
        }
        else if(index >size)
        {
            int i = size;
            while(i--)      // 寻找尾节点
            {
                cur = cur->next;
            }
            cur->next = newnode;
            newnode->next = null;
            size = size + 1;
        }
        else
        {
            int i = index-1;
            while(i--)      // 寻找pre和next节点
            {
                pre = pre->next;
            }
            cur = pre->next;
            newnode->next = cur;
            pre->next = newnode;
            size = size + 1;
        }
    }
    
    void deleteAtIndex(int index) {
        node *cur = head;
        node *pre = head;
        node *next = null;
        if(index<0)
        {
            return;
        }
        if(index==0)
        {
            cur = head->next;
            delete head;
            head = cur;
            size = size - 1;
        }
        else if(index==size)
        {
            int i = size-1;
            while(i--)      // 寻找倒数第二节点
            {
                pre = pre->next;
            }
            cur = pre->next;
            delete cur;
            pre->next = null;
            size = size-1;
        }
        else if(index>size)
        {
            return;
        }
        else
        {
            int i = index-1;
            while(i--)      // 寻找pre和next节点
            {
                pre = pre->next;
            }
            cur = pre->next;
            next = cur->next;
            pre->next = next;
            delete cur;
            size = size - 1;
        }        
    }
    friend std::ostream &operator<<(std::ostream &out, const MyLinkedList &list)
    {
        int i = list.size + 1;
        node *cur = list.head;
        out << "the list is : ";
        while(i--)
        {
            out << cur->val << " ";
            cur = cur->next;
        }
        out << std::endl;
        return out;
    }

private:
    int size;
    node *head;
};

int main()
{
    MyLinkedList *_list =  new MyLinkedList();
    _list->addAtHead(1);
    _list->addAtTail(3);
    _list->addAtIndex(1, 2);
    std::cout << *_list;
    _list->deleteAtIndex(1);
    std::cout << *_list;

    return 0;
}