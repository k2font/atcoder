#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c; cin >> a >> b >> c;

    int min_n = min({a + b, a + c, b + c});

    cout << min_n << endl;
}