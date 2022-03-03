#include <iostream>
#include "sql_access.hpp"
#include "conf_parser.hpp"

int main(){

	auto e = Conf_Parser();
	//std::cout << e.password << std::endl;
	//const sqlInfo Param = sqlInfo("127.0.0.1", "root", "1234", "dev"); //Parameter of the sql server
	//const sqlInfo Param2 = sqlInfo("127.0.0.1", "root", "1234", "units"); //Parameter of the sql server

	
	auto *db = new sqlAccess(e);
	std::string query = "select * from db1";
	db->getWholeQuery(query);

	//std::string query = "describe db1";
	//db->getQuery(query,"");

	//db->Describe("db1");

	//db->Switch_Schema("units");
	//db->Describe("conversiontable");

	//delete db;

	return 0;
}
