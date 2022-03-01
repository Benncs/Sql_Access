#ifndef __SQLMANAGER_HPP__
#define __SQLMANAGER_HPP__

#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <vector>


/**
 * \brief Structur to store sql server's info
 */
struct sqlInfo {
	sqlInfo() = default;
	sqlInfo(std::string s,std::string un, std::string pwd,std::string schem)
		:server(std::move(s)),username(std::move(un)),password(std::move(pwd)),schema(std::move(schem)) {}
	std::string server;
	std::string username;
	std::string password;
	std::string schema;
};

class sqlManager {
public:
	/**
	 * \brief unique constructor 
	 * \param Databse : sql server's info 
	 */
	sqlManager(const sqlInfo& Database);
	~sqlManager();

private:
	sql::Driver* driver; //sql driver 
	sql::Connection* db_connection; //sql connection 
	sql::Statement* statement = nullptr; //query statement 

protected:
	sql::ResultSet* query_res = nullptr; //query result 

	/**
	 * \brief Function to execute a query 
	 * \param sql query line to execute 
	 */
	void Query(const std::string& Query); 

	/**
	 * \brief Concatenate to string 
	 */
	static std::string concatstring(const std::string& s1, const std::string& s2);

};
#endif 