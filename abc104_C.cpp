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

int D; ll G;
vector<ll> p; vector<ll> c;
ll ans = pow(10, 12);

int main() {
  cin >> D >> G;
  p.resize(D); c.resize(D);
  REP(i, D) cin >> p[i] >> c[i];
  for(int bit = 0; bit < (1 << D); bit++) {
    ll tmp = 0; int res = 0;
    for(int i = 0; i < D; ++i) {
      if(bit & (1 << i)) {
        res += p[i];
        tmp += ((100 * (i + 1)) * p[i] + c[i]);
      }
    }
    if(tmp >= G) {
      if(ans >= res) ans = res; // 答えの更新
      continue;
    }
    // 最も配点の高い問題を1問〜p_i-1問まで試す
    for(int i = D - 1; i >= 0; --i) {
      if(bit & (1 << i)) continue;
      else {
        for(int k = 0; k < p[i]; ++k) {
          tmp += (100 * (i + 1)); res++;
          if(tmp >= G) {
            if(ans >= res) ans = res; // 答えの更新
            break;
          }
        }
        break;
      }
    }
  }
  cout << ans << endl;
}