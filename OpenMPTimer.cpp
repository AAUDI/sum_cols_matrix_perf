
#include "OpenMPTimer.h"


OpenMPTimer::OpenMPTimer() {
  start_time = 0.0;
  total_time = 0.0;
} 


OpenMPTimer::~OpenMPTimer() {
} 


void OpenMPTimer::start() 
{
  start_time = omp_get_wtime(); 
} 


void OpenMPTimer::stop()
{
  double now = omp_get_wtime();
  total_time += (now-start_time);
} 


double OpenMPTimer::elapsed() const
{
  return total_time;
} 

void OpenMPTimer::reset()
{
  total_time = 0.0;
}

