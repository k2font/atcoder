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

ll score(string S) {
  vector<ll> cnt(10);
  iota(all(cnt), 0);
  for(char c : S) cnt[c - '0'] *= 10;
  return accumulate(all(cnt), 0ll);
}

int main() {
  int K; cin >> K;
  string S, T; cin >> S >> T;
  // 全探索して点数を計算、高橋くんが勝つ回数を数える

  // とりあえず、現在使えるカードの枚数を計算する
  vector<ll> cnt(10, K);
  for(char c : S) cnt[c - '0']--;
  for(char c : T) cnt[c - '0']--;

  ll win = 0;

  for(int x = 1; x <= 9; ++x) {
    for(int y = 1; y <= 9; ++y) {
      S.back() = '0' + x; // この置き換えは天才すぎる
      T.back() = '0' + y;
      if(score(S) <= score(T)) continue;
      win += cnt[x] * (cnt[y] - (x == y)); // スコアの合計を計算する
    }
  }

  ll mot = ((9 * (ll)K - 8) * (9 * (ll)K - 9));
  double ans = double(win) / mot;
  cout << fixed << setprecision(10) << ans << endl;
}