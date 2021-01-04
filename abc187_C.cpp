#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using P = pair<ll, ll>;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};
string char_to_string(char val) {
  return string(1, val);
}
int char_to_int(char val) {
  return val - '0';
}
char inverse_char(char c) {
  if(isupper(c)) return tolower(c);
  else return toupper(c);
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
  int N; cin >> N;
  vector<string> S(N); REP(i, N) cin >> S[i];
  map<string, int> m, p;
  REP(i, N) {
    if(S[i][0] != '!') {
      m[S[i]]++;
    } else {
      string s = S[i].substr(1, S[i].size() - 1);
      p[s]++;
    }
  }
  for(auto x : m) {
    string s = x.first;
    if(p[s] > 0) {
      cout << s << endl;
      return 0;
    }
  }
  cout << "satisfiable" << endl;
}