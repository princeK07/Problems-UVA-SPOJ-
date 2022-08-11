#include<bits/stdc++.h>
using namespace std;

#define nl "\n"
#define all(x) (x).begin(), (x).end()

const int N = 5e4+5;
int n, m;
vector<int> v(N);

bool valid(int mid){
  int k=0, dist=0;
  for(int i=0; i<n; i++){
    if(v[i]>dist){
      dist=v[i]+mid*2;
      k++;
    }
  }
  return k<=m;
}

int main() {

  ios_base::sync_with_stdio(false);
  cout.tie(nullptr);

if(fopen("angry.in", "r")){
  freopen("angry.in","r",stdin);
  freopen("angry.out","w",stdout);
}
  cin>>n>>m;
  for(int i=0; i<n; i++)
    cin>>v[i];

  v.resize(n);
  sort(all(v));

  int lo=0, hi=v[n-1];
  while(hi-lo>1){
    int mid = (lo+hi)/2;
    if(valid(mid)) hi=mid;
    else lo=mid+1;
  }

  if(valid(lo)) cout<<lo;
  else cout<<hi;
}
