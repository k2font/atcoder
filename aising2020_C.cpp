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
  for(int i = 1; i <= N; ++i) {
    int ans = 0;
    bool flag = false;
    for(int k = 1; k <= 100; ++k) {
      int x = k * k;
      for(int m = 1; m <= 100; ++m) {
        int y = m * m;
        ll res = x + y + (k * m);
        if(res > i) {
          break;
        }
        for(int l = 1; l <= 100; ++l) {
          int z = l * l;
          ll tmp = x + y + z + (k * m) + (m * l) + (l * k);
          if(tmp > i) {
            break;
          }
          if(i == tmp) {
            ans++;
          }
        }
      }
    }
    cout << ans << endl;
  }
}