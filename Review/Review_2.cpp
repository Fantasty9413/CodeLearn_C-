# include <iostream>

double NumericalCalculation_e(int iter)
{
    double e = 0;
    double temp = 1;
    for(int i=0; i<iter; i++)
    {
        e = e + temp;
        temp = temp / (i+1);
    }
    return e;
}

int main()
{
    int iter = 1000;
    double e = NumericalCalculation_e(iter);
    std::cout << "iter = " << iter << ", " << "the result is " << e << "." << std::endl;

    return 0;
}