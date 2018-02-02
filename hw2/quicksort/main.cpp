#include <iostream>

using namespace std;

int count = 0;

int Partition(long long int A[], int p, int r);

void Quicksort(long long int A[], int p, int r){
	if(p < r)
    {
		int q = Partition(A, p, r);		/* divide */
		Quicksort(A, p, q-1);		/* conquer */
		Quicksort(A, q+1, r);		/* conquer */
    }
}

int Partition(long long int A[], int p, int r){
	int i = p-1;
	for(int j = p; j < r; j++)
    {
        if( A[j] <= A[r] )
        {/* comparison of elements of A*/
		 	i = i+1;
			//exchange A[i] and A[j]
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
	//exchange A[i+1] and A[r]
	if( (i+1) == r || i == (p-1) )
        count++;
	int temp = A[i+1];
    A[i+1] = A[r];
    A[r] = temp;
	return i+1;
}


int main()
{
    int num;
    cin >> num;
    for(int i = 0; i < num; i++)
    {
        int len;
        long long int A[2000] = {0};
        cin >> len;

        //read file
        for(int j = 0; j < len; j++)
            cin >> A[j];

        //quick sort
        Quicksort(A, 0, len-1);

        //count is for worst case judgment
        if(count == len-1)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;

        //reset count
        count = 0;

        //print answer
        for(int k = 0; k < len; k++)
            cout << A[k] << " ";
        cout << endl;
    }

    return 0;
}
