#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define sq(a) (a) * (a)
#define append push_back
#define bg begin
const ll mod = 1e9 + 7;

vector<int> a;
int n, cmd, num;

int calc_gcd(vector<int> &a) {
	int ans = 0;
	for (int i : a) ans = __gcd(i, ans);
	return ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	// #ifndef ONLINE_JUDGE
	// 	#define file "uni"
	// 	freopen(file".inp", "r", stdin); freopen(file".out", "w", stdout);
	// #endif

	cin >> n;
	while (n--) {
		cin >> cmd >> num;
		if (cmd == 1) a.append(num);
		else a.erase(find(a.bg(), a.end(), num));
		cout << calc_gcd(a) << endl;
	}

	return 0;
}