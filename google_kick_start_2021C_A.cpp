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

bool kaibun(string str){
  bool f = true;
  for(int i = 0; i < str.size(); ++i) {
    if(str[i] != str[str.size() - (i + 1)]) f = false;
  }
  if(f) return true;
  else return false;
}

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

ll N, K; string S;
// vector<string> ans;
// void dfs(string t) {
//   if(t.size() == N) {
//     // 回分の判定
//     if(kaibun(t) && t < S) {
//       ans.push_back(t);
//     }
//     return;
//   }
//   char tar = 'v';
//   if(K == 1) tar = 'a';
//   if(K == 2) tar = 'b';
//   if(K == 3) tar = 'c';
//   if(K == 4) tar = 'd';
//   if(K == 5) tar = 'e';
//   for(char i = 'a'; i <= tar; ++i) {
//     t += i;
//     dfs(t);
//     t.pop_back();
//   }
// }

int main() {
  int T; cin >> T;
  REP(t, T) {
    cin >> N >> K >> S;
    char tar = 'a' + (K - 1);
    // cout << tar - 'a' + 1 << endl;
    string s_tmp = S.substr(0, ceil((double)N / 2.0)); reverse(all(s_tmp));
    mint ans = 0; mint k = 1; 
    REP(i, s_tmp.size()) {
      mint tmp = char_to_int(s_tmp[i] - 49);
      ans += tmp * k;
      k *= K;
    }

    string hantei = S.substr(0, N / 2);
    hantei += s_tmp;
    if(hantei < S) ans += 1;

    cout << "Case #" << t + 1 << ": " << ans << endl;
  }
}