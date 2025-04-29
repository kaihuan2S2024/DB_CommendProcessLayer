# external_dependencies.cmake

# refer VDBE_LAYER


set(BUILD_TESTING OFF CACHE BOOL "" FORCE)
include(FetchContent)

FetchContent_Declare(
        VDBE_LAYER
        GIT_REPOSITORY git@github.com:CMUSV-FDD/T3_S25_Virtual_Machine_Layer.git
        GIT_TAG integration
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(VDBE_LAYER)
