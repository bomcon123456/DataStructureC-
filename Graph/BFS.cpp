#include <bits/stdc++.h>

using namespace std;

int Size;

vector<vector<int>> AdjList;
map<int, int> level;
map<int, int> parent;
vector<int> frontier;

queue<int> Q;
map<int, int> levelQ;
map<int, int> parentQ;
vector<int> frontierQ;

void AddEdge(int u, int v)
{
    AdjList[u].push_back(v);
    AdjList[v].push_back(u);
}

void BFS(int s)
{
    level[s] = 0;
    parent[s] = -1;
    //int i = 1;
    frontier.push_back(s);
    // Frontier => reachable in "i-1" moves (reached)
    while (frontier.size() > 0)
    {
        // Next => reachable in "i" moves (going to reach now)
        vector<int> next;
        for (auto u : frontier)
        {
            for (auto v : AdjList[u])
            {
                auto it = level.find(v);
                if (it == level.end())
                {
                    level[v] = level[u] + 1;
                    parent[v] = u;
                    next.push_back(v);
                }
            }
        }
        frontier = next;
    }
}

void BFSQueue(int s)
{
    for (int i = 0; i < Size; i++)
    {
        levelQ[i] = -2;
        parentQ[i] = -2;
    }
    levelQ[s] = 0;
    parentQ[s] = -1;
    Q.push(s);
    while (Q.size() > 0)
    {
        int u = Q.front();
        Q.pop();
        for (auto v : AdjList[u])
        {
            if (levelQ[v] == -2)
            {
                levelQ[v] = levelQ[u] + 1;
                parentQ[v] = u;
                Q.push(v);
            }
        }
    }
}

int main()
{
    Size = 8;
    AdjList.resize(Size);
    AddEdge(0, 1);
    AddEdge(0, 3);
    AddEdge(1, 2);
    AddEdge(3, 4);
    AddEdge(3, 5);
    AddEdge(4, 5);
    AddEdge(4, 6);
    AddEdge(5, 6);
    AddEdge(5, 7);
    AddEdge(6, 7);
    BFS(0);
    for (int i = 0; i < Size; i++)
    {
        cout << "Vertex: " << i << " has level: " << level[i] << endl;
        cout << "Parent of " << i << " is: " << parent[i] << endl;
    }
    cout <<endl <<endl;
    BFSQueue(0);
    for (int i = 0; i < Size; i++)
    {
        cout << "Vertex: " << i << " has level: " << levelQ[i] << endl;
        cout << "Parent of " << i << " is: " << parentQ[i] << endl;
    }
}