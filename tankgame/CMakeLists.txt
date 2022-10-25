set(TARGET_NAME TankGame)

add_executable(${TARGET_NAME} main.cpp)

add_subdirectory(utils)

# Compile options
target_compile_options(
    ${TARGET_NAME}
        PRIVATE
            $<$<CXX_COMPILER_ID:GNU>:-Wall -Werror>
)