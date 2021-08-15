# include <iostream>

# define Len 10

class Signal
{
    protected:
    double *p;      // data

    public:
    Signal();
    Signal(double* data);
    Signal(const Signal &obj);
    void displaydata();
};

Signal::Signal()
{
    p = new double[10];
}

Signal::Signal(double* data)
{
    // p = data;
    p = new double[10];
    int index = 0;
    while(index < 10)
    {
        p[index] = data[index];
        index++;
    }
}

Signal::Signal(const Signal &obj)
{
    p = new double[Len];
    *p = *obj.p;
}

void Signal::displaydata()
{
    int index = 0;
    while(index < Len)
    {
        std::cout << p[index] << " ";
        index++;
    }
    std::cout << '\n';
}

class Computation
{
    public:
    virtual double getmean() = 0;
};

class Mysignal: public Signal, public Computation
{
    public:
    Mysignal();
    Mysignal(double *data);
    double getmean();
};

Mysignal::Mysignal():Signal(){}

Mysignal::Mysignal(double *data):Signal(data){}

double Mysignal::getmean()
{
    double sum = 0;
    int index = 0;
    while(index < Len)
    {
        sum += p[index];
        index++;
    }
    return sum/Len;
}

int main()
{
    double *data = new double[Len];
    int index = 0;
    while(index < Len)
    {
        data[index] = index;
        index++;
    }

    // std::cout << *data << '\n';

    // index = 0;
    // while(index < Len)
    // {
    //     std::cout << data[index] << " ";
    //     index++;
    // }

    Signal signal(data);
    signal.displaydata();

    data[0] = 10;
    signal.displaydata();

    Mysignal ms(data);
    std::cout << "mean: " << ms.getmean()  << '\n';

    ms.displaydata();

    return 0;
}
