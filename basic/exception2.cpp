# include <iostream>
# include <exception>

struct Myexception: public std::exception
{
    const char * what () const throw ()
    {
        return "C++ Exception";
    }
};


int main()
{
    try
    {
        throw Myexception();
    }
    catch(Myexception& e)
    {
        std::cout << "Myexception caughted" << '\n';
        std::cerr << e.what() << '\n';
    }
    catch(const std::exception& e)
    {
        std::cout << "exception caughted" << '\n';
        std::cerr << e.what() << '\n';
    }


    return 0;
}