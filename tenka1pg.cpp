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
  ll N; cin >> N;
  vector<pair<ll, ll>> ab(N);
  REP(i, N) {
    int a, b;
    cin >> a >> b;
    ab[i] = make_pair(a, b);
  }

  sort(all(ab));

  ll cnt = 0;
  ll max_A = ab[N - 1].first;
  ll max_B = ab[N - 1].second;
  ll min_A = ab[0].first;
  ll min_B = ab[0].second;
  // cout << max_A << " " << min_A << " " << max_B << " " << min_B << endl;
  cnt = (max_A - min_A) + 1 + max_B + (min_A - 1);
  cout << cnt << endl;
}
