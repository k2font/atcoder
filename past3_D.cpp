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
  int N; cin >> N;
  int s = 5;
  vector<string> S(s); REP(i, s) cin >> S[i];
  vector<int> ans;
  for(int i = 0; i < 4 * N + 1; i = i + 4) {
    if(S[0][i + 1] == '.') {
      ans.push_back(1);
    } else {
      if(S[1][i + 1] == '.') {

        if(S[2][i + 1] == '#') {
          if(S[3][i + 1] == '#') {
            ans.push_back(2);
          } else if(S[3][i + 1] == '.') {
            ans.push_back(3);
          }
        } else if(S[2][i + 1] == '.') {
          ans.push_back(7);
        }

      } else if(S[1][i + 1] == '#') {
        if(S[2][i + 1] == '#' && S[3][i + 1] == '#' && S[2][i + 2] == '.') {
          ans.push_back(0);
        } else if(S[2][i + 1] == '#' && S[3][i + 1] == '.' && S[2][i + 2] == '#') {
          if(S[4][i + 1] == '.') {
            ans.push_back(4);
          } else if(S[1][i + 3] == '.') {
            ans.push_back(5);
          } else if(S[1][i + 3] == '#') {
            ans.push_back(9);
          }
        } else { // 6か8
          if(S[1][i + 3] == '.') {
            ans.push_back(6);
          } else if(S[1][i + 3] == '#') {
            ans.push_back(8);
          }
        }
      }
    }
  }
  REP(i, ans.size()) cout << ans[i];
  cout << endl;
}
