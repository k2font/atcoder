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
int vector_finder(std::vector<ll> vec, int number) {
  auto itr = std::find(vec.begin(), vec.end(), number);
  size_t index = std::distance( vec.begin(), itr );
  if (index != vec.size()) { // 発見できたとき
    return 1;
  }
  else { // 発見できなかったとき
    return 0;
  }
}

int main() {
  int N; cin >> N;
  vector<ll> A(N); REP(i, N) cin >> A[i];
  ll mon = 1000; ll kabu = 0;
  REP(i, N - 1) {
    if(A[i] < A[i + 1] && mon >= A[i]) {
      kabu = mon / A[i];
      mon = mon % A[i];
    } else if(A[i] > A[i + 1] && kabu != 0) {
      mon = mon + (kabu * A[i]);
      kabu = 0;
    }

    if(i == N - 2) {
      if(A[i] <= A[N - 1]) {
        if(kabu == 0) continue;
        mon = mon + (kabu * A[N - 1]);
      } else if(A[i] > A[N - 1]) {
        if(kabu == 0) continue;
        mon = mon + (kabu * A[i]);
      }
    }
  }
  cout << mon << endl;
}