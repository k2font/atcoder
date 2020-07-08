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
  double N; cin >> N;
  int a, b, c;
  double tmp = 4 / N;
  bool flag = false;
  for(int i = 1; i <= 3500; ++i) {
    for(int k = 1; k <= 3500; ++k) {
      double A = N * i * k;
      double B = 4 * i * k - N * k - N * i;
      double C = A / B;
      if(floor(C) == C && C > 0) {
        a = i; b = k; c = C;
        cout << a << " " << b << " " << c << endl;
      }
    }
  }
  cout << a << " " << b << " " << c << endl;
}