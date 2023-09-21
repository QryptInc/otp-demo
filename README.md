# otp-demo
Demonstration of OTP technology to encrypt an image.

## Part 1
We will encrypt the image using AES ECB mode to demonstrate the shortcommings of classical cryptography.

Boilerplate code is provided in this repository. Please fill out encryptAES256ECB in encrypt.cpp before moving to the next part. In addition, fill out the main function so that the application can encrypt the image contents using AES ECB mode.

## Part 2
We will encrypt the image using OTP to demonstrate the improvement over classical cryptography.

Boilerplate code is provided in this repository. Please fill out xorVectors and the main function so that the application can encrypt the image contents using the OTP.

## Setup instructions
You can follow the steps below to get started if you choose to use the boilerplate code in the repository.

### Start dev container
1. Install docker desktop and VSCode
1. Open this folder in VSCode
2. Install the Dev Containers extension in VSCode
3. Reopen the folder in the dev container

#### References
- https://www.docker.com/products/docker-desktop/
- https://code.visualstudio.com
- https://code.visualstudio.com/docs/devcontainers/containers

### Build Steps
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

### Run Demo
We have provided a sample input image, AES key (32 bytes) and OTP (196608 bytes).

Execute the following command from the build directory.
```
./otp-demo encrypt --input-filename=../files/tux.bmp --key-filename=../files/aes.dat --output-filename=../files/encrypted_tux.bmp
```
