file(GLOB main_SRC
        )

add_executable(sqlite_learn main.cpp ${main_SRC})

find_package(SQLite3)
include_directories(${SQLite3_INCLUDE_DIRS})
target_link_libraries(sqlite_learn ${SQLite3_LIBRARIES})