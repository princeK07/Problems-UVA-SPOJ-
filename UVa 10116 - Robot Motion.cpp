#include<bits/stdc++.h>
using namespace std;

#define nl "\n"
#define pb push_back

const int N = 15;

vector<string>s;
int vis[N][N];
int ct=0;

int n,m,u;

vector<int> step(char ch){
  if(ch=='S') return {1, 0};
  else if(ch=='E') return {0, 1};
  else if(ch=='W') return {0, -1};
  return {-1, 0};
}

bool check(int i, int j){
  return i>=0 && j>=0 && i<n && j<m;
}

void dfs(int y, int x){
  vis[x][y]=++ct;
  vector<int> val = step(s[x][y]);
  x+=val[0];
  y+=val[1];

  if(!check(x, y)){
    cout<<vis[x-val[0]][y-val[1]];
    cout<<" step(s) to exit";
    return;
  }

  else if(check(x, y)){
    if(vis[x][y]){
      cout<<min(vis[x][y], vis[x-val[0]][y-val[1]])-1<<" step(s) before a loop of ";
      cout<<abs(vis[x][y] - vis[x-val[0]][y-val[1]])+1;
      cout<<" step(s)";
      return;
    }

    else dfs(y, x);
  }
}

void reset(){
  s.clear();
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++) vis[i][j]=0;
  }
  ct=0;
}

void solve(){
  while(cin>>n>>m>>u && n||m||u){

    reset();

    for(int i=0; i<n; i++){
      string str; cin>>str;
      s.pb(str);
    }
    u--;
    dfs(u, 0);
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
  }

}
