#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum Color{
    #define DEFINE_OPP(color,opp) eColor_##color,
    #include "colorinfo.h"
    #undef DEFINE_OPP
    NOT_A_COLOR
};

string ColorToString(Color c){
    switch (c){
    #define DEFINE_OPP(color,opp) case eColor_##color : return string(#color);
    #include "colorinfo.h"
    #undef DEFINE_OPP
    default:
        return "<unknown>";
    }
}

Color OppsiteColor(Color c){
    switch (c){
        #define DEFINE_OPP(color,opp) case eColor_##color : return eColor_##opp;
        #include "colorinfo.h"
        #undef DEFINE_OPP
        default:
            return c;
    }
}

Color StringToColor(string c){
    
    vector<string> color_str_list = {
                            #define DEFINE_OPP(color,opp) string(#color),
                            #include "colorinfo.h"
                            #undef DEFINE_OPP
                            };
    vector<Color> color_list = {
                            #define DEFINE_OPP(color,opp) eColor_##color,
                            #include "colorinfo.h"
                            #undef DEFINE_OPP
                            };
    for(int i = 0;i < color_str_list.size();i++){
        if(c == color_str_list[i]){
            return color_list[i];
        }
    }
    return NOT_A_COLOR;
}

int main(){
    #include "colorinfo.h"
    cout << ColorToString(eColor_Red) << endl;
    cout << ColorToString(OppsiteColor(eColor_Red)) << endl;
    cout << StringToColor("Red") << endl;
    cout << StringToColor("Silver") << endl;
}