#include<bits/stdc++.h>
using namespace std;

int graph[105][105];

bool bfs(int start,int stop,int parent[],int node)
{
    bool vis[node]={false};
    queue<int>nxt ; nxt.push(start);
    vis[start] = 1;parent[start]=-1;

    while(!nxt.empty())
    {
        int u = nxt.front();nxt.pop();
        for(int v = 0;v<node;v++)
        {
            if(!vis[v] and graph[u][v]>0)
            {
                vis[v] = 1;
                nxt.push(v);
                parent[v] = u;
            }
        }
    }
    return vis[stop];
}
int fordFulkerson(int start,int stop,int node)
{
    int parent[node];
    int flow = 0;

    while(bfs(start,stop,parent,node))
    {
        int pathFlow = INT_MAX;

        for(int u = stop;u!=start;u = parent[u])
        {
            pathFlow = min(pathFlow,graph[parent[u]][u]);
        }

        for(int u = stop;u!=start;u = parent[u])
        {
            graph[parent[u]][u] -= pathFlow;
            graph[u][parent[u]] += pathFlow;
        }
        flow += pathFlow;
    }
    return flow;
}
int main()
{
    int node,edge;
    cin >> node >> edge;
    for(int i=0;i<edge;i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        graph[u][v] = w;
    }
    int start,stop;
    cin >> start >> stop;
    cout<<fordFulkerson(start,stop,node)<<endl;
}
