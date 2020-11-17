#pragma once

#include <station.h>
#include <pipe.h>


namespace ITC {
int menu();
bool fin(std::string, std::vector<ITC::pipe>&, std::vector<ITC::station>&);
bool fout(std::string, std::vector<ITC::pipe>&, std::vector<ITC::station>&);
bool selectPipes(std::vector<pipe>&);
bool selectStations(std::vector<station>&);
std::vector<size_t> filterSelectPipes(std::vector<pipe>&);
std::vector<size_t> filterSelectStations(std::vector<station>&);


//фильтр для поиска
template<typename T, typename Class>
using filter = bool(*)(const Class&, T);

//варинаты фильтра
template<typename Class>
bool checkByName(const Class &p, std::string name){
    return p.name == name;
}

bool checkByStatus(const ITC::pipe &p, bool state);

bool checkByEffcy(const ITC::station &s, int effcy);

template<typename Class>
bool checkByID(const Class &p, int id){
    return p.get_id() == id;
}

//сам поиск
template<typename T, typename Class>
std::vector<size_t> FindByFilter(std::vector<Class>& ps, filter<T,Class> f, T param){
    std::vector<size_t> ans;
    size_t i = 0;
    for(auto t: ps){
        if(f(t,param)) ans.push_back(i);
        i++;
    }
    return ans;
}

template<typename Class>
bool edit(std::vector<Class>& ps, int id){
    bool find = false;
    for(auto p: FindByFilter(ps,checkByID,id)){
        ps[p].set();
        find = true;
    }
    return find;
}

}
