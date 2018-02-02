#include <iostream>

using namespace std;

struct Job{
    long double day;
    long double penalty;
    long double slope;
    int index;
};

int Partition(Job A[], int p, int r);

void Quicksort(Job A[], int p, int r){
	if(p < r)
    {
		int q = Partition(A, p, r);		/* divide */
		Quicksort(A, p, q-1);		/* conquer */
		Quicksort(A, q+1, r);		/* conquer */
    }
}

int Partition(Job A[], int p, int r){
	int i = p-1;
	for(int j = p; j < r; j++)
    {
        if( A[j].slope <= A[r].slope )
        {/* comparison of elements of A*/
		 	i = i+1;
			//exchange A[i] and A[j]
            Job temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
	//exchange A[i+1] and A[r]
	Job temp = A[i+1];
    A[i+1] = A[r];
    A[r] = temp;

	return i+1;
}


int main()
{
    int times;
    cin >> times;
    for(int i = 0; i < times; i++)
    {
        long long int num, total_penalty = 0;
        Job job[10000];
        cin >> num;
        for(int j = 0; j < num; j++)
        {
            cin >> job[j].day;
            job[j].index = j+1; // index
        }
        for(int j = 0; j < num; j++)
        {
            cin >> job[j].penalty;
            job[j].slope = job[j].penalty / job[j].day;
            total_penalty += job[j].penalty;
        }
        Quicksort(job, 0, num-1);

        long long int sum = 0;
        for(int j = num-1; j >= 0; j--)
        {
            total_penalty -= job[j].penalty;
            sum += total_penalty * job[j].day;
        }
        cout << sum << endl;

        for(int j = num-1; j >= 0; j--)
            if(j == 0)
                cout << job[j].index << endl;
            else
                cout << job[j].index << " ";
    }

    return 0;
}
