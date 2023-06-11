// Json.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "json.h"
#include <fstream>

using namespace std;


void readFileJson(string json_root)
{
	Json::Reader reader;
	Json::Value root;
	//从文件中读取，保证当前文件有demo.json文件  
	ifstream input(json_root, ios::binary);
	if (!input.is_open())
	{
		cout << "Error opening file\n";
		return;
	}

	if (reader.parse(input, root))
	{
		//读取根节点信息  
		string name = root["name"].asString();
		int age = root["age"].asInt();
		string sex = root["sex"].asString();
		//读取子节点信息  
		string friend_name = root["friends"]["friend_name"].asString();
		int friend_age = root["friends"]["friend_age"].asInt();
		string friend_sex = root["friends"]["friend_sex"].asString();

		//读取数组信息 
		string info="hoppy:\t[";
		for (unsigned int i = 0; i < root["hobby"].size(); i++)
		{
			string ach = root["hobby"][i].asString();
			info = info + ach + "," + "\t";
		}
		info = info + "]";
		
		cout << "{\n age:" << age << ",\n name:" << name << ",\n sex:" << sex << ",\n friends:{\n" << "\tfriend_age:" << friend_age << ",\n\tfridend_name:" << friend_name <<
			",\n\tfriend_sex:" << friend_sex << "\n\t},\n"<<info<<"\n}"<<endl;
	
			
	}

	input.close();
}




int main()
{
	string json_root = "../test.json";
	readFileJson(json_root);

    
    return 0;
}

