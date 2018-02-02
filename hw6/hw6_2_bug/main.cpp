#include <iostream>
#include <algorithm>

using namespace std;

int find_longest_subseq(int arr_num)
{
    int longest = 0;
    int arr[arr_num][2];
    for(int i = 0; i < arr_num; i++)
    {
        cin >> arr[i][0];
        arr[i][1] = 1;
    }

    for(int i = arr_num - 1; i >= 0; i--)
    {
        int index = i+1;
        while(index < arr_num)
        {
            if(arr[index][0] >= arr[i][0])
                arr[i][1] = max( arr[i][1] , 1 + arr[index][1] );
            longest = max(longest, arr[i][1]);
            index++;
        }
    }
    return longest;
}

int main()
{
    int num;
    cin >> num;
    for(int i = 0; i < num; i++)
    {
        int arr_num;
        cin >> arr_num;
        cout << find_longest_subseq(arr_num) << endl;
    }

    return 0;
}
