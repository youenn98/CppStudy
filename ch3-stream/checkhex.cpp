#include <sstream>
#include <iostream>
#include <string>
#include <cctype>

using namespace std;
string GetLine();
int GetInteger();

int GetInteger(){
    while(true){
        stringstream converter; 
        converter << GetLine();
        int result;
        if(converter >> result){
            char remaining;
            if(converter >> remaining){
                cout << "Unexpected character: " << remaining << endl;
            }else return result;
        }else{
            cout << "please enter an integer." << endl;
        }
        cout << "Retry" << endl;
    }
}

string GetLine(){
    string result;
    getline(cin,result);
    return result;
}

bool HasHexLetters(int num){
    stringstream ss;
    ss << hex << num;
    string test;
    ss >> test;
    for(int i = 0; i < test.size();i++){
        if(isalpha(test[i])) return true;
    }
    return false;

}

int main(){
    int num = GetInteger();
    if(HasHexLetters(num)){
        printf("Has hex letters.\n");
    }else{
        printf("Does not have hex letters.\n");
    }
    return 0;
}