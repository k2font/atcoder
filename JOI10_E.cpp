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
  int H, W, N; cin >> H >> W >> N;
  vector<string> S(H); REP(i, H) cin >> S[i];
  vector<vector<int>> flag(H);
  int s, g;
  REP(i, H) {
    REP(k, W) {
      flag[i].push_back(-1);
      if(S[i][k] == 'S') {
        s = i;
        g = k;
      }
    }
  }
  int t_s = s, t_g = g;
  for(int m = 1; m <= N; ++m) {
    queue<pair<int, int>> Q;
    Q.push(make_pair(t_s, t_g));
    const int dx[4] = {1, 0, -1, 0};
    const int dy[4] = {0, -1, 0, 1};
    while(!Q.empty()) {
      auto q = Q.front(); Q.pop();
      for(int i = 0; i < 4; ++i) {
        if(q.first + dx[i] < 0 || q.first + dx[i] >= H) continue;
        if(q.second + dy[i] < 0 || q.second + dy[i] >= W) continue;
        if(S[q.first + dx[i]][q.second + dy[i]] == 'X') continue;
        if(flag[q.first + dx[i]][q.second + dy[i]] != -1) continue;
        Q.push(make_pair(q.first + dx[i], q.second + dy[i]));
        flag[q.first + dx[i]][q.second + dy[i]] = flag[q.first][q.second] + 1;
      }
      char d = '0' + m;
      if(S[q.first][q.second] == d) {
        t_s = q.first; t_g = q.second;
        break;
      }
    }
    REP(i, H) {
      REP(k, W) {
        if(t_s == i && t_g == k) continue;
        else flag[i][k] = -1;
      }
    }
    if(m == N) {
      cout << flag[t_s][t_g] + 1 << endl;
    }
  }
}
