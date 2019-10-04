#include <iostream>
#include <cmath>

using namespace std;
//__________________________________________________________________________
// ham thuc hien quicksort(sap xep nhanh)
int partition (double arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int left = low;
    int right = high - 1;
    while(true){
        while(left <= right && arr[left] < pivot) left++;
        while(right >= left && arr[right] > pivot) right--;
        if (left >= right) break;
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
    swap(arr[left], arr[high]);
    return left;
}

/* Hàm thực hiện giải thuật quick sort */
void quickSort(double arr[], int low, int high)
{
    if (low < high)
    {
        /* pi là chỉ số nơi phần tử này đã đứng đúng vị trí
         và là phần tử chia mảng làm 2 mảng con trái & phải */
        int pi = partition(arr, low, high);

        // Gọi đệ quy sắp xếp 2 mảng con trái và phải
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
//________________________________________________________________________________

int main(){
    freopen("ThreeNumber.inp","r",stdin);
    freopen("ThreeNumber.out","w",stdout);
    int n;
    double inputArray[10];
    double executingArray[10];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin>>inputArray[i];
        executingArray[i]=inputArray[i];
    }
    quickSort(executingArray,0,n-1);
    int minNumberindex=-1, middleNumberindex=-1, maxNumberindex=-1;
    for (int i = 0; i < n; i++)
    {
        if (inputArray[i] == executingArray[0]){
            minNumberindex=i+1;
            continue;
        }
        else 
            if (inputArray[i] == executingArray[n/2])
            {
                middleNumberindex=i+1;
                continue;
            }
            else
            if (inputArray[i]==executingArray[n-1])
                {
                    maxNumberindex=i+1;
                    continue;
                }
                else 
                    if ((minNumberindex != -1) && (middleNumberindex != -1) && (maxNumberindex != -1)) break;
            
    }
    cout<<minNumberindex << " " << middleNumberindex << " " << maxNumberindex;
    //cout << executingArray[inputArray[0]] + 1 << " "<<executingArray[inputArray[(n/2)+1]] + 1 << " " << executingArray[inputArray[n-1]] + 1;
    return 0;
}
