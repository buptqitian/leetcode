#include <iostream>
using namespace std;


void swap(int &num1, int &num2){
    int temp = num1;
    num1 = num2;
    num2 = temp;
}


int partition(int *nums, int p, int q){
    int pivot = nums[q];
    int i = p - 1;
    int j = p;
    while(j <= q - 1){
        if(nums[j] <= pivot){
            i++;
            swap(nums[i], nums[j]);
        }
        j++;
    }
    swap(nums[q], nums[i + 1]);
    return i + 1;
}


void fastSort(int *nums, int p, int q){
    if(p < q){
        int i = partition(nums, p, q);
        fastSort(nums, p, i - 1);
        fastSort(nums, i + 1, q);
    }
}

void print(int *nums, int length){
    for(int i = 0; i < length; i++){
        cout << nums[i] << endl;
    }
}


int main()
{
    int nums[] = {1, 4, 9, 7, 8, 4};
    fastSort(nums, 0, 5);
    print(nums, 6);
}
