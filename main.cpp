#include <iostream>
#include <cmath>

using namespace std;

int main(){
    freopen("inversions.inp","r",stdin);
    freopen("inversions.out","w",stdout);
    int n,res=0;
    int arr[100000]={};
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (arr[i]>arr[j]) res++;
        }
        
    }
    cout<<res;
    return 0;
}