#include <iostream>
using namespace std;
typedef unsigned long long ll;

ll n,t,cnt;
ll chkNum[3] = { 2,7,61 };

//거듭 제곱
ll pow(ll x, ll y, ll mod) {//ret = (x^y)%mod
	ll ret = 1;
	x %= mod;
	while (y) {
		if (y % 2==1) ret = (ret * x) % mod;
		y /= 2;
		x = (x * x) % mod;
	}
	return ret;
}
//밀러 라빈
bool miller(ll x, ll a) {
	if (a%x == 0) return true;//소수
	ll k = x - 1;//a^(x-1)-1
	while (1) {
		ll temp = pow(a, k, x);//a^k(mod x)
		if (temp == x - 1) return true;//소수
		if (k % 2 == 1) return (temp == 1 || temp == x - 1);
		k /= 2;
	}
}

int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	t = 0; n = 0; cnt = 0;
	cin >> t;
    for(int j=0;j<t;j++) {
        cin >> n;
		for (int i = 0; i < 3; i++) {//2,7,61에 대해 판정
			if (!miller(2 * n + 1, chkNum[i])) {//소수가 아니면
				cnt++;
				break;
			}
		}
    }
	cout << t-cnt;
	return 0;
}
