#include<bits/stdc++.h>
using namespace std;

#define nl "\n"
#define ff first
#define ss second
#define pb push_back

const int N = 1e2+10;

int r, c, m, n;
int a[N][N];
bool vis[N][N];

int ct=0;

void reset(){
  for(int i=0; i<r; i++){
    for(int j=0; j<c; j++){
      a[i][j]=0;
      vis[i][j]=0;
    }
  }
}

bool check(int i, int j){
  return i>=0 && j>=0 && i<r && j<c && a[i][j]!=-1; 
}

void bfs(){
  queue<pair<int, int>> q;

  q.push({0,0});
  vis[0][0]=1;

  int dx[] = {m,m,-m,-m,n,n,-n,-n};
  int dy[] = {n,-n,-n,n,m,-m,-m,m};

  int ev=0, od=0;

  while(!q.empty()){
    int x = q.front().ff;
    int y = q.front().ss;
    q.pop();

    set<pair<int, int>> s;

    for(int i=0; i<8; i++){
      if(check(x+dx[i], y+dy[i])){
        s.insert({x+dx[i], y+dy[i]});
      }
    }

    for(auto i: s){
      a[i.ff][i.ss]++;
      if(!vis[i.ff][i.ss]){
        vis[i.ff][i.ss]=1;
        q.push({i.ff, i.ss});
      }
    }
  }

  for(int i=0; i<r; i++){
    for(int j=0; j<c; j++){
      if((a[i][j]!=-1 && a[i][j]!=0) || (i==0 && j==0)){
        if(a[i][j]%2) od++;
        else ev++;
      }
    }
  }
  
  cout<<"Case "<<++ct<<": ";
  cout<<ev<<" "<<od;
}

void solve(){
  cin>>r>>c>>m>>n;
  reset();

  int q; cin>>q;
  while(q--){
    int x, y; cin>>x>>y;
    a[x][y]=-1;
  }

  bfs();
}

int main() {

  ios_base::sync_with_stdio(false);
  cout.tie(NULL);

  int t=1; 
  cin>>t;
  while(t--){
    solve();
    cout<<nl;
  }

  return 0;
}
