#ifndef COMMON_H
#define COMMON_H

#include <stdexcept>
#include <vector>
#include <string>

const uint32_t AESKeyLengthInBytes = 32;
constexpr int OPENSSL_SUCCESS = 1;
constexpr int BMP_HEADER_SIZE = 54;


size_t hexCharToInt(char input);

std::vector<uint8_t> hexStrToByteVec(std::string& str);

#endif /* COMMON_H */