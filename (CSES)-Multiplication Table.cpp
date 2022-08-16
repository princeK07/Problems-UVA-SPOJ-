/*
  Time Complexity: O(log(n*n)*n)
*/

#include<bits/stdc++.h>
using namespace std;

#define nl "\n"
typedef long long ll;

void solve(){
  ll n; cin>>n;
  ll lo=1, hi=n*n;

  ll req_pos = (n*n + 1)/2;

  while(hi>lo){
    ll mid = (lo+hi)/2;
    ll curr=0;

    for(int i=1; i<=n; i++){
      curr+=min(n, mid/i);
    }

    if(curr>=req_pos) hi=mid;
    else lo=mid+1;
  }
  cout<<hi;
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
