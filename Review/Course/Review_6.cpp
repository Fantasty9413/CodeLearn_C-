# include <iostream>
# include <string>
# include <algorithm>

int main()
{
    std::string str1;
    std::string str_find;

    std::cout << "please input the str: " << std::endl;
    std::cin >> str1;

    std::cout << "please input the str_find: " << std::endl;
    std::cin >> str_find;

    std::cout << "the first postion of str_find is " << str1.find(str_find) << std::endl;

    std::cout << "length of str1 is " << str1.size() << std::endl;

    return 0;
}