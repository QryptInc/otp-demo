
#include <iostream>
#include <filesystem>

#include "cli.h"

namespace fs = std::filesystem;

void printUsage(std::string mode) {
    if (mode == "encrypt") {
        std::cout << EncryptUsage;
    } else if (mode == "decrypt") {
        std::cout << DecryptUsage;
    } else {
        std::cout << GeneralUsage;
    }
}

// Tokenize arguments into key-value pairs
std::tuple<std::string, std::string> tokenizeArg(std::string arg) {
    std::string flag, value;
    if(!(arg.find("--") == 0)) {
        throw std::invalid_argument("Invalid argument: " + arg);
    }
    size_t delim_pos = arg.find("=");
    flag = arg.substr(0, delim_pos);
    if (arg.length() > delim_pos) {
        value = arg.substr(delim_pos + 1);
    }
    return {flag, value};
}

EncryptDecryptArgs parseEncryptDecryptArgs(char** unparsed_args) {
    std::string input_filename, output_filename, key_filename;

    while(*unparsed_args) {
        auto[arg_name, arg_value] = tokenizeArg(*unparsed_args++);
        try {
            switch(EncryptDecryptFlagsMap.at(arg_name)){
                case CRYPT_FLAG_INPUT_FILENAME:
                    input_filename = arg_value;
                    break;
                case CRYPT_FLAG_OUTPUT_FILENAME:
                    output_filename = arg_value;
                    break;
                case CRYPT_FLAG_KEY_FILENAME:
                    key_filename = arg_value;
                    break;
            }
        } catch (std::out_of_range& /*ex*/) {
            throw std::invalid_argument("Invalid argument: " + std::string(arg_name));
        }
    }
    if (input_filename.empty()) {
        throw std::invalid_argument("Missing input-filename");
    } 
    else if (!fs::exists(fs::path(input_filename))) {
        throw std::invalid_argument("Input file \"" + input_filename + "\" does not exist!");
    }
    if (output_filename.empty()) {
        throw std::invalid_argument("Missing output-filename");
    }
    if (key_filename.empty()) {
        throw std::invalid_argument("Missing key-filename");
    }
    else if (!fs::exists(fs::path(key_filename))) {
        throw std::invalid_argument("Key file \"" + key_filename + "\" does not exist!");
    }

    return { input_filename, output_filename, key_filename };
}
