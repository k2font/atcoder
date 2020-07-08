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

int A, B;

int digits(int num) {
  int ans = 0;
  for(int i = 1; i <= num; ++i) {
    int tmp = i;
    int res = 0;
    while(tmp > 0) {
      int a = tmp % 10;
      res += a;
      tmp = tmp / 10;
    }
    if(A <= res && res <= B) ans += i;
  }
  return ans;
}

int main() {
  int N; cin >> N;
  cin >> A >> B;
  cout << digits(N) << endl;
}