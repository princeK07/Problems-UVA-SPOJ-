#include<bits/stdc++.h>
using namespace std;

#define nl "\n"
#define pb push_back
#define all(x) (x).begin(), (x).end()

const int N = 1e5+10;
vector<int> v;
int n, m, c;

bool valid(int x){

  int mx=0;
  int bus_req=0;
  int i=0;

  while(i<n){
    if(mx==i) bus_req++;

    if(v[i]-v[mx]>x){
      mx=i;
    }

    else if(i-mx+1==c){
      mx=++i;
    }

    else i++;
  }

  return bus_req<=m;
}

int main() {

  ios_base::sync_with_stdio(false);
  cout.tie(nullptr);

if(fopen("convention.in", "r")){
  freopen("convention.in","r",stdin);
  freopen("convention.out","w",stdout);
}
  cin>>n>>m>>c;

  for(int i=0; i<n; i++){
    int x; cin>>x;
    v.pb(x);
  }

  sort(all(v));

  int lo=0, hi=v[n-1] - v[0];

  while(hi-lo>1){
    int mid = (lo+hi)/2;
    if(valid(mid)) hi=mid;
    else lo=mid+1;
  }

  if(valid(lo)) cout<<lo;
  else cout<<hi;
}
