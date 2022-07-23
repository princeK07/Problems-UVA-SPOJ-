#include<bits/stdc++.h>
using namespace std;

#define nl "\n"
#define pb push_back    
vector<string> s;
int n, m, inst;

bool check(int i, int j){
  return i>=0 && i<n && j>=0 && j<m && s[i][j]!='#';
}

void solve(){

  while(cin>>n>>m>>inst && (n||m||inst)){

    s.clear();

    for(int i=0; i<n; i++){
      string str; cin>>str;
      s.pb(str);
    }



    int x=0, y=0;
    char ch;

    for(int i=0; i<s.size(); i++){
      for(int j=0; j<s[i].size(); j++){
        if(s[i][j]=='N' || s[i][j]=='S' || s[i][j]=='L' || s[i][j]=='O'){
          x=i;
          y=j;
          ch=s[i][j];
          break;
        }
      }
    }
    string q; cin>>q;

    int ans = 0;
    for(int i=0; i<(q).size(); i++){
      
      if(q[i]=='F'){
        if(ch=='N'){
          if(check(x-1, y)){
            x-=1;
            if(s[x][y]=='*'){ 
              ans++;
              s[x][y]='.';
            }
          }
        }

        else if(ch=='S'){
          if(check(x+1, y)){
            x+=1;
            if(s[x][y]=='*'){
              ans++;
              s[x][y]='.';
            }
          }
        }

        // east
        else if(ch=='L'){
          if(check(x, y+1)){
            y+=1;
            if(s[x][y]=='*'){
              ans++;
              s[x][y]='.';
            }
          }
        }

        else {
          if(check(x, y-1)){
            y-=1;
            if(s[x][y]=='*'){
              ans++;
              s[x][y]='.';
            }
          }
        }
      }
      // right
      else if(q[i]=='D'){
        if(ch=='N') ch='L';
        else if(ch=='L') ch='S';
        else if(ch=='S') ch='O';
        else ch='N';
      }

        // left
        else{
          if(ch=='N') ch='O';
          else if(ch=='L') ch='N';
          else if(ch=='S') ch='L';
          else ch='S';
        }
      }
    cout<<ans<<nl;
  }
}

int main() {

  ios_base::sync_with_stdio(false);
  cout.tie(NULL);

  int t=1; 
  // cin>>t;
  while(t--){
    solve();
    // cout<<nl;
  }

  return 0;
}
