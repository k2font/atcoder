#include <bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N;
    vector<string> S(N); for(int i = 0; i < N; ++i) cin >> S[i];

    int cnt = 1;
    int rep_cnt = 0;
    int max_n = 0;
    vector<pair<string, int>> a(N);

    sort(S.begin(), S.end());

    for(int i = 1; i < N; ++i) {
        if(i == N - 1) {
            if(S.at(i - 1) == S.at(i)) {
                cnt++;
                a[rep_cnt] = make_pair(S.at(i - 1), cnt);
                rep_cnt++;
            } else {
                a[rep_cnt] = make_pair(S.at(i - 1), cnt);
                rep_cnt++;
                a[rep_cnt] = make_pair(S.at(i), 1);
                rep_cnt++;
            }
            if(max_n < cnt) {
                max_n = cnt;
            }
        } else {
            if(S.at(i - 1) == S.at(i)) {
                cnt++;
            } else {
                a[rep_cnt] = make_pair(S.at(i - 1), cnt);
                rep_cnt++;
                if(max_n < cnt) {
                    max_n = cnt;
                }
                cnt = 1;
            }
        }
    }

    for(int i = 0; i < rep_cnt; ++i) {
        if(a[i].second == max_n) {
            cout << a[i].first << endl;
        }
    }
}