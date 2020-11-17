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
        case 3: //see all
            for (auto s: stations) cout << s;
            for (auto p: pipes)    cout << p;
            break;
        case 4: //edit pipe
        {
            if(!edit(pipes,check_input_int("ID"))) cout << "can't edit pipe\n";
            break;
        }
        case 5: //edit station
        {
            if(!edit(stations,check_input_int("ID"))) cout << "can't edit station\n";
            break;
        }
        case 6: //select pipes
        {
            if(!selectPipes(pipes)) cout<<"can't select any pipe\n";
            break;
        }
        case 7: //select stations
        {
            if(!selectStations(stations)) cout<<"can't select any station\n";
            break;
        }
        case 8: //save
            fout("base.txt", pipes, stations);
            break;
        case 9: //load
            fin("base.txt", pipes, stations);
            break;
        case 10: //delete pipe
            for(auto p: FindByFilter(pipes,checkByID,check_input_int("ID"))) //id is unique
                pipes.erase(pipes.begin()+p);
            break;
        case 11: //delete station
            for(auto s: FindByFilter(stations,checkByID,check_input_int("ID"))) //id is unique
                stations.erase(stations.begin()+s);
            break;
        }
    }
}
