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
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
constexpr ll OO = 0x3f3f3f3f3f3f3f3f;
const ll MOD =  1e9+7;
const int N = 2e3+5;


int dx[8] = {0,0,1,-1,1,-1,1,-1};
int dy[8] = {1,-1,0,0,1,-1,-1,1};

ll dp[105][105];
int n,m,x,y;
vector<vector<int>>v;
ll solve(int i,int j)
{
 if(i>=n||j>=m||i<0||j<0)return 0;
 ll &ret=dp[i][j];
 if(~ret)return ret;

          ret=max(ret,solve(i+1,j)+v[i][j]);

          ret=max(ret,solve(i+1,j-1)+v[i][j]);

          ret=max(ret,solve(i+1,j+1)+v[i][j]);




  return ret;
}


int main()
{
   // fast
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll t=1;
    int z=1;
   cin>>t;
    while(t--)
    {
        memset(dp,-1,sizeof(dp));
       //   cout<<"Case "<<z++<<": ";
       cin>>n>>m;
       v=vector<vector<int>>(n+2,vector<int>(m+2));

       for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
           cin>>v[i][j];

        ll mx=0;
        for(int i=0;i<m;i++)
        {
            mx=max(solve(0,i),mx);
        }
        cout<<mx<<el;


    }

}
