# include <iostream>
# define null nullptr

class MyLinkedList {
public:
    struct listnode
    {
        int val;
        listnode *pre;
        listnode *next;
        listnode(): val(0), pre(null), next(null){}
        listnode(int x): val(x), pre(null), next(null){}
        listnode(int x, listnode *pre, listnode *next): val(x), pre(pre), next(next){}
    };
    
    MyLinkedList() 
    {
        head = new listnode();
        length = 0;
    }
    
    int get(int index) 
    {
        if(index<0||index>=length)
        {
            return -1;
        }

        int i = 0;
        listnode *cur =head;
        while(i<index)
        {cur=cur->next; i++;}
        return cur->val;
    }
    
    void addAtHead(int val) 
    {
        if(length==0)
        {
            head->val=val;
            length=length+1;
            return;
        }

        listnode *cur = new listnode(val);
        cur->next = head;
        head->pre = cur;
        head = cur;
        length = length + 1;
    }
    
    void addAtTail(int val) 
    {
        if(length==0)
        {
            head->val=val;
            length=length+1;
            return;
        }
        else
        {
            listnode *cur = new listnode(val);
            listnode *tail = head;
            while(tail->next != null)
            {tail = tail->next;}
            tail->next = cur;
            cur->pre = tail;
            length = length + 1;
            return;
        }
    }
    
    void addAtIndex(int index, int val)     // 前插
    {
        if(index<0||index>length)
        {return;}
        if (index==0)
        {
            addAtHead(val);
            return;
        }
        else if(index==length)
        {
            addAtTail(val);
            return;
        }
        else
        {
            // 定位至next节点
            listnode *next = head;
            int i = 0;
            while(i<index)
            {next = next->next; i++;}
            
            // 前插
            listnode *cur = new listnode(val);
            cur->next = next;
            cur->pre = next->pre;
            next->pre->next = cur;
            next->pre = cur;

            //表长+1
            length = length + 1;
            return;
        }
    }
    
    void deleteAtIndex(int index) 
    {
        if(index<0 || index >=length)
        {return;}

        // 删除头节点
        if(index==0)
        {
            if(length==1)       // 只有头节点
            {delete head; head=null; length--; return;}
            head = head->next;
            delete head->pre;
            head->pre=null;
            length = length - 1;
            return;
        }  
        // 删除其他节点
        int i = 0;
        listnode *pre = head;
        while(i<index-1)
        {
            pre = pre->next;
            i++;
        }
        
        pre->next = pre->next->next;
        if(pre->next!=null)    // 删除尾节点
        {
            delete pre->next->pre;
            pre->next->pre = pre;
        }

        // 表长+1    
        length = length - 1;
    }

private:
    listnode *head;
    int length;    
};

int main()
{
    MyLinkedList *list = new MyLinkedList();
    list->addAtHead(1);
    list->addAtTail(3);
    list->addAtIndex(1, 2);
    list->deleteAtIndex(1);
    list->deleteAtIndex(0);

    return 0;
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */