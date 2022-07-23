#include<bits/stdc++.h>
using namespace std;

#define inf 1e9+5
#define nl "\n"
#define pb push_back
#define ff first
#define ss second
#define sz(x) ((int)(x).size())

typedef vector<int> vi;

const int N = 505;

vector<pair<int, int>> v[N];
vi dis(N), vis(N,inf);

int n, m, ct=0;

void dijkstra(){
  set<pair<int, int>> s;
  s.insert({0, 1});
  dis[1]=0;

  while(!s.empty()){
    auto node = *s.begin();
    int wt = node.ff;
    int p = node.ss;

    s.erase(s.begin());

    if(vis[p]) continue;
    vis[p]=1;

    for(auto i: v[p]){
      if(dis[p]+i.ss < dis[i.ff]){
        dis[i.ff]=dis[p]+i.ss;
        s.insert({dis[i.ff], i.ff});
      }
    }

  }
}

void lastDomino(){
  double ans = 0;
  int a=1, b=-1;

  for(int i=1; i<=n; i++){
    if(dis[i]>ans && dis[i]!=inf){
      ans=dis[i];
      a=i;
    }
  }

  for(int i=1; i<=n; i++){
    for(int j=0; j<sz(v[i]); j++){
      int child = v[i][j].ff;
      int wt = v[i][j].ss;

      int x = dis[child];
      int y = dis[i];

      if(x>y) swap(x, y);
      double val = x + ((wt - (x-y))*1.0)/2;

      if(val>ans){
        ans=val;
        a=max(i, child);
        b=min(i, child);
      }
    }
  }

  cout<<"System #"<<++ct<<nl;
  cout<<"The last domino falls after "<<ans<<" seconds, ";

  if(b==-1){
    cout<<"at key domino "<<a;
  }
  else cout<<"between key dominoes "<<b<<" and "<<a;

  cout<<".\n";

}

void reset(){
  for(int i=0; i<N; i++){
    v[i].clear();
    dis[i]=inf;
    vis[i]=0;
  }
}

void solve(){
  cout<<fixed<<setprecision(1);

  while(cin>>n>>m && n||m){
    reset();

    for(int i=1; i<=m; i++){
      int x,y,wt; cin>>x>>y>>wt;
      v[x].pb({y, wt});
      v[y].pb({x, wt});
    }

    dijkstra();
    lastDomino();
    cout<<nl;
  }
}

int main() {

  ios_base::sync_with_stdio(false);
  cout.tie(nullptr);

  int t=1;
  // cin>>t;
  while(t--){
    solve();
    // cout<<nl;
  }

}
