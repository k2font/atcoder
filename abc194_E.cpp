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
  ll N, M; cin >> N >> M;
  vector<ll> A(N); REP(i, N) cin >> A[i];
  vector<ll> tmp(2000000, 0);
  ll ans = 10000000000000000; ll t = 0;
  REP(i, N - M + 1) {
    if(i == 0) {
      REP(i, M) {
        tmp[A[i]]++;
      }
      REP(i, 2000000) {
        if(tmp[i] == 0) {
          t = i; break;
        }
      }
    } else {
      // cout << A[i - 1] << endl;
      tmp[A[i - 1]]--;
      tmp[A[i + (M - 1)]]++;
      if(tmp[A[i - 1]] == 0 && A[i - 1] < t) {
        t = A[i - 1];
      }
      if(tmp[A[i + (M - 1)]] == t) {
        for(int k = t + 1; k < 2000000; ++k) {
          if(tmp[k] == 0) {
            t = k; break;
          }
        }
      }
    } 
    ans = min(ans, t);
    // REP(m, 10) cout << tmp[m] << " ";
    // cout << endl; 
  }
  cout << ans << endl;
}