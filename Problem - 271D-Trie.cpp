
// Good Substrings
// https://codeforces.com/problemset/problem/271/D

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<string> us;

struct Node{

int ans_cnt=0,idx=-1;

Node* next[26]{};



};



int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  //freopen("inp.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);

        string s;
        cin>>s;
        bool is_good[26]{};
        for(int i=0;i<26;i++)
        {
            char c;cin>>c;
            is_good[i]=c-'0';
        }
        Node root;
        int ans=0,k;
        cin>>k;
        for(int i=0;i<s.size();i++)
        {
            Node* current=&root;
            int rem=k;
            for(int j=i;j<s.size();j++)
            {
                rem-= not is_good[s[j]-'a'];
                if(rem<0)
                break;

                if(not current->next[s[j]-'a'])
                {
                    current->next[s[j]-'a']=new Node;
                    ans++;
                }
                current=current->next[s[j]-'a'];
            }
        }
        cout<<ans<<'\n';
    return 0;



}
