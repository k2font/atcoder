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
  string N; cin >> N;
  if(N.size() == 1) {
    if(N[0] == '2' || N[0] == '4' || N[0] == '5' || N[0] == '7' || N[0] == '9') {
      cout << "hon" << endl;
    } else if(N[0] == '0' || N[0] == '1' || N[0] == '6' || N[0] == '8') {
      cout << "pon" << endl;
    } else if(N[0] == '3') {
      cout << "bon" << endl;
    }
  } else if(N.size() == 2) {
    if(N[1] == '2' || N[1] == '4' || N[1] == '5' || N[1] == '7' || N[1] == '9') {
      cout << "hon" << endl;
    } else if(N[1] == '0' || N[1] == '1' || N[1] == '6' || N[1] == '8') {
      cout << "pon" << endl;
    } else if(N[1] == '3') {
      cout << "bon" << endl;
    }
  } else if(N.size() == 3) {
    if(N[2] == '2' || N[2] == '4' || N[2] == '5' || N[2] == '7' || N[2] == '9') {
      cout << "hon" << endl;
    } else if(N[2] == '0' || N[2] == '1' || N[2] == '6' || N[2] == '8') {
      cout << "pon" << endl;
    } else if(N[2] == '3') {
      cout << "bon" << endl;
    }
  }
}
