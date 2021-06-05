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
  int T; cin >> T;
  REP(i, T) {
    ll N; cin >> N; vector<ll> A(N); REP(i, N) cin >> A[i];
    vector<ll> sub(N - 1);
    REP(k, N - 1) sub[k] = A[k + 1] - A[k];
    vector<ll> sub2;
    ll ans = 0;
    REP(k, sub.size()) {
      sub2 = sub; // copy of vector
      if(k == 0) {
        sub2[0] = sub2[1];
      } else {
        ll t = sub2[k];
        sub2[k] = sub2[k - 1]; // 前と同じになるように変更して...
        if(k + 1 < sub.size()) sub2[k + 1] -= (sub2[k] - t);
      }

      ll cnt = 1; ll tmp = 0;
      // REP(l, N - 1) cout << sub2[l] << " ";
      // cout << endl;
      REP(l, sub.size() - 1) {
        if(sub2[l] == sub2[l + 1]) cnt++;
        else {
          tmp = max(tmp, cnt); cnt = 1;
        }
      }
      tmp = max(tmp, cnt);

      ans = max(ans, tmp);
    }
    for(int k = sub.size() - 1; k >= 0; --k) {
      sub2 = sub; // copy of vector
      if(k == sub.size() - 1) {
        sub2[k] = sub2[k - 1];
      } else {
        ll t = sub2[k];
        sub2[k] = sub2[k + 1]; // 前と同じになるように変更して...
        if(k - 1 >= 0) sub2[k - 1] -= (sub2[k] - t);
      }

      ll cnt = 1; ll tmp = 0;
      REP(l, sub.size() - 1) {
        if(sub2[l] == sub2[l + 1]) cnt++;
        else {
          tmp = max(tmp, cnt); cnt = 1;
        }
      }
      tmp = max(tmp, cnt);

      ans = max(ans, tmp);
    }
    cout << "Case #" << i + 1 << ": ";
    cout << ans + 1 << endl;
  }
}