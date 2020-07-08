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
struct edge {
  ll to, cost;
};

int main() {
  ll N; cin >> N;
  vector<ll> A(N); REP(i, N) cin >> A[i];
  ll Q; cin >> Q;
  vector<ll> B(Q), C(Q); REP(i, Q) cin >> B[i] >> C[i];
  map<ll, ll> m;
  ll ans = accumulate(all(A), 0LL);
  REP(i, N) {
    m[A[i]]++;
  }
  for(int i = 0; i < Q; ++i) {
    ll tmp = m[B[i]];
    ll res = C[i] * tmp - B[i] * tmp;
    ll a = ans + res;
    ans += res;
    cout << a << endl;
    m[C[i]] += m[B[i]];
    m[B[i]] = 0;
  }
}