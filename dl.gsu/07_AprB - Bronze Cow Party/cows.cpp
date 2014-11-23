#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

#define INF ((1<<21)-1)

int main()
{
    freopen("bparty.in", "r", stdin); freopen("bparty.out", "w", stdout);
    int n, m, s;
    cin >> n >> m >> s;
    vector<long > d(n+1, INF);
    vector<vector<long> > a(n+1, vector<long>(n+1, INF));
    vector<bool> f(n + 1, false);
    long x, y, z;
    for(int i = 1; i <= m; i++)
    {
        scanf("%ld %ld %ld", &x, &y, &z);
        if(a[x][y] == INF || a[x][y] > z)
        {
            a[x][y] = z; a[y][x] = z;
        }
        a[x][x] = INF;
        a[y][y] = INF;
    }
    for(int i = 1; i <= n; i++)
    {
        d[i] = a[s][i];
    }
    f[s] = true;
    d[s] = 0;
    for(int i = 1; i <= n-1; i++)
    {
        long nmin = 1, kmin = INF;
        for(int j = 1; j <= n; j++)
            if(!f[j] && kmin > d[j])
            {
                kmin = d[j]; nmin = j;
            }
        f[nmin] = true;
        for(int j = 1; j <= n; j++)
            if(!f[j] && d[j] > d[nmin] + a[nmin][j])
            {
                d[j] = d[nmin] + a[nmin][j];
            }
    }
    cout << *max_element(d.begin() + 1, d.end()) * 2 << endl;

    return 0;
}
