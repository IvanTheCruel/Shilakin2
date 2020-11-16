#include <iostream>
#include <station.h>
#include <pipe.h>

using namespace std;

namespace ITC {
     int menu();
}

int ITC::menu(){
    vector<string> q = {"1-add pipe","2-add station","3-see all",
                        "4-edit pipe","5-edit station","6-select pipes",
                        "7-select stations","8-save","9-load",
                        "10-delete pipe","11-delete station","0-exit"};
    cout << "options:\n";
    for (auto t: q){
        cout << t << "\n";
    }
    return check_input_int("option");
}




