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
template <class T> T up(T a, T div) { return (a + div - 1) / div; }

int main() {
  ll N; cin >> N;
  string S, T; cin >> S >> T;
  // 1の個数をカウントする
  int sone = 0;
  REP(i, S.size()) {
    if(S[i] == '1') sone++;
  }
  int tone = 0;
  REP(i, T.size()) {
    if(T[i] == '1') tone++;
  }
  if(sone != tone) {
    cout << -1 << endl;
    return 0;
  }

  vector<ll> a, b;
  REP(i, N) {
    if(S[i] == '0') a.push_back(i);
    if(T[i] == '0') b.push_back(i);
  }

  // 1の個数が同じ場合
  int ans = 0;
  REP(i, a.size()) {
    if(a[i] != b[i]) ans++;
  }
  cout << ans << endl;
}