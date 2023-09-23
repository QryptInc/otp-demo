
#include <cstring>
#include <iostream>
#include <fstream>
#include <vector>

#include "cli.h"
#include "common.h"
#include "encrypt.h"


int main(int argc, char* argv[]) {
    // Set mode and handle --help
    if (argc < 2) {
        std::cout << GeneralUsage;
        return 0;
    }
    std::string mode = *++argv;
    for(int i=0; i<argc-1; i++) {
        if (strcmp(argv[i], "--help") == 0) {
            printUsage(mode);
            return 0;
        }
    }

    // Parse and unpack cli arguments
    auto encrypt_decrypt_args = parseEncryptDecryptArgs(++argv);
    std::ifstream input_file(encrypt_decrypt_args.input_filename, std::ios::in | std::ios::binary);
    if (!input_file.is_open()) {
        throw std::invalid_argument("Unable to open input file " + encrypt_decrypt_args.input_filename);
    }
    std::ifstream key_file(encrypt_decrypt_args.key_filename, std::ios::in | std::ios::binary);
    if (!key_file.is_open()) {
        throw std::invalid_argument("Unable to open key file " + encrypt_decrypt_args.key_filename);
    }
    std::ofstream output_file(encrypt_decrypt_args.output_filename, std::ios::out | std::ios::binary);
    if (!output_file.is_open()) {
        throw std::invalid_argument("Unable to open output file " + encrypt_decrypt_args.output_filename);
    }

    // Read in key and convert key to binary
    std::vector<uint8_t> key(std::istreambuf_iterator<char>(key_file), {});
    std::string key_string(key.begin(), key.end());
    key = hexStrToByteVec(key_string);

    // Read input image and preserve bmp header so it doesn't get encrypted
    std::vector<uint8_t> input(std::istreambuf_iterator<char>(input_file), {});
    std::vector<uint8_t> header = std::vector<uint8_t>(input.begin(), input.begin() + BMP_HEADER_SIZE);
    std::vector<uint8_t> input_data = std::vector<uint8_t>(input.begin() + BMP_HEADER_SIZE, input.end());

    // Run cryptography operation
    std::vector<uint8_t> output;
    // PART 1: AES ECB encryption
#if 0
    if (key.size() != AESKeyLengthInBytes) {
        throw std::invalid_argument("AES-256 key is invalid. The file is not the correct size.");
    }
    if (mode == "encrypt") {
        output = encryptAES256ECB(key, input_data);
    }
    else { // operation == "decrypt"
        output = decryptAES256ECB(key, input_data);
    }
    // PART 2: OTP encryption
#else
    if (key.size() != input_data.size()) {
        throw std::invalid_argument("One-time-pad is invalid. The key file must be the same length as the input file.");
    }
    output = xorVectors(key, input_data);
#endif

    // Write output
    output_file.write((char *)&(header)[0], header.size());
    output_file.write((char *)&(output)[0], output.size());

    input_file.close();
    output_file.close();

}
