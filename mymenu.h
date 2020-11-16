#pragma once

#include <iostream>
#include <station.h>
#include <pipe.h>


namespace ITC {
     int menu();

     template<typename T>

     using filter = bool(*)(const ITC::pipe&, T);


     bool checkByName(const ITC::pipe &p, std::string name){
         return p.name == name;
     }

     bool checkByStatus(const ITC::pipe &p, bool state){
         return p.under_repair == state;
     }

     bool checkByID(const ITC::pipe &p, int id){
         return p.get_id() == id;
     }

     template<typename T>
     std::vector<size_t> FindPipeByFilter(std::vector<ITC::pipe>& p, filter<T> f, T param){
         std::vector<size_t> ans;
         size_t i = 0;
         for(auto t: p){
             if(f(t,param)) ans.push_back(i);
             i++;
         }
         return ans;
     }

////     template<typename T>

////     using filter = bool(*)(const ITC::station&, T);


//     bool checkByName(const ITC::station &p, std::string name){
//         return p.name == name;
//     }

//     bool checkByID(const ITC::station &p, int id){
//         return p.get_id() == id;
//     }

//     template<typename T>
//     std::vector<size_t> FindPipeByFilter(std::vector<ITC::station>& p, filter<T> f, T param){
//         std::vector<size_t> ans;
//         size_t i = 0;
//         for(auto t: p){
//             if(f(t,param)) ans.push_back(i);
//             i++;
//         }
//         return ans;
//     }
}


