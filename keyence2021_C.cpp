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

// modint: mod 計算を int を扱うように扱える構造体
template<int MOD> struct Fp {
    long long val;
    constexpr Fp(long long v = 0) noexcept : val(v % MOD) {
        if (val < 0) val += MOD;
    }
    constexpr int getmod() { return MOD; }
    constexpr Fp operator - () const noexcept {
        return val ? MOD - val : 0;
    }
    constexpr Fp operator + (const Fp& r) const noexcept { return Fp(*this) += r; }
    constexpr Fp operator - (const Fp& r) const noexcept { return Fp(*this) -= r; }
    constexpr Fp operator * (const Fp& r) const noexcept { return Fp(*this) *= r; }
    constexpr Fp operator / (const Fp& r) const noexcept { return Fp(*this) /= r; }
    constexpr Fp& operator += (const Fp& r) noexcept {
        val += r.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
    constexpr Fp& operator -= (const Fp& r) noexcept {
        val -= r.val;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr Fp& operator *= (const Fp& r) noexcept {
        val = val * r.val % MOD;
        return *this;
    }
    constexpr Fp& operator /= (const Fp& r) noexcept {
        long long a = r.val, b = MOD, u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b; swap(a, b);
            u -= t * v; swap(u, v);
        }
        val = val * u % MOD;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr bool operator == (const Fp& r) const noexcept {
        return this->val == r.val;
    }
    constexpr bool operator != (const Fp& r) const noexcept {
        return this->val != r.val;
    }
    friend constexpr ostream& operator << (ostream &os, const Fp<MOD>& x) noexcept {
        return os << x.val;
    }
    friend constexpr Fp<MOD> modpow(const Fp<MOD> &a, long long n) noexcept {
        if (n == 0) return 1;
        auto t = modpow(a, n / 2);
        t = t * t;
        if (n & 1) t = t * a;
        return t;
    }
};

const int MOD = 998244353;
using mint = Fp<MOD>;

const int MAX = 510000;
long long fac[MAX], finv[MAX], inv[MAX];
 
// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
 
// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

// 多次元 vector 生成を行うテンプレート
template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
  return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

int main() {
  int H, W, K; cin >> H >> W >> K;
  vector<ll> h(K), w(K); vector<string> c(K); REP(i, K) cin >> h[i] >> w[i] >> c[i];
  vector<vector<string>> s(H, vector<string>(W, ""));
  REP(i, K) {
    s[h[i] - 1][w[i] - 1] = c[i];
  }
  // 前処理
  COMinit();

  auto dp = make_vec<ll>(H + 1, W + 1, 3); dp[0][0][0] = 1;

  // DPするんだろうな........................
  // O(HW - K) くらいのやつ
  // dp[i][k][m] := i番目の空いているマスに{R, D, X}を書いたときにそこに到達できる場合の数

  REP(i, H) {
    REP(k, W) {
      REP(m, 3) {
        if(s[i][k] == "R") {
          dp[i + 1][k][m] += dp[i][k][m] + 1;
          dp[i + 1][k][m] %= MOD;
          continue;
        } else if(s[i][k] == "D") {
          dp[i][k + 1][m] += dp[i][k][m] + 1;
          dp[i][k + 1][m] %= MOD;
          continue;
        } else if(s[i][k] == "W") {
          dp[i + 1][k][m] += dp[i][k][m] + 1;
          dp[i + 1][k][m] %= MOD;
          dp[i][k + 1][m] += dp[i][k][m] + 1;
          dp[i][k + 1][m] %= MOD;
          continue;
        } 
        if(m == 0) {
          dp[i + 1][k][m] += dp[i][k][m] + 1;
          dp[i + 1][k][m] %= MOD;
        } else if(m == 1) {
          dp[i][k + 1][m] += dp[i][k][m] + 1;
          dp[i][k + 1][m] %= MOD;
        } else {
          dp[i + 1][k][m] += dp[i][k][m] + 1;
          dp[i + 1][k][m] %= MOD;
          dp[i][k + 1][m] += dp[i][k][m] + 1;
          dp[i][k + 1][m] %= MOD;
        }
      }
    }
  }

  cout << dp[H - 1][W - 1][0] + dp[H - 1][W - 1][1] + dp[H - 1][W - 1][2] << endl;
}
