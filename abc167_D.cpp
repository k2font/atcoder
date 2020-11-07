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
  ll N, K; cin >> N >> K;
  vector<ll> A(N);
  REP(i, N) {
    cin >> A[i];
    A[i]--;
  }
  vector<ll> memo(N, -1); ll ans = 0; ll tmp = 0;
  for(ll i = 0; i < K; ++i) {
    if(memo[A[tmp]] != -1) {
      const ll t = i - memo[A[tmp]]; // ループ1周分の長さ
      const ll c = (K - i - 1) / t; // ループはあと何周するか？
      i += t * c;
    } else {
      memo[A[tmp]] = i;
    }
    tmp = A[tmp];
  }
  cout << tmp + 1 << endl;
}