add_custom_target(practicum)

function(add_practicum SOURCE_FILE)
    string(REGEX REPLACE "^([a-z])\\.cpp$" "\\1" TARGET_SUFFIX ${SOURCE_FILE})
    set(TARGET_NAME "practicum-${TARGET_SUFFIX}")
    add_executable(${TARGET_NAME} ${SOURCE_FILE})
    add_dependencies(practicum ${TARGET_NAME})
endfunction()

add_practicum("a.cpp")
add_practicum("c.cpp")
add_practicum("d.cpp")
add_practicum("f.cpp")
