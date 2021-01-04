#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using P = pair<ll, ll>;
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
struct edge {
  ll to, cost;
};

int main() {
  string S; cin >> S;
  string ans = "NO"; bool i = false; bool c = false;
  int s = S.size();
  REP(k, s) {
    if(S[k] == 'I' || S[k] == 'i') i = true;
    if(i && (S[k] == 'C' || S[k] == 'c')) c = true;
    if(i && c && (S[k] == 'T' || S[k] == 't')) ans = "YES";
  }
  cout << ans << endl;
}