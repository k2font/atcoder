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

const int MOD = 1'000'000'007;
using mint = Fp<MOD>;

int main() {
  ll N, K; cin >> N >> K;
  vector<ll> A(N); REP(i, N) cin >> A[i];
  // 絶対値が大きい順番にとっていきたいよね
  mint ans = 1;
  // まずは絶対値が大きい順番にK個拾って掛け合わせる
  vector<ll> tmp; // 配列に一旦入れておかないと出し入れできなくなる！
  vector<pair<ll, ll>> so;

  // 絶対値が大きい順番に並べる
  int t = 0;
  REP(i, N) {
    so.push_back(make_pair(abs(A[i]), A[i]));
  }

  // もしすべて負の値かつKが奇数であれば小さい順番に拾っていく
  if(t == N && K % 2 == 1) {
    sort(all(so));
    REP(i, K) ans *= so[i].second;
    cout << ans << endl;
    return 0;
  } else if(t == N && K % 2 == 0) {
    sort(all(so), greater<pair<ll, ll>>());
    REP(i, K) ans *= so[i].second;
    cout << ans << endl;
    return 0;
  }
  sort(all(so), greater<pair<ll, ll>>());
  REP(i, K) {
    if(so[i].second < 0) t++;
    tmp.push_back(so[i].second);
  }
  REP(i, K) ans *= mint(tmp[i]);

  // tmpの中に負の数が奇数個であれば...
  // 1. tmpの最も大きい(絶対値が小さい)負の数を取り除いて、拾っていない数の中から最も大きい正の数を取り出す

  // 2. tmpの最も小さい正の数を取り除いて、拾っていない数の中から最も小さい(絶対値が大きい)負の数を取り出す

  // 1と2のうち、差分が大きい方を選択してansに格納する

  if(t % 2 == 1) {
    ll m1 = 2e18; ll p1 = 2e18;
    REP(i, K) {
      if(so[i].second < 0) m1 = so[i].second;
    }
    for(int i = K; i < N; ++i) {
      if(so[i].second >= 0) {
        p1 = so[i].second; break;
      }
    }
    bool ok1 = (m1 != 2e18) && (p1 != 2e18);

    ll p2 = 2e18; ll m2 = 2e18;
    REP(i, K) {
      if(so[i].second > 0) {
        p2 = so[i].second;
      }
    }
    for(int i = K; i < N; ++i) {
      if(so[i].second <= 0) {
        m2 = so[i].second; break;
      }
    }
    bool ok2 = (m2 != 2e18) && (p2 != 2e18);

    if(ok1 && ok2) {
      if(p1 * p2 > m1 * m2) {
        ans = ans * p1 / m1;
      } else {
        ans = ans * m2 / p2;
      }
    } else if(ok1) {
      ans = ans * p1 / m1;
    } else if(ok2) {
      ans = ans * m2 / p2;
    } else {
      sort(all(A), greater<ll>());
      ans = 1;
      REP(i, K) ans *= A[i];
    }
  }
 
  cout << ans << endl;
}