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

struct Ruisekiwa2D {
    int VH, VW;
    using T = int;
    vector<vector<T>> v;
    bool needBuild = false;
    Ruisekiwa2D() { }
    Ruisekiwa2D(int w, int h) { init(w, h); }
    void init(int w, int h) {
        needBuild = true;
        VH = h; VW = w;
        v.clear();
        v.resize(h, vector<T>(w));
        REP(y, VH) REP(x, VW) v[y][x] = 0;
    }
    void set(int x, int y, T c) { v[y][x] = c; }
    void add(int x, int y, T c) { v[y][x] += c; }
    void build() {
        REP(y, VH) REP(x, VW) {
            if (0 < y) v[y][x] += v[y - 1][x];
            if (0 < x) v[y][x] += v[y][x - 1];
            if (0 < y && 0 < x) v[y][x] -= v[y - 1][x - 1];
        }
        needBuild = false;
    }
    // [sx,sy]-[tx,ty]
    T get(int sx, int tx, int sy, int ty) {
        if (needBuild) assert(0 && "Need Build");
        if (tx < sx or ty < sy) return 0;
        T rs = v[ty][tx];
        if (0 < sx) rs -= v[ty][sx - 1];
        if (0 < sy) rs -= v[sy - 1][tx];
        if (0 < sx && 0 < sy) rs += v[sy - 1][sx - 1];
        return rs;
    }
};
ll N, K;
vector<vector<ll>> A;

bool solve(ll n) {
  Ruisekiwa2D r2d(N, N);
  REP(y, N) {
    REP(x, N) {
      if(n <= A[y][x]) r2d.add(x, y, 1);
    }
  }

  r2d.build();

  REP(y, N - K + 1) {
    REP(x, N - K + 1) {
      ll t = r2d.get(x, x + K - 1, y, y + K - 1);
      if(t < K * K / 2 + 1) return false;
    }
  }

  return true;
}

int main() {
  cin >> N >> K;
  A.resize(N, vector<ll>(N));
  REP(i, N) {
    REP(k, N) {
      cin >> A[i][k];
    }
  }

  ll ok = 0; ll ng = 2e18;
  while(abs(ok - ng) > 1) {
    ll mid = (ok + ng) / 2;
    if(solve(mid)) ok = mid;
    else ng = mid;
  }
  cout << ok << endl;
}