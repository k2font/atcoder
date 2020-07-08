#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main(){
    string S; cin >> S;

    int min_n = 10000007;
    for(int i = 0; i < S.size() - 1; ++i) {
        string target = "000";
        target[0] = S[i];
        target[1] = S[i + 1];
        target[2] = S[i + 2];

        if(abs(stoi(target) - 753) < min_n) {
            min_n = abs(stoi(target) - 753);
        }
    }

    cout << min_n << endl;
}