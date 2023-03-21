target_sources(${CMAKE_PROJECT_NAME} PRIVATE
        mpc-flow/mpc-parallel/mpc_context.cpp
        mpc-flow/mpc-parallel/mpc_round.cpp
        mpc-flow/mpc-parallel/LazyBCValidator.cpp
        mpc-flow/mpc-parallel-v2/mpc_context.cpp
        mpc-flow/mpc-parallel-v2/mpc_round.cpp
        )

# Refer to single internal library only if it's not assembled into a big library.
option(ENABLE_ASSEMBLE "Enable assemble" OFF)
if (NOT ${ENABLE_ASSEMBLE})
    find_package(PkgConfig REQUIRED)
    #set(OPENSSL_USE_STATIC_LIBS TRUE)
    find_package(OpenSSL REQUIRED)

    target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
            ${OPENSSL_INCLUDE_DIR}
            )

    target_link_libraries(${CMAKE_PROJECT_NAME}
            OpenSSL::Crypto
            -ldl
            )
endif()
