#include <iostream>
using namespace std;


void merge(int *a, int left, int mid, int right, int *temp){
    int i = left, j = mid + 1;
    int k = 0;
    while(i <= mid && j <= right){
        if(a[i] <= a[j]){
            temp[k++] = a[i++];
        }else{
            temp[k++] = a[j++];
        }
    }

    while(i <= mid){
        temp[k++] = a[i++];
    }

    while(j <= right){
        temp[k++] = a[j++];
    }

    for(int i = 0; i < k; i++){
        a[left + i] = temp[i];
    }
}


void _mergeSort(int *a, int left, int right, int *temp){
    if(left < right){
        int mid = (left + right)/2;
        _mergeSort(a, left, mid, temp);
        _mergeSort(a, mid +1, right, temp);
        merge(a, left, mid, right, temp);
    }
}

void mergeSort(int *a, int n){
    int *temp = new int[n];
    _mergeSort(a, 0, n - 1, temp);
    delete []temp;
}

int main()
{
    int nums[] = {1, 4, 9, 7, 8, 4};
    mergeSort(nums, 6);
    for(int i = 0; i < 6;i++){
        cout << nums[i] << " ";
    }
    cout << endl;
}
