cmake_minimum_required(VERSION 3.28.3)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 20)
endif()
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-O2 -ggdb -g)
endif()

find_package(pybind11 REQUIRED)
find_package(OpenCV REQUIRED)

set(whycode_SRCS
  ../src/whycode/CWhycode.cpp
  ../src/whycode/CRawImage.cpp
  ../src/whycode/CCircleDetect.cpp
  ../src/whycode/CTransformation.cpp
  ../src/whycode/CNecklace.cpp
)

set(whycode_BINDS
  bind_types.cpp
  bind_CWhycode.cpp
  bind_CRawImage.cpp
)

pybind11_add_module(whycode_cpp
  pybind_wrapper.cpp
  ${whycode_BINDS}
  ${whycode_SRCS}
)

target_include_directories(whycode_cpp PRIVATE
  ../include
  ${OpenCV_INCLUDE_DIRS}
)

target_link_libraries(whycode_cpp PRIVATE
  ${OpenCV_LIBS}
)
