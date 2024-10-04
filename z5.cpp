#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    string s;
    getline(cin, s);
    vector <bool> vec;
    for (auto& a : s){
        if (a == '1') vec.push_back(true);
        else if (a == '0') vec.push_back(false);
    }
    vector <bool> resheto(vec.size()+1, true);
    resheto[0]=resheto[1]=false;
    for (int i = 2; i *i < resheto.size(); i++){
        if (resheto[i] == true){
            for (int j = i*i; j < resheto.size(); j+=i){
                resheto[j] = false; 
            }
        }
    }
    int Za = 0, against = 0;
    for (int i = 0; i < vec.size(); i++){
        if (resheto[i+1] == true and vec[i] == false) against +=2;
        else if (resheto[i+1] == true and vec[i] == true) Za +=2;
        else if (resheto[i+1] == false and vec[i] == false) against++;
        else if (resheto[i+1] == false and vec[i] == true) Za++;
    }
    cout << Za-against;
}