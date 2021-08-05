#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "KMerGeniePlugin.h"

void KMerGeniePlugin::input(std::string file) {
	 inputfile = file;
 std::ifstream ifile(inputfile.c_str(), std::ios::in);
 while (!ifile.eof()) {
   std::string key, value;
   ifile >> key;
   ifile >> value;
   parameters[key] = value;
 }

}

void KMerGeniePlugin::run() {
   
}

void KMerGeniePlugin::output(std::string file) {
	 std::string outputfile = file;
 std::string myCommand = "";
 //kmergenie Short-reads_files -k 101 -l 11 -s 10
 myCommand += "kmergenie "+std::string(PluginManager::prefix())+"/"+parameters["files"]+" -k "+parameters["high"]+" -l "+parameters["low"]+" -s "+parameters["step"];
 myCommand += " -o "+file;
 std::cout << myCommand << std::endl;

 system(myCommand.c_str());
}

PluginProxy<KMerGeniePlugin> KMerGeniePluginProxy = PluginProxy<KMerGeniePlugin>("KMerGenie", PluginManager::getInstance());
