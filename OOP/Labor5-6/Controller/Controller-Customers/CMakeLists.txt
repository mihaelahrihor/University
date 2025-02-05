set(HEADER_FILES CustomerController.h)

set(SOURCE_FILES CustomerController.cpp)

add_library(CustomerControllerLib STATIC ${SOURCE_FILES} ${HEADER_FILES})

target_link_libraries(CustomerControllerLib CustomerRepoLib CustomerLib)