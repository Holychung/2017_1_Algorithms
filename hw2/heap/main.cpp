#include <iostream>

using namespace std;

void maxHeapify(int A[], int i, int heapsize){
    int l = i*2;
    int r = i*2 + 1;
    int largest = i;
    if(l <= heapsize && A[l] > A[i])
        largest = l;
    if(r <= heapsize && A[r] > A[largest])
        largest = r;
    if(largest != i)
    {
        //cout << "swap: " << i << " " << largest << endl;
        //exchange A[i] and A[largest];
        int temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        maxHeapify(A, largest, heapsize);
    }
}

int main()
{
    int A[2000] = {0};
    int heapsize;
    cin >> heapsize;
    int totalnum = heapsize;

    for(int i = 0; i < heapsize; i++)
        cin >> A[i+1];

    for(int i = heapsize/2; i >= 1; i--)
        maxHeapify(A, i, heapsize);

    for(int i = 0; i < heapsize; i++)
        cout << A[i+1] << " ";

        cout << endl;

    for(int i = heapsize; i >= 2; i--){
        //exchange A[1] and A[i]
        int temp = A[1];
        A[1] = A[i];
        A[i] = temp;
        heapsize = heapsize - 1;
        maxHeapify(A, 1, heapsize);
    }

    for(int i = 0; i < totalnum; i++)
        cout << A[i+1] << " ";


    return 0;
}
