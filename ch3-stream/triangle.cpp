#include <iostream>
#include <iomanip>

using namespace std;

void print_triangle(int height,char k){
    int all_weight = 2 * height - 1;
    for(int i = 0;i < height;i++){
        int weight = i*2 + 1;
        int padding = (all_weight - weight)/2;
        cout << setw(padding) << setfill(' ')<<"";
        cout << setw(weight)  << setfill(k) <<""<<endl;
    }
}

int main(){
    print_triangle(10,'*');


    return 0;
}