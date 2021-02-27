#include <iostream>
#include <map>
#include <string>

using namespace std;

#define make_pair MP

map<string,string> ComposeMap(const map<string,string> &mp1,const map<string,string> &mp2){
    map<string,string> ret;
    for(map<string,string>::const_iterator itr = mp1.begin();itr != mp1.end();itr++){
        if(mp2.count(itr->second)){
            ret[itr->first] = mp2.find(itr->second)->second;
        }
    }
    return ret;
}


int main(){
    map<string,string> receip_rank = {{"apple","A"},{"watermellon","B"},{"strawberry","C"},{"latiao","A"}};
    map<string,string> rank_point  = {{"A","100"},{"B","80"},{"C","60"},{"D","40"}}; 
    map<string,string> receip_point = ComposeMap(receip_rank,rank_point);
    cout << receip_point["apple"] << endl;
}