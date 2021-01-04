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
  ll A, B, C, K; cin >> A >> B >> C >> K;
  ll ans = 0;
  for(int i = 0; i < K; ++i) {
    if(A > 0) {
      ++ans; --A;
    } else if(B > 0) {
      --B;
    } else {
      --ans; --C;
    }
  }
  cout << ans << endl;
}