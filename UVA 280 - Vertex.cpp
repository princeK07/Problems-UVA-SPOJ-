#include<bits/stdc++.h>
using namespace std;

#define nl "\n"
#define pb push_back
typedef vector<int> vi;

const int N = 110;
vi v[N];
vi vis(N, 0);
int ct=0;

void dfs(int u){
  for(auto i: v[u]){
    if(!vis[i]){ 
      ct--;
      vis[i]=1; 
      dfs(i);
    }
  }
}

void resetVis(){
  for(int i=1; i<=N; i++) vis[i]=0;
}

void solve(){
  int n;

  while(cin>>n && n!=0){
    int x;
    while(cin>>x && x!=0){
      int y;
      while(cin>>y && y!=0){ 
        v[x].pb(y);
      }
    }

    int t; cin>>t;
    while(t--){
      int u; cin>>u;

      resetVis();
      ct=n;
      dfs(u);
      cout<<ct;
      for(int i=1; i<=n; i++){
        if(!vis[i])cout<<" "<<i;
      }
      cout<<nl;
    }
    for(int i=1; i<=n; i++){
      v[i].clear();
    }
  }

}

int main() {

  ios_base::sync_with_stdio(false);
  cout.tie(NULL);

  int t=1; 
  // cin>>t;
  while(t--){
    solve();
    // cout<<nl;
  }

  return 0;
}
