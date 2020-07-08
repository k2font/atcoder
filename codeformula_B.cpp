#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
  return string(1, val);
}
int char_to_int(char val) {
  return val - '0';
}
template<class T> inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template<class T> inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

int main() {
  int a, b; cin >> a >> b;
  vector<int> p(a), q(b);
  REP(i, a) cin >> p[i];
  REP(i, b) cin >> q[i];
  vector<int> ans(10); REP(i, 10) ans[i] = 0;
  REP(i, a) {
    if(p[i] == 0) {
      ans[9] = 1;
      continue;
    }
    ans[p[i] - 1] = 1;
  }
  REP(i, b) {
    if(q[i] == 0) {
      ans[9] = 2;
      continue;
    }
    ans[q[i] - 1] = 2;
  }
  for(int i = 6; i < 10; ++i) {
    if(ans[i] == 1) cout << "." << " ";
    else if(ans[i] == 2) cout << "o" << " ";
    else cout << "x" << " ";
  }
  cout << endl;
  for(int i = 3; i < 6; ++i) {
    if(i == 3)cout << " ";
    if(ans[i] == 1) cout << "." << " ";
    else if(ans[i] == 2) cout << "o" << " ";
    else cout << "x" << " ";
  }
  cout << endl;
  for(int i = 1; i < 3; ++i) {
    if(i == 1)cout << "  ";
    if(ans[i] == 1) cout << "." << " ";
    else if(ans[i] == 2) cout << "o" << " ";
    else cout << "x" << " ";
  }
  cout << endl;
  for(int i = 0; i < 1; ++i) {
    cout << "   ";
    if(ans[i] == 1) cout << "." << " ";
    else if(ans[i] == 2) cout << "o" << " ";
    else cout << "x" << " ";
  }
  cout << endl;
}