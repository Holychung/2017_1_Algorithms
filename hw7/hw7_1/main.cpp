#include <iostream>

using namespace std;

int main()
{
    int num, len, m;
    cin >> num;
    char str[1000];
    for(int i = 0; i < num; i++)
    {
        cin >> len >> m >> str;
        int temp = 0, num = 0;
        for(int j = 0; j < len; j++)
        {
            temp = (10*temp + str[j]-48) % m;
            if(temp == 0)
            {
                num++;
                temp = 0;
            }
        }
        cout << num << endl;
    }
    return 0;
}
