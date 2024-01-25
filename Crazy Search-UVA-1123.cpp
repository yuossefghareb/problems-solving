// Crazy Search - UVA 1123
// https://vjudge.net/problem/UVA-1123

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<string> us;

struct Node{


Node* next[26]{};

};



int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   // freopen("inp.txt", "r", stdin);
   //freopen("out.txt", "w", stdout);

        int tc;cin>>tc;
        while(tc--){
        int n,nc;cin>>n>>nc;
        string s;
        cin>>s;
       
        Node root;
        int ans=0;
        
        for(int i=0;i + n <= s.size();i++)
        {
            Node* current=&root;
            bool new_word = false;
             for (int j = i, e = i + n; j < e; ++j) 
            {
               
                if(not current->next[s[j]-'a'])
                {
                    current->next[s[j]-'a']=new Node;
                   new_word = true;
                }
                current=current->next[s[j]-'a'];
            }
            ans+=new_word;
        }
        cout<<ans<<'\n';
         if (tc) cout << '\n';
        }
    return 0;



}
