#include <mymenu.h>
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
            bool found = false;
            for(auto p: FindByFilter(pipes,checkByID,check_input_int("ID"))){ //id is unique
                found = true;
                cout << pipes[p];
                pipes[p].set();
            }
            if (!found) cout<<"no pipe with such ID\n\n";
            break;
        }
        case 5:
        {
            bool found = false;
            for(auto s: FindByFilter(stations,checkByID,check_input_int("ID"))){ //id is unique
                found = true;
                cout << stations[s];
                stations[s].set();
            }
            if (!found) cout<<"no pipe with such ID\n\n";
            break;
        }
        case 6:
        {
            cout << "options: 1-select by name, 2-select by state,3-both,0-cancel\n";
            switch (check_input_int("option")) {
            case 0:
                break;
            case 1:
                for(auto p: FindByFilter(pipes,checkByName,check_input_str("name of station('ctrl+z' to end input)")))
                    cout<<p;
                break;
            case 2:
                for(auto p: FindByFilter(pipes,checkByStatus,check_ans("under repair?")))
                    cout<<p;
                break;
            case 3:
                for(auto i: FindByFilter(pipes,checkByName,check_input_str("name of station('ctrl+z' to end input)")))
                    for(auto j: FindByFilter(pipes,checkByStatus,check_ans("under repair?")))
                        if (i==j) cout<<j;
                break;
            }
            break;
        }
        case 7:
        {
            cout << "options: 1-select by name, 2-select by efficiency,3-both,0-cancel\n";
            switch (check_input_int("option")) {
            case 0:
                break;
            case 1:
                for(auto p: FindByFilter(stations,checkByName,check_input_str("name of station('ctrl+z' to end input)")))
                    cout<<p;
                break;
            case 2:
                for(auto p: FindByFilter(stations,checkByEffcy,check_input_int("efficiency")))
                    cout<<p;
                break;
            case 3:
                for(auto i: FindByFilter(stations,checkByName,check_input_str("name of station('ctrl+z' to end input)")))
                    for(auto j: FindByFilter(stations,checkByEffcy,check_input_int("efficiency")))
                        if (i==j) cout<<j;
                break;
            }
            break;
        }
        case 8:
            fout("base.txt", pipes, stations);
            break;
        case 9:
            fin("base.txt", pipes, stations);
            break;
        case 10:
            for(auto p: FindByFilter(pipes,checkByID,check_input_int("ID"))) //id is unique
                pipes.erase(pipes.begin()+p);
            break;
        case 11:
            for(auto s: FindByFilter(stations,checkByID,check_input_int("ID"))) //id is unique
                stations.erase(stations.begin()+s);
            break;
        }
    }
}
