#ifndef __SQL_ACCESS_HPP
#define __SQL_ACCESS_HPP

#include "sqlmanager.hpp"
#include <iostream>


constexpr int SQL_SUCCESS = 0;
constexpr int SQL_ERROR_CONNECTION = -12345;
constexpr int SQL_ERROR_QUERY = -9876;
constexpr int SQL_UNDEF_ERROR = -93344;

class sqlAccess : public sqlManager{
    public :
        explicit sqlAccess(const sqlInfo& db);
        int getQuery(const std::string& query,const std::string& col);

        template<typename ...columns>
        int getQuery(const std::string& query, const std::string& Col, const columns& ... colname);

        int Switch_Schema(const std::string& schema);

        int getWholeQuery(const std::string& query);

        int Describe(const std::string& table);

        int switch_db(const sqlInfo& db);
    
    private:
        void WholeQueryRes();
        
};


template<typename ...columns>
int sqlAccess::getQuery(const std::string& query, const std::string& Col, const columns& ... colname){

    try {
        Query(query);
        std::vector<std::string> Columns;
        Columns.emplace_back(Col);
        std::cout << Col << " | ";
        for (auto& i : {colname...}){
            std::cout << i << " | ";
            Columns.emplace_back(i);
        }
        std::cout << std::endl;
        while (query_res->next()){
            for (auto& i : Columns){
                std::cout << query_res->getString(i) << " | ";
            }
            std::cout << std::endl;
        }
        return SQL_SUCCESS;
    }
    catch(std::exception&e ){
        std::cout << e.what() << std::endl;
        return SQL_ERROR_QUERY;
    }
}
    


#endif 
