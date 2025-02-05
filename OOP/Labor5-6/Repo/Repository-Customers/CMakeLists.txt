set(HEADER_FILES CustomerRepository.h)

set(SOURCE_FILES CustomerRepository.cpp)

add_library(CustomerRepoLib STATIC ${SOURCE_FILES} ${HEADER_FILES})

target_link_libraries(CustomerRepoLib CustomerLib)