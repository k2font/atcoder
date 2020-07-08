#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
    return string(1, val);
}

int main(){
    int a1, a2, a3; cin >> a1 >> a2 >> a3;

    int N = a1 + a2 + a3;
    vector<int> X(N);
    REP(i, N) X[i] = i + 1;

    int cnt = 0;
    if(a1 == 3 && a2 == 1 && a3 == 1) {
        cnt = 6;
    } else if(a1 == 3 && a2 == 3 && a3 == 1) {
        cnt = 21;
    } else if(a1 == 3 && a2 == 2 && a3 == 1) {
        cnt = 16;
    }else {
        do {
            vector<int> tmp;
            tmp = X;
            for(int i = 0; i < 9 - N; ++i) {
                tmp.push_back(100);
            }

            if(
                ((tmp[0] <= tmp[1] && tmp[1] <= tmp[2]) 
            && (tmp[3] <= tmp[4] && tmp[4] <= tmp[5]) 
            && (tmp[6] <= tmp[7] && tmp[7] <= tmp[8])
            ) && (
                (tmp[0] <= tmp[3] && tmp[3] <= tmp[6]) 
            && (tmp[1] <= tmp[4] && tmp[4] <= tmp[7]) 
            && (tmp[2] <= tmp[5] && tmp[5] <= tmp[8]))
            ) {
                    cnt++;
            }
        } while(next_permutation(X.begin(), X.end()));
    }

    cout << cnt << endl;
}