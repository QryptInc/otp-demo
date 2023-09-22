#ifndef QRYPTCLI_H
#define QRYPTCLI_H

#include <map>
#include <string>


static const char* GeneralUsage = 
    "Commands:\n"
    "  encrypt     Encrypt data using an AES-256 key or one-time-pad.\n"
    "  decrypt     Decrypt data using an AES-256 key or one-time-pad.\n"
    "\n";

static const char* EncryptUsage = 
    "Usage: qrypt encrypt --input-filename=<file> --output-filename=<file> [Optional Args]\n"
    "\n"
    "Encrypt data using an AES-256 key or one-time-pad.\n"
    "\n"
    "Required Arguments:\n"
    "  --input-filename=<filename>     Plaintext input file.\n"
    "  --output-filename=<filename>    Encrypted output file.\n"
    "  --key-filename=<filename>       Key input file.\n"
    "Optional Arguments:\n"
    "  --help                          Display this message.\n"
    "\n";

static const char* DecryptUsage = 
    "Usage: qrypt decrypt --input-filename=<file> --output-filename=<file> [Optional Args]\n"
    "\n"
    "Decrypt data using an AES-256 key or one-time-pad.\n"
    "\n"
    "Required Arguments:\n"
    "  --input-filename=<filename>     Encrypted input file.\n"
    "  --output-filename=<filename>    Decrypted output file.\n"
    "  --key-filename=<filename>       Key input file.\n"
    "Optional Arguments:\n"
    "  --help                          Display this message.\n"
    "\n";

enum EncryptDecryptFlag {
    CRYPT_FLAG_INPUT_FILENAME,
    CRYPT_FLAG_OUTPUT_FILENAME,
    CRYPT_FLAG_KEY_FILENAME,
};

static const std::map<std::string, EncryptDecryptFlag> EncryptDecryptFlagsMap = {
    {"--input-filename", CRYPT_FLAG_INPUT_FILENAME},
    {"--output-filename", CRYPT_FLAG_OUTPUT_FILENAME},
    {"--key-filename", CRYPT_FLAG_KEY_FILENAME},
};

struct EncryptDecryptArgs {
    std::string input_filename;
    std::string output_filename;
    std::string key_filename;
};

void printUsage(std::string mode);

EncryptDecryptArgs parseEncryptDecryptArgs(char** unparsed_args);

#endif /* QRYPTCLI_H */