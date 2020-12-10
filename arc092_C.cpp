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
struct edge {
  ll to, cost;
};

const int inf = 2e9;
#define fore(i,a) for(auto &i:a)
struct BipartiteMatching {
    vector<vector<int>> E; int n, m; vector<int> match, dist;
    void init(int _n,int _m){n=_n,m=_m;E.resize(n+m+2);match.resize(n+m+2);dist.resize(n+m+2);}
    bool bfs() {
        queue<int> que;
        for(int i = 1; i < n + 1; ++i) {
            if (!match[i]) dist[i] = 0, que.push(i);
            else dist[i] = inf;
        }
        dist[0] = inf;
        while (!que.empty()) {
            int u = que.front(); que.pop();
            if (u) fore(v, E[u]) if (dist[match[v]] == inf) {
                dist[match[v]] = dist[u] + 1;
                que.push(match[v]);
            }
        }
        return (dist[0] != inf);
    }
    bool dfs(int u) {
        if (u) {
            fore(v, E[u]) if (dist[match[v]] == dist[u] + 1) if (dfs(match[v])) {
                match[v] = u; match[u] = v;
                return true;
            }
            dist[u] = inf;
            return false;
        }
        return true;
    }
    void add(int a, int b) { b += n; E[a + 1].push_back(b + 1); E[b + 1].push_back(a + 1); }
    int whois(int x) { return match[x + 1] - 1; }
    int solve() {
        for(int i = 0; i < n + m + 1; ++i) match[i] = 0;
        int res = 0;
        while (bfs()) for(int i = 1; i < n + 1; ++i) if (!match[i] && dfs(i)) res++;
        return res;
    }
};

int main() {
  int N; cin >> N;
  vector<int> a(N), b(N), c(N), d(N);
  REP(i, N) cin >> a[i] >> b[i];
  REP(i, N) cin >> c[i] >> d[i];
  BipartiteMatching bm;
  bm.init(N, N);
  REP(i, N) {
    REP(k, N) {
      if(a[i] < c[k] && b[i] < d[k]) bm.add(i, k);
    }
  }
  cout << bm.solve() << endl;
}