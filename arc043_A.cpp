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
  ll N, A, B; cin >> N >> A >> B;
  vector<double> S(N); REP(i, N) cin >> S[i];
  double P = (double)B / (*max_element(all(S)) - *min_element(all(S)));
  ll sum_n = accumulate(all(S), 0LL);
  double Q = A - (P * sum_n / N);
  if(P >= pow(10, 18) || Q >= pow(10, 18)) cout << -1 << endl;
  else cout << fixed << setprecision(10) << P << " " << Q << endl;
}