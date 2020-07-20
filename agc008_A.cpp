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
  ll x, y; cin >> x >> y;
  ll ans = 0;
  if(y - x >= 0) {
    if(x < 0 && y >= 0) {
      if(abs(x) <= y) {
        ans++;
        ans += (y - abs(x));
      } else {
        if(y == 0) {
          ans += ((-y) - x);
        } else {
          ans++;
          ans += ((-y) - x);
        }
      }
    } else {
      ans += (y - x);
    }
  } else {
    if(x < 0) {
      ans += 2;
      ans += (abs(y) - abs(x));
    } else if(x >= 0 && y < 0) {
      if(y < -x) {
        ans++;
        ans += (abs(y) - abs(x));
      } else {
        ans++;
        ans += (y - (-x));
      }
    } else {
      if(y == 0) {
        ans++;
      } else {
        ans += 2;
      }
      ans += (x - y);
    }
  }
  cout << ans << endl;
}