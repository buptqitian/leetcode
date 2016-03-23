#include <iostream>
using namespace std;

typedef unsigned int uint;

void radixSort(uint *nums, int n){
    uint *temp0 = new uint[n];
    uint *temp1 = new uint[n];
    for(uint bit = 0; bit < 32; bit++){
        int base_0 = 0;
        int base_1 = 0;
        for(int i = 0; i < n; i++){
            int d = nums[i];
            uint bit_mask = (1 << bit);
            if((d & bit_mask) > 0){
                temp1[base_1++] = d;
            }else{
                temp0[base_0++] = d;
            }
        }
        for(int i = 0; i < base_0; i++){
            nums[i] = temp0[i];
        }
        for(int i = 0; i < base_1; i++){
            nums[base_0 + i] = temp1[i];
        }
    }
}


int main()
{
    uint nums[] = {122, 10, 2, 22, 12, 9};
    radixSort(nums, 6);
    for(int i = 0; i < 6; i++){
        cout << nums[i] << endl;
    }
    return 0;
}
