// Catapult that ball
//  https://vjudge.net/problem/SPOJ-THRBL
#include <bits/stdc++.h>
#define el endl
using namespace std;

typedef long long ll;


const int N=1e5+5,P=17;
int n,a[N],st[P][N],LOG[N];

void prepare() {
    for (int i = 2; i < N; ++i)
        LOG[i] = LOG[i / 2] + 1;
}

void build_st()
{
    for(int i=0;i<n;i++)
    {
        st[0][i]=a[i];
    }
    for(int p=1;(1<<p)<=n;p++)
    {
        for(int i=0;i+(1<<p)<=n;i++)
        {
            st[p][i]=max(st[p-1][i],st[p-1][i+(1<<(p-1))]);
        }
    }
}
int query(int l,int r)
{
    int p=LOG[r-l+1];
    return max(st[p][l],st[p][r-(1<<p)+1]);
}


int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  prepare();

  cin>>n;
  int q;cin>>q;
  for(int i=0;i<n;i++)
    cin>>a[i];
   build_st();
  int ans=0;
  while(q--)
  {
      int l,r;cin>>l>>r;
      l--;r--;
     if(r-l+1<3 or query(l+1,r-1)<=a[l])
        ans++;
  }
  cout<<ans<<el;



}
