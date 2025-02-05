set(HEADER_FILES Car.h)

set(SOURCE_FILES Car.cpp)

add_library(CarLib STATIC ${SOURCE_FILES} ${HEADER_FILES})

