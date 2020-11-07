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
  // cout << 298023223876953125 + 450283905890997363 << endl;
  ll N; cin >> N;
  ll A = 1; 
  for(int i = 1; i < 100; ++i) {
    A *= 3; ll B = 1;
    for(int k = 1; k < 100; ++k) {
      B *= 5;
      // cout << B << endl;
      if(A + B < 0) continue;
      if(A + B == N) {
        cout << i << " " << k << endl;
        return 0;
      }
    }
  }
  cout << -1 << endl;
}
