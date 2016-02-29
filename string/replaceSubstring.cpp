#include <iostream>
#include <string>
using namespace std;

void replaceSubstr(string &a, const string b){
    int current = 0;
    int j = 0;
    for(int i = 0; i < a.size(); i++){
        j = 0;
        int temp = i;
        while(j < 3 && b[j] == a[temp]){
            temp++;
            j++;
        }
        if(j == 3){
            a[current] = '*';
            current++;
            i = i + 3;
        }else{
            a[current] = a[i];
            current++;
        }
    }
    //cout << current << endl;
    a = a.substr(0, current);
}



int main()
{
    //string a = "ABCDELBCDT";
    string a = "ABCD";
    string b = "BCD";
    cout << a << endl;
    cout << b << endl;
    replaceSubstr(a, b);
    cout << a << endl;
}
