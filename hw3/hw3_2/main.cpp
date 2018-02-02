#include <iostream>
#define MAX 10000000
using namespace std;

long long int a, b, c;

long long int cal(long long int n)
{
    return (a*n*n + b*n + c) % 1000000;
}

int main()
{
    long long int num;
    cin >> num;
    for(long long int i = 0; i < num; i++)
    {
        long long int total, nth;
        long long int *f;
        f = new long long int[MAX]();

        cin >> total >> nth >> a >> b >> c;
        for(long long int j = 1; j <= total; j++)
        {
            f[cal(j)]++;
        }
        long long int accumulation = 0;
        for(long long int j = 0; j <= 1000000; j++)
        {
            accumulation += f[j];
            //cout << accumulation << endl;
            if(accumulation >= nth)
            {
                cout << j << endl;
                break;
            }
        }

        delete [] f;
    }

    return 0;
}
