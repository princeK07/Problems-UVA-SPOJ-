#include<bits/stdc++.h>
using namespace std;

#define nl "\n"

const int N = 1e4+10;
vector<int> v[N];
vector<bool> vis(N,0);

bool dfs(int u, int p){
  vis[u]=1;
  for(auto i: v[u]){
    if(!vis[i]){
      dfs(i, u);
    }

    else if(i != p){
      return false;
    }
  }
  return true;
}

void solve(){
  int n, m;
  cin>>n>>m;

  for(int i=0; i<m; i++){
    int x, y; cin>>x>>y;
    x--, y--;
    v[x].push_back(y);
    v[y].push_back(x);
  }

  int ct=0;
  for(int i=0; i<n; i++){
    if(!vis[i]){
     ct++;
     if(ct>=2){
      cout<<"NO"; return;
     }
     if(!dfs(i, -1)){
      cout<<"NO"; return;
     }
   }
  }

  cout<<"YES";
}

int main() {

  ios_base::sync_with_stdio(false);
  cout.tie(NULL);

  int t=1; 
  // cin>>t;
  while(t--){
    solve();
    cout<<nl;
  }

  return 0;
}
