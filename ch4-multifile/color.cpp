#include <iostream>
#include <string>

using namespace std;

enum Color{Red,Yellow,Blue,Green,Black,White};

string ColorToString(Color c){
    switch (c)
    {
    case Red : return "Red";
    case Blue : return "Blue";
    case Yellow : return "Yellow";
    case Green : return "Green";
    case Black : return "Black";
    case White : return "White";
    default:
        return "<unknown>";
    }
}

Color OppsiteColor(Color c){
    switch (c){
        case Red : return Blue;
        case Blue : return Red;
        case Yellow : return Green;
        case Green : return Yellow;
        case Black : return White;
        case White : return Black;
        default:
            return c;
    }
}


int main(){
    cout << ColorToString(Red) << endl;
    cout << ColorToString(OppsiteColor(Red)) << endl;


}