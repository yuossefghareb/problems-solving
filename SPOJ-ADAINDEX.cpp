#include <bits/stdc++.h>
#include<algorithm>
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

ll OO = 0x3f3f3f3f3f3f3f3f;

struct Node{
int cnt=0;
bool isword=false;
Node* next[26]{};

void insert (string &s)
{
    Node* current=this;
    for(auto c:s)
    {
        int i=c-'a';
        if(current->next[i]==nullptr)
            current->next[i]=new Node;
        current=current->next[i];
        ++current->cnt;
    }
    current->isword=true;
}

int sum_of_prefix(string &s)
{
    Node* current=this;
    for(auto c:s)
    {
        int i=c-'a';
        if(current->next[i]==nullptr)
            return 0;
        current=current->next[i];
    }
    return current->cnt;
}


};




void solve()
{

 int n,m;cin>>n>>m;
 Node trie;
vector<string>v(n);
 for(int i=0;i<n;i++)
 {
    cin>>v[i];
  trie.insert(v[i]);
 }
bool ok=1;
 for(int i=0;i<m;i++)
 {
     string s;cin>>s;
     cout<<trie.sum_of_prefix(s)<<el;

 }




}






int main()
{
    fast

   // freopen("ladder.in", "r", stdin);
     //freopen("ladder.out", "w", stdout);
    ll t=1;
   //cin>>t;
    while(t--)
    {
        solve();

    }

}
