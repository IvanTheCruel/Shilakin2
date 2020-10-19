#include <iostream>
#include <station.h>
#include <pipe.h>
using namespace std;
using namespace ITC;

int main(){
    vector<pipe> pipes;
    vector<station> stations;
    while(1){
        switch(menu()){
        case 0:
            return 0;
        case 1:
            pipes.emplace_back();
            break;
        case 2:
            stations.emplace_back();
            break;
        case 3:
            for (auto s: stations) cout << s;
            for (auto p: pipes)    cout << p;
            break;
        case 4:
        {
            int id = check_input_int("ID");
            if(id > pipe::get_max_id()-1) cout<<"no pipe with such ID\n";
            else
                pipes[id].set();
            break;
        }
        case 5:
        {
            int id = check_input_int("ID");
            if(id > station::get_max_id()-1) cout<<"no station with such ID\n";
            else
                stations[id].set();
            break;
        }
        case 6:
        {
            ofstream fout;
            fout.open("newbase.txt");
            if (fout.is_open()){
                for (auto s: stations) fout << s;
                for (auto p: pipes)    fout << p;

            } else cout<<"ERROR:file isn't open!";
            fout.close();
            break;
        }
        case 7:
        {
            ifstream fin;
            fin.open("newbase.txt");
            if (fin.is_open()){
                char t;
                pipes.clear();
                stations.clear();
                pipe::kill_sId();
                station::kill_sId();
                fin >> t;
                while(t != 'e'){
                    if (t=='S') {
                        stations.emplace_back(fin);
                    } else if (t=='P') {
                        pipes.emplace_back(fin);
                    }
                    fin >> t;
                }
            } else cout<<"ERROR:file isn't open!";
            fin.close();
            break;
        }
        }
    }
}
