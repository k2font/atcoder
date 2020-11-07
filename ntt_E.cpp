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

vector<ll> ans;
vector<ll> t;
void dfs(vector<ll> tmp, map<ll, ll> s) {
  if(tmp.size() >= 3) {
    vector<int> a;
    for(auto x : s) {
      a.push_back(x.second);
    }
    if(a.size() >= 2) {
      if(s.size() == 2 && (a.at(0) == a.at(1) * 2 || a.at(0) * 2 == a.at(1))) {
        ll res = 0;
        REP(i, tmp.size()) {
          res += tmp.at(i);
          if(i != tmp.size() - 1) res *= 10;
        }
        ans.push_back(res);
      }
    }
  }
  if(tmp.size() == 15) return;

  for(int i = 0; i <= 9; ++i) {
    if(tmp.empty() && i == 0) continue;
    s[i]++;
    tmp.push_back(i);
    if(s.size() <= 2) dfs(tmp, s);
    tmp.pop_back();
    if(s[i] == 1) s.erase(i);
    else s[i]--;
  }
}

int main() {
  int K; cin >> K;
  map<ll, ll> p{};
  dfs(t, p);
  sort(all(ans));
  cout << ans.at(K - 1) << endl;
}
