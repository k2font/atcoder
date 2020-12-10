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
  string s, t; cin >> s >> t;
  map<char, vector<ll>> m;
  REP(i, s.size()) {
    m[s[i]].push_back(i + 1);
  }
  // -1チェック
  REP(i, t.size()) {
    if(m[t[i]].size() == 0) {
      cout << -1 << endl;
      return 0;
    }
  }

  ll ans = 0;
  ll last = 0; // 最後に見た文字列sの上のindexを保持

  // 解を求めるパート
  REP(i, t.size()) {
    auto it = upper_bound(all(m[t[i]]), last); // m[t[i]]の中に値があるかを二分探索で調べる
    if(it == m[t[i]].end()) { // 存在しなかったら(lastより後にもうその文字は出現しない時)
      ans += s.size(); // sの文字列の長さ分だけ答えに足し込む
      it = m[t[i]].begin();
    }
    last = *it; // 最後に見た文字列sの位置を格納
  }
  ans += last;
  cout << ans << endl;
}