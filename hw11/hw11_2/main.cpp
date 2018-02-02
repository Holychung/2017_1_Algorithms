#include <iostream>
#include <cstdlib>
#define _ ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int cmp( const void *a , const void *b )
{
    return ( *(int*)b - *(int*)a );
}

int main()
{
    int n;
    int num_family, num_desk;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> num_family >> num_desk;
        bool ans = 1;
        int family[num_family] = {0}, desk[num_desk] = {0};
        for(int j = 0; j < num_family; j++)
            cin >> family[j];
        for(int j = 0; j < num_desk; j++)
            cin >> desk[j];

        for(int j = 0; j < num_family; j++)
        {
            qsort(desk, num_desk, sizeof(int), cmp);
            if(family[j] > num_desk)
            {
                ans = 0;
                break;
            }
            for(int k = 0; k < family[j]; k++)
            {
                desk[k]--;
                if(desk[k] < 0)
                    ans = 0;
            }
            if(!ans)  break;
        }
        if(ans)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
