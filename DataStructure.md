# Data Structure

## 线性表

### 单链表

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

* 单链表的删除（倒数节点+一次遍历）
  * 问题：删除单链表中的倒数第n个节点，并且只用一次循环遍历。
  * 解决方案：利用**快慢指针-间隔指针**定位要删除的节点。先让快指针和慢指针**间隔n-1个节点**（快指针先出发**走n步**，慢指针后出发），然后快慢指针同时前进，当快指针到达尾节点时，慢指针到达要被删除的节点。
  * 要点：
    * **快指针要到尾节点，或者尾节点的next（即为null）**
    * 删除节点有两种情况：1.删除中间节点，需要pre节点的信息（对应快指针到尾节点）。2.**删除头节点**（对应快指针到next）。

### 循环链表

* 循环链表：

  * 判断链表是否有环：快慢指针技巧。慢指针每次走一步，快指针每次走两步。当快慢指针相遇，即有环；当快指针为空了，即没有环。[示例](.\datastruct\CircleList.cpp)。

  * 判断链表环入口节点位置：

    思路：**快慢指针寻找相遇节点，两慢指寻找入口节点**。先用快慢指针寻找到相遇节点；再同时用**两个慢指针**分别从**相遇节点和head节点**出发，下一次相遇的即为入口节点。

    编程实现逻辑如下，[示例](.\datastruct\CircleList_2.cpp)

    1. 判断链表是否为空或者只有头节点。（是即没有环）
    2. 定义快慢指针，**都指向头节点**。
    3. 寻找相遇节点
       1. 快指针、慢指针前移
       2. 判断是否相等
    4. 判断是否有相遇节点（看fast节点是否在表中）
       1. 若是，则寻找入口节点（两慢指针同时前进）
       2. 若否，则无。

    <img src="https://pic.leetcode-cn.com/1623750708-inrvVm-1623750459597.jpg" alt="1623750459597.jpg" style="zoom: 15%;" />

### 相交链表

* 相交链表：

  * 问题：两相交链表，寻找相交节点。

  * 解决方案：**双指针，两层暴力循环**。指针1走A表，到底后转B表；指针2走B表，到底后转A表。若有相交点，中途会出现指针内容相等。若没有相交点，则最后都指向空。[实例](.\datastruct\CrossList.cpp)

  * 示意图：

    <img src="C:\Users\96919\AppData\Roaming\Typora\typora-user-images\image-20220315170202243.png" alt="image-20220315170202243" style="zoom:50%;" />

  * 要点：即使两链表没有相交点，但两次循环过后，指针1和指针2都同时走完两表，然后分别指向空（即尾节点的下一节点`tail->next`）。

