#include<bits/stdc++.h>
using namespace std;

#define INF 1e18
typedef long long ll;

const int N = 2e5+5;
vector<ll> v(N);
ll n, k; 

bool valid(ll x){
  ll subArr=1;

  ll sum=0;
  for(int i=0; i<n; i++){
    if(v[i]>x) return false;
    sum+=v[i];
    if(sum>x){
      subArr++;
      sum=v[i];
    }
  }

  return subArr<=k;
}

void solve(){
  cin>>n>>k;
  for(int i=0; i<n; i++) 
    cin>>v[i];

  ll lo=1, hi=INF;
  while(hi-lo>1){
    ll mid = (lo+hi)/2;
    if(valid(mid)) hi=mid;
    else lo=mid+1;
  }

  if(valid(lo)) cout<<lo;
  else cout<<hi;
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
