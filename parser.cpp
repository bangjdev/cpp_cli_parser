#include "parser.h"
#include <bits/c++config.h>
#include <cstring>
#include <string>
#include <vector>
#include <regex>


// User-defined function to split a string into a std::vector<std::string> using delimiter

std::vector<std::string> split(std::string str, const std::string &delimiter) {
    std::regex delimRegex("[" + delimiter + "]");
    std::regex_token_iterator<std::string::iterator> itEnd;
    std::regex_token_iterator<std::string::iterator> it(str.begin(), str.end(), delimRegex);

    std::vector<std::string> splitResult;

    while (it != itEnd) {
        if (*it != "") {
            splitResult.push_back(*it);
        }
        it ++;
    }
    return splitResult;
}


/*
 *
 * Class implementation
 *
 *
 */

Parser::Parser() {
    this->paramsMap.clear();
    this->flagsList.clear();
}

// Get current params map
std::map<std::string, std::string&> Parser::getParamsMap() {
    return this->paramsMap;
}

// Set the delimiter for multi-flag parameter
void Parser::setDelimiter(const std::string &delim) {
    this->delimiter = delim;
}

// Get the current delimiter
std::string Parser::getDelimiter() {
    return this->delimiter;
}

void Parser::addParamMapping(const std::string &flags, std::string &variable) {
    this->flagsList = split(flags, this->delimiter);
    for (std::string &flag: flagsList) {
        this->paramsMap.insert(std::pair<std::string, std::string&>(flag, variable));
    } 
}

void Parser::parseArguments(int argc, char **argv)  {
    std::map<std::string, std::string&>::iterator mapping;
    for (int i = 0; i < argc; i ++) {
        for (std::string &flag : this->flagsList) {
            if (strcmp(flag.c_str(), argv[i]) == 0) {
                if (i + 1 < argc) {
                    mapping = paramsMap.find(flag);
                    if (mapping != paramsMap.end()) {
                        (*mapping).second = argv[i + 1];
                    }
                }
                break;
            }
        }
    }
}
