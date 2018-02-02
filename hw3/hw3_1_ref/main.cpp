#include <iostream>
#include <cstdio>

using namespace std;

#define min(a,b) a>b? b:a

int find_kth(int a[], int b[], int size_a, int size_b, int k){
        /* to maintain uniformaty, we will assume that size_a is smaller than size_b
                else we will swap array in call :) */
        if(size_a > size_b)
                return find_kth(b, a, size_b, size_a, k);
        /* Now case when size of smaller array is 0 i.e there is no elemt in one array*/
        if(size_a == 0 && size_b >0)
                return b[k-1]; // due to zero based index
        /* case where K ==1 that means we have hit limit */
        if(k ==1)
                return min(a[0], b[0]);

        /* Now the divide and conquer part */
        int i =  min(size_a, k/2) ; // K should be less than the size of array
        int j =  min(size_b, k/2) ; // K should be less than the size of array

        if(a[i-1] > b[j-1])
                // Now we need to find only K-j th element
                return find_kth(a, b+j, i, (size_b-j)+1, k-j);
        else
                return find_kth(a+i, b, (size_a-i)+1, j,  k-i);

        return -1;
}
int main(){
        int a[] = {10,30,40,50,60};
        int b[] = {30,50,100,110, 200};

        int size_a  = sizeof(a)/sizeof(a[0]);
        int size_b  = sizeof(b)/sizeof(b[0]);

        printf("\n Kth smallest element is : %d", find_kth(a,b,size_a, size_b, 4));
        return 0;
}
