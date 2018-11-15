
#ifndef OPENMP_TIMER_H_
#define OPENMP_TIMER_H_

#include <omp.h>
#include <stdio.h>

class OpenMPTimer
{
  
public:
  
  OpenMPTimer();
    
  void start();
  void stop();
  void reset();
  double elapsed() const;

  ~OpenMPTimer();

protected:
  double start_time;
  double total_time;

};


#endif 