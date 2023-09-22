# otp-demo
Demonstration of OTP technology to encrypt an image.

## Setup instructions
Log in to your personal GitHub account. Click the `<> Code` dropdown on GitHub and select `Create codespace on main`. This will create a new codespace, which is a sandbox with everything you need to complete this workshop. Please allow up to 5 minutes for the codespace to set up the environment.

## Part 1
We will encrypt the image using AES ECB mode to demonstrate the shortcomings of classical cryptography.

Boilerplate code is provided in this repository. Please fill out encryptAES256ECB function in encrypt.cpp. In addition, fill out the main function so that the application can encrypt the image contents using AES ECB mode.

Follow the build steps at the end of this README to build the application. We have provided a sample input image and AES key (32 bytes) to test this part. Execute the following command from the build directory.
```
./otp-demo encrypt --input-filename=../files/tux.bmp --key-filename=../files/aes.dat --output-filename=../files/encrypted_tux.bmp
```

### References
- https://www.openssl.org/docs/man1.1.1/man3/EVP_EncryptInit_ex.html
- https://en.wikipedia.org/wiki/Block_cipher_mode_of_operation

## Part 2
We will encrypt the image using OTP to demonstrate the improvement over classical cryptography.

Boilerplate code is provided in this repository. Please fill out xorVectors function and the main function so that the application can encrypt the image contents using the OTP.

Again, follow the build steps at the end of this README to build the application. We have provided a sample input image and OTP (196608 bytes) to test this part. Execute the following command from the build directory.
```
./otp-demo encrypt --input-filename=../files/tux.bmp --key-filename=../files/otp.dat --output-filename=../files/encrypted_tux.bmp
```

## Build Steps
1. Open a terminal in VSCode
2. Create a build directory
    ```
    mkdir build && cd build
    ```
3. Build using cmake
    ```
    cmake ..
    cmake --build .
    ```
