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
  int N, M; cin >> N >> M;
  vector<int> k(M); vector<vector<int>> s(M);
  vector<int> p(M);
  REP(i, M) {
    cin >> k[i];
    REP(m, k[i]) {
      int S; cin >> S;
      s[i].push_back(S);
    }
  }
  REP(i, M) cin >> p[i];
  int ans = 0;
  for(int bit = 0; bit < (1 << N); ++bit) {
    int res = 0;
    REP(m, M) {
      int tmp = 0;
      for(int i = 0; i < k[m]; ++i) {
        if(bit & (1 << (s[m][i]) - 1)) {
          tmp++;
        }
      }
      if(tmp % 2 == p[m]) res++;
    }
    if(res == M) ans++;
  }
  cout << ans << endl;
}