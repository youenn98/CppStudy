#include <ctime>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main(){
    string s(100,'a');
    clock_t start_time = clock();
    vector<string> vs1;
    //vs1.reserve(1000000);
    for(int i = 0;i < 1000000;i++){
        vs1.push_back(s);
    }
    clock_t end_time = clock();

    cout << end_time - start_time << endl;
}
