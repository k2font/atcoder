#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using P = pair<ll, ll>;
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

ll N;
vector<ll> A;
void dfs(ll i) {
  if(i <= N && i != 0) {
    map<ll, ll> m;
    string check = to_string(i);
    REP(i, check.size()) {
      m[check[i]]++;
    }
    if(m.size() == 3) A.push_back(i);
  }
  if(i > N || to_string(i).size() >= 13) return;
  dfs(i * 10 + 3);
  dfs(i * 10 + 5);
  dfs(i * 10 + 7);
}

int main() {
  cin >> N;
  dfs(3); dfs(5); dfs(7);
  cout << A.size() << endl;
}