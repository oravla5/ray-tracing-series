include_directories(include)
add_subdirectory(base)
add_subdirectory(hittable)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} rayBaseLib rayHittableLib)