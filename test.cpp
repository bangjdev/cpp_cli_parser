#include "parser.h"
#include <string>
#include <iostream>

std::string input_file, output_file, time_limit;
Parser parser;

int main(int argc, char **argv) {
    parser.addParamMapping("-i|--input", input_file);
    parser.addParamMapping("-o|--output", output_file);
    parser.addParamMapping("-tl|--time-limit", time_limit);
    parser.parseArguments(argc, argv);
    std::cout << "Input " << input_file << "\n";
    std::cout << "Input " << output_file << "\n";
    std::cout << "Input " << time_limit << "\n";
    return 0;
}
