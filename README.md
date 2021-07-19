# CodeLearn_C-
the learning repository of C++

record learning process of C++

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
    
    [参考](https://www.cnblogs.com/tyner/p/11010895.html)