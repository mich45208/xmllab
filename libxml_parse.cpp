#include <iostream>
#include <string>
#include <libxml/tree.h>
#include <libxml/parser.h>
#include <libxml/xpath.h>
#include <libxml/xpathInternals.h>
using namespace std;

int main(int argc, char* argv[]){
	xmlDocPtr doc;
	xmlXPathContextPtr xpathCtx; 
    xmlXPathObjectPtr xpathObj;
    doc = xmlParseFile("upload.xml");
    if (doc==NULL){
    	cout << "cannot parse xml" << endl;
    }
    const xmlChar* xpathExpr = "//name";
   	const xmlChar* value = "foo bar";
    xpathCtx = xmlXPathNewContext(doc);
    xpathObj = xmlXPathEvalExpression(xpathExpr, xpathCtx);
    print_xpath_nodes(xpathObj->nodesetval, stdout);
    update_xpath_nodes(xpathObj->nodesetval, value);
}