set(HEADER_FILES Customer.h)

set(SOURCE_FILES Customer.cpp)

add_library(CustomerLib STATIC ${SOURCE_FILES} ${HEADER_FILES})