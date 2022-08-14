#include<bits/stdc++.h>
using namespace std;

#define nl "\n"
#define pb push_back

typedef vector<int> vi;

bool valid(int x, int n, vi a, int d){

  for(int i=1; i<=n; i++){
    a[i]=max(0, a[i]-x);

    if(a[i]/d > x) 
      return false;

    a[i+1]+=a[i];
  }
  return a[n]==0;

}

void solve(){
  int n, d, m;
  cin>>n>>d>>m;

  vi v(m);
  vi a(n+1, 0);
  vector<int> q[n+1];

  for(int i=0; i<m; i++){
    cin>>v[i];
    a[v[i]]++;
    q[v[i]].pb(i+1);
  }

  int lo=1, hi=1e6+10;
  while(hi-lo>1){
    int mid = (lo+hi)/2;
    if(valid(mid,n,a,d)) hi=mid;
    else lo=mid+1; 
  }

  int ans=0;
  if(valid(lo,n,a,d)){ cout<<lo; ans=lo;}
  else {cout<<hi; ans=hi;}

  cout<<nl;

  queue<int> qq;

  for(int i=1; i<n+1; i++){
    for(int j=0; j<q[i].size(); j++){
      qq.push(q[i][j]);
    }
  }

  int ct=0, count=0;
  while(!qq.empty()){
      count++;
    while(ct!=ans && !qq.empty()){
      ct++;
      cout<<qq.front()<<" ";
      qq.pop();
    }
    cout<<"0\n";
    ct=0;
  }
  
  count=n-count;
  while(count--) cout<<"0\n";
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
