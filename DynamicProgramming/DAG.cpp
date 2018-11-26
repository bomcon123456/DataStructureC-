#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef map<int, int> mii;
typedef vector<int> vi;

int n;
vector<vii> AdjWeightedList;

int memo[101][101];

void Init()
{
    n = 7;
    AdjWeightedList.resize(n);
    memset(memo, -1, sizeof memo);
}

void AddEdge(int u, int v, int w)
{
    AdjWeightedList[u].push_back({v, w});
}

vii Find(int v)
{
    vii res;
    for(int i = 0;i<n;i++)
    {
        for(auto u : AdjWeightedList[i])
        {
            if(u.first == v)
                res.push_back({i,u.second});
        }
    }
    return res;
}

/////
int DP(int s, int f)
{
    if (memo[s][f] != -1)
        return memo[s][f];
    if (s == f)
        return memo[s][f] = 0;
    auto arr = Find(f);
    int r = 99999999;
    for(auto i : arr)
    {
        r = min(r, DP(s,i.first) + i.second);
    }
    return memo[s][f] = r;
}

int main()
{
    Init();
    AddEdge(0, 1, 7);
    AddEdge(0, 2, 3);
    AddEdge(0, 3, 1);
    AddEdge(1, 2, 6);
    AddEdge(2, 3, 2);
    AddEdge(3, 4, 1);
    AddEdge(3, 5, 9);
    AddEdge(4, 6, 3);
    AddEdge(5, 6, 7);
    cout << DP(4,6) << endl;
}