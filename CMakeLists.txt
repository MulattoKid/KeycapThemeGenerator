cmake_minimum_required(VERSION 3.7)
project(keycap_theme_generator)

# IMPORTANT directories
set(BUILD_DIR ${CMAKE_CURRENT_SOURCE_DIR}/build/)
set(OUTPUT_DIR ${BUILD_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${OUTPUT_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${OUTPUT_DIR})

# Source files
set(SRC_FILES
	src/main.cpp
)

# Create targets
add_executable(keycap_theme_generator ${SRC_FILES})
set(CMAKE_CXX_STANDARD 11)
if(MSVC)
	set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT keycap_theme_generator)
endif()

# Set target include directories
target_include_directories(keycap_theme_generator PRIVATE include)

# Set COMPILATION FLAGS and LINKING
if(MSVC)
	# https://docs.microsoft.com/en-us/cpp/build/reference/compiler-options-listed-by-category?view=vs-2019
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /Od /Zi -W2 /MP")
	set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} /O3 /Zi -W2 /MP")
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /O2 -W2 /MP")
	set_property(TARGET keycap_theme_generator PROPERTY VS_DEBUGGER_WORKING_DIRECTORY ${OUTPUT_DIR})
else()
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -g -Wall -march=native")
	set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} -O3 -g -Wall -march=native")
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -Wall -march=native")
endif()
