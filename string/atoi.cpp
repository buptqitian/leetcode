#include <iostream>
#include <string>
#include <limits.h>
#include <cmath>

using namespace std;

class Solution{
public:
    int myAtoi(const string & str){
        int length = str.size();
        int sign = 1;
        int i = 0;
        int result = 0;
        int j = length - 1;
        int k = 0;
        if(str[0] == '+'){
            sign = 1;
            i++;
        }
        if(str[0] == '-'){
            sign = -1;
            i++;
        }
        while(j >= i){
            if(str[j] < '0' || str[j] > '9'){
                return 0;
            }
            result = result + (str[j] - '0') * pow(10, k);
            j--;
            k++;
        }
        return result * sign;
    }

    int myAtoi1(const string &str){
        int num = 0;
        int sign = 1;
        int length = str.size();
        int i = 0;
        while( str[i] == ' ') i++;
        if(str[i] == '+'){
            i++;
        }
        if(str[i] == '-'){
            i++;
            sign = -1;
        }
        while(i < length){
            if(str[i] < '0' || str[i] > '9')
                break;
            if(num > INT_MAX/10 && (str[i] - '0') > INT_MAX % 10){
                return sign == -1 ? INT_MIN : INT_MAX;
            }
            num = num * 10 + str[i] - '0';
            i++;
        }
        return num;
    }
};

int main()
{
    Solution s;
    string a = "2147483649";
    string b = "-2147483648";
    int num = s.myAtoi1(a);
    int num2 = s.myAtoi1(b);
    cout << num << endl;
    cout << num2 << endl;
    cout << INT_MAX/10 << endl;
    cout << INT_MAX % 10 << endl;
}
