#include <iostream>
#include <complex>
#include <vector>
#include <algorithm>
using namespace std;

const double PI = acos(-1);//PI값 지정
typedef complex<double> cpx;//복소수

string a, b;
vector<cpx> x, y, z;

//n-1차 다항식 f를 n개의 복소수로 dft함, x=w
void FFT(vector<cpx>& f, cpx w) {
    int n = f.size();//f의 길이
    if (n == 1) return;//분할 종료

    //다항식 분리(홀, 짝으로)
    vector<cpx> even(n / 2), odd(n / 2);
    for (int i = 0; i < n; i++) {
        (i % 2 ? odd : even)[i / 2] = f[i];
    }

    //분할
    FFT(even, w * w);
    FFT(odd, w * w);

    cpx wp(1);//1+0i

    for (int i = 0; i < n / 2; i++) {
        //앞 : f(x) = f_even(x^2)+x*f_odd(x^2);
        f[i] = even[i] + wp * odd[i];
        //뒤 : f(-x) = f_even(x^2)-x*f_odd(x^2);
        f[i + n / 2] = even[i] - wp * odd[i];
        wp *= w;
    }
}
//h(x)=f(x)*g(x), i번째 원소는 x^i의 계수
vector<cpx>multiply(vector<cpx> a, vector<cpx> b) {
    //다항식의 길이보다 큰 최소의 2의 거듭제곱수를 찾아 n으로 둔다.
    int n = 1;//다항식의 길이
    while (n < a.size() + 1 || n < b.size() + 1) n *= 2;
    n *= 2;
    a.resize(n);
    b.resize(n);
    //0+0i로 초기화된 complex원소를 n개 가진다.(길이 n)
    vector<cpx> c(n);

    //cosx+i*sinx
    cpx w(cos(2 * PI / n), sin(2 * PI / n));

    //고속 푸리에 변환을 이용해 DEF한다.
    FFT(a, w);
    FFT(b, w);

    //내적곱
    for (int i = 0; i < n; i++) c[i] = a[i] * b[i];

    //c의 다항식 복원
    FFT(c, cpx(1, 0) / w);//1+0i
    for (int i = 0; i < n; i++) {
        c[i] /= cpx(n);//n으로 나눈다.
        //정수값만 추출(다항식의계수가 정수일때만)
        c[i] = cpx(round(c[i].real()), round(c[i].imag()));
    }
    return c;
}

//입력
void input() {
    cin >> a >> b;

    for (int i = 0; i < a.size(); i++) x.push_back(cpx(a[i] - '0', 0));
    for (int i = 0; i < b.size(); i++) y.push_back(cpx(b[i] - '0', 0));

    //뒤집기
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());

    z = multiply(x, y);//곱하기(역으로 나온다.)
}
//더해주기
void add() {
    int l = z.size();
    int carry = 0;
    vector<int> ans;

    //실수
    for (int i = 0; i < l; i++) {
        int n = (int)round(z[i].real()) + carry;
        carry = n / 10;//받아 올림
        ans.push_back(n % 10);
    }
    //마지막 자리
    while (carry > 0) {
        ans.push_back(carry % 10);
        carry /= 10;
    }
    //0 예외처리
    int i = ans.size() - 1;
    while(i >= 0) {
        if (ans[i] != 0) break;
        i--;
    }
    if (i < 0) cout << 0;
    else{
        while (i >= 0) {
            cout << ans[i];
            i--;
        }
    }
}

int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
    input();//입력
    add();//더해주기
	return 0;
}
