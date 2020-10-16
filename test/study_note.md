## class_20	数组    10.12

### 1.获取数组长度

```C++
int arr[5] = {1, 2, 3, 4, 5};
int len = sizeof(arr)/sizeof(arr[0]);
```
利用*sizeof*函数获取数组长度。但是**只能用在main函数中**，因为当数组名作为地址传入子函数时只传入了首地址，无法获得整个数组的信息。

## class_22	地址与指针  10.11

### 1.传值、传址与传引用

指针就是一种保存地址的变量类型，本质还是地址。

```c++
void swap_pointer(int* pa, int* pb)		//传指针调用，传址
{  
    int temp;
    temp = *pa;
    *pa = *pb;
    *pb = temp;
}

swap_pointer(&a, &b);	
```

传指针调用，又名传址（因此调用函数时实参是地址值），是一种特殊的传值调用，只不过传的是地址，按照指针进行操作。



```c++
void swap_reference(int& a, int& b)   //传引用
{  
    int temp;
    temp = a;
    a = b;
    b = temp;
}

swap_reference(a, b);
```

传引用调用，是传址调用的升级版，本质上也是传的地址。但函数调用是只用直接输变量，其原因是**传引用调用可以看作“封装”了的，其可以避免对地址的直接操作从而造成地址改变或丢失等问题**。这也是传引用调用相对于传地址调用的优点。



另外，C++自带了库函数*swap*，因此函数命名时要避免重名。

```C++
    swap(a, b)		//自带库函数
```

---

### 2.函数返回多变量

当函数需要返回多个变量值或结果时，考虑使用传址调用。

```C++
void get_min_max(int arr[], int* max_v, int* min_v, int len)
{
    int i =0;
    * max_v = 0;
    * min_v = 0;
    
    while(i < len)
    {
        arr[i] > *max_v ? *max_v = arr[i] : 0;
        arr[i] < *min_v ? *min_v = arr[i] : 0;
        i++;
    }

}
```

## class_23	数组与指针  10.12
```C++
    int num[5] = {0, 1. 2, 3, 4};
    int* p1;
    P1 = num;
    int* p2 = &num[0];
```

数组名就是地址，可以给指针直接赋值,之后指针名和数组名就一样了。唯一的区别是数组名不可被改变，其本质是个常量指针。

```C++
    int* const num;     //常量指针
    num++       //错误，num为常量
```

因为存在地址名不可变动的约束，但又要实现数组标号后移，就需要使用指针代替数组名。

```C++
    //实现字符串copy
    char str1[50] = {0};
    char str2[] = "I Love u";

    char* p1 = str1;
    char* p2 = str2;
    while(*p2 != '\0')
    {
        *(p1++) = *(p2++);
        // p1++;
        // p2++;
    }
```

数组元素的4种调用方式：
```C++
    int num[100] = {1, 2, 3, 4};
    int* pnum = num;
    num[1] = 0;     //下标法
    pnum[1] = 0;
    *(num+1) = 1;   //指针法
    *(pnum+1) = 1;
```

## class_25 结构体与指针    10.16
```C++
    void set_num(student *stu)
    {
        static int stunum = 101;
        stu++ ->num = stunum++;
        // (*stu++).num = stunum++;
    }
```

子函数需要多次计数时，可用*static*定义静态变量。

结构体成员调用元素时使用'.'符号，结构体指针调用时使用'->'符号。




