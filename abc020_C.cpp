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

#define rep(i,n) for(int i=0;i<(n);i++)

ll H, W, T; 
vector<string> s;
int startx; int starty; int goalx; int goaly;
bool solve(int m){
    ll memo[12][12];
    rep(i, 12)rep(j, 12)memo[i][j] = 1e9 * 10;//mより大きな値で初期化しておかないと
    priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<tuple<ll, int, int>> > q;
    q.push(make_tuple(0, startx, starty));
    memo[startx][starty] = 0;
    while(!q.empty()){
        ll c; int y, x;
        tie(c, x, y) = q.top(); q.pop();
        rep(i, 4){
            int ny = y + dy[i], nx = x + dx[i];
            if(!(0 <= ny && ny < W && 0 <= nx && nx < H)) continue;
            if(s[nx][ny] == '#'){
                if(memo[nx][ny] > c + m){//最小値が更新
                    memo[nx][ny] = c + m;
                    q.push(make_tuple(c + m, nx, ny));
                }
            }else{//最小値を更新
                if(memo[nx][ny] > c + 1){
                    memo[nx][ny] = c + 1;
                    q.push(make_tuple(c + 1, nx, ny));
                }
            }
        }
    }
    if(memo[goalx][goaly] <= T) return true;
    else return false;
}

int main() {
  // 最小値の最大化なので、二分探索をしながらBFSする
  cin >> H >> W >> T;
  s.resize(H); REP(i, H) cin >> s[i];

  // スタートとゴールの特定
  REP(i, H) {
    REP(k, W) {
      if(s[i][k] == 'S') {
        startx = i; starty = k;
      }
      if(s[i][k] == 'G') {
        goalx = i; goaly = k;
      }
    }
  }

  // 答えを探索する
  ll ng = 1;
	ll ok = 1e9;
  while(abs(ok - ng) > 1) {
		ll mid = (ok + ng) / 2;
		if(solve(mid)) {
			ng = mid;
		} else {
			ok = mid;
		}
	}

  cout << ng << endl;
}