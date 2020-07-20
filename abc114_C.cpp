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

ll N;
vector<string> ans;
void dfs(string s) {
  if(stoll(s) > N) return;
  if(s.size() > 10) return;
  if(s.size() <= 10 && s.size() > 2) {
    bool flag = false;
    map<char, int> m; m['3'] = 0; m['5'] = 0; m['7'] = 0;
    REP(i, s.size()) m[s[i]]++;
    if(m['3'] > 0 && m['5'] > 0 && m['7'] > 0) flag = true;
    if(flag == true) ans.push_back(s);
  }
  dfs(s + "3");
  dfs(s + "5");
  dfs(s + "7");
}

int main() {
  cin >> N;
  dfs("3");
  dfs("5");
  dfs("7");
  cout << ans.size() << endl;
}
