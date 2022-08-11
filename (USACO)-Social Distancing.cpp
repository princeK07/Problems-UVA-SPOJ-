#include<bits/stdc++.h>
using namespace std;

#define INF 1e18
#define nl "\n"
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()

typedef long long ll;

bool valid(ll mid, vector<pair<ll, ll>> v, int n, int m){
  int cows=1;
  ll dist=v[0].ff+mid;  
  for(int i=0; i<m; i++){
    if(dist<v[i].ff) dist=v[i].ff;
    while(v[i].ff<=dist && v[i].ss>=dist){
      cows++;
      dist+=mid;
    }
  }
  return cows>=n;
}

int main() {

  ios_base::sync_with_stdio(false);
  cout.tie(nullptr);

if(fopen("socdist.in", "r")){
  freopen("socdist.in","r",stdin);
  freopen("socdist.out","w",stdout);
}
  int n, m;
  cin>>n>>m;

  vector<pair<ll, ll>> v;

  for(int i=0; i<m; i++){
    ll x, y; 
    cin>>x>>y;

    v.pb({x, y});
  }

  sort(all(v));

  ll lo=0, hi=INF;
  while(hi-lo>1){
    ll mid = (lo+hi)/2;
    if(valid(mid, v, n, m))lo=mid;
    else hi=mid-1;
  }

  if(valid(hi, v, n, m)) cout<<hi;
  else cout<<lo;
}
