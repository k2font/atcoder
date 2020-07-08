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
  string a, b, c; cin >> a >> b >> c;
  int A = 0, B = 0, C = 0;
  char state = 'a';
  while(true) {
    if(state == 'a') {
      state = a[A];
      A++;
    }

    if(state == 'b') {
      state = b[B];
      B++;
    }

    if(state == 'c') {
      state = c[C];
      C++;
    }

    if(A == a.size() + 1) {
      cout << "A" << endl;
      break;
    }

    if(B == b.size() + 1) {
      cout << "B" << endl;
      break;
    }

    if(C == c.size() + 1) {
      cout << "C" << endl;
      break;
    }
  }
}
