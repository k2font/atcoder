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

int m, n;
vector<vector<int>> a;
int cnt;
vector<vector<bool>> flag;
int ans = 0;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

void dfs(int p, int q, int count) {
  flag[p][q] = 1;
  for(int i = 0; i < 4; ++i) {
    if(p + dx[i] < 0 || p + dx[i] >= n) continue;
    if(q + dy[i] < 0 || q + dy[i] >= m) continue;
    if(flag[p + dx[i]][q + dy[i]] == 0 && a[p + dx[i]][q + dy[i]] == 1) {
      dfs(p + dx[i], q + dy[i], count + 1);
      if(ans < count + 1) ans = count + 1;
    }
  }
  flag[p][q] = 1;
}

int main() {
  cin >> m >> n; a.resize(n);
  flag.resize(n);
  REP(i, n) {
    REP(k, m) {
      int p; cin >> p;
      a[i].push_back(p);
      flag[i].push_back(0);
    }
  }
  REP(i, n) {
    REP(k, m) {
      cnt = 1;
      if(a[i][k] == 1) dfs(i, k, cnt);
      REP(p, n) {
        REP(q, m) {
          flag[p][q] = 0;
        }
      }
    }
  }
  cout << ans << endl;
}
