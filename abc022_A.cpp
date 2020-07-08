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
  int N, S, T; cin >> N >> S >> T;
  int W; cin >> W;
  vector<int> A(N); for(int i = 1; i < N; ++i) cin >> A[i];

  int cnt = 0;
  for(int i = 0; i < N; ++i) {
    if(i == 0) {
      if(S <= W && W <= T) {
        cnt++;
      }
      continue;
    }

    W += A[i];
    if(S <= W && W <= T) {
      cnt++;
    }
  }
  cout << cnt << endl;
}