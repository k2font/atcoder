#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using P = pair<int, int>;
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
  int N; cin >> N;
  vector<pair<int, pair<int, int>>> p;
  REP(i, N) {
    int a, b; cin >> a >> b;
    p.push_back(make_pair(i, make_pair(a, b)));
  }
  int tmp = 0;
  double res = 0;
  do {
    tmp++;
    for(int i = 0; i < N - 1; ++i) {
      res += sqrt(pow(p[i].second.first - p[i + 1].second.first, 2) + pow(p[i].second.second - p[i + 1].second.second, 2));
    }
  } while(next_permutation(p.begin(),p.end()));
  double ans = res / (double)tmp;
  cout << fixed << setprecision(15) << ans << endl;
}