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
  int N, K; cin >> N >> K;
  vector<int> A(N); REP(i, N) cin >> A[i];
  vector<int> imos(N + 1); REP(i, N + 1) imos[i] = 0;
  REP(i, K) {
    int flag_s = 0;
    int flag_g = 0;
    REP(n, N) {
      int start = ceil((n + 1) - A[n] - 0.5);
      int end = floor((n + 1) + A[n] + 0.5);
      if(start < 1) {
        imos[0]++;
        flag_s++;
      } else {
        imos[start - 1]++;
      }

      if(end >= N) {
        imos[N]--;
        flag_g++;
      } else {
        imos[end]--;
      }
    }
    REP(m, N) {
      if(m == 0) A[m] = imos[m];
      else {
        A[m] = imos[m] + A[m - 1];
        imos[m - 1] = 0;
      }
    }
    imos[N - 1] = 0;
    if(flag_s == N && flag_g == N) {
      break;
    }
  }
  REP(i, N) {
    cout << A[i] << " ";
  }
  cout << endl;
}