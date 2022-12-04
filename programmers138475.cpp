#include <string>
#include <vector>

using namespace std;
const int maxi = 5000001;
int countDiv[maxi];//약수의 개수
int maxiNum[maxi];//i~e까지 약수의 개수가 최대인 수

//약수의 개수
void CountDiv(int e){
    for(int i=1;i<=e;i++) countDiv[i] = 1;//약수 1은 존재
    //에라토스테네스의 체 원리 응용
    for(int i=2;i<=e;i++){
        for(int j=i;j<=e;j+=i) countDiv[j]++;
    }
}
//어떤 수가 최대 약수 개수인가?
void MaxDivNum(int e){
    int cnt = countDiv[e];//e~e
    int num = e;//해당 숫자
    for(int i=e;i>=1;i--){//i~e까지이므로 역순으로
        if(cnt<=countDiv[i]){//약수의 개수가 기존 이상이라면
            cnt = countDiv[i];
            num = i;//최댓값 갱신
        }
        maxiNum[i] = num;
    }
}
vector<int> solution(int e, vector<int> starts) {
    vector<int> answer;
    CountDiv(e);//1~e까지 약수의 개수
    MaxDivNum(e);//약수 개수가 최대인 수 구하기
    for(int i=0;i<starts.size();i++) answer.push_back(maxiNum[starts[i]]);//정답 넣기
    return answer;
}
