add_library(
        ranges INTERFACE
        requirements.h
        transformIter.h
        transform.h
        drop.h
        dropIter.h
        filter.h
        filterIter.h
        keys.h
        position.h
        positionIter.h
        reverse.h
        reverseIter.h
        take.h
        takeIter.h
        values.h
)

target_include_directories(ranges INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})