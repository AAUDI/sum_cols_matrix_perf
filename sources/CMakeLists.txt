# include header for main application
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(/usr/local/cuda-8.0/include/)

if (KOKKOS_ENABLE_CUDA)
  set(EXE_NAME "parallel_sum_matrix_kokkos_cuda")
else()
  set(EXE_NAME "parallel_sum_matrix_kokkos_openmp")
endif()


set (EXE_NAME_SRC
     main.cpp
     matrix_template.hpp 
     matrix_template.cpp
     kokkos_shared.h
     kokkos_functor.h
)
  
if (KOKKOS_ENABLE_OPENMP)
  set (EXE_NAME_SRC
    ${EXE_NAME_SRC}
    OpenMPTimer.cpp
    OpenMPTimer.h)
endif()

if (KOKKOS_ENABLE_CUDA)
  set (EXE_NAME_SRC
    ${EXE_NAME_SRC}
    CudaTimer.h)
endif()

add_executable(${EXE_NAME} ${EXE_NAME_SRC})
target_link_libraries(${EXE_NAME} kokkos)

target_compile_options(${EXE_NAME} PUBLIC -lcudart -lm -fopenmp)
