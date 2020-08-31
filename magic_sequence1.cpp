// https://open.kattis.com/problems/magicsequence
// Radix sort by radix 1e5
#include<iostream>
using namespace std;
/*
// DEBUG
#define format(x) << #x << ": " << (x)
#define com << ", "
#define ndl << "\n"
#define debug1(x) cerr format(x) ndl;
#define debug2(x, y) cerr format(x) com format(y) ndl;
#define debug3(x, y, z) cerr format(x) com format(y) com format(z) ndl;
#define debug4(x, y, z, w) cerr format(x) com format(y) com format(z) com format(w) ndl;
void debug_out() { cerr << "\n"; }
template <typename H, typename... T> 
void debug_out(H h, T... t) { cerr << " " << (h); debug_out(t...); }
#define DEBUG(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
// 
*/
const int MOD1 = 100000;
const int MOD2 = 10000;
int s[1000000];
int out1[1000000];
int out2[1000000];
int cnt1[3000000];
int cnt2[300000];
int md[3000000];
int tc;
int n;
int a, b, c;
int x, y;
long long pre;
int start1, start2;
int end1, end2;
int i;
long long v;
int main() {
	cin >> tc;
	end1 = MOD1;
	end2 = MOD2;
	while (tc--) {
		cin >> n >> a >> b >> c >> x >> y;
		cnt1[(md[0] = start1 + (s[0] = pre = a) % MOD1)]++;
		//DEBUG(0, s[0]);
		for (i = 1; i < n; i++) {
			//DEBUG('(', pre, '*', b, '+', a, ')', '%', c, '=', (pre * b + a) % c);
			s[i] = (pre = (pre * b + a) % c);
			cnt1[(md[i] = start1 + pre % MOD1)]++;
			//DEBUG(i, s[i]);
		}
		for (i = start1 + 1; i < end1; i++) {
			cnt1[i] += cnt1[i - 1];
		}
		for (i = n - 1; i > -1; i--) {
			out1[(--cnt1[md[i]])] = s[i];
		}
		for (i = 0; i < n; i++) {
			//DEBUG(i, out1[i]);
			cnt2[(md[i] = start2 + (out1[i] / MOD1) % MOD2)]++;
		}
		for (i = start2 + 1; i < end2; i++) {
			cnt2[i] += cnt2[i - 1];
		}
		for (i = n - 1; i > -1; i--) {
			out2[(--cnt2[md[i]])] = out1[i];
		}
		v = 0;
		for (i = 0; i < n; i++) {
			//DEBUG(i, out2[i]);
			//DEBUG('(', v, '*', x, '+', out2[i], ')', '%', y, '=', (v * x + out2[i]) % y);
			v = (v * x + out2[i]) % y;
		}
		cout << v << "\n";
		start1 += MOD1;
		start2 += MOD2;
		end1 += MOD1;
		end2 += MOD2;
	}
	return 0;
}

