#include <iostream>
#define mod 100000

using namespace std;

struct node
{
    long long int value;
    long long int ct = 1; //count �Pvalue���ƶq
    node* next = 0;
};

int find_key(long long int a) //�t��%���٬O�t��
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
        ///////////////////////// ��map�̲ŦX i+j=k����
        temp = table[key_i];
        while(temp != 0)
        {
            if(temp->value == i)pairs+= temp->ct;
            temp = temp->next;
        }
        /////////////////////// �sj�i�hmap
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
            if(temp->value == j)  //�Pvalue count++
                temp->ct++;
            else  //�S���Pvalue   �b���ݷs�Wnode
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
