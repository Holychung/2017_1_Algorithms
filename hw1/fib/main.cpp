#include <iostream>

using namespace std;

void fib(long long int n,long long int *ptr);

int main()
{
    int times;
    cin >> times;


    for(int i = 0; i < times; i++)
    {
        long long int arr[3];
        long long int *ptr = arr;
        long long int a;
        cin >> a;
        fib(a, ptr);
        cout << ptr[1] % 29989 << endl;
    }
    return 0;
}

void fib(long long int n, long long int *ptr){

    if(n <= 1)
    {
        ptr[2] = 1;
        ptr[1] = 1;
        ptr[0] = 0;
    }
    else if(n == 2)
    {
        ptr[2] = 2;
        ptr[1] = 1;
        ptr[0] = 1;
    }
    else
    {
        if( n % 2 == 0) // °¸¼Æ
        {
            fib(n/2, ptr);

            long long int temp0 = ptr[0] % 29989;
            long long int temp1 = ptr[1] % 29989;
            long long int temp2 = ptr[2] % 29989;
            ptr[2] = temp2*temp2 + temp1*temp1;
            ptr[1] = temp1*temp2 + temp1*temp0;
            ptr[0] = temp1*temp1 + temp0*temp0;
        }
        else    //©_¼Æ
        {
            fib( (n-1)/2 , ptr);

            long long int temp0 = ptr[0] % 29989;
            long long int temp1 = ptr[1] % 29989;
            long long int temp2 = ptr[2] % 29989;
            ptr[2] = temp2*temp2 + 2*temp1*temp2;
            ptr[1] = temp2*temp2 + temp1*temp1;
            ptr[0] = temp1*temp2 + temp0*temp1;
        }
    }
}

