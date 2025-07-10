cmake_minimum_required(VERSION 3.28.3)

project(whycode)

#####################
## Global settings ##
#####################

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 20)
endif()
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-O2 -ggdb -g)
endif()

#######################
## Find dependencies ##
#######################

find_package(OpenCV REQUIRED)

###########
## Build ##
###########

add_library(whycode_lib
  src/whycode/CWhycode.cpp
  src/whycode/CCircleDetect.cpp
  src/whycode/CRawImage.cpp
  src/whycode/CTransformation.cpp
  src/whycode/CNecklace.cpp
)

target_include_directories(whycode_lib PRIVATE
  include/
  ${OpenCV_INCLUDE_DIRS}
)

target_link_libraries(whycode_lib PRIVATE
  ${OpenCV_LIBS}
)

add_subdirectory(python)

#############
## Install ##
#############



###########
## Setup ##
###########


