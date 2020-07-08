#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
    return string(1, val);
}


int main() {
    int N; cin >> N;
    vector<int> a(N); REP(i, N) cin >> a[i];

    int red = 0;
    map<string, int> m;

    REP(i, N) {
        if(1 <= a[i] && a[i] <= 399) {
            m["灰"]++;
        } else if(400 <= a[i] && a[i] <= 799) {
            m["茶"]++;
        } else if(800 <= a[i] && a[i] <= 1199) {
            m["緑"]++;
        } else if(1200 <= a[i] && a[i] <= 1599) {
            m["水"]++;
        } else if(1600 <= a[i] && a[i] <= 1999) {
            m["青"]++;
        } else if(2000 <= a[i] && a[i] <= 2399) {
            m["黄"]++;
        } else if(2400 <= a[i] && a[i] <= 2799) {
            m["橙"]++;
        } else if(2800 <= a[i] && a[i] <= 3199) {
            m["赤"]++;
        } else {
            red++;
        }
    }

    int cnt = 0;
    for(auto itr = m.begin(); itr != m.end(); ++itr) {
        int i = itr->second;
        if(i > 0) cnt++;
    }

    if(8 - cnt < red) {
        cout << cnt << " " << red + cnt << endl;
    } else if(cnt == 0) {
        cout << 1 << " " << red << endl;
    } else {
        cout << cnt << " " << red + cnt << endl;
    }
}