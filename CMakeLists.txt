cmake_minimum_required(VERSION 2.8.3)
project(mtyping)
# project(duo CXX)

set(LIB_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/../..)

link_directories(${LIB_ROOT}/lib/mstring)

set(INCLUDE_DIRS
	${LIB_ROOT}/mstring/include
)

include_directories(
	include
	${INCLUDE_DIRS}
)

SET(CMAKE_CXX_FLAGS "-std=c++11 -O2 -g -Wall ${CMAKE_CXX_FLAGS}")

# add_library(duo
#   src/${PROJECT_NAME}/duo.cpp
# )

add_executable(test_duo src/test.cpp src/mtyping/mtyping.cpp src/mtyping/sentence.cpp)

target_link_libraries(test_duo mstring)
# target_link_libraries(typing ${my_LIBRARIES})
# target_link_libraries(flashcards_sentences ${my_LIBRARIES})
# target_link_libraries(flashcards_words ${my_LIBRARIES})

