#include <iostream>
using namespace std;

void swap(int &num1, int &num2){
    int temp = num1;
    num1 = num2;
    num2 = temp;
}


int partition(int *nums, int p, int q){
    int paviot = nums[q];
    int i = p - 1;
    int j = p;
    while(j <= q - 1){
        if(nums[j] < paviot){
            i++;
            swap(nums[i], nums[j]);
        }
        j++;
    }
    swap(nums[i + 1], nums[q]);
    return (i + 1);
}


void fastSort(int *nums, int p, int r){
    if(p < r){
        int q = partition(nums, p, r);
        fastSort(nums, p, q -1);
        fastSort(nums, q + 1, r);
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
