#include <iostream>
#include "sql_access.hpp"

int main(){

	const sqlInfo Param = sqlInfo("127.0.0.1:3389", "root", "", "DB"); //Parameter of the sql server
	
	auto *db = new sqlAccess(Param);
	std::string query = "select * from TestDB";
	db->getQuery(query,"name");

	delete db;

	return 0;
}
