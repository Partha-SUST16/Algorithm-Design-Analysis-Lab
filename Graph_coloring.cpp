#include<bits/stdc++.h>
using namespace std;
#define BLOCK -1
vector<int>graph[20];
int color[20][20];
bool vis[20];

void graph_color(int node)
{
    int selectd = -1;

    for(int i=0;i<node;i++)
    {
        vis[i] = 1;

        for(int j=0;j<node;j++)
        {
            if(color[i][j]!=BLOCK)
            {
                selectd = j;
                printf("node %d colored with: %d\n",i,selectd);
                break;
            }
        }

        for(int j : graph[i])
        {
            if(!vis[j])
            {
                color[j][selectd] = BLOCK;
                printf("\t Node %d blocked for %d\n", j, selectd); // print that block

            }
        }
    }
}
int main()
{
    int nodes, edges; // declare nodes and edges
    cin >> nodes >> edges; // define values from user input

    // input adjacent nodes from user
    for(int i=0, n1, n2; i<edges; i++){
        cin >> n1 >> n2;
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }

    graph_color(nodes);
}
