#include <iostream>
using namespace std;

void get_min_max(int arr[], int* max_v, int* min_v, int len = 5)
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

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int len = sizeof(arr)/sizeof(arr[0]);

    int max = 0;
    int min = 0;

    get_min_max(arr, &max, &min);

    cout<<"max ="<<max<<endl;
    cout<<"min ="<<min<<endl;

    return 0;

}