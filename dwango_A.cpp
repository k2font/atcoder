#include <bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N;
    vector<string> s(N);
    vector<int> t(N); for(int i = 0; i < N; ++i) cin >> s[i] >> t[i];
    string X; cin >> X;

    bool flag = false;
    int res = 0;

    for(int i = 0; i < N; ++i) {
        if(X == s[i]) {
            flag = true;
            continue;
        }

        if(flag == true) {
            res += t[i];
        }
    }

    cout << res << endl;
}