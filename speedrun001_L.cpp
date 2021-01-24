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
  ll N; cin >> N;
  vector<ll> a(N); REP(i, N) cin >> a[i];
  REP(i, N) --a[i];
  vector<pair<ll, ll>> b(N);
  REP(i, N) {
    b[i] = make_pair(a[i], i);
  }
  sort(all(b));
  int c = 0;
  REP(i, N) {
    int p = b[i].second; // 確認する現在位置を定める
    if(i == p) continue; // もしすでにその数がおいてあればcontinue;
    swap(b[i].second, b[a[i]].second); // i番目とa[i]番目の位置を入れ替える
    swap(a[p], a[i]); // 配列aも入れ替えておく
    ++c;
  }

  // この時点でソートに失敗していればNO
  bool flag = true;
  REP(i, N) {
    if(a[i] != i) flag = false;
  }
  if(flag == true) {
    if(N % 2 == c % 2) {
      cout << "YES" << endl;
    } else cout << "NO" << endl;
  } else cout << "NO" << endl;
}
