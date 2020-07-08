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
  int x1, y1, r; cin >> x1 >> y1 >> r;
  int x2, y2, x3, y3; cin >> x2 >> y2 >> x3 >> y3;
  int ans = 3;

  int mx, px, my, py;
  mx = x1 - r, px = x1 + r, my = y1 - r, py = y1 + r;
  if(x2 <= mx && mx <= x3 && x2 <= px && px <= x3) {
    if(y2 <= my && my <= y3 && y2 <= py && py <= y3) {
      ans = 1;
    }
  } else {
    double a = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    double b = sqrt(pow((x3 - x1), 2) + pow((y3 - y1), 2));
    double c = sqrt(pow((x2 - x1), 2) + pow((y3 - y1), 2));
    double d = sqrt(pow((x3 - x1), 2) + pow((y2 - y1), 2));
    if(a <= r && b <= r && c <= r && d <= r) {
      ans = 2;
    }
  }

  if(ans == 1) {
    cout << "NO" << endl;
    cout << "YES" << endl; 
  } else if(ans == 2) {
    cout << "YES" << endl;
    cout << "NO" << endl;
  } else if(ans == 3) {
    cout << "YES" << endl;
    cout << "YES" << endl;
  }
}