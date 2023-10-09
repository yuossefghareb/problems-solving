#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define pb push_back

#define ld long double
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define RT(x) return cout << x, 0
#define pi 3.1415926535897932384626433
#define outf(x) cout << fixed << setprecision(x)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define el '\n'
#define si(t) scanf("%d",&t)
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
constexpr ll OO = 0x3f3f3f3f3f3f3f3f;
const int MOD =  1073741824;
const int N = 1e5+5;


vector<int>g[N];

bool vis[N];





int d[8][2]=
{
    {0,1},
    {0,-1},
    {1,0},
    {-1,0},

    {1,1},
    {-1,1},
    {1,-1},
    {-1,-1},


};

ll parent[N],sizee[N],sum[N];

bool wa[N];
void init(int n)
{
  //  iota(parent,parent+N-1,0);
for ( int i = 1, j = n + 1; i <= n; ++i, ++j ) {
        parent[i] = j;
        parent[j] = j;
        sizee[j] = 1;
        sum[j] = i;
    }
   // fill(sizee,sizee+N-1,1);

}

int find_set(int v)
{
      if (v == parent[v])
        return v;
    return parent[v]=find_set(parent[v]);
}


void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sizee[a] < sizee[b])
            swap(a, b);
        parent[b] = a;
        sizee[a] += sizee[b];
        sum[a]+=sum[b];
    }
}

vector<pair<int,int>>edges;

void move ( int x, int y ) {
    int x_root = find_set(x);
    int y_root = find_set(y);
    if ( x_root != y_root ) {
        ++sizee[y_root];
        --sizee[x_root];
        sum[y_root] += x;
        sum[x_root] -= x;
        parent[x] = y_root;
    }
}
void solve() {


int n,m;
while(cin>>n>>m){


init(n);

while(m--)
{
    int t,u,v;
    cin>>t;
    if(t==1)
    {
        cin>>u>>v;
//
        union_sets(u,v);
    }
    else if(t==2)
    {
        cin>>u>>v;
    move(u,v);

    }
    else
    {
        cin>>u;
        cout<<sizee[find_set(u)]<<" "<<sum[find_set(u)]<<el;

    }
}


}

}




int main()
{
    fast
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll t=1;
     //cin>>t;
    while(t--)
    {
        solve();
        // cout<<el;

    }

}
