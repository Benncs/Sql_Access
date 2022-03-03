#ifndef __SQLMANAGER_HPP__
#define __SQLMANAGER_HPP__

#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <vector>
#include "sql_info.hpp"


class sqlManager {



private:
	sql::Connection* db_connection; //sql connection 
	sql::Statement* statement = nullptr; //query statement 
	sql::Driver* driver; //sql driver 

	
protected:
	sql::ResultSet* query_res = nullptr; //query result 
	void connect(const sqlInfo& db);
	void disconnnect();
	/**
	 * \brief Function to execute a query 
	 * \param sql query line to execute 
	 */
	void Query(const std::string& Query); 

	/**
	 * \brief unique constructor
	 * \param Databse : sql server's info
	 */
	sqlManager(const sqlInfo& Database);
	~sqlManager();

	inline void switch_schema(const std::string& schema){
		try{
			db_connection->setSchema(schema);
		}
		catch (std::exception& e){
			std::string err = std::string("Error switching schema : ") + e.what();
			throw std::runtime_error(err);
		}
	}

	/**
	 * \brief Concatenate to string 
	 */
	static std::string concatstring(const std::string& s1, const std::string& s2);

};
#endif 
