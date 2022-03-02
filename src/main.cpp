#include <iostream>
#include "sql_access.hpp"

int main(){

	const sqlInfo Param = sqlInfo("127.0.0.1", "root", "1234", "dev"); //Parameter of the sql server
	const sqlInfo Param2 = sqlInfo("127.0.0.1", "root", "1234", "units"); //Parameter of the sql server

	
	auto *db = new sqlAccess(Param);
	//std::string query = "select * from db1";
	//db->getQuery(query, "col1", "col2");

	//std::string query = "describe db1";
	//db->getQuery(query,"");

	db->Describe("db1");

	db->Switch_Schema("units");
	db->Describe("conversiontable");

	delete db;

	return 0;
}
