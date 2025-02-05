set(HEADER_FILES EmployeeRepository.h)

set(SOURCE_FILES EmployeeRepository.cpp)

add_library(EmployeeRepositoryLib STATIC ${SOURCE_FILES} ${HEADER_FILES})

target_link_libraries(EmployeeRepositoryLib CarLib)