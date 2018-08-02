#include <iostream>
#include <fstream>
#include "tinyxml2.h"
using namespace tinyxml2;

int main(int argc, char *argv[]){
	XMLDocument doc;
	doc.LoadFile("no_task_reply.xml");
	XMLElement* element = doc.FirstChildElement("scheduler_reply")->FirstChildElement("message");
	if (element != NULL){
		std::cout << "there is no task" << std::endl;
	}
	//XMLElement* repeatElement = doc.FirstChildElement("scheduler_reply")->FirstChildElement("file_info");
	
	// for(XMLElement* myiter = repeatElement; myiter != NULL; myiter = myiter -> NextSiblingElement("file_info")){
	// 	std::cout << "name: " << myiter->FirstChildElement("name")->GetText() << std::endl;
	// }

	//store whole document into a string variable by xml printer.
	// XMLPrinter printer;
	// doc.Accept(&printer);
	// std::string output = printer.CStr();

	// std::cout << "========start========" << std::endl;
	// std::cout << output << std::endl;
	// std::cout << "========end========" << std::endl;
	
	//the other way to store xml file to a string.
	// std::ifstream t("sched.xml");
	// std::string str((std::istreambuf_iterator<char>(t)),
	// 				std::istreambuf_iterator<char>());
	// std::cout << str << std::endl;	

	// const char* title = doc.FirstChildElement("scheduler_reply")->FirstChildElement("file_info")->FirstChildElement("url")->GetText();
	// std::cout << "url is: " << title << std::endl;

	// title = doc.FirstChildElement("scheduler_reply")->FirstChildElement("file_info")->FirstChildElement("name")->GetText();
	// std::cout << "url is:\n" << title << std::endl;
	// XMLText* textNode = doc.FirstChildElement("scheduler_reply")->FirstChildElement("file_info")->FirstChildElement("name")\
	// 	->FirstChild()->ToText();
	// title = textNode->Value();
	// std::cout << title << std::endl;


	doc.SaveFile("foo.xml");
}