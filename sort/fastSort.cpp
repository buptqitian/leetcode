#include <iostream>
#include <vector>
using namespace std;


void swap(int &num1, int &num2){
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

int partition(int *nums, int left, int right){
    int pivot = nums[right];
    int i = left - 1, j = left;
    while(j <= right - 1){
        if(nums[j] <= pivot){
            i++;
            swap(nums[i], nums[j]);
        }
        j++;
    }
    swap(nums[i + 1], nums[right]);
    return i + 1;
}

void fastSort(int *nums, int left, int right){
    if(left < right){
        int q = partition(nums, left, right);
        fastSort(nums, left, q - 1);
        fastSort(nums, q + 1, right);
    }
}

void print(int *nums, int length){
    for(int i = 0; i < length; i++){
        cout << nums[i] << " ";
    }
}

int main()
{
    int nums[] = {1, 4, 9, 7, 8, 4};
    //partition(nums, 0, 5);
    fastSort(nums, 0, 5);
    print(nums, 6);
    cout << endl;
}
