#include <iostream>
#include <string>

using namespace std;


int Myatoi(string str){
    if(str.size() == 0) return 0;
    long result = 0;
    int i = 0;
    int sign = 1;
    while(str[i] == ' ') i++;
    if(str[i] == '+'){
        i++;
    }else if(str[i] == '-'){
        i++;
        sign = -1;
    }
    while(i < str.size()){
        if(str[i] < '0' || str[i] > '9') break;
        result = result * 10 + (str[i] - '0');
        if(result > 2147483647 && sign == 1) return 0;
        if(result > 2147483648 && sign == -1) return 0;
        i++;
    }
    return result * sign;
}


int main()
{
    string a = "-2147483649";
    cout << Myatoi(a) << endl;
}
