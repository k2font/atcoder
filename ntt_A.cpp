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
  int A, B; cin >> A >> B;
  int ans = 0;
  if(A <= 5) {
    if(B <= 5) {
      ans += (B - A);
    } else {
      ans += (5 - A);
    }
  }
  if(B >= 22 && B <= 29) {
    if(A >= 22 && A <= 29) {
      ans += (B - A);
    } else {
      ans += (B - 22);
    }
  } else if(B > 29) {
    if(A >= 22 && A <= 29) {
      ans += (29 - A);
    } else if(A < 22) {
      ans += 7;
    }
  }
  if(B >= 47) ans++;
  cout << ans << endl;
}
