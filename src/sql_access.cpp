#include "sql_access.hpp"


sqlAccess::sqlAccess(const sqlInfo& param):sqlManager(param){
}

void sqlAccess::getQuery(const std::string& query,const std::string& col){
    Query(query);
    while(query_res->next()){
        std::cout<<query_res->getString(col)<<std::endl;
    }
}
