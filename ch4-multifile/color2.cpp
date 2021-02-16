#include <iostream>
#include <string>

using namespace std;

enum Color{
    #define DEFINE_OPP(color,opp) color,
    #include "colorinfo.h"
    #undef DEFINE_OPP
};

string ColorToString(Color c){
    switch (c){
    #define DEFINE_OPP(color,opp) case color : return #color;
    #include "colorinfo.h"
    #undef DEFINE_OPP
    default:
        return "<unknown>";
    }
}

Color OppsiteColor(Color c){
    switch (c){
        #define DEFINE_OPP(color,opp) case color : return opp;
        #include "colorinfo.h"
        #undef DEFINE_OPP
        default:
            return c;
    }
}


int main(){
    cout << ColorToString(Red) << endl;
    cout << ColorToString(OppsiteColor(Red)) << endl;


}