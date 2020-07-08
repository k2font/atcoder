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
  int N; cin >> N;
  vector<int> a(N); REP(i, N) cin >> a[i];
  vector<int> ans(N);
  REP(i, N) {
    ans[i] = 0;
  }
  for(int i = N - 1; i >= 0; --i) {
    int tmp = 0;
    for(int k = i; k < N; k = k + (i + 1)) {
      tmp += ans[k];
    }
    if(tmp % 2 != a[i]) {
      ans[i] = 1;
    }
  }

  int num = 0;
  REP(i, N) {
    if(ans[i] == 1) num++;
  }
  cout << num << endl;

  REP(i, N) {
    if(ans[i] == 1) cout << i + 1 << " ";
  }
  cout << endl;
}