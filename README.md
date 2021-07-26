# CodeLearn_C-
the learning repository of C++

record learning process of C++

## 1.class

* string类

    提供查询是否为空、查询长度和查询特定字符等方法。
    
    其中查询字符方法稍复杂。
    
    ```c++
    string str = "This is a str for testing find function.";
    string str_find = "str";
    str.find(str_find,15);		//从index15处开始查找
    str.find("str",10,3);		//从index10处开始查找"str"的前3个字符，不能用str_find变量代替"str"
    str.refind()		//倒叙查找
    str.find_last_of()		//查找最后以一个
    ```
    **下标是从0开始。**

    string类的其他**基本方法**：删除(erase)、插入(insert)、替换(swap)、延长(append)、交换(swap)和提取子字符串(substr)。

    其中前面个几种方法都是直接改变当前对象的值，只有`substr`不会改变当前对象的属性，而是返回一个新的对象。

    **如何查看当前方法的返回值：**
    
    将鼠标放在方法的函数名上，查看详细注释（同时也可查看输入参数等信息）。若返回值是`Reference to this string`，则就是改变对象属性直接返回；若返回值是`The new string`，则返回新对象。

    [参考](https://www.cnblogs.com/tyner/p/11010895.html)

* vector

    类似于数组，可以变长度。

    **迭代器(iterator)**：类似于指针，可以指向容器中的元素.

    `c.begin()`和`c.end()`分别返回指向vector第一个元素的迭代器和指向vector**最后一个元素**的下一个位置的迭代器。

    迭代器的操作**和指针类似**，可以定义，也可以自加。利用迭代器的移动可以输出整个容器的元素。

    ```C++
    vector<int>::iterator p2;       // 定义迭代器
    p2 = number.begin();            // 指向头元素
    while(p2 != number.end())
    {
        cout << *p2 <<' ';
        p2 ++;                      // 移动到下一元素
    }
    cout << endl;
    ```

    加上`reverse`后可以实现反向迭代器，即从vector的尾部实现上述操作。
    
    方法变为`c.rbegin()`和`c.rend()`，定义变为`vector<int>::reverse_iterator rp; `。

    `auto`：自动类型推断。可以用于代替冗长复杂的命名；在定义模板函数时，用于声明依赖模板参数的变量类型。

    **插入与删除：(插前删后)**

    `iterator insert(iterator it, int n, const T& x)`插入元素。**插入位置在当前迭代器指向元素之前**。**且迭代器位置会指向到新增的第一个元素**。

    插入至尾部：`v.push_back()`；插入至其他位置：`v.insert()`。

    `iterator erase(iterator it)`删除元素。删除位置为当前迭代器指向元素。**删除后迭代器指向删除元素之后的第一个元素**。

    `iterator erase(iterator first,iterator last)`删除向量的[first,last)间的元素。last指向的元素不删，**且迭代器更新后指向last**。

    **vector操作表：**

    |操作类型|方法|备注|
    |:---:|:---:|:---:|
    | 增 | **`insert()`** | 除开尾部，可以插至任意位置(前插)，要用迭代器 |
    |  | `push_back()` | 尾部插入 |
    | 删 | **`erase()`** | 删除任意位置的元素（迭代器后移） |
    |  | `pop_back` | 尾部删除 |
    |  | `clear()` | 删除所有元素 |
    | 改 | **`at()`** | 更改指定位置的元素的值 |
    |  | `front()` | 更改头部元素 |
    |  | `back()` | 更改尾部元素 |
    |  | `assig()` | 指定位置赋值，会覆盖原向量，**适合用于初始化** |
    | 查 |  | **借助迭代器`iterator`**，可正向，可反向 |
    |  | `empty()` | 是否为空 |

* list

    * 迭代器

    迭代器生成指向指定元素后，再改变list，不会影响迭代器指向的元素的位置。

    ```c++
        auto p2 = num2.begin();     // p2指向list的头元素
        num2.push_front(100);       // list的头元素增加为100，p2指向原元素，相当于新list的第二个元素
    ```

    list的迭代器只定义了++和--操作，不能实现+和-的操作；而vector的迭代器可以＋和-操作。

    其原因是因为**两者支持的迭代器类别不同**，vector支持的是随机访问迭代器；list支持的是双向迭代器。前者所重载的运算符远多于后者，具体参考[迭代器的类别与区别](https://www.cnblogs.com/fenglongyu/p/7699645.html)。

    **移动list的迭代器**使用`advance(it, n)`函数。


    ## 2.其他

* Template模板

        模板就是实现**代码重用机制**的一种工具，它可以实现类型参数化，即把类型定义为参数， 从而实现了真正的代码可重用性。
        
        模版可以分为两类，一个是函数模版，另外一个是类模版。

     * 函数模板：

        ```C++
            Template <class或者也可以用typename T>
            返回类型 函数名（形参表）
            {//函数定义体 }
            template<typename T> void swap(T &a, T &b) 
            {
                 T tmp{a}; 
                 a = b;
                 b = tmp;
            }
        ```

     * 类模板

        ```C++
            Template < class或者也可以用typename T > class类名
            {
                // 类定义
            }
        ```
