#include <iostream>
#include <cstdio>
#include <math.h>
#include <cstdlib>

#define MAX 100003

using namespace std;

struct Node{
    Node *next = 0;
    long long int data;
    long long int count = 1;
};

long long int find_hash(long long int k, long long int sum)
{
    Node *arr[MAX] = {0};   // hash table
    Node *temp;
    long long int total_count = 0;

    for(long long int i = 0; i < k; i++)
    {
        long long int def;  // default value
        cin >> def;
        long long int key = abs(def) % MAX;  // key_def
        long long int implememt = sum - def;
        long long int key_i = abs(implememt) % MAX;  // key_implement

        temp = arr[key_i];

        // first, find the implement if exist in hash table
        while(temp != 0)
        {
            if(temp -> data == implememt)
                total_count += temp -> count;
                temp = temp -> next;
        }

        // if the node is empty, new node and save data in hash table
        if(arr[key] == 0){
            arr[key] = new Node;
            arr[key] -> data = def;
        }else{
            // create a chaining node tree
            temp = arr[key];
            while(temp -> next != 0 && temp -> data != def )
            {
                temp = temp -> next;
            }
            // one condition is the same value in the hash table, count++
            if(temp -> data == def)
                temp -> count++;
            // the other is new node
            else{
                temp -> next = new Node;
                temp -> next -> data = def;
            }
        }
    }
    return total_count;
}

int main()
{
    long long int num, k, sum;
    cin >> num;
    for(long long int i = 0; i < num; i++)
    {
        cin >> k >> sum;
        cout << find_hash(k, sum) << endl;
    }
    return 0;
}
