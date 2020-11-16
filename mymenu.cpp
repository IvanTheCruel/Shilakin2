#include <mymenu.h>
using namespace std;

int ITC::menu(){
    vector<string> q = {"1-add pipe","2-add station","3-see all",
                        "4-edit pipe","5-edit station","6-select pipes",
                        "7-select stations","8-save","9-load",
                        "10-delete pipe","11-delete station","0-exit"};
    cout << "options:\n";
    for (auto t: q){
        cout << t << "\n";
    }
    return check_input_int("option:");
}

bool ITC::fin(std::string address, vector<ITC::pipe>&pipes, vector<ITC::station>&stations){
    ifstream fin(address);
    if (fin.is_open()){
        char t;
        pipes.clear(); stations.clear();
        ITC::pipe::kill_sId(); ITC::station::kill_sId();
        fin >> t;
        while(t != 'e'){
            if (t=='S') {
                stations.emplace_back(fin);
            } else if (t=='P') {
                pipes.emplace_back(fin);
            }
            fin >> t;
        }
    } else {
        cout<<"ERROR:file isn't open!\n\n";
        fin.close();
        return false;
    }
    fin.close();
    return true;
}

bool ITC::fout(std::string address, vector<ITC::pipe>&pipes, vector<ITC::station>&stations){
    ofstream fout;
    fout.open(address);
    if (fout.is_open()){
        for (auto s: stations) fout << s;
        for (auto p: pipes)    fout << p;

    } else {
        cout<<"ERROR:file isn't open!\n\n";
        fout.close();
        return false;
    }
    fout.close();
    return true;
}

bool ITC::checkByStatus(const ITC::pipe &p, bool state){
    return p.under_repair == state;
}

bool ITC::checkByEffcy(const ITC::station &s, int effcy){
    return s.efficiency == effcy;
}



