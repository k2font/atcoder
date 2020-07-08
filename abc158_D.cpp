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
  int Q; cin >> Q;
  deque<string> ans;
  REP(i, S.size()) ans.push_back(char_to_string(S[i]));
  bool flag = true;
  for(int i = 0; i < Q; ++i) {
    int a; cin >> a;
    if(a == 1) {
      flag = !flag;
    } else if(a == 2) {
      int b; string c;
      cin >> b >> c;
      if(b == 1) {
        if(flag == true) {
          ans.push_front(c);
        } else {
          ans.push_back(c);
        }
      } else if(b == 2) {
        if(flag == true) {
          ans.push_back(c);
        } else {
          ans.push_front(c);
        }
      }
    }
  }
  if(flag == true) {
    REP(i, ans.size()) {
      cout << ans[i];
    }
    cout << endl;
  } else {
    for(int i = ans.size() - 1; i >= 0; --i) {
      cout << ans[i];
    }
    cout << endl;
  }
}