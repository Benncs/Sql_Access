#ifndef __SQL_ACCESS_HPP
#define __SQL_ACCESS_HPP

#include "sqlmanager.hpp"
#include <iostream>

class sqlAccess : public sqlManager{
    public :
        explicit sqlAccess(const sqlInfo& db);
        void getQuery(const std::string& query,const std::string& col);
    
    private:
        
}

#endif 