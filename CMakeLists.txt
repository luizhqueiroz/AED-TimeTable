cmake_minimum_required(VERSION 3.23)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled main.cpp Classes/aula.cpp Classes/aula.h Classes/horario.cpp Classes/horario.h Classes/estudante.cpp Classes/estudante.h Classes/turma.cpp Classes/turma.h Classes/hour.cpp Classes/hour.h Classes/bst.cpp Classes/bst.h Classes/menu.cpp Classes/menu.h Classes/functions.cpp Classes/functions.h Classes/uc.cpp Classes/uc.h Classes/pedido.cpp Classes/pedido.h Classes/mudancaHorario.cpp Classes/mudancaHorario.h)


# Doxygen Build
find_package(Doxygen)
if(DOXYGEN_FOUND)
    set(BUILD_DOC_DIR "${CMAKE_SOURCE_DIR}/docs/output")
    if(NOT EXISTS "${BUILD_DOC_DIR}")
        file(MAKE_DIRECTORY "${BUILD_DOC_DIR}")
    endif()

    set(DOXYGEN_IN "${CMAKE_CURRENT_SOURCE_DIR}/Doxygen/Doxyfile")
    set(DOXYGEN_OUT "${CMAKE_CURRENT_BINARY_DIR}/Doxyfile")
    configure_file("${DOXYGEN_IN}" "${DOXYGEN_OUT}" @ONLY)

    message("Doxygen build started")
    add_custom_target(Doxygen ALL
            COMMAND "${DOXYGEN_EXECUTABLE}" "${DOXYGEN_OUT}"
            WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM)
else(DOXYGEN_FOUND)
    message("Doxygen needs to be installed to generate the documentation.")
endif(DOXYGEN_FOUND)