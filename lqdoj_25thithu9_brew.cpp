#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const ll mod = 1e9 + 7;

ll n, k, a[int(1e5) + 1], ps[int(1e5) + 1], ans = 0, len_doancon, rem, sum;

/*
doancon = so thia duong * (k + 1);

*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
        freopen("BREW.INP", "r", stdin);
        freopen("BREW.OUT", "w", stdout);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ps[i] = ps[i - 1] + a[i];
    }    

    for (int i = 1; i <= ps[n]; i++) { // i = so thia duong
        for (int start = 1; start + i * (k + 1) - 1 <= n; start++) {
            len_doancon = i * (k + 1);
            sum = ps[start + i * (k + 1) - 1] - ps[start - 1];
            rem = len_doancon - sum;
            if (sum * k == rem) ans = len_doancon;
        }
    }

    cout << ans << endl;

    return 0;
}
