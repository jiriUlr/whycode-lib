cmake_minimum_required(VERSION 3.28.3)

project(whycode LANGUAGES CXX)

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

find_package(pybind11 REQUIRED)
find_package(OpenCV REQUIRED)

###########
## Build ##
###########

set(whycode_SRCS
  src/whycode/CWhycode.cpp
  src/whycode/CRawImage.cpp
  src/whycode/CCircleDetect.cpp
  src/whycode/CTransformation.cpp
  src/whycode/CNecklace.cpp
)

set(whycode_PYBINDS
  python/bind_types.cpp
  python/bind_CWhycode.cpp
  python/bind_CRawImage.cpp
)

add_library(whycode_lib ${whycode_SRCS})

target_include_directories(whycode_lib PRIVATE
  include/
  ${OpenCV_INCLUDE_DIRS}
)

target_link_libraries(whycode_lib PRIVATE ${OpenCV_LIBS})

pybind11_add_module(whycode_py
  python/pybind_wrapper.cpp
  ${whycode_PYBINDS}
  ${whycode_SRCS}
)

target_include_directories(whycode_py PRIVATE
  include/
  ${OpenCV_INCLUDE_DIRS}
)

target_link_libraries(whycode_py PRIVATE ${OpenCV_LIBS})

#############
## Install ##
#############

install(TARGETS whycode_py LIBRARY DESTINATION whycode)
