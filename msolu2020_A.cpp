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
  int X; cin >> X;
  if(X >= 400 && X <= 599) {
    cout << 8 << endl;
  } else if(X >= 600 && X <= 799) {
    cout << 7 << endl;
  } else if(X >= 800 && X <= 999) {
    cout << 6 << endl;
  } else if(X >= 1000 && X <= 1199) {
    cout << 5 << endl;
  } else if(X >= 1200 && X <= 1399) {
    cout << 4 << endl;
  } else if(X >= 1400 && X <= 1599) {
    cout << 3 << endl;
  } else if(X >= 1600 && X <= 1799) {
    cout << 2 << endl;
  } else if(X >= 1800 && X <= 1999) {
    cout << 1 << endl;
  } 
}