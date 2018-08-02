#include <iostream>
#include "tinyxml2.h"

using namespace tinyxml2;

int main(){
	XMLDocument doc;
	XMLNode* root = doc.NewElement("ROOT");
	doc.InsertFirstChild(root);

	XMLElement* element = doc.NewElement("Messages");
	element->SetText("hello world");
	root->InsertEndChild(element);

	element = doc.NewElement("Lists");
	root->InsertEndChild(element);    //one could insert the end of an element immediately after the creation of it.
	XMLElement* item = doc.NewElement("item");
	item->SetText("item1");
	element->InsertEndChild(item);

	item = doc.NewElement("item");
	item->SetText("item2");
	element->InsertEndChild(item);

	XMLError result = doc.SaveFile("hello.xml");
	//XMLCheckResult(result);
	return 0;
}