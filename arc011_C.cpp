#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using P = pair<ll, ll>;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};
string char_to_string(char val) {
  return string(1, val);
}
int char_to_int(char val) {
  return val - '0';
}
char inverse_char(char c) {
  if(isupper(c)) return tolower(c);
  else return toupper(c);
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
struct edge {
  ll to, cost;
};
template <class T> T up(T a, T div) { return (a + div - 1) / div; }

int main() {
  string first, last; cin >> first >> last;
  int N; cin >> N;
  vector<string> s(N); REP(i, N) cin >> s[i];

  // めんどくさいので先に算出する
  if(first == last) {
    cout << 0 << endl;
    cout << first << endl;
    cout << last << endl;
    return 0;
  }

  // firstとlastが1文字のときはグラフ探索せずにOK!
  if(first.size() == 1) {
    cout << 0 << endl;
    cout << first << endl;
    cout << last << endl;
    return 0;
  }

  unordered_map<string, vector<string>> tree(N + 10);
  // スタートから各点、ゴールから各点のグラフを構築する
  REP(i, N) {
    int cnt = 0;
    REP(k, first.size()) {
      if(first[k] == s[i][k]) cnt++;
    }
    if(cnt == first.size() - 1) {
      tree[first].push_back(s[i]);
      tree[s[i]].push_back(first);
    }
  }

  REP(i, N) {
    int cnt = 0;
    REP(k, last.size()) {
      if(last[k] == s[i][k]) cnt++;
    }
    if(cnt == last.size() - 1) {
      tree[last].push_back(s[i]);
      tree[s[i]].push_back(last);
    }
  }

  // 与えられた単語同士のグラフを構築する
  // 自己ループと二重辺は作らないように注意する
  REP(i, N) {
    REP(k, N) {
      if(i >= k) continue;
      if(s[i] == s[k]) continue;
      int cnt = 0;
      REP(m, first.size()) {
        if(s[i][m] == s[k][m]) cnt++;
      }
      if(cnt == first.size() - 1) {
        tree[s[i]].push_back(s[k]);
        tree[s[k]].push_back(s[i]);
      }
    }
  }

  unordered_map<string, bool> visited;
  unordered_map<string, ll> dis;
  REP(i, N) {
    visited[s[i]] = false; dis[s[i]] = 1000000;
  }
  visited[first] = false; visited[last] = false;
  dis[first] = 1000000; dis[last] = 1000000;

  // スタートからゴールまでBFSする O(N^2)
  vector<string> tmp;
  queue<string> q; q.push(first);
  unordered_map<string, string> prev; // 答えを格納する
  dis[first] = 0;
  while(!q.empty()) {
    auto x = q.front(); q.pop();
    if(visited[x] == true) continue; // 必ずvisited判定は、下のfor文ではなく入り口で実施しよう。探索数が爆発するよ！
    visited[x] = true;
    if(x == last) break;
    for(auto p : tree[x]) {
      if(dis[p] > dis[x] + 1) {
        dis[p] = dis[x] + 1;
        prev[p] = x;
      }
      q.push(p);
    }
  }

  // 経路を復元する
  vector<string> ans; ans.push_back(last);
  string p = last;

  if(dis[last] == 1000000) {
    cout << -1 << endl;
    return 0;
  } else {
    while(true) {
      ans.push_back(prev[p]);
      p = prev[p];
      if(p == first) break;
    }
  }

  cout << ans.size() - 2 << endl;
  for(int i = ans.size() - 1; i >= 0; --i) {
    cout << ans[i] << endl;
  }
}