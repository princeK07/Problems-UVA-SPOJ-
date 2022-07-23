#include<bits/stdc++.h>
using namespace std;

#define nl "\n"
#define pb push_back
#define sz(x) ((int)(x).size())

const int N = 65;

vector<string> s;
vector<string> inst;
int n, m;

vector<int> mov(char ch){
  if(ch=='N') return {-1, 0};
  else if(ch=='W') return {0, -1};
  else if(ch=='E') return {0, 1};
  else return {1, 0};
}

bool check(int i, int j){
  return s[i][j]!='*';
}

void maze(int x, int y, char ch){
  for(int i=0; i<sz(inst); i++){
    for(int j=0; j<sz(inst[i]); j++){
      char c = inst[i][j];
      if(c==' ') continue;

      if(c=='F'){
        vector<int> v = mov(ch);
        if(check(x+v[0], y+v[1])){
          x+=v[0], y+=v[1];
        }
      }

      else if(c=='R'){
        if(ch=='N') ch='E';
        else if(ch=='E') ch='S';
        else if(ch=='S') ch='W';
        else ch='N';
      }

      else if(c=='L'){
        if(ch=='N') ch='W';
        else if(ch=='E') ch='N';
        else if(ch=='S') ch='E';
        else ch='S';
      }

      else if(c=='Q'){
        cout<<x+1<<" "<<y+1<<" "<<ch;
        return;
      }
    }
  }
}

void solve(){
  s.clear();
  inst.clear();

  cin>>n>>m;

  cin.ignore();
  for(int i=0; i<n; i++){
    string str; getline(cin, str);
    s.pb(str);
  }

  int x, y;
  cin>>x>>y;
  x--, y--;
  cin.ignore();

  string str;
  while(getline(cin, str)){
    if(sz(str)==0) break;
    inst.pb(str);
  }

  maze(x, y, 'N');
  cout<<nl;
}

int main() {

  ios_base::sync_with_stdio(false);
  cout.tie(nullptr);

  int t=1;
  cin>>t;

  string s;
  getline(cin, s);
  cin.ignore();
  while(t--){

    solve();
    if(t!=0) cout<<nl;
    // cout<<nl;
  }

}
