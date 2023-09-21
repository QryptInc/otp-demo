
#include "common.h"

size_t hexCharToInt(char input) {
    if (input >= '0' && input <= '9') {
        return input - '0';
    } else if (input >= 'a' && input <= 'f') {
        return input - 'a' + 10;
    }
    throw std::runtime_error("Invalid character");
}

std::vector<uint8_t> hexStrToByteVec(std::string& str) {
    std::vector<uint8_t> buffer(str.size() / 2);
    for (size_t i = 0; i < str.size(); i += 2) {
        buffer[i / 2] = (hexCharToInt(str[i + 1]) & 0x0F) + ((hexCharToInt(str[i]) << 4) & 0xF0);
    }
    return buffer;
}
