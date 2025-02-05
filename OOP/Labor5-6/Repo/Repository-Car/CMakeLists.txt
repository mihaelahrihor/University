set(HEADER_FILES CarRepository.h)

set(SOURCE_FILES CarRepository.cpp)

add_library(CarRepositoryLib STATIC ${SOURCE_FILES} ${HEADER_FILES})

target_link_libraries(CarRepositoryLib CarLib)