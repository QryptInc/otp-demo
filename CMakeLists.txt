
cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD          17) 
set(CMAKE_CXX_STANDARD_REQUIRED ON) 
set(CMAKE_CXX_EXTENSIONS        OFF) 

project(OTPDemo_project)
set(DEMO_TARGET "otp-demo")

# Enable -fPIC
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_executable(${DEMO_TARGET}
    src/main.cpp
    src/cli.cpp
    src/common.cpp
    src/encrypt.cpp
)

# Link against openssl
target_link_libraries(${DEMO_TARGET}
    "crypto"
)
