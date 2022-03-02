#ifndef __SQL_ACCESS_HPP
#define __SQL_ACCESS_HPP

#include "sqlmanager.hpp"
#include <iostream>

class sqlAccess : public sqlManager{
    public :
        explicit sqlAccess(const sqlInfo& db);
        void getQuery(const std::string& query,const std::string& col);

        template<typename ...queries>
        void getQuery(const std::string& query,const std::string& col,const std::string&& ... queries);
    
    private:
        
};

template<typename ...queries>
        void sqlAccess::getQuery(const std::string& query,const std::string& col,const std::string&& ... queries){
            Query(query);
            while(query_res->next()){
                for(auto&& i :{...queries}){
                    std::cout<<query_res->getString(i)<<" | ";
                }
                std::cout<<std::endl;
            }  
    }


#endif 
