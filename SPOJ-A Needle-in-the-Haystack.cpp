// A Needle in the Haystack
// https://vjudge.net/problem/SPOJ-NHAY
//Solve by combining the 2 strings separated by '#'
#include <bits/stdc++.h>
#define el endl
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

   int n;
    while(cin>>n)
    {
        string s,pat;
        cin>>pat>>s;
        auto failure=string_pi(pat+'#'+s);
        vector<int>ans;
        for(int i=0; i<failure.size(); i++)
        {
            if(failure[i]==pat.size())
            {

                cout<<(i-2*pat.size())<<el;
            }
        }

        cout<<el;

    }


}
