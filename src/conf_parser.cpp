#include "conf_parser.hpp"


sqlInfo Conf_Parser(const std::string& path){
	std::ifstream file;
	file.open(path);
	sqlInfo DB;

	bool isInMysqlSection = false;
	bool isInOtherSection = false;

	std::string token; //Token is = 
	std::string key; 
	std::string value;
	

	//Loop through the whole file 
	while (file){

		/* Take first; key may be key or section name(as[mysql_server])
		*  We compare it to know in which section is the file  */
		file >> key;

		if (isInMysqlSection){
			file >> token;
			file >> value;
			isInMysqlSection = MySqlSection(DB, key, value);
		}
		if (isInOtherSection){
			file >> token;
			file >> value;
			//Just an example to check another section if needed later
		}
		if (!isInOtherSection && !isInMysqlSection){
		
		//A if/else swtich case would be better (like we did in mysqlsection) but some sections may have the same size and booleans have to be correctly set
		isInMysqlSection = !key.compare("[mysql_server]");
		isInOtherSection = !key.compare("[other]");
	}
		
	}

	file.close();
	return DB;
}


bool MySqlSection(sqlInfo& DB,const std::string& key,const std::string& value){

	//Basic switch case using the kenght of the key, values are set in the right structure member
	switch (key.length()){
	case user:
	{
		DB.username = value;
		break;
	}
	case server_ip:
	{
		DB.server = value;
		break;
	}
	case password:
	{
		DB.password = value;
		break;
	}
	case schema:
	{
		DB.schema = value;
		break;
	}
	default:
		return false;
		break;
	}
	return true;
}
