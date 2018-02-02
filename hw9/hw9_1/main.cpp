#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;

struct Node{
    // 0 is whit,e 1 is gray, 2 is black
    int color = 0;
    Node *tail = NULL; // point to the last node for faster insert
    Node *next = NULL;
    int data = 0;
};

void create_graph(Node people[], int a, int b)
{
    Node *now = &people[a];
    if(now->tail != NULL)
        now = now->tail;
    now->data = b;
    now->next = new Node;
    people[a].tail = now->next;

    return;
}

void DFS_visit(Node people[], int i, int &ct)
{
    Node *current = &people[i];
    people[i].color = 1;
    while(current->next != NULL)
    {
        int next = current->data;
        if(people[next].color == 0)
        {
            ct++;
            DFS_visit(people, next, ct);
        }
        current = current->next;
    }
    return;
}

int main()
{
    int n_people, m_pairs;

    scanf("%d %d", &n_people, &m_pairs);
    Node *people;
    people = new Node[n_people+1];

    for(int i = 0; i < m_pairs; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);

        create_graph(people, a, b);
        create_graph(people, b, a);
    }

    int maxx = 0;
    for(int i = 1; i <= n_people; i++)
    {
        int ct = 1; // count
        if(people[i].color == 0){
            DFS_visit(people, i, ct);
            maxx = max(maxx, ct);
        }
    }
    cout << maxx << endl;

    return 0;
}
