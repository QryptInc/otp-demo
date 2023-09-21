#ifndef COMMON_H
#define COMMON_H

#include <stdexcept>
#include <map>
#include <vector>
#include <string>
#include <tuple>

extern std::string sdk_token;

const uint32_t IVLengthInBytes = 12;
const uint32_t AESKeyLengthInBytes = 32;
const uint32_t AESKeyWithIVLengthInBytes = AESKeyLengthInBytes + IVLengthInBytes;
const uint32_t AETagSizeInBytes = 2;
constexpr int OPENSSL_SUCCESS = 1;
constexpr int BMP_HEADER_SIZE = 54;



size_t hexCharToInt(char input);

std::vector<uint8_t> hexStrToByteVec(std::string& str);

#endif /* COMMON_H */