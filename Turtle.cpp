#include <iostream>
#include <cmath>

using namespace std;

int main(){
    freopen("turtle.inp","r",stdin);
    freopen("turtle.out","w",stdout);
    int rowNumber,columnNumber;
    int map[1000][1000];
    cin >> rowNumber >> columnNumber;
    for (int i = 1; i <= rowNumber; i++)
        for (int j = 1; j <= columnNumber; j++)
        {
            cin >> map[i][j];
        }
    int res[1001][1001];
    for (int i=0; i <= rowNumber+1; i++)
    {
        for (int j=0; j <= columnNumber+1; j++){
            res[i][j]=-1;
        }
    }
    res[rowNumber][1]=map[rowNumber][1];
    res[rowNumber+1][1]=0;
    res[rowNumber][0]=0;
    for (int i=rowNumber; i>=1; i--)
    {
        for (int j=1; j<=columnNumber; j++){
            res[i][j]=map[i][j]+max(res[i+1][j],res[i][j-1]);
        }
    }
    /*for (int i=1; i <= rowNumber; i++)
    {
        for (int j=1; j <= columnNumber; j++){
            cout << res[i][j] << " ";
        }
        cout<<endl;
    }*/
    cout<<res[1][columnNumber];
    return 0;
    
}