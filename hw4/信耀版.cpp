#include <iostream>
#define mod 100000

using namespace std;

struct node
{
    long long int value;
    long long int ct = 1; //count 同value的數量
    node* next = 0;
};

int find_key(long long int a) //負數%後還是負的
{
    int key = a%mod;
    while(key < 0)
        key += mod;
    return key;
}

long long int find_pair(long long int n , long long int k)
{
    node* table[mod] = {0};
    node* temp;
    long long int i,j,pairs = 0;
    long long int key_i, key_j;
    for(int a = 0;a < n;a++)
    {
        cin >> j;
        i = k - j;
        key_i = find_key(i);
        key_j = find_key(j);
        ///////////////////////// 找map裡符合 i+j=k的值
        temp = table[key_i];
        while(temp != 0)
        {
            if(temp->value == i)pairs+= temp->ct;
            temp = temp->next;
        }
        /////////////////////// 存j進去map
        if(table[key_j] == 0)
        {
            table[key_j] = new node;
            table[key_j]->value = j;
        }
        else
        {
            temp = table[key_j];
            while(temp->next != 0 && temp->value != j)
            {
                temp = temp->next;
            }
            if(temp->value == j)  //同value count++
                temp->ct++;
            else  //沒有同value   在尾端新增node
            {
            temp->next = new node;
            temp->next->value = j;
            }
        }
    }
    return pairs;
}

int main()
{
    long long int times,n,k;
    cin >> times;
    for(int i = 0;i < times;i++)
    {
        cin >> n >> k;
        cout << find_pair(n,k) << endl;
    }
    return 0;
}
