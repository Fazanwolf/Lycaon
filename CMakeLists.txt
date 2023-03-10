cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)
set(PROJECT_NAME lycaon)

option(LYCAON_BUILD_TESTS "Build tests" OFF)
option(LYCAON_INSTALL "Install R-Type" ON)
option(LYCAON_CPACK "Create the installer" OFF)
option(USE_CLANG_TIDY "Use clang-tidy" OFF)
option(USE_CLANG_TIDY_WITH_ERRORS "Use clang tidy but all warnings are errors" OFF)
option(USE_CLANG_TIDY_WITH_FIX "Use clang-tidy with fix" OFF)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF) # Fix dll issues on Windows

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

if(WIN32)
    set(${PROJECT_NAME}_ICON cmake/assets/app.rc)
endif()

add_executable(${PROJECT_NAME} src/main.cpp
    src/tests/TestWindow.cpp src/tests/TestAudio.cpp src/tests/TestSprite.cpp
    src/tests/TestTools.cpp
)

target_include_directories(${PROJECT_NAME}
        PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/src"
        PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>"
        "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)

find_package(SFML 2.6 REQUIRED COMPONENTS graphics window system audio)

project(
        lycaon
        VERSION 0.0.1.0
        DESCRIPTION "Lycaon is an implementation of ECS using SFML as graphics library in C++/"
        HOMEPAGE_URL "https://github.com/Fazanwolf/R-Type"
        LANGUAGES CXX
)


# Link all libraries
target_link_libraries(${PROJECT_NAME}
        PUBLIC
        sfml-graphics sfml-audio sfml-system sfml-window
)

target_compile_options(${PROJECT_NAME} PRIVATE
        $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>: -Wall -Wextra>
        $<$<CXX_COMPILER_ID:MSVC>: /W4>
)

set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION} SOVERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR})
set_target_properties(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX "-debug")

# Set the startup project in Visual Studio
if (MSVC)
    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
    message(STATUS "Setting startup project to ${PROJECT_NAME}")
endif (MSVC)

if (LYCAON_BUILD_TESTS)
    message(STATUS "Generating tests")
    include(GoogleTest)
    enable_testing()
    add_subdirectory(tests)
endif ()

if (USE_CLANG_TIDY OR USE_CLANG_TIDY_WITH_ERRORS OR USE_CLANG_TIDY_WITH_FIX)
    find_program(CLANG_TIDY_EXE NAMES "clang-tidy-16")
    if (NOT CLANG_TIDY_EXE)
        message(WARNING "clang-tidy not found.")
    else ()
        message(STATUS "clang-tidy found: ${CLANG_TIDY_EXE}")
        if (USE_CLANG_TIDY_WITH_FIX)
            set(CLANG_TIDY_COMMMAND "${CLANG_TIDY_EXE}" "--fix" "--config-file=${CMAKE_CURRENT_SOURCE_DIR}/.clang-tidy")
        elseif (USE_CLANG_TIDY_WITH_ERRORS)
            set(CLANG_TIDY_COMMMAND "${CLANG_TIDY_EXE}" "--warnings-as-errors=*" "--config-file=${CMAKE_CURRENT_SOURCE_DIR}/.clang-tidy")
        else ()
            set(CLANG_TIDY_COMMMAND "${CLANG_TIDY_EXE}" "--config-file=${CMAKE_CURRENT_SOURCE_DIR}/.clang-tidy")
        endif ()
        set_target_properties(${PROJECT_NAME} PROPERTIES CXX_CLANG_TIDY "${CLANG_TIDY_COMMMAND}")
    endif ()
endif ()

if (LYCAON_INSTALL OR LYCAON_CPACK)
    # Specify the files to be installed
    message(STATUS "Installing ${PROJECT_NAME}")
    get_target_property(${PROJECT_NAME}_deps ${PROJECT_NAME} INTERFACE_LINK_LIBRARIES)

    install(TARGETS ${PROJECT_NAME} ${${PROJECT_NAME}_deps}
            EXPORT ${PROJECT_NAME}Targets
            LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} COMPONENT library
            ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR} COMPONENT archive
            RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR} COMPONENT runtime
            INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR} COMPONENT headers
            )

    install(DIRECTORY include
            DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/../ # Remove the extra include directory
            COMPONENT headers
            )

    install(EXPORT ${PROJECT_NAME}Targets
            FILE ${PROJECT_NAME}Targets.cmake
            NAMESPACE ${PROJECT_NAME}::
            DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
            )

    # Setup the version file
    include(CMakePackageConfigHelpers)
    write_basic_package_version_file(
            ${PROJECT_NAME}ConfigVersion.cmake
            VERSION ${PROJECT_VERSION}
            COMPATIBILITY AnyNewerVersion
    )

    # generate the config file that is includes the exports
    configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/cmake/Config.cmake.in
            "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
            INSTALL_DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}"
            NO_SET_AND_CHECK_MACRO
            NO_CHECK_REQUIRED_COMPONENTS_MACRO
            )

    install(FILES
            ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
            ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
            DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
            )
    export(EXPORT ${PROJECT_NAME}Targets FILE "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Targets.cmake")
endif ()

if (LYCAON_CPACK)
    include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/CPackConfig.cmake)
endif ()