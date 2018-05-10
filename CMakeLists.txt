cmake_minimum_required(VERSION 2.8.3)
project(mtyping)
# project(duo CXX)

include_directories(
	include
)

SET(CMAKE_CXX_FLAGS "-std=c++11 -O2 -g -Wall ${CMAKE_CXX_FLAGS}")

# add_library(duo
#   src/${PROJECT_NAME}/duo.cpp
# )

add_executable(test_duo src/test.cpp src/mtyping/sentence.cpp)

# target_link_libraries(test)
# target_link_libraries(typing ${my_LIBRARIES})
# target_link_libraries(flashcards_sentences ${my_LIBRARIES})
# target_link_libraries(flashcards_words ${my_LIBRARIES})

