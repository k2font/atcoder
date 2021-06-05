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

int main() {
  int T; cin >> T;
  REP(i, T) {
    ll N, K, P; cin >> N >> K >> P;
    vector<vector<ll>> a(N, vector<ll>(K));
    vector<vector<ll>> sum(N + 10, vector<ll>(K + 10, 0));
    REP(k, N) {
      REP(m, K) {
        cin >> a[k][m];
      }
    }
    REP(k, N) {
      REP(m, K) {
        sum[k][m + 1] = sum[k][m] + a[k][m];
      }
    }
    // REP(k, N) {
    //   REP(m, K + 1) {
    //     cout << sum[k][m] << " ";
    //   }
    //   cout << endl;
    // }
    vector<vector<ll>> dp(N + 100, vector<ll>(P + 100, 0));
    for(int k = 1; k < N + 1; ++k) {
      REP(m, P + 1) {
        ll min_n = min((ll)m, K);
        REP(q, min_n + 1) {
          // if(k - 1 >= 0) cout << dp[k][m] << " " << dp[k - 1][m - q] + sum[k - 1][q] << endl;
          dp[k][m] = max(dp[k][m], dp[k - 1][m - q] + sum[k - 1][q]);
        }
      }
    }

    // cout << "===" << endl;
    // REP(k, N + 1) {
    //   REP(m, P + 1) {
    //     cout << dp[k][m] << " ";
    //   }
    //   cout << endl;
    // }
    // cout << "===" << endl;

    cout << "Case #" << i + 1 << ": " << dp[N - 1][P - 1] << endl;
  }
}