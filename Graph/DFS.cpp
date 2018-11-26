#include <bits/stdc++.h>
using namespace std;

int n, t;

vector<vector<int>> AdjList;
vector<int> color;
vector<int> parent;
vector<int> start;
vector<int> finish;

forward_list<int> TopoSort;

void Init()
{
    AdjList.resize(n);
    color.resize(n);
    parent.resize(n);
    start.resize(n);
    finish.resize(n);
}

void AddEdge(int u, int v)
{
    AdjList[u].push_back(v);
   // AdjList[v].push_back(u);
}

void DFS_Visit(int s)
{
    cout << s << " " << endl;
    t++;
    start[s] = t;
    color[s] = 1;
    for(auto v : AdjList[s])
    {
        if(color[v] == 2)
        {
            parent[v] = s;
            DFS_Visit(v);
        }
    }
    color[s] = 0;
    t++;
    finish[s] = t;
    TopoSort.push_front(s);
}

//Color: 0 = B (dun), 1 = G (seen but not finished), 2 = W (not discovered);
//Parent: -2 = not discovered
void DFS()
{
    for (int i = 0; i < n; i++)
    {
        color[i] = 2;
        parent[i] = -2;
    }
    t = 0;
    for (int u = 0; u < n; u++)
    {
        if(color[u] == 2)
        {
            DFS_Visit(u);
        }
    }
}

int main()
{
    n=6;
    Init();
    AddEdge(0,1);
    AddEdge(0,3);
    AddEdge(3,1);
    AddEdge(1,4);
    AddEdge(4,3);
    AddEdge(2,4);
    AddEdge(2,5);
    AddEdge(5,5);
    DFS();

}