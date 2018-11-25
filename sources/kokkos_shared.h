#ifndef KOKKOS_SHARED_H_
#define KOKKOS_SHARED_H_

#include <Kokkos_Core.hpp>
#include <Kokkos_Parallel.hpp>
#include <Kokkos_View.hpp>

using Device = Kokkos::DefaultExecutionSpace;


template <typename T>

typedef Kokkos::TeamPolicy<Device>::member_type member_type;


/************************************************/

// Data array for matrix
typedef Kokkos::View<T*, Device> DataArrayMTX;
// host mirror
typedef DataArrayMTX::HostMirror DataArrayMTXHost;


// Data array for sum of columns of matrix
typedef Kokkos::View<T*, Device> DataArraySUMCOLS;
// host mirror
typedef DataArraySUMCOLS::HostMirror DataArraySUMCOLSHost;



/************************************************/


#endif // KOKKOS_SHARED_H_

