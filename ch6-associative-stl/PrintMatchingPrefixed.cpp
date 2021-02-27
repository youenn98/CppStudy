#include <iostream>
#include <set>
#include <string>

using namespace std;

void PrintMatchingPrefix(const set<string> &st,const string pre){
    auto itr = st.lower_bound(pre);
    int sz = pre.size();
    while(itr != st.end()){
        if(itr->size() < sz) break;
        if(itr->substr(0,sz) != pre) break;
        cout << *itr << endl;
        itr++;
    }

}

int main(){
    set<string> apps = {"appa","appb","appc","apb","apz","ap"};
    PrintMatchingPrefix(apps,"app");



    return 0;
}