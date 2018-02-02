#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <algorithm>

using namespace std;

int V, E, ques;

int w[1001][1001];
int dist[1001];
int wdist[1001];
int ans[1001];

vector<vector<int> > edge;

struct Q{
    int a;
    int b;
    int i;
};

int cmp( const void *a , const void *b )
{
    Q *c = (Q *)a;
    Q *d = (Q *)b;
    return ( c->a - d->a);
}

class Node{
private:
    int index;
    int dist;
public:
    Node(int i, int d)
    {
        index = i;
        dist = d;
    }
    int get_index() const{ return index; }
    int get_dist() const{ return dist; }
};

// Determine min priority queue
bool operator<(const Node &a, const Node &b)
{
    return a.get_dist() > b.get_dist();
}

void init(void)
{
    edge.resize(V+1);
    for(int i = 0; i <= V; i++)
        for(int j = 0; j <= V; j++)
            w[i][j] = 1e9;
    for(int i = 1; i <= V; i++)
        edge[0].push_back(i);
}

void bellman_ford(int source)
{
    for (int i = 0; i <= V; i++)
    {
        // super origin initialize
        wdist[i] = 0;
        w[0][i] = 0;
    }

    for(int i = 0; i < V; i++)
        for(int a = 1; a <= V; a++)
            for(int b = 0; b < edge[i].size(); b++)
                if (wdist[a] + w[a][edge[i][b]] < wdist[edge[i][b]])
                    wdist[edge[i][b]] = wdist[a] + w[a][edge[i][b]];

    /*for(int i = 0; i <= V; i++)
        cout << "w: " << wdist[i] << " ";*/
}

void reweighing(void)
{
    for(int i = 1; i <= V; i++)
        for(int j = 1; j <= V; j++)
        {
            if(w[i][j] != 1e9)
            {
                w[i][j] += wdist[i] - wdist[j]; // reweighing
                //cout << "w: " << "ij: " << i << " " << j << " " << w[i][j] << endl;
            }
        }
    /*cout << endl;
    for(int i = 0; i <= V; i++)
    {
        for(int j = 0; j <= V; j++)
            cout << w[i][j] << " " ;
        cout << endl;
    }*/
}

void dijkstra(int source)
{
    priority_queue<Node> pq;
    bool visited[V+1] = {false};

    // initialize
    for (int i = 1; i <= V; i++)
        dist[i] = 1e9;
    dist[source] = 0;

    // create priority queue
    for (int i = 1; i <= V; i++)
    {
        if(i == source)
        {
            Node temp(source, 0);
            pq.push(temp);
        }
        else
        {
            Node temp(i, 1e9);
            pq.push(temp);
        }
    }

    for (int k = 1; k <= V; k++)
    {
        int a = pq.top().get_index();
        pq.pop();
        if(visited[a])
        {
            k--;
            continue;
        }
        else
            visited[a] = true;

        for(int i = 0; i < edge[a].size(); i++)
        {
            int b = edge[a][i];
            if(dist[a] + w[a][b] < dist[b])
            {
                // relax ab edge
                dist[b] = dist[a] + w[a][b];
                // update distance
                Node temp(b, dist[b]);
                pq.push(temp);
            }
        }
    }
}

int shortest_path(int a, int b)
{
    int sum = 0;
    sum = dist[b] + wdist[b] - wdist[a];    // reweighing

    return sum;
}

void input(int a, int b, int c)
{
    edge[a].push_back(b);
    w[a][b] = c;
}

void cal_ans(Q question[])
{
    for(int i = 0; i < ques; i++)
    {
        //cout << "a b: " << question[i].a << " " << question[i].b << " " << shortest_path(question[i].a, question[i].b) << endl;
        if(i > 0 && question[i].a == question[i-1].a)
        {
            if(dist[question[i].b] == 1e9)
                ans[question[i].i] = 1e9;
            else
            {
                int sum = shortest_path(question[i].a, question[i].b);
                ans[question[i].i] = sum;
            }
        }
        else
        {
            dijkstra(question[i].a);
            if(dist[question[i].b] == 1e9)
                ans[question[i].i] = 1e9;
            else
            {
                int sum = shortest_path(question[i].a, question[i].b);
                ans[question[i].i] = sum;
            }
        }
    }
}

int main()
{
    scanf("%d %d %d", &V, &E, &ques);
    init();
    for(int i = 0; i < E; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        input(a, b, c);
    }
    bellman_ford(0);
    reweighing();

    Q question[ques];
    for(int i = 0; i < ques; i++)
    {
        scanf("%d %d", &question[i].a, &question[i].b);
        question[i].i = i;
    }

    qsort(question, ques, sizeof(Q), cmp);
    cal_ans(question);

    for(int i = 0; i < ques; i++)
        if(ans[i] == 1e9)
            cout << "no path" << endl;
        else
            cout << ans[i] << endl;
    return 0;
}
