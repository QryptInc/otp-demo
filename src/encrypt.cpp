
#include <memory>

#include <openssl/err.h>
#include <openssl/evp.h>
#include <openssl/kdf.h>
#include <openssl/rand.h>
#include <openssl/sha.h>

#include "encrypt.h"
#include "common.h"

std::vector<uint8_t> encryptAES256ECB(const std::vector<uint8_t> aesKey, const std::vector<uint8_t> &data) {

    // 1. Create openssl context


    // 2. Set engine EVP_aes_256_ecb: AES-256 Electronic Codebook


    // 3. Over allocate vector for encrypted data to account for block size


    // 4. Encrypt the plaintext


    // 5. Finalize encrypt


}

std::vector<uint8_t> decryptAES256ECB(const std::vector<uint8_t> aesKey, const std::vector<uint8_t> &data) {

    // 1. Create openssl context


    // 2. Set engine EVP_aes_256_ecb: AES-256 Electronic Codebook


    // 3. Allocate vector for decrypted data


    // 4. Decrypt the ciphertext


    // 5. Finalize decrypt


}

std::vector<uint8_t> xorVectors(const std::vector<uint8_t> otp, const std::vector<uint8_t> &data) {


}
