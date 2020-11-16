#pragma once

#include <station.h>
#include <pipe.h>


namespace ITC {
int menu();
bool fin(std::string, std::vector<ITC::pipe>&, std::vector<ITC::station>&);
bool fout(std::string, std::vector<ITC::pipe>&, std::vector<ITC::station>&);

template<typename T, typename N>
using filter = bool(*)(const N&, T);

template<typename N>
bool checkByName(const N &p, std::string name){
    return p.name == name;
}

bool checkByStatus(const ITC::pipe &p, bool state);

bool checkByEffcy(const ITC::station &s, int effcy);

template<typename N>
bool checkByID(const N &p, int id){
    return p.get_id() == id;
}

template<typename T, typename N>
std::vector<size_t> FindByFilter(std::vector<N>& ps, filter<T,N> f, T param){
    std::vector<size_t> ans;
    size_t i = 0;
    for(auto t: ps){
        if(f(t,param)) ans.push_back(i);
        i++;
    }
    return ans;
}
}


