// Pattern Find
// https://vjudge.net/problem/SPOJ-NAJPF
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


vector<int> string_pi(const string &s) {
    vector<int> failure(s.size());
    for (int j, i = 1; i < (int) s.size(); ++i) {
        for (j = failure[i - 1]; j > 0 and s[j] != s[i]; j = failure[j - 1]);
        failure[i] = j + (s[i] == s[j]);
    }
    return failure;
}

int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   // freopen("inp.txt", "r", stdin);
  //  freopen("out.txt", "w", stdout);

   int tc;cin>>tc;
   while(tc--)
   {
       string s,p;
       cin>>s>>p;
       auto failure=string_pi(p);
       vector<int>ans;
       for(int j=0,i=0;i<s.size();i++)
       {
           while(j>0 &&s[i]!=p[j])
           {
             j=failure[j-1];
           }
           j+=(s[i]==p[j]);
           if(j<p.size())
             continue;
           ans.push_back(i-j+1);
           j = failure[j - 1];
       }
        if (ans.empty()) {
            cout << "Not Found\n";
        } else {
            cout << ans.size() << '\n';
            for (int x : ans)
                cout << x + 1 << ' ';
            cout << '\n';
        }
        cout << '\n';
   }


}
