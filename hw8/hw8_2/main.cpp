#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int num;
    cin >> num;
    for(int i = 0; i < num; i++)
    {
        int arr[101][1025];
        memset(arr ,0 , 101*1025*sizeof(int));
        int group;
        cin >> group;
        for(int j = 0; j < group; j++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            if(j == 0)
            {
                arr[0][a] = 1;
                arr[0][b] = 1;
                arr[0][c] = 1;
            }
            else
            {
                for(int k = 0; k < 1025; k++)
                {
                    if(arr[j-1][k] == 0)
                        continue;
                    else
                    {
                        arr[j][k^a] = 1;
                        arr[j][k^b] = 1;
                        arr[j][k^c] = 1;
                    }
                }
            }
        }
        for(int j = 1024; j >= 0; j--)
            if(arr[group-1][j] == 1)
            {
                cout << j << endl;
                break;
            }
    }

    return 0;
}
