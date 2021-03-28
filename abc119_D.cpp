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

const ll INF = 2e18;

int main() {
  int A, B, Q; cin >> A >> B >> Q;
  vector<ll> s(A + 2), t(B + 2), x(Q);
  REP(i, A + 2) {
    if(i == 0) {
      s[i] = -INF; continue;
    }
    if(i == A + 1) {
      s[i] = INF;
      continue;
    }
    cin >> s[i];
  }
  REP(i, B + 2) {
    if(i == 0) {
      t[i] = -INF; continue;
    }
    if(i == B + 1) {
      t[i] = INF; continue;
    }
    cin >> t[i];
  }
  REP(i, Q) cin >> x[i];
  REP(i, Q) {
    ll back_s = lower_bound(all(s), x[i]) - s.begin(); // 後方
    ll front_s = back_s - 1; // 前方
    ll back_t = lower_bound(all(t), x[i]) - t.begin(); // 後方
    ll front_t = back_t - 1; // 前方
    ll ans1 = min(min(abs(x[i] - s[front_s]) + abs(s[front_s] - t[front_t]), abs(x[i] - s[front_s]) + abs(s[front_s] - t[back_t])), min(abs(x[i] - s[back_s]) + abs(s[back_s] - t[front_t]), abs(x[i] - s[back_s]) + abs(s[back_s] - t[back_t])));
    ll ans2 = min(min(abs(x[i] - t[front_t]) + abs(t[front_t] - s[front_s]), abs(x[i] - t[front_t]) + abs(t[front_t] - s[back_s])), min(abs(x[i] - t[back_t]) + abs(t[back_t] - s[front_s]), abs(x[i] - t[back_t]) + abs(t[back_t] - s[back_s])));
    cout << min(ans1, ans2) << endl;
  }
}