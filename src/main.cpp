#include <iostream>
#include "sql_access.hpp"

int main(){

	const sqlInfo Param = sqlInfo("127.0.0.1:3389", "root", "", "DB"); //Parameter of the sql server
	
	auto *db = new sqlAccess(Param);
	db->getQuery("name");

	delete db;

	return 0;
}
