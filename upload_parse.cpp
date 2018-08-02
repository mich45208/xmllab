#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "tinyxml2.h"
using namespace std;

string lastline(string filename){
    ifstream fin;
    fin.open(filename.c_str());
    string lastLine;
    if(fin.is_open()) {
        fin.seekg(-1,ios_base::end);                // go to one spot before the EOF

        bool keepLooping = true;
        while(keepLooping) {
            char ch;
            fin.get(ch);                            // Get current byte's data

            if((int)fin.tellg() <= 1) {             // If the data was at or before the 0th byte
                fin.seekg(0);                       // The first line is the last line
                keepLooping = false;                // So stop there
            }
            else if(ch == '\n') {                   // If the data was a newline
                keepLooping = false;                // Stop at the current position.
            }
            else {                                  // If the data was neither a newline nor at the 0 byte
                fin.seekg(-2,ios_base::cur);        // Move to the front of that data, then to the front of the data before it
            }
        }
           
        getline(fin,lastLine);                      // Read the current line
        //cout << "Result: " << lastLine << '\n';     // Display it

        fin.close();
    }
    return lastLine;
}

int main(){
	//std::ifstream fupload("upload.xml");
	string line = lastline("upload.xml");
	//if last line is not </data></file_upload></data_server_request>, tinyxml parser cannot parse
	//so add this temporaly for the purpose of parsing.
	if (line !=  "</data></file_upload></data_server_request>"){
		std::ofstream upload;
		upload.open("upload.xml", std::ios_base::app);
		upload << "</data>";
		upload << "</file_upload>";
		upload << "</data_server_request>";
		upload.close();
	}

	tinyxml2::XMLDocument upload_doc;
	upload_doc.LoadFile("upload.xml");
	
}