#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int V, E;
vector<int> adj[100005];
vector<int> rev_adj[100005];
bool visit[10005] = {false};
vector<int> finish;          // DFS leaving ordering
int contract[100005];        // for contract
int tm = 0; // time

struct Scc{
    int p = -1;
    int num = 0;
    vector<int> vec;
}scc[100005];

void DFS1(int i)
{
    if (visit[i])
        return;
    visit[i] = true;
    for (int j = 0; j < adj[i].size(); j++)
        DFS1(adj[i][j]);

    finish.push_back(i);
}

void DFS2(int i, int p)
{
    if (visit[i])
        return;
    visit[i] = true;
    for (int j = 0; j < rev_adj[i].size(); j++)
        DFS2(rev_adj[i][j], p);     // reverse edges
    contract[i] = p;                // contract to p

    // record every point in every SCC
    for(int j = 0; j < V; j++)
    {
        // new SCC
        if(scc[j].p == -1)
        {
            scc[j].p = p;
            scc[j].num++;
            scc[j].vec.push_back(i);
            break;
        }
        // already has the SCC
        else if(p == scc[j].p)
        {
            scc[j].num++;
            scc[j].vec.push_back(i);
            break;
        }
    }
}

void DFS3(int i)
{
    if(visit[i])
        return;
    tm = tm + 1;
    visit[i] = true;
    for (int j = 0; j < adj[i].size(); j++)
        DFS3(adj[i][j]);
    tm = tm + 1;
}

void init(void)
{
    for(int i = 0; i < 100005; i++)
    {
        adj[i].clear();
        rev_adj[i].clear();
    }
    finish.clear();
    memset(contract, 0, 100005);
    memset(visit, false, sizeof(visit));
}

void kosaraju()
{
    for (int i = 1; i <= V; i++)
        DFS1(i);
    memset(visit, false, sizeof(visit));
    for (int i = V; i > 0; i--)
        DFS2(finish[i-1], finish[i-1]);
}

int main()
{
    int times;
    cin >> times;
    for(int i = 0; i < times; i++)
    {
        init();
        cin >> V >> E;
        for(int j = 0; j < E; j++)
        {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            rev_adj[b].push_back(a);
        }
        kosaraju();

        int num_origin = 0;
        for(int j = 0; scc[j].p != -1 ;j++)
        {
            tm = 0; // time  = 0
            memset(visit, false, sizeof(visit));
            DFS3(scc[j].p);

            if(tm == 2*V)   // if time = 2*vertex , it's an origin
            {
                num_origin+=scc[j].num;
                break;
            }
        }
        cout << num_origin << endl;

        // reset SCC
        for(int j = 0; j < 100005; j++)
        {
            scc[j].p = -1;
            scc[j].num = 0;
            scc[j].vec.clear();
        }

        /*cout << "contract: ";
        for(int j = 1; j <= V; j++)
        {
            cout << contract[j] << " ";
        }
        cout << endl;*/
        /*cout << "finish: ";
        for(int j = 0; j < V; j++)
        {
            cout << finish[j] << " ";
        }
        cout << endl;*/
    }

    return 0;
}
