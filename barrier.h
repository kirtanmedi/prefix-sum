#ifndef BARRIER_H
#define BARRIER_H

#include <boost/thread.hpp>
#include <boost/thread/barrier.hpp>
#include <mutex>
#include <semaphore.h>

namespace synchronization
{

   // Provides a reusable barrier
   class barrier {
   private:
      sem_t mutexSem;
      sem_t phase1;
      sem_t phase2;

      unsigned int threadCount;
      unsigned int currCount;

   public:

      // Constructor
      barrier( int numberOfThreads );

      // Destructor
      ~barrier( );

      // Function to wait at the barrier until all threads have reached the barrier
      void arriveAndWait( void );
   };

}

#endif
