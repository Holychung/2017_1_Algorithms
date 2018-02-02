#include <iostream>
#include <cstdlib>
using namespace std;

long long int min(long long int a, long long int b)
{
    return a > b ? b : a;
}

long long int c, d, e, x, y, z;

long long int cal_a(int a)
{
    return c*a*a + d*a + e;
}

long long int cal_b(int b)
{
    return x*b*b + y*b + z;
}

long long int find_kth(long long int a_left, long long int a_right, long long int b_left, long long int b_right, long long int k)
{
    long long int size_a = a_right - a_left + 1;
    long long int size_b = b_right - b_left + 1;

    //array a is empty
    if(size_a == 0 && size_b > 0)
        return cal_b(k-1);
    if(size_b == 0 && size_a > 0)
        return cal_a(k-1);

    if(k == 1)
        return min( cal_a(a_left) ,cal_b(b_left) );

    long long int i = min(size_a, k/2);
    long long int j = min(size_b, k/2);

    if( cal_a(a_left+i-1) > cal_b(b_left+j-1) )
        return find_kth(a_left, a_left+i, b_left+j, b_right, k-j);
    else
        return find_kth(a_left+i, a_right, b_left, b_left+j, k-i);

    return -1;
}


int main()
{
    long long int num;
    long long int kth;
    cin >> num;
    for(int i = 0; i < num; i++)
    {
        cin >> c >> d >> e >> x >> y >> z;
        cin >> kth;
        cout << find_kth(0, kth-1, 0, kth-1 ,kth) << endl;
    }
    return 0;
}
