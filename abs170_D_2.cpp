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

map< int, int > prime_factor(int n) {
  map< int, int > ret;
  for(int i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return ret;
}

int main() {
  int N; cin >> N;
  vector<int> A(N); REP(i, N) cin >> A[i];
  sort(all(A));
  vector<int> res(1000005); REP(i, 1000005) res[i] = 0;
  int ans = 0;

  for(int i = 0; i < N; ++i) {
    if(res[A[i]] > 1) continue;
    for(int k = A[i]; k < 1000005; k += A[i]) {
      res[k]++;
      if(k > A[N - 1] + 1) break;
    }
  }

  REP(i, N) {
    if(res[A[i]] == 1) ans++;
  }

  if(N == 1) cout << 1 << endl;
  else cout << ans << endl;
}
