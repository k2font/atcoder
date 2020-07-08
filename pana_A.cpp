#include <bits/stdc++.h>
using namespace std;

int main(){
    int K; cin >> K;

    vector<int> s;
    s = {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};

    cout << s[K - 1] << endl;
}