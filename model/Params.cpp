#include <fstream>
#include "Params.h"
#include "Constants.h"
#include <filesystem>
#include <regex>

namespace fs = std::filesystem;

std::map<std::string, std::string> Params::cfgMap;

void Params::loadParameters() {
    std::ofstream paramFileCreate;
    std::string cfgFileDirectory = fs::temp_directory_path().string();
    std::ifstream paramFile((cfgFileDirectory + PROPERTIES_FILE_NAME).c_str());
    std::string outfileLeft = "", outfileRight = "";
    //if - when there is no cfg file yet
    if (!paramFile.good()) {
        paramFileCreate.open(cfgFileDirectory + PROPERTIES_FILE_NAME, std::ios_base::app);
        paramFileCreate << DEFAULT_CONFIG;
        paramFileCreate.close();

        Params::cfgMap.insert(std::pair<std::string, std::string>(TSTAMP_PROPERTY, TSTAMP_PROPERTY_VAL));
        Params::cfgMap.insert(std::pair<std::string, std::string>(APPENDER_PROPERTY, APPENDER_PROPERTY_VAL));
        Params::cfgMap.insert(std::pair<std::string, std::string>(FILE_OUTPUT_PROPERTY, FILE_OUTPUT_PROPERTY_VAL));

    } else {
        //if the cfg file already exists
        std::ifstream paramFile((cfgFileDirectory + PROPERTIES_FILE_NAME));
        std::string propFileString;

        while (!paramFile.eof()) {
            std::string prop = "";
            getline(paramFile, outfileLeft, '=');
            prop += (outfileLeft + "=");
            getline(paramFile, outfileRight);
            prop += outfileRight;

            std::regex propertiesFilePattern(".+[=].+");
            if (!(std::regex_match(prop, propertiesFilePattern))) throw -4;

            Params::cfgMap.insert(std::pair<std::string, std::string>(outfileLeft, outfileRight));
        }
        paramFile.close();
    }
}

