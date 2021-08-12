# CodeLearn_C-
the learning repository of C++

record learning process of C++

## 0.basic

* 引用（reference）

    类似于别名，与指针相似。可以将引用当成是变量在内存中的第二个标签，**对变量的引用进行操作就等于对变量本身就行操作**。

    引用的特性（引用与指针的区别）
    1. 引用必须在创建时被初始化。（指针可以任何时候被初始化）
    2. 不能存在空应用，引用必须连接到一块合法的内存上。（指针可以为空）
    3. 引用绑定到一个对象上后，就不可以指向或者切换绑定到另外的对象上了。（指针可以切换指向）

    引用作为函数返回值：

* 动态内存：

    * 创建对象：

    | 操作 | 描述 | 操作 | 描述 |
    | :---: | :---: | :---: | :---: |
    | `class obj` | ✔：创建对象，调用默认构造函数 | `int i` | ✔：初值为0 |
    | `class obj()` | ❌：函数声明，返回值为class，参数为void | `int i()` | ❌:函数声明 |
    | `class obj(arg)` | ✔：创建对象，调用带参构造函数 | `int i(arg)` | ❌：初值为0，arg无效 |
    | `class obj = obj2` | ✔ | `int i = arg` | ✔：常用 |

    对象的创立一般采用`class obj`和`class obj(arg)`；一般变量的创立采用`int i`和`int i = arg`。

    * 利用`new`关键字进行内存分配：

    `class* pc = NULL`、`int* pi = NULL`

     | 操作 | 描述 | 操作 | 描述 |
    | :---: | :---: | :---: | :---: |
    | `pc = new class` | ✔：分配内存，创建对象，调用默认构造函数 | `pi = new int` | ❌：初值无效，只分配内存 |
    | `pc = new class()` | ✔：同上 | `pi = new int()` | ✔:初值为0 |
    | `pc = new class(arg)` | ✔：同上 | `pi = new int(arg)` | ✔：同左 |

    对于对象，由于存在默认构造函数，因此分配内存后，类似于自动创建对象。
    对于一般变量，若不指定初值（不带括号），则只分配内存，不创建对象。

    **最安全保险的方法**：先分配内存，再进行一次绑定（赋值或者初始化）。

    * 数组的动态内存分配：`int* p = new int[10];`。分配一个长度为10的存放int型数据的内存，起始地址为`p`。**区分和`int* p = new int(10);`的区别**。

    * 分配和删除的关键字：`new`和`delete`。
    ```c++
        int* p1 = new int(10);
        int* p2 = new int[10];

        delete p1;
        delete[] p2;
    ```

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

## 2.STL

* vector

    连续存储结构。

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

    **capacity**与**size**。前者是vector的容量，和vector的空间分配机制有关系（1，2，4，8，总是分配之前两倍大小的空间）。后者是现存元素的大小。

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

    非连续存储结构。

    * 迭代器

    迭代器生成指向指定元素后，再改变list，不会影响迭代器指向的元素的位置。

    ```c++
        auto p2 = num2.begin();     // p2指向list的头元素
        num2.push_front(100);       // list的头元素增加为100，p2指向原元素，相当于新list的第二个元素
    ```

    list的迭代器只定义了++和--操作，不能实现+和-的操作；而vector的迭代器可以＋和-操作。

    其原因是因为**两者支持的迭代器类别不同**，vector支持的是随机访问迭代器；list支持的是双向迭代器。前者所重载的运算符远多于后者，具体参考[迭代器的类别与区别](https://www.cnblogs.com/fenglongyu/p/7699645.html)。

    再深层次的原因是两者的**空间分配机制不同**。
    
    vector分配的空间是连续的。当就空间满载时，会分配原来大小两倍的空间，并将原空间的内容移动到新空间，因此vector最好提前分配空间以提升效率。vector随机存储效率高，插入效率低，因此不提供push_front()方法。而list的空间是不可以不连续的，这样方便高效率的进行插入、删除等操作。

    **移动list的迭代器**使用`advance(it, n)`函数。

    * 合并list

    `l1.merge(l2)`：直接合并l1和l2两个list，**合并后l2变为空**。

    `splice`：可以理解为merge的升级版。起可以指定合并出入至l1的位置；还可以指定需要被合并的list的起始位置。l2中被合并的元素也会为空（相当于是内存上的移动）。

    ```c++
        list<int> l1, l2;
        auto it1 = l1.begin();
        auto it2_s = l2.begin(), it2_e = l2.end();
        l1.splice(it1, l2, it2_s, it2_e);
    ```

* deque

    连续存储结构（假象连续空间），由几块大空间连接而成，每块大空间内部连续，大空间之间不连续，随时可以新增一段空间链接至原空间。也因此需要一块map来作为主控管理空间地址。

    一种双开口数据结构。

    迭代器：当容器大小发生变化后，**最安全的方法是认为原来的迭代器已失效**，重新赋值使用。

    `insert`与迭代器：

    insert(iterator it,const T& x)与insert(iterator it,int n,const T& x)的插入本身不会迭代器的相对位置，只改变绝对位置（前插元素，**迭代器的index后移，但指向的元素不变**）。而insert函数本身是带返回值的，其返回值是一个迭代器，这个**迭代器指向当前插入元素的第一个元素**。

    当然，有时也不一定会有返回值，还是写的时候要多看**函数的description**。

    `erase`与迭代器：

    erase(iterator it)实现删除，删除完成后，it指向被删除位置之前的元素；返回值指向被删除元素之后的元素。

    erase(iterator it, iterator last)实现删除，删除完成后，it指向**被删除的第一个元素(?)**；返回值指向被删除元素之后的元素。**(还是认为它失效稳妥些)**

    **总结：**

    |操作类型|方法|备注|
    |:---:|:---:|:---:|
    | 增 | **`insert()`** | 前插，有多种重载 |
    |  | `push_front()` | 头部插入 |
    |  | `push_back()` | 尾部插入 |
    | 删 | **`erase()`** | 有多种重载 |
    |  | `pop_front` | 头部删除 |
    |  | `pop_back` | 尾部删除 |
    |  | `clear()` | 删除所有元素 |
    | 改 | **`at()`** | 更改或者返回指定位置的元素的值 |
    |  | `front()` | 更改头部元素 |
    |  | `back()` | 更改尾部元素 |
    |  | `assig()` | 指定位置赋值，会覆盖原向量，**适合用于初始化** |
    |  | `swap()` | 交换 |
    | 查 |  | **借助迭代器`iterator`**，可正向，可反向 |
    |  | `empty()` | 是否为空 |
    | 其他 | `size()` | 元素个数 |
    |  | `max_size()` | 最大值 |

* stack
  
    **顶入顶出**。

    先进后出（First In Last Out， FILO）。**不允许有遍历行为（也没有迭代器）**，即只能对顶部元素进行操作（新增、移除和读写栈顶元素）。

    stack**基于既有容器形成底部结构**，如双端数据结构deque和list。其只修改接口，因此又被称为adapter（配接器）。

    |操作类型|方法|备注|
    |:---:|:---:|:---:|
    | 增 | `push()` | 入顶 |
    | 删 | `pop()` | 出顶，**没有返回值** |
    | 改 | `top()` | 更改或者返回指定位置的元素的值 |
    | 查 | `empty()` |  |
    | 其他 | `size()` | 元素个数 |

 * queue
  
    **底入顶出**：底（`push()`和`back()`）;顶（`pop()`和`front()`）。

    先进后出（First In First Out， FILO）。**不允许有遍历行为（也没有迭代器）**，即只能对**两端元素**进行操作（底部新增、顶部移除和读写两端元素）。

    queue**基于既有容器形成底部结构**，如双端数据结构deque和list。其只修改接口，因此又被称为adapter（配接器）。

    |操作类型|方法|备注|
    |:---:|:---:|:---:|
    | 增 | `push()` | 入底 |
    | 删 | `pop()` | 出顶，**没有返回值** |
    | 改 | `front()` | 读写**顶部**元素 |
    |  | `back()` | 读写**底部**元素 |
    | 查 | `empty()` |  |
    | 其他 | `size()` | 元素个数 |   

## 3.对象

* 类：public、private、protect

    定义成员时不写访问修饰符默认**private**。

    * 不同位置对不同类型的成员的访问权限：

      | 位置\成员类型 | public | protected | private |
      | :---: | :---: | :---: | :---: |
      | （当前）类 | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |
      | 派生类 | :heavy_check_mark: | :heavy_check_mark: | :x: |
      | 外部或其他类 | :heavy_check_mark: | :x: | :x: |

* 成员函数

* 构造与析构函数：
  
    * 构造函数：用于初始化或者进行初步计算，创建新对象时自动执行。

        1. 没有返回值类型（也不返回void）
        2. 函数名称与类名相同
        3. 可以带参数（用于给对象赋值）
        4. 可以带初始化列表来初始化字段
        5. 可以重载

    * 析构函数：用于跳出程序时关闭文件或释放内存，删除对象时自动执行。

        1. 没有返回值类型（也不返回void）
        2. 函数名称为'~'+类名
        3. 不能带参数

    * 拷贝构造函数：一类特殊的构造函数。
  
        主要用于：

        1. 通过使用另一个同类型的对象来初始化新创建的对象。例子：类的成员中带动态内存分配时的初初始化。
        2. 复制对象把它作为参数传递给函数。例子：带动态内存分配时的传值调用
        3. 复制对象，并从函数返回这个对象。

        其特点：

        1. 返回值和名称同普通构造函数，参数一般为`(const classname &obj)`。
        2. 如果类带有指针变量，并有动态内存分配，则它必须有一个拷贝构造函数。

* 友元函数：一种定义在**外部或者其他类**的函数（不是成员函数），可以访问当前类的私有和保护成员。

    * 友元函数没有this指针，参数主要有三种情况

        1. 要访问非static成员时，需要对象做参数；
        2. 要访问static成员或全局变量时，则不需要对象做参数；
        3. 如果做参数的对象是全局对象，则不需要对象做参数；

* 友元类：整个类及其成员都是友元。

* 静态成员：属于类的属性。static作为关键字，只存在一个副本。

    * 静态变量：静态成员变量要在类外面进行初始化（要用范围解析运算符::）。

        * 一般用于：

            1. 创建对象时数量自增。
            2. 由友元函数和静态函数访问。

    * 静态函数：可以将函数与类的特定对象独立开来，静态函数使用类名加::即可访问（在类对象不存在的情况下也可访问）。

        * 一般用于：

            1. 获取静态变量的值。

        * **注意**：

            1. 静态成员函数没有this指针，因此其不能访问除静态成员之外的数据和函数。

* 默认参数：

    默认参数不能同时在声明和实现中定义。只能单独在其中一个地方定义。定义默认参数时一般将其位于参数表**右部**。

    一般将默认参数定义在声明中， 原因是定义在实现中的话，用户通常看不见，而且不方便修改。

* this指针：

    用于访问成员变量或者成员函数，即调用对象。**本质是一个地址**。

    只有成员函数才有this指针（即在成员函数中才能用this指针），**友元函数不是类的成员，不能调用this指针**。

    ```c++
        class* class::getaddress()
        {
            return this;        // 返回地址
        }

        int main()
        {
            class c;
            class* p = c.getaddress();      // 定义指针
            p->function();                  // 指针调用
        }
    ```

    指针加->也可调用成员，相当于对象+.的操作。

* 继承(Inherit)

    * 作用：提高代码的重用性贺提高执行效率。

    * 定义：基类(base-class)和派生类(derived-class)。

    ```c++
        class derived-class: access-specifier base-class
        {
            ...
        }
    ```

    * 继承后，**派生类（基于派生类的视角来看）**的成员属性对应表：

      | 继承方式\成员类型 | public | protected | private | 关系变化概括 |
      | :---: | :---: | :---: | :---: | :---: |
      | public | public | protected | 无法访问 | 基类的非私有成员在派生类的属性不变 |
      | protected | protected | protected | 无法访问 | 基类的非私有成员在派生类变为protected |
      | private | private | private | 无法访问 | 基类的非私有成员在派生类变为private |

      无法访问：继承后的private成员其属性还是基类的private，还是私有（按照访问权限表，其只能在基类内部被访问，其他位置都不能访问），所以在一定程度上可以理解为它没被继承，即private成员**不能也没有**被继承。   

    * 派生类不会继承的内容：
        1. 基类的构造函数、析构函数和拷贝构造函数。**虽然没有继承， 但是会被调用**，具体规则见[参考](https://www.cnblogs.com/bonelee/p/5825885.html)。
        2. 基类的重载运算符。
        3. 基类的友元函数。（不是类的成员）

    * 多继承：
    ```c++
        class <派生类名>:<继承方式1><基类名1>,<继承方式2><基类名2>,…
        {
        <派生类类体>
        };
    ```

    * 构造函数：派生类继承基类后，可以在派生类的构造函数中调用基类的构造函数来实现赋初值。（可以配合参数列表使用）
    ```c++
        class Animal
        {
            public:
            Animal(int x, int y);
        }
        
        class Dog: public Animal
        {
            public:
            Dog(int x, int y, int z);
        }
        Dog::Dog(int x, int y, int z)Animal(x, y), z(z){}
    ```
    

* 重载

    * 函数重载：参数个数、类型或者顺序不同。不可以**只有返回值不同**。

    * 运算符重载

        1. 可以作为成员函数也可作为普通函数，定义如下。参数**必须为引用**（？），函数名为operator加运算符的符号，返回值为对象。
        ```c++
            class class::operator+ (const class& obj);
            class operator+ (const class& obj1, const class& obj2);
        ```

        1. 不可重载的运算符：`.`、`->`、`::`、`sizeof`、`?:`和`#`。

* 多态

    多态：概括说就是“一个接口，多种方法”。。

    原理：一般情况下，是静态多态，即在编译器**编译时就确定了对象调用的函数地址**（称为早绑定）。实现动态多态后，可以实现**程序运行时才决定调用机制**的功能（称为迟绑定）。

    实现：**虚函数**。在基类中声明虚函数，关键字`virtual`（基类中声明virtual后，子类中就不用声明了）。

    使用情形：使用基类定义了指针，指针指向了派生类对象的引用，通过指针实现成员调用。
    ```c++
        class Shape
        {
            virtual int getarea();
        }

        class Rectangle: public Shape
        {
            int gerarea();
        }

        class Triangle: public Shape
        {
            int gerarea();
        }        

        int main()
        {
            Shape* shape;
            shape = new Rectangle();
            shape->getarea();
            shape = new Triangle();
            shape->getarea();           
        }
    ```

    纯虚函数：没有具体功能和实现的虚函数，只是实现一个接口，进行一个形式上的定义，以达到规范的作用。
    ```c++
        virtual int getarea() = 0;
    ```

* 数据抽象：一种仅向用户暴露接口而把具体的实现细节隐藏起来的机制。

* 数据封装：一种把数据和操作数据的函数捆绑在一起的机制。

* 接口与抽象类

    * 接口：描述了类的行为和功能，而不需要完成类的特定实现。

    * C++的接口是使用抽象类来实现的，抽象类与数据抽象互不混淆。

    * 抽象类：如果类中至少有一个函数被声明为**纯虚函数**，则这个类就是抽象类。抽象类的设计目的是为其他类提供一个可以继承的合适的基类。

      抽象类只能作为接口使用，不可以用于实例化对象，否则会导致编译错误。

      与之相对应的是可以实例化对象的类：**具体类**。

    * 设计策略：定义一个抽象基类（提供合适的、通用的、标准化的接口），派生类通过继承抽象基类实现各种操作。


## 4.其他

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
