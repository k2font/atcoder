#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, K;
    cin >> N >> K;

    string S;
    cin >> S;

    S.at(K - 1) = S.at(K - 1) + 0x20;

    cout << S << endl;
}