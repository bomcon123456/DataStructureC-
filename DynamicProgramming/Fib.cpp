#include <bits/stdc++.h>
using namespace std;

int memo[100];
int dp(int n)
{
    if (memo[n] != -1)
        return memo[n];
    if (n <= 2)
        return memo[n] = 1;
    return memo[n] = dp(n - 1) + dp(n - 2);
}
int BottomUpFib(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (i <= 2)
        {
            memo[i] = 1;
        }
        memo[i] = memo[i - 1] + memo[i - 2];
    }
    return memo[n];
}

int main()
{
    memset(memo, -1, sizeof memo);
    //cout << dp(6) << endl;
    BottomUpFib(6);
    return 0;
}