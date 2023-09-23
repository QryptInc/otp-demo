
#include <memory>

#include <openssl/err.h>
#include <openssl/evp.h>
#include <openssl/kdf.h>
#include <openssl/rand.h>
#include <openssl/sha.h>

#include "encrypt.h"
#include "common.h"

std::vector<uint8_t> encryptAES256ECB(const std::vector<uint8_t> aesKey, const std::vector<uint8_t> &data) {
    int resCode = 0;

    // 1. Create openssl context
    std::unique_ptr<EVP_CIPHER_CTX, decltype(&::EVP_CIPHER_CTX_free)> pEvpCtx(EVP_CIPHER_CTX_new(), ::EVP_CIPHER_CTX_free);
    if (pEvpCtx == nullptr) {
        throw std::runtime_error("EVP_CIPHER_CTX_new() returned NULL!");
    }

    // 2. Set engine EVP_aes_256_ecb: AES-256 Electronic Codebook
    resCode = EVP_EncryptInit_ex(pEvpCtx.get(), EVP_aes_256_ecb(), nullptr, aesKey.data(), nullptr);
    if (resCode != OPENSSL_SUCCESS) {
        throw std::runtime_error("EVP_EncryptInit_ex() failed!");
    }

    // 3. Encrypt the plaintext
    int blockSizeInBytes = EVP_CIPHER_CTX_block_size(pEvpCtx.get());
    int numBlocks = (data.size() + blockSizeInBytes) / blockSizeInBytes;
    std::vector<uint8_t> encryptedData(blockSizeInBytes*numBlocks);
    int len;
    resCode = EVP_EncryptUpdate(pEvpCtx.get(), encryptedData.data(), &len, data.data(), data.size());
    if (resCode != OPENSSL_SUCCESS) {
        throw std::runtime_error("EVP_EncryptUpdate() failed!");
    }

    // 4. Finalize encrypt
    resCode = EVP_EncryptFinal_ex(pEvpCtx.get(), encryptedData.data() + len, &len);
    if (resCode != OPENSSL_SUCCESS) {
        throw std::runtime_error("EVP_EncryptFinal_ex() failed!");
    }

    return encryptedData;

}

std::vector<uint8_t> decryptAES256ECB(const std::vector<uint8_t> aesKey, const std::vector<uint8_t> &data) {
    int resCode = 0;

    // 1. Create openssl context
    std::unique_ptr<EVP_CIPHER_CTX, decltype(&::EVP_CIPHER_CTX_free)> pEvpCtx(EVP_CIPHER_CTX_new(), ::EVP_CIPHER_CTX_free);
    if (pEvpCtx == nullptr) {
        throw std::runtime_error("EVP_CIPHER_CTX_new() returned NULL!");
    }

    // 2. Set engine EVP_aes_256_ecb: AES-256 Electronic Codebook
    resCode = EVP_DecryptInit_ex(pEvpCtx.get(), EVP_aes_256_ecb(), nullptr, aesKey.data(), nullptr);
    if (resCode != OPENSSL_SUCCESS) {
        throw std::runtime_error("EVP_DecryptInit_ex() failed!");
    }

    // 3. Decrypt the ciphertext
    std::vector<uint8_t> decryptedData(data.size());
    int len;
    resCode = EVP_DecryptUpdate(pEvpCtx.get(), decryptedData.data(), &len, data.data(), data.size());
    if (resCode != OPENSSL_SUCCESS) {
        throw std::runtime_error("EVP_DecryptUpdate() failed!");
    }

    // 4. Finalize decrypt
    resCode = EVP_DecryptFinal_ex(pEvpCtx.get(), decryptedData.data() + len, &len);
    if (resCode != OPENSSL_SUCCESS) {
        throw std::runtime_error("EVP_DecryptFinal_ex() failed!");
    }

    return decryptedData;
}

std::vector<uint8_t> xorVectors(const std::vector<uint8_t> otp, const std::vector<uint8_t> &data) {
    std::vector<uint8_t> result;
    if(otp.size() != data.size()) {
        throw std::runtime_error("One time pad size does not match data size.");
    }
    for(int i = 0; i < otp.size(); i++) {
        result.push_back(otp[i] ^ data[i]);
    }
    return result;
}
