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
  vector<int> A(N); REP(i, N) cin >> A[i];
  vector<int> tmp_A; tmp_A = A;
  sort(all(tmp_A));
  int max_n = tmp_A[N - 1];
  int max_n2 = tmp_A[N - 2];

  REP(i, N) {
    if(A[i] == max_n) {
      cout << max_n2 << endl;
    } else {
      cout << max_n << endl;
    }
  }
}