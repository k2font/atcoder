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
  string S; cin >> S;
  map<char, int> m;
  REP(i, S.size()) m[S[i]]++;
  char tmp = 'a' - 1; char ans; int cnt = 0; bool sw = false;
  for(auto x : m) {
    cnt++;
    if(x.first - tmp == 1) {
      tmp = x.first;
      continue;
    } else {
      ans = tmp + 1;
      sw = true;
      break;
    }
  }
  if(m.size() == 26) {
    if(S[S.size() - 1] == 'z') {
      cout << "Z!!!!" << endl;
    } else {
      S[S.size() - 2] = S[S.size() - 2] + 1;
      S.pop_back();
      cout << S << endl;
    }
  } else {
    if(sw == false) {
      char a = S[S.size() - 1] + 1;
      cout << S + a << endl;
    } else {
      cout << S + ans << endl;
    }
  }
}