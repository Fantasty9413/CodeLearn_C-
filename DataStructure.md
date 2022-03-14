# Data Structure

## 线性表

* 单链表的节点的典型定义：

  ```c++
  // Definition for singly-linked list.
  struct SinglyListNode {
      int val;
      SinglyListNode *next;
      SinglyListNode(int x) : val(x), next(NULL) {}
  };
  ```

* 单链表的插入：

  * 过程：1.创建新节点cur 2.cur指向next 3.prev指向cur。一句话概括：让新来的节点有指向。
  * 复杂度：时间复杂度O（1）

  ![image-20220314203840940](C:\Users\96919\AppData\Roaming\Typora\typora-user-images\image-20220314203840940.png)

* 单链表的删除：

  * 过程：1.找到cur节点 2.pre指向next
  * 复杂度：时间复杂度O(N)，空间复杂度O（1）。

  ![image-20220314204341452](C:\Users\96919\AppData\Roaming\Typora\typora-user-images\image-20220314204341452.png)

* 技巧：

  * 定位至第i个节点

    ```c++
    node *cur = head;
    while(i--)
    {
    	cur = cur->next;
    }
    ```

