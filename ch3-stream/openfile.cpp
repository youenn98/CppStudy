#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

void OpenFile(ifstream &input_f){
    string result;
    printf("Please enter the filename:");
    getline(cin,result);
    while (true){
        input_f.open(result);
        if(input_f.fail()){
            printf("Cannot open file. Please enter the right filename:");
            input_f.clear();
            getline(cin,result);
        }else{
            return;
        }
    }
}

int main(){
    ifstream input_f;
    OpenFile(input_f);
    string a;
    input_f >> a;
    cout << a << endl;
}