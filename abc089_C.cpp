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

ll combi3(ll a) {
  return (a * (a - 1) * (a - 2)) / 6;
}

ll combi2(ll a) {
  return (a * (a - 1)) / 2;
}

int main() {
    int N; cin >> N;
    vector<string> S(N); REP(i, N) cin >> S[i];

    map<char, ll> m;
    m['M'] = 0;
    m['A'] = 0;
    m['R'] = 0;
    m['C'] = 0;
    m['H'] = 0;

    REP(i, N) {
      if(S[i].at(0) == 'M') m['M']++;
      if(S[i].at(0) == 'A') m['A']++;
      if(S[i].at(0) == 'R') m['R']++;
      if(S[i].at(0) == 'C') m['C']++;
      if(S[i].at(0) == 'H') m['H']++;
    }

    ll A = 0;
    if(m['M'] > 2) A += combi3(m['M']);
    if(m['A'] > 2) A += combi3(m['A']);
    if(m['R'] > 2) A += combi3(m['R']);
    if(m['C'] > 2) A += combi3(m['C']);
    if(m['H'] > 2) A += combi3(m['H']);

    ll B = 0;
    if(m['M'] > 1) B += combi2(m['M']) * (m['A'] + m['R'] + m['C'] + m['H']);
    if(m['A'] > 1) B += combi2(m['A']) * (m['M'] + m['R'] + m['C'] + m['H']);
    if(m['R'] > 1) B += combi2(m['R']) * (m['M'] + m['A'] + m['C'] + m['H']);
    if(m['C'] > 1) B += combi2(m['C']) * (m['M'] + m['A'] + m['R'] + m['H']);
    if(m['H'] > 1) B += combi2(m['H']) * (m['M'] + m['A'] + m['R'] + m['C']);
    
    ll C = combi3(m['M'] + m['A'] + m['R'] + m['C'] + m['H']);
    cout << C - A - B << endl;
}