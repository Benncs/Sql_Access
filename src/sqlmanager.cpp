#include "sqlmanager.hpp"

sqlManager::sqlManager(const sqlInfo& Database) {
	connect(Database);
}

sqlManager::~sqlManager()
{
	delete db_connection;
	delete statement;
	delete query_res;
	//delete driver;
}

void sqlManager::connect(const sqlInfo& db){
	try{
		driver = get_driver_instance(); //Check sql driver 
		db_connection = driver->connect(db.server, db.username, db.password); //Establish connection 
		db_connection->setSchema(db.schema);
		query_res = nullptr;
		statement = nullptr;
	}
	catch (std::exception& e){
		std::string Err = std::string("Error connection to mysql server") + e.what();
		throw std::invalid_argument(Err);
	}
}

void sqlManager::disconnnect(){
	db_connection->close();
}



void sqlManager::Query(const std::string& Query)
{
	try{
		statement = db_connection->createStatement();
		query_res = statement->executeQuery(Query.c_str());
	}
	catch (std::exception&e ){
		std::string err = std::string("Error switching schema : ") + e.what();

		if (statement){
			delete statement;
			statement = nullptr;
		}
		if (query_res){
			delete query_res;
			query_res = nullptr;
		}
		throw std::runtime_error(err);
	}
}

std::string sqlManager::concatstring(const std::string& s1, const std::string& s2)
{
	return s1 + s2;
}
