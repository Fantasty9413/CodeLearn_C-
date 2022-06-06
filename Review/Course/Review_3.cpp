# include <iostream>

void _strcpy(char* p, char* q)
{
    while(*p != NULL)
    {
        *q = *p;
        q++;
        p++;
    }
}

int main()
{
    char p[20] = "afdahlajhg";
    char q[20] = "";
    _strcpy(p, q);
    std::cout << q << std::endl;

    return 0;
}