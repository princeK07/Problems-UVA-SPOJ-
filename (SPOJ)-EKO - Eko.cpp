#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e6+10;
ll n, m;
ll trees[N];

bool valid(int value){
  ll total=0;
  for(int i=0; i<n; i++){
    if(trees[i]>=value)
      total+=(trees[i]-value);
  }
  return total>=m;
}

void solve(){
  cin>>n>>m;
  
  for(int i=0; i<n; i++) cin>>trees[i];            

  ll lo=0, hi=1e9, mid;
  
  while(hi-lo>1){
    mid = (lo+hi)/2;
    if(valid(mid)) lo=mid;
    else hi=mid-1;    
  }
  if(valid(hi)) cout<<hi;
  else cout<<lo;
}

int main() {
  #ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
  #endif

  ios_base::sync_with_stdio(false);
  cout.tie(nullptr);

  int t=1;
  // cin>>t;
  while(t--){
    solve();
    // cout<<nl;
  }

}
