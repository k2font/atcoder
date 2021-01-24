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
  int N, K; cin >> N >> K;
  string S; cin >> S;
  // データ構造作成パート
  vector<map<char, ll>> m;
  char t = S[0];
  // REP(i, N) {
  //   if(i == 0) continue;
  //   if(S[i] != t) {
  //     m.push_back(tmp);
  //     t = S[i];
  //     tmp.clear();
  //   }
  //   tmp[S[i]]++;
  //   if(i == N - 1) {
  //     m.push_back(tmp);
  //     t = S[i];
  //     tmp.clear();
  //   }
  // }
  
  // ll ans = 0;
  // // 得点計算パート
  // char p = S[0];
  // REP(i, m.size()) {
  //   if(i % 2 == 0) continue;
  //   for(auto x : m[i]) {

  //   }
  // }
  ll ans = 0;
  int tmp = 0;
  REP(i, N - 1) {
    if(S[i] != S.at(i + 1)) tmp++;
  }
  if((tmp - 2 * K) >= 0) ans = N - 1 - (tmp - 2 * K);
  else ans = N - 1;
  cout << ans << endl;
}
