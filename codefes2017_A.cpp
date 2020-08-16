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
struct edge {
  ll to, cost;
};

int main() {
  string S; cin >> S;
  if(S == "KIHBR") {
    cout << "YES" << endl;
  } else if(S == "AKIHBR" || S == "KIHABR" || S == "KIHBAR" || S == "KIHBRA") {
    cout << "YES" << endl;
  } else if(S == "AKIHABR" || S == "AKIHBAR" || S == "AKIHBRA") {
    cout << "YES" << endl;
  } else if(S == "KIHABAR" || S == "KIHABRA") {
    cout << "YES" << endl;
  } else if(S == "KIHBARA" || S == "AKIHABARA") {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}