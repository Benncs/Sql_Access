#include "sqlmanager.hpp"

sqlManager::sqlManager(const sqlInfo& Database) {
	try {
		driver = get_driver_instance(); //Check sql driver 
		db_connection = driver->connect(Database.server, Database.username, Database.password); //Establish connection 
		db_connection->setSchema(Database.schema); 
		query_res = nullptr;
		statement = nullptr;
	}
	catch (std::exception& e) {
		std::string Err = "Error connection"; //+ e.what();
		throw std::invalid_argument(Err);
	}

}

sqlManager::~sqlManager()
{
	delete db_connection;
	delete statement;
	delete query_res;
//	delete driver;
}



void sqlManager::Query(const std::string& Query)
{
	statement = db_connection->createStatement();
	query_res = statement->executeQuery(Query.c_str());
}

std::string sqlManager::concatstring(const std::string& s1, const std::string& s2)
{
	return s1 + s2;
}
