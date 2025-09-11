cmake_minimum_required(VERSION 3.16)
project(vf3)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB VF3_HEADERFILES
    "include/*.h"
    "include/*.hpp"
)

set(VF3_SOURCEFILES
    src/vf3.cpp
)

set(VF3K_SOURCEFILES
    src/main.cpp
)

include_directories(
  include
)

add_library(vf3)
target_sources(vf3
 PRIVATE
  ${VF3_SOURCEFILES}
  ${VF3_HEADERFILES}
)
target_include_directories(vf3
 PRIVATE
  include
)

add_executable(vf3exe)
target_sources(vf3exe
 PRIVATE
  ${VF3K_SOURCEFILES}
  ${VF3_HEADERFILES}
)
target_include_directories(vf3exe
 PRIVATE
  include
)
target_link_libraries(vf3exe
 PRIVATE
  vf3
)

