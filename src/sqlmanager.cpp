#include "sqlmanager.hpp"

sqlManager::sqlManager(const sqlInfo& Database) {
	//try {
		driver = get_driver_instance(); //Check sql driver 
		con = driver->connect(Database.server, Database.username, Database.password); //Establish connection 
		con->setSchema(Database.schema); 
		res = nullptr;
		stmt = nullptr;
	//}
	//catch (...) {
	//	throw std::invalid_argument("Error connection");
	//}

}

sqlManager::~sqlManager()
{
	//delete con;
	//delete stmt;
	//delete res;
}



void sqlManager::Query(const std::string& Query)
{
	stmt = con->createStatement();
	res = stmt->executeQuery(Query.c_str());
}

std::string sqlManager::concatstring(const std::string& s1, const std::string& s2)
{
	return s1 + s2;
}
