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
  vector<int> A(N); REP(i, N) cin >> A[i];
  vector<int> odd(N); REP(i, N) odd[i] = 0;
  vector<int> even(N); REP(i, N) even[i] = 0;
  ll INF = pow(10, 9) + 7;
  if(N % 2 == 1) {
    for(int i = 0; i < N; ++i) {
      odd[A[i]]++;
    }
    bool flag = false;
    for(int i = 1; i < N; ++i) {
      if(i % 2 == 0) {
        if(odd[i] != 2) {
          flag = true;
        }
      }
    }
    if(flag == true) cout << 0 << endl;
    else {
      ll ans = 1;
      for(int i = 0; i < (N - 1) / 2; ++i) {
        ans *= 2;
        ans %= INF;
      }
      cout << ans << endl;
    }
  } else {
    for(int i = 0; i < N; ++i) {
      even[A[i]]++;
    }
    bool flag = false;
    for(int i = 1; i < N; ++i) {
      if(i % 2 == 1) {
        if(even[i] != 2) {
          flag = true;
        }
      }
    }
    if(flag == true) cout << 0 << endl;
    else {
      ll ans = 1;
      for(int i = 0; i < N / 2; ++i) {
        ans *= 2;
        ans %= INF;
      }
      cout << ans << endl;
    }
  }
}
