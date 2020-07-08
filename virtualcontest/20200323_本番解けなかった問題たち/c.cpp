#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
    return string(1, val);
}

int main(){
    int N; cin >> N;
    vector<int> P(N); REP(i, N) cin >> P[i];
    vector<int> Q(N); REP(i, N) cin >> Q[i];

    int a = 0;
    int b = 0;
    int cnt = 0;

    vector<int> v(N);
    int num = 0;
    REP(i, N) {
        v[num] = num + 1;
        num++;
    }

    do{
        for(int i = 0; i < N; ++i){
            if(v == P) {
                a = cnt + 1;
            }

            if(v == Q) {
                b = cnt + 1;
            }
        }
        cnt++;
    } while(next_permutation(v.begin(), v.end()));

    cout << abs(a - b) << endl;
}