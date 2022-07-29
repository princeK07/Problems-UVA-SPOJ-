// O(N^2), TLE

#include<bits/stdc++.h>
using namespace std;

#define nl "\n"

typedef vector<int> vi;

const int N = 5e4+10;
vi v(N), vis(N), dis(N);
int n;

void reset(){
  for(int i=0; i<=n; i++){
    v[i]=0;
    vis[i]=0;
    dis[i]=0;
  }
}

int dfs(int u){
  vis[u]=1;
  dis[u]=0;
  if(!vis[v[u]]){
    dis[u]=dfs(v[u])+1;
  }
  vis[u]=0;
  return dis[u];
}

int ct=0;

void solve(){
  cin>>n;

  reset();

  for(int i=0; i<n; i++){
    int x, y; cin>>x>>y;
    v[x]=y;
  }

  int ans = 0;
  cout<<"Case "<<++ct<<": ";
  for(int i=1, mx=0; i<=n; i++){
    int x = dfs(i);
    if(dfs(i)>mx){
      mx = dfs(i);
      ans = i;
    }
 }
 cout<<ans<<nl;
}

int main() {
  #ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
  #endif

  ios_base::sync_with_stdio(false);
  cout.tie(nullptr);

  int t=1;
  cin>>t;
  while(t--){
    solve();
    // cout<<nl;
  }

}
