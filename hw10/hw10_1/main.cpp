#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

int n_vertice = 0, m_edge = 0;
int dset[100005];

struct Edge{
    int index;
    int a;
    int b;
    int w;
    bool mark = false;
};

int cmp( const void *a , const void *b )
{
    Edge *c = (Edge *)a;
    Edge *d = (Edge *)b;
    return ( c->w - d->w);
}

void init(void)
{
    for(int i = 0; i < 100005; i++)
        dset[i] = i;
}

int find(int x)
{
    return x == dset[x] ? x : (dset[x] = find(dset[x]));
}

void union_set(int x, int y)
{
    dset[find(x)] = find(y);
}

void Kruskal(Edge e[])
{
    int k;
    int A[m_edge];
    for(int i = 0; i < m_edge; i++)
    {
        A[i] = 0;
    }

    for(int j = 0; j < m_edge-1; j++)
    {
        while(find(e[j].a) == find(e[j].b))
        {
            j++;
            if(j>=m_edge)
                break;
        }
        if(j>=m_edge)
            break;

        A[j] = 1;
        k=j;

        while(j < m_edge-1)
        {
            if(e[j].w == e[j+1].w)
            {
                if(find(e[j+1].a) != find(e[j+1].b))
                {
                    A[j+1] = 1;
                }
                j++;
            }
            else break;
        }

        for(; k <= j; k++)
        {
            if(A[k] == 1)
            {
                union_set(e[k].a, e[k].b);
                e[e[k].index].mark = true;
            }
        }
    }
}

int main()
{
    cin >> n_vertice >> m_edge;

    Edge edge[m_edge];
    init();

    // read file
    for(int i = 0; i < m_edge; i++)
    {
        int a,b;
        edge[i].index = i;
        cin >> a >> b >> edge[i].w;
        edge[i].a = a-1;
        edge[i].b = b-1;
    }

    qsort(edge, m_edge, sizeof(Edge), cmp);

    Kruskal(edge);

    for(int i = 0; i < m_edge; i++)
    {
        if(edge[i].mark)
            cout << "at least one" << endl;
        else
            cout << "none" << endl;
    }

    return 0;
}
