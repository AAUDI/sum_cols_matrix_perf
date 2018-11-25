#Global Settings used to generate this library
set(KOKKOS_PATH /usr/local CACHE FILEPATH "Kokkos installation path" FORCE)
set(KOKKOS_GMAKE_DEVICES "OpenMP,Serial" CACHE STRING "Kokkos devices list" FORCE)
set(KOKKOS_GMAKE_ARCH "None" CACHE STRING "Kokkos architecture flags" FORCE)
set(KOKKOS_DEBUG_CMAKE ON CACHE BOOL "Kokkos debug enabled ?" FORCE)
set(KOKKOS_GMAKE_USE_TPLS "librt" CACHE STRING "Kokkos templates list" FORCE)
set(KOKKOS_CXX_STANDARD c++11 CACHE STRING "Kokkos C++ standard" FORCE)
set(KOKKOS_GMAKE_OPTIONS "disable_dualview_modify_check" CACHE STRING "Kokkos options" FORCE)
set(KOKKOS_GMAKE_CUDA_OPTIONS "" CACHE STRING "Kokkos Cuda options" FORCE)
set(KOKKOS_GMAKE_TPL_INCLUDE_DIRS "" CACHE STRING "Kokkos TPL include directories" FORCE)
set(KOKKOS_GMAKE_TPL_LIBRARY_DIRS "" CACHE STRING "Kokkos TPL library directories" FORCE)
set(KOKKOS_GMAKE_TPL_LIBRARY_NAMES " dl rt" CACHE STRING "Kokkos TPL library names" FORCE)
if(NOT DEFINED ENV{NVCC_WRAPPER})
set(NVCC_WRAPPER /home/aaudi/work/work_numscale_kokkos/kokkos/bin/nvcc_wrapper CACHE FILEPATH "Path to command nvcc_wrapper" FORCE)
else()
  set(NVCC_WRAPPER $ENV{NVCC_WRAPPER} CACHE FILEPATH "Path to command nvcc_wrapper")
endif()

#Source and Header files of Kokkos relative to KOKKOS_PATH
set(KOKKOS_HEADERS /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_Serial.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_hwloc.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_ExecPolicy.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_OpenMPTargetSpace.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_Parallel.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_Macros.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_Qthreads.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_Timer.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_Pair.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_UniqueToken.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_Profiling_ProfileSection.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_OpenMP.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_Vectorization.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_Atomic.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_Crs.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_CudaSpace.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_ScratchSpace.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_Core_fwd.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_CopyViews.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_Parallel_Reduce.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_NumericTraits.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_OpenMPTarget.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_ROCmSpace.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_ROCm.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_HBWSpace.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_TaskScheduler.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_Cuda.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_Array.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_AnonymousSpace.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/KokkosExp_MDRangePolicy.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_Core.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_Complex.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_HostSpace.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_View.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_MasterLock.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_WorkGraphPolicy.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_MemoryPool.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_TaskPolicy.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_MemoryTraits.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_Concepts.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_Threads.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_Layout.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_ClockTic.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_Profiling_DeviceInfo.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_ViewTile.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_ConcurrentBitset.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_Atomic_Fetch_Sub.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_Atomic_Windows.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_HostThreadTeam.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_FunctorAnalysis.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_Atomic_Fetch_And.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/KokkosExp_ViewMapping.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_SharedAlloc.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_Spinwait.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_Volatile_Load.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_Atomic_Fetch_Add.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_Atomic_Generic.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_FunctorAdapter.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_Serial_WorkGraphPolicy.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_Utilities.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_AnalyzePolicy.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_ViewCtor.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_TaskQueue.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_CPUDiscovery.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_ViewArray.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_PhysicalLayout.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_HostBarrier.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_Memory_Fence.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_Atomic_Decrement.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_Error.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_Atomic_View.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_Profiling_Interface.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_Atomic_Exchange.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/KokkosExp_Host_IterateTile.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_Atomic_Compare_Exchange_Strong.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_OldMacros.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_TaskQueue_impl.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_StaticAssert.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_Atomic_Assembly.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_BitOps.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_Traits.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_Atomic_Increment.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_Tags.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_Timer.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_ViewMapping.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_Serial_Task.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_Atomic_Fetch_Or.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/containers/src/Kokkos_DynRankView.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/containers/src/Kokkos_Vector.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/containers/src/Kokkos_StaticCrsGraph.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/containers/src/Kokkos_Functional.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/containers/src/Kokkos_DualView.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/containers/src/Kokkos_DynamicView.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/containers/src/Kokkos_Bitset.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/containers/src/Kokkos_UnorderedMap.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/containers/src/Kokkos_ScatterView.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/containers/src/Kokkos_ErrorReporter.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/containers/src/impl/Kokkos_StaticCrsGraph_factory.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/containers/src/impl/Kokkos_Functional_impl.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/containers/src/impl/Kokkos_Bitset_impl.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/containers/src/impl/Kokkos_UnorderedMap_impl.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/algorithms/src/Kokkos_Random.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/algorithms/src/Kokkos_Sort.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/OpenMP/Kokkos_OpenMP_Task.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/OpenMP/Kokkos_OpenMP_Exec.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/OpenMP/Kokkos_OpenMP_Parallel.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/OpenMP/Kokkos_OpenMP_WorkGraphPolicy.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/OpenMP/Kokkos_OpenMP_Team.hpp CACHE STRING "Kokkos headers list" FORCE)
set(KOKKOS_HEADERS_IMPL CACHE STRING "Kokkos headers impl list" FORCE)
set(KOKKOS_HEADERS_CUDA CACHE STRING "Kokkos headers Cuda list" FORCE)
set(KOKKOS_HEADERS_OPENMP /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/OpenMP/Kokkos_OpenMP_Task.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/OpenMP/Kokkos_OpenMP_Exec.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/OpenMP/Kokkos_OpenMP_Parallel.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/OpenMP/Kokkos_OpenMP_WorkGraphPolicy.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/OpenMP/Kokkos_OpenMP_Team.hpp CACHE STRING "Kokkos headers OpenMP list" FORCE)
set(KOKKOS_HEADERS_ROCM CACHE STRING "Kokkos headers ROCm list" FORCE)
set(KOKKOS_HEADERS_THREADS CACHE STRING "Kokkos headers Threads list" FORCE)
set(KOKKOS_HEADERS_QTHREADS CACHE STRING "Kokkos headers QThreads list" FORCE)
set(KOKKOS_SRC /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_Serial.cpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_HostBarrier.cpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_ExecPolicy.cpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_HostThreadTeam.cpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_SharedAlloc.cpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_Spinwait.cpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_Profiling_Interface.cpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_CPUDiscovery.cpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_hwloc.cpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_Core.cpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_Error.cpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_HostSpace.cpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_Serial_Task.cpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_MemoryPool.cpp /home/aaudi/work/work_numscale_kokkos/kokkos/containers/src/impl/Kokkos_UnorderedMap_impl.cpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/OpenMP/Kokkos_OpenMP_Task.cpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/OpenMP/Kokkos_OpenMP_Exec.cpp CACHE STRING "Kokkos source list" FORCE)

#Variables used in application Makefiles
set(KOKKOS_OS Linux CACHE STRING "" FORCE)
set(KOKKOS_CPP_DEPENDS KokkosCore_config.h /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_Serial.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_hwloc.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_ExecPolicy.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_OpenMPTargetSpace.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_Parallel.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_Macros.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_Qthreads.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_Timer.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_Pair.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_UniqueToken.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_Profiling_ProfileSection.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_OpenMP.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_Vectorization.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_Atomic.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_Crs.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_CudaSpace.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_ScratchSpace.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_Core_fwd.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_CopyViews.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_Parallel_Reduce.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_NumericTraits.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_OpenMPTarget.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_ROCmSpace.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_ROCm.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_HBWSpace.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_TaskScheduler.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_Cuda.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_Array.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_AnonymousSpace.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/KokkosExp_MDRangePolicy.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_Core.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_Complex.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_HostSpace.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_View.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_MasterLock.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_WorkGraphPolicy.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_MemoryPool.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_TaskPolicy.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_MemoryTraits.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_Concepts.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_Threads.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/Kokkos_Layout.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_ClockTic.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_Profiling_DeviceInfo.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_ViewTile.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_ConcurrentBitset.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_Atomic_Fetch_Sub.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_Atomic_Windows.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_HostThreadTeam.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_FunctorAnalysis.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_Atomic_Fetch_And.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/KokkosExp_ViewMapping.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_SharedAlloc.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_Spinwait.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_Volatile_Load.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_Atomic_Fetch_Add.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_Atomic_Generic.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_FunctorAdapter.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_Serial_WorkGraphPolicy.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_Utilities.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_AnalyzePolicy.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_ViewCtor.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_TaskQueue.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_CPUDiscovery.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_ViewArray.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_PhysicalLayout.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_HostBarrier.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_Memory_Fence.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_Atomic_Decrement.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_Error.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_Atomic_View.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_Profiling_Interface.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_Atomic_Exchange.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/KokkosExp_Host_IterateTile.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_Atomic_Compare_Exchange_Strong.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_OldMacros.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_TaskQueue_impl.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_StaticAssert.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_Atomic_Assembly.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_BitOps.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_Traits.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_Atomic_Increment.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_Tags.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_Timer.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_ViewMapping.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_Serial_Task.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/impl/Kokkos_Atomic_Fetch_Or.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/containers/src/Kokkos_DynRankView.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/containers/src/Kokkos_Vector.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/containers/src/Kokkos_StaticCrsGraph.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/containers/src/Kokkos_Functional.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/containers/src/Kokkos_DualView.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/containers/src/Kokkos_DynamicView.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/containers/src/Kokkos_Bitset.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/containers/src/Kokkos_UnorderedMap.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/containers/src/Kokkos_ScatterView.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/containers/src/Kokkos_ErrorReporter.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/containers/src/impl/Kokkos_StaticCrsGraph_factory.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/containers/src/impl/Kokkos_Functional_impl.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/containers/src/impl/Kokkos_Bitset_impl.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/containers/src/impl/Kokkos_UnorderedMap_impl.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/algorithms/src/Kokkos_Random.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/algorithms/src/Kokkos_Sort.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/OpenMP/Kokkos_OpenMP_Task.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/OpenMP/Kokkos_OpenMP_Exec.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/OpenMP/Kokkos_OpenMP_Parallel.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/OpenMP/Kokkos_OpenMP_WorkGraphPolicy.hpp /home/aaudi/work/work_numscale_kokkos/kokkos/core/src/OpenMP/Kokkos_OpenMP_Team.hpp CACHE STRING "" FORCE)
set(KOKKOS_LINK_DEPENDS libkokkos.a CACHE STRING "" FORCE)
set(KOKKOS_CXXFLAGS --std=c++11 -fopenmp CACHE STRING "" FORCE)
set(KOKKOS_CPPFLAGS -I./ -I/home/aaudi/work/work_numscale_kokkos/kokkos/core/src -I/home/aaudi/work/work_numscale_kokkos/kokkos/containers/src -I/home/aaudi/work/work_numscale_kokkos/kokkos/algorithms/src CACHE STRING "" FORCE)
set(KOKKOS_LDFLAGS -L/home/aaudi/work/work_numscale_kokkos/build_openmp/kokkos -fopenmp CACHE STRING "" FORCE)
set(KOKKOS_LIBS -lkokkos -ldl -lrt CACHE STRING "" FORCE)
set(KOKKOS_EXTRA_LIBS -ldl -lrt CACHE STRING "" FORCE)
set(KOKKOS_LINK_FLAGS -fopenmp CACHE STRING "extra flags to the link step (e.g. OpenMP)" FORCE)

#Internal settings which need to propagated for Kokkos examples
set(KOKKOS_INTERNAL_USE_CUDA 0 CACHE STRING "" FORCE)
set(KOKKOS_INTERNAL_USE_OPENMP 1 CACHE STRING "" FORCE)
set(KOKKOS_INTERNAL_USE_PTHREADS 0 CACHE STRING "" FORCE)
set(KOKKOS_INTERNAL_USE_SERIAL 1 CACHE STRING "" FORCE)
set(KOKKOS_INTERNAL_USE_ROCM 0 CACHE STRING "" FORCE)
set(KOKKOS_INTERNAL_USE_QTHREADS 0 CACHE STRING "" FORCE)

set(KOKKOS_CXX_FLAGS --std=c++11 -fopenmp)
set(KOKKOS_CPP_FLAGS -I./ -I/home/aaudi/work/work_numscale_kokkos/kokkos/core/src -I/home/aaudi/work/work_numscale_kokkos/kokkos/containers/src -I/home/aaudi/work/work_numscale_kokkos/kokkos/algorithms/src)
set(KOKKOS_LD_FLAGS -L/home/aaudi/work/work_numscale_kokkos/build_openmp/kokkos -fopenmp)
set(KOKKOS_LIBS_LIST "-lkokkos -ldl -lrt")
set(KOKKOS_EXTRA_LIBS_LIST "-ldl -lrt")
set(KOKKOS_LINK_FLAGS -fopenmp)