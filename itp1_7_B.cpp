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
  int n = 0; int x = 0;
  cin >> n >> x;
  while(n != 0 || x != 0) {
    int ans = 0;
    for(int i = 1; i <= n; ++i) {
      for(int k = i; k <= n; ++k) {
        if(i == k) continue;
        if(x - i - k > 0 && x - i - k <= n && x - i - k != i && x - i - k != k && i < x - i - k && k < x - i - k) {
          ans++;
        }
      }
    }
    cout << ans << endl;
    cin >> n >> x;
  }
}