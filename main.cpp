#include <iostream>
#include <station.h>
#include <pipe.h>
using namespace std;
using namespace ITC;

int main(){
    vector<pipe>    pipes;
    vector<station> stations;
    while(1){
        switch(menu()){
        case 0:
            return 0;
        case 1:
            pipes.emplace_back(true);
            break;
        case 2:
            stations.emplace_back(true);
            break;
        case 3:
            for (auto s: stations) cout << s;
            for (auto p: pipes)    cout << p;
            break;
        case 4:
        {
            int id = check_input_int("ID");
            if(id > pipe::get_max_id()-1) cout<<"no pipe with such ID\n\n";
            else {
                bool found = false;
                for (size_t i = 0; i < pipes.size(); i++){
                    if (pipes[i].get_id()==id) {
                        pipes[i].set();
                        found = true;
                        break;
                    }
                }
                if (!found) cout<<"no pipe with such ID\n\n";
            }
            break;
        }
        case 5:
        {
            int id = check_input_int("ID");
            if(id > station::get_max_id()-1) cout<<"no station with such ID\n\n";
            else {
                bool found = false;
                for (size_t i = 0; i < stations.size(); i++){
                    if (stations[i].get_id()==id) {
                        stations[i].set();
                        found = true;
                        break;
                    }
                }
                if (!found) cout<<"no stations with such ID\n\n";
            }
            break;
        }
        case 6:
        {
            cout << "options: 1-select by name, 2-select by state,3-both,0-cancel\n";
            int answer = check_input_int("option");

            if (answer!=0){
                string find_name;
                bool find_ur = false;
                if (answer == 1 || answer == 3) find_name = check_input_str("name of pipe('ctrl+z' to end input)");
                if (answer == 2 || answer == 3) find_ur = check_ans("under repair?");
                vector<size_t> select_pipes;

                for(size_t i = 0; i < pipes.size(); i++){
                    if ((pipes[i].under_repair==find_ur || answer == 1) && (pipes[i].name==find_name || answer == 2)) {
                        cout << pipes[i];
                        select_pipes.push_back(i);
                    }
                }

                if (select_pipes.empty()) cout << "no pipes with such parameters\n\n";
//                else {
//                    while(check_ans("want to edit?")){
//                            for (auto i: select_pipes) cout << pipes[i];
//                            answer = check_input_int("enter ID");

//                    }
//                }
            }
            break;
        }
        case 7:
        {
            cout << "options: 1-select by name, 2-select by efficiency,3-both,0-cancel\n";

            int answer = check_input_int("option");
            if (answer!=0) {
                string find_name;
                int find_eff=0;
                bool found=false;
                if (answer == 1 || answer == 3) find_name = check_input_str("name of station('ctrl+z' to end input)");
                if (answer == 2 || answer == 3) find_eff = check_input_int("station efficiency");

                for(auto s: stations){
                    if ((s.efficiency==find_eff || answer == 1) && (s.name==find_name || answer == 2) && answer != 0) {
                        cout << s;
                        found = true;
                    }
                }
                if (found){
                    if(check_ans("Want to edit them?"))
                        for(auto s: stations){
                            if ((s.efficiency==find_eff || answer == 1) && (s.name==find_name || answer == 2) && answer != 0) s.set();
                        }
                } else {
                    cout << "No stations with such parameters\n\n";
                }
            }

            break;
        }
        case 8:
        {
            ofstream fout;
            fout.open("base.txt");
            if (fout.is_open()){
                for (auto s: stations) fout << s;
                for (auto p: pipes)    fout << p;

            } else cout<<"ERROR:file isn't open!\n\n";
            fout.close();
            break;
        }
        case 9:
        {
            ifstream fin;
            fin.open("base.txt");
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
            } else cout<<"ERROR:file isn't open!\n\n";
            fin.close();
            break;
        }
        case 10:
        {
            int id = check_input_int("ID");
            if(id > pipe::get_max_id()-1) cout<<"no pipe with such ID\n\n";
            else {
                bool found = false;
                for (size_t i = 0; i < pipes.size(); i++){
                    if (pipes[i].get_id()==id) {
                        pipes.erase(pipes.begin() + i);
                        found = true;
                        break;
                    }
                }
                if (!found) cout<<"no pipe with such ID\n\n";
            }
            break;
        }
        case 11:
        {
            int id = check_input_int("ID");
            if(id > station::get_max_id()-1) cout<<"no station with such ID\n\n";
            else {
                bool found = false;
                for (size_t i = 0; i < stations.size(); i++){
                    if (stations[i].get_id()==id) {
                        stations.erase(stations.begin() + i);
                        found = true;
                        break;
                    }
                }
                if (!found) cout<<"no stations with such ID\n\n";
            }
            break;
        }
        }
    }
}
