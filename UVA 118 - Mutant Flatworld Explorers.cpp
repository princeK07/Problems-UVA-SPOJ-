#include<bits/stdc++.h>
using namespace std;

#define nl "\n"
#define pb push_back
#define ff first
#define ss second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int n, m, x, y;
char ch;
string s;
set<pair<int, int>> off;

bool check(int i, int j){
  return i>=0 && i<=n && j>=0 && j<=m;
}

bool checkoff(int x, int y){
  return off.find({x,y})!=off.end();
}

void solve(){
  cin>>n>>m;
  

  while(cin>>x>>y){
    cin>>ch;
    string s;
    cin>>s;
    bool flag=1;

    pair<pair<int, int>, char> prev;

    prev={{x,y}, ch};

    for(int i=0; i<sz(s); i++){
      if(s[i]=='F'){
        if(ch=='N'){
         if(!check(x, y+1)){
          if(!checkoff(x,y)){
            y++;
          }
         }
         else y++;
       }
        else if(ch=='E'){ 
          if(!check(x+1, y)){
            if(!checkoff(x,y)){
              x++;
            }
          }
          else x++;}

        else if(ch=='S'){
         if(!check(x, y-1)){
          if(!checkoff(x, y)){
            y--;
          }
         }
         else y--;}
        else{
         if(!check(x-1, y)){
          if(!checkoff(x,y)){
            x--;
          }
         }
         else x--;}
      }

      else if(s[i]=='R'){
        if(ch=='N') ch='E';
        else if(ch=='E') ch='S';
        else if(ch=='S') ch='W';
        else ch='N';
      }

      else{
        if(ch=='N') ch='W';
        else if(ch=='E') ch='N';
        else if(ch=='S') ch='E';
        else ch='S';
      }

      if(!check(x,y)){
        off.insert({prev.ff.ff, prev.ff.ss});
        cout<<prev.ff.ff<<" "<<prev.ff.ss<<" "<<prev.ss<<" LOST"<<nl; 
        flag=0;
        break;
      }
      prev={{x,y}, ch};
    }
    if(flag){
      cout<<x<<" "<<y<<" "<<ch<<nl;
    }
  }

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
