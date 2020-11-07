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

const int MOD = 1000000007;
using mint = Fp<MOD>;

// 多次元 vector 生成
template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
  return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

int main() {
  int N; cin >> N;
  mint ans = 1;
  // dp[i文字目][3文字前][2文字前][1文字前]
  // 直近3文字分のみ確認する。次の文字を足したときの場合の数を計算する。
  auto dp = make_vec<mint>(N + 1, 5, 5, 5); dp[0][0][0][0] = 1;
  for(int n = 0; n < N; ++n) {
    for(int i = 0; i < 5; ++i) {
      for(int j = 0; j < 5; ++j) {
        for(int k = 0; k < 5; ++k) {
          for(int l = 1; l < 5; ++l) { // 4文字目として追加する文字は、0からではなく1から始める。
            // なぜなら、0はダミーなので、0を4文字目に加えると余計なものが足されてしまう。
            // ngパターンを列挙している
            if(i == 1 && j == 2 && l == 3) continue;
            if(i == 1 && k == 2 && l == 3) continue;
            if(j == 1 && k == 2 && l == 3) continue;
            if(j == 2 && k == 1 && l == 3) continue;
            if(j == 1 && k == 3 && l == 2) continue;
            dp[n + 1][j][k][l] += dp[n][i][j][k]; // 文字をスライドさせる
          }
        }
      }
    }
  }
  mint res = 0;
  for(int i = 1; i < 5; ++i) {
    for(int j = 1; j < 5; ++j) {
      for(int k = 1; k < 5; ++k) {
        res += dp[N][i][j][k];
      }
    }
  }
  cout << res << endl;
}