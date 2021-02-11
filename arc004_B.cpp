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
  vector<int> d(N); REP(i, N) cin >> d[i];
  ll ans_max = accumulate(all(d), 0LL);

  cout << ans_max << endl;
  if(N > 3) {
    ll ans_min = 0;
    sort(all(d), greater<ll>());
    ll m = accumulate(all(d), 0LL);
    ll c = m - d[0];
    if(c > d[0]) {
      ans_min = 0;
    } else {
      ans_min = d[0] - c;
    }
    cout << ans_min << endl; // 四角形以上の場合でも0じゃない場合があるが、一旦0とする
  } else {
    ll ans_min = 0;
    if(N == 3) {
      if(d[0] + d[1] > d[2] && d[0] + d[2] > d[1] && d[1] + d[2] > d[0]) {
        ans_min = 0;
      } else {
        sort(all(d));
        ans_min = d[2] - d[1] - d[0];
      }
    } else if(N == 2) {
      ans_min = abs(d[0] - d[1]);
    } else if(N == 1) {
      ans_min = d[0];
    }

    cout << ans_min << endl;
  }
}