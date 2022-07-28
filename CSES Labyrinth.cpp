#include<bits/stdc++.h>
using namespace std;

#define nl "\n"
#define pb push_back
#define ff first
#define ss second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e3+10;

int n, m;

vector<string> s;
int dis[N][N], vis[N][N], ans[N][N];

int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

char dir(int i){
  if(i==0) return 'L';
  else if(i==1) return 'R';
  else if(i==2) return 'D';
  else return 'U';
}

bool check(int i, int j){
  return i>=0 && j>=0 && i<n && j<m && !vis[i][j];
}

void mov_bfs(pair<int, int> a, pair<int, int> b){
  vis[a.ff][a.ss]=1;

  queue<pair<int, int>> q;
  q.push({a.ff, a.ss});

  while(!q.empty()){
    int x = q.front().ff;
    int y = q.front().ss;

    q.pop();

    for(int i=0; i<4; i++){
      if(check(x+dx[i], y+dy[i])){
        ans[x+dx[i]][y+dy[i]]=i;
        vis[x+dx[i]][y+dy[i]]=1;

        dis[x+dx[i]][y+dy[i]]=dis[x][y]+1;
        q.push({x+dx[i], y+dy[i]});
      }
    }
  }

  if(!vis[b.ff][b.ss]) cout<<"NO";
  else{
    cout<<"YES\n";

    int ct = dis[b.ff][b.ss];
    cout<<ct<<nl;

    pair<int, int> p = b;
    vector<int> c;

    for(int i=0; i<ct; i++){

      c.pb(ans[p.ff][p.ss]);

      if(ans[p.ff][p.ss]==0){
        p.ss+=1;
      }

      else if(ans[p.ff][p.ss]==1){
        p.ss-=1;
      }

      else if(ans[p.ff][p.ss]==2){
        p.ff-=1;
      }

      else p.ff+=1;
    }

    reverse(all(c));

    for(int i=0; i<ct; i++){
      cout<<dir(c[i]);
    }
  }
}

void solve(){
  cin>>n>>m;

  for(int i=0; i<n; i++){
    string str; cin>>str;
    s.pb(str);
  }

  pair<int, int> st, e;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(s[i][j]=='#') vis[i][j]=1;
      if(s[i][j]=='A'){
        st.ff = i;
        st.ss = j;
      }

      if(s[i][j]=='B'){
        e.ff = i;
        e.ss = j;
      }
    }
  }

  mov_bfs(st, e);
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
