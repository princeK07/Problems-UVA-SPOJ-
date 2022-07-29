#include<bits/stdc++.h>
using namespace std;

#define nl "\n"
#define pb push_back

typedef vector<int> vi;

const int N = 2e3+5;
int n, m;
vi v[N];
vi vis(N, 0), color(N, 0);

void reset(){
  for(int i=0; i<N; i++){
    color[i]=0;
    vis[i]=0;
    v[i].clear();
  }
}

bool bfs(int u){
  vis[u]=1;

  queue<int> q;
  q.push(u);

  color[u]=0;

  while(!q.empty()){
    int f = q.front();
    q.pop();

    for(auto i: v[f]){
      if(!vis[i]){
        vis[i]=1;
        q.push(i);

        color[i]=1-color[f];
      }

      else if(color[i]==color[f]) return false;
    }
  }
  return true;
}

int ct=0;

void solve(){
  cin>>n>>m;

  reset();

  for(int i=0, x, y; i<m; i++){
    cin>>x>>y;
    x--, y--;

    v[x].pb(y);
    v[y].pb(x);
  }  

  cout<<"Scenario #"<<++ct<<":\n";

  for(int i=0; i<n; i++){
    if(!vis[i]){
      if(!bfs(i)){
        cout<<"Suspicious bugs found!";
        return;
      }
    }
  }
  cout<<"No suspicious bugs found!";
}

int main() {

  ios_base::sync_with_stdio(false);
  cout.tie(nullptr);

  int t=1;
  cin>>t;
  while(t--){
    solve();
    cout<<nl;
  }

}
