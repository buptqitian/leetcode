#include <iostream>
#include <vector>
using namespace std;



vector<int> merge(vector<int> a1, vector<int> a2){
    vector<int> result;
    int size = (a1.size() <= a2.size()) ? a1.size() : a2.size();
    int i = 0, j = 0, k = 0;
    while(k < size){
        if(a1[i] < a2[j]){
            result.push_back(a1[i++]);
        }else{
            result.push_back(a2[j++]);
        }
        k++;
    }
    if(a1.size() < a2.size()){
        while(j < a2.size()){
            result.push_back(a2[j++]);
        }
    }else{
        while(i < a1.size()){
            result.push_back(a1[i++]);
        }
    }
    return result;
}


int main()
{
    vector<int> a1 = {1, 3, 6, 7, 10};
    vector<int> a2 = {0, 4, 7, 8, 9, 10, 11};

    vector<int> result = merge(a1, a2);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    cout << endl;
}
