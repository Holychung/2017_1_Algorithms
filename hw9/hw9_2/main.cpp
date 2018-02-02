#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;

int total_cost = 0;
int maxx = 0;
int cost[10001] = {0};

struct Node{
    // 0 is whit,e 1 is gray, 2 is black
    int color = 0;
    Node *tail = NULL; // point to the last node for faster insert
    Node *next = NULL;
    int data = 0;
};

void create_graph(Node pts[], int a, int b)
{
    Node *now = &pts[a];
    if(now->tail != NULL)
        now = now->tail;
    now->data = b;
    now->next = new Node;
    pts[a].tail = now->next;

    return;
}

void DFS_visit(Node pts[], int i)
{
    Node *current = &pts[i];

    while(current->next != NULL)
    {
        int next = current->data;
        if(pts[next].color == 0)
        {
            pts[next].color = 1;
            total_cost += cost[next];
            DFS_visit(pts, next);
            total_cost -= cost[next];
        }
        current = current->next;
    }
    maxx = max(maxx, total_cost);
    return;
}

int main()
{
    int n_pts;

    scanf("%d", &n_pts);
    Node *pts;
    pts = new Node[n_pts+1];

    for(int i = 1; i <= n_pts; i++)
        cin >> cost[i];
    for(int i = 0; i < n_pts-1; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);

        create_graph(pts, a, b);
        create_graph(pts, b, a);
    }

    pts[1].color = 1;
    total_cost += cost[1];
    DFS_visit(pts, 1);

    cout << maxx << endl;

    return 0;
}
