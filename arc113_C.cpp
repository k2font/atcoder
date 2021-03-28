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
  string S; cin >> S;
  map<char, int> m;
  // 後ろから2連続担っている部分を探し、そこから末尾までの文字数を答えに足し込む
  ll ans = 0;
  reverse(all(S));
  REP(i, S.size() - 1) {
    if(S[i] == S[i + 1]) {
      ans += i;
      ans -= m[S[i]];
      m.clear(); m[S[i]] += i;
    }
    m[S[i]]++;
  }

  // このままだとWA
  // rrarrが3と出力されるが、正しくは1。
  // これは、以前出現した同じ文字種までも操作の対象に含めようとしているからである

  // mapとか使って、以前出てきた文字とその位置を覚えておくと良さげ。

  cout << ans << endl;
}