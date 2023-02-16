#include <string>
#include <vector>
using namespace std;
typedef vector<vector<int>> Matrix;

//곱
Matrix mul(Matrix a,Matrix b){
    //행렬 크기 구하기
    int aRow = a.size();int aCol = a[0].size();
    int bRow = b.size();int bCol = b[0].size();
    
    //곱셈
    Matrix res;
    for(int i=0;i<aRow;i++){
        vector<int> Row;
        for(int j=0;j<bCol;j++){
            int num = 0;
            for(int k=0;k<aCol;k++) num+=(a[i][k]*b[k][j]);
            Row.push_back(num);
        }
        res.push_back(Row);
    }
    return res;
}

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    answer = mul(arr1,arr2);
    return answer;
}
