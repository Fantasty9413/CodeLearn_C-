# include <iostream>

double division(int a, int b = 1)
{
    if(b == 0)
    {
        throw "Division by zero condition!";
    }
    return (a/b);
}

int main()
{
    int x = 50;
    int y = 10;
    int z = 0;
    double *ans = new double(0);

    *ans = division(x, y);
    std::cout << "the ans is " << *ans << '\n';

    try
    {
        *ans = division(x, z);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    // *ans = division(x, z);
    // std::cout << "the ans is " << *ans << '\n';

    return 0;
}