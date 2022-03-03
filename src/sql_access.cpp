#include "sql_access.hpp"


sqlAccess::sqlAccess(const sqlInfo& param):sqlManager(param){
    //TODO error if thrown when connection error occurs
}

int sqlAccess::getQuery(const std::string& query,const std::string& col){
    
    try{
        Query(query);
        std::cout << "Column : " << col << std::endl;
        while (query_res->next()){
            std::cout << query_res->getString(col) << std::endl;
        }
        return SQL_SUCCESS;
    }
    catch(std::exception& e){
        std::cout << e.what() << std::endl;
        return SQL_ERROR_CONNECTION;
    }
}

int sqlAccess::Switch_Schema(const std::string& schema){
    try{
        switch_schema(schema);
        return SQL_SUCCESS;
    }
    catch (std::exception& e){
        std::cout << e.what() << std::endl;
        return SQL_UNDEF_ERROR;
    }
    return 0;
}

int sqlAccess::getWholeQuery(const std::string& query){
    try{

        Query(query);
        WholeQueryRes();
        return SQL_SUCCESS;
    }
    catch(std::exception&e ){
        std::cout << e.what() << std::endl;
        return SQL_ERROR_QUERY;
    }
}

int sqlAccess::Describe(const std::string& table){
    try{
        Query(concatstring("describe ", table));
        WholeQueryRes();
        return SQL_SUCCESS;
    }
    catch(std::exception&e ){
        std::cout << e.what() << std::endl;
        return SQL_ERROR_QUERY;
    }
    
}

int sqlAccess::switch_db(const sqlInfo& db){
    try{
        disconnnect();
        connect(db);
        return SQL_SUCCESS;
    }
    catch (std::exception& e){
        std::cout << e.what() << std::endl;
        return SQL_UNDEF_ERROR;
    }
}

void sqlAccess::WholeQueryRes(){
    sql::ResultSetMetaData* res_meta = query_res->getMetaData();
    int columns = res_meta->getColumnCount();
    while (query_res->next()){
        for (int i = 1; i < columns+1; ++i){
            std::cout << query_res->getString(i) << "    |";
        }
        std::cout << std::endl;
    }
}
