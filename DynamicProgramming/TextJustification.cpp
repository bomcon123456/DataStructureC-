#include <bits/stdc++.h>
using namespace std;
#define oo 1e9

vector<string> wordList;
int lineWidth = 100;
int n;

float memo[1001];
vector<int> parent;

void Init()
{
    for(int i=0;i<1002;i++)
    {
        memo[i] = -1.0f;
    }
    freopen("text.txt","r",stdin);
    string test;
    getline(cin,test);
    stringstream ss;
    ss << test;
    string lol;
    while (ss >> lol)
    {
        wordList.push_back(lol);
    }
    n = wordList.size();
    parent.resize(n);
}

float badness(int i, int j)
{
    if (i == j)
        return 0;
    int spaces = j - i - 1;
    int width = spaces;
    for (int k = i; k < j; k++)
    {
        width += wordList[k].size();
    }
    if (width > lineWidth)
    {
        return (float)oo;
    }
    else
    {
        return pow(lineWidth - width, 3);
    }
}

double DP(int i)
{
    if (memo[i] != -1.0f)
    {
        return memo[i];
    }
    if (i == n)
        return 0;
    float res = oo;
    for (int j = i + 1; j <= n; j++)
    {
        float x = DP(j) + badness(i, j);
        //cout << x << endl;
        if (res > x)
        {
            res = x;
            parent[i] = j;
        }
    }
    return memo[i] = res;
}

int main()
{
    Init();
    DP(0);
    int k = 0;
    for(int i = 0 ;i<n;i++)
    {
        cout << wordList[i] << " ";
        if(i==parent[k])
        {
            cout << endl;
            k = parent[k];
        }
    }
    cout << endl;
}
