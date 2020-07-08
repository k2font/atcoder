#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
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

int main() {
  int N, M; cin >> N >> M;
  vector<int> A(N); REP(i, N) cin >> A[i];
  map<int, int> m;

  REP(i, N) {
    m[A[i]]++;
  }

  ll ans = -1;
  for(auto x : m) {
    if((x.second >= N / 2 + 1)) {
      ans = x.first;
    }
  }

  if(ans == -1) {
    cout << "?" << endl;
  } else {
    cout << ans << endl;
  }
}