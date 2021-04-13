#include "barrier.h"
#include <boost/thread.hpp>
#include <boost/thread/barrier.hpp>
#include <mutex>
#include <semaphore.h>

namespace synchronization {
   
   barrier::barrier( int numberOfThreads ) {
      threadCount = numberOfThreads;
      currCount = 0;
      sem_init(&mutexSem, 0, 1);
      sem_init(&phase1, 0, 0);
      sem_init(&phase2, 0, 1);

      return;
   }

   barrier::~barrier( ) {
      sem_destroy(&mutexSem);
      sem_destroy(&phase1);
      sem_destroy(&phase2);
      return;
   }

   void barrier::arriveAndWait(void) {
      sem_wait(&mutexSem);
      currCount++;

      if(currCount == threadCount){
         sem_wait(&phase2);
         sem_post(&phase1);
      }

      sem_post(&mutexSem);

      sem_wait(&phase1);
      sem_post(&phase1);

      //critical point 

      sem_wait(&mutexSem);
      currCount--;
      if(currCount == 0){
         sem_wait(&phase1);
         sem_post(&phase2);
      }

      sem_post(&mutexSem);

      sem_wait(&phase2);
      sem_post(&phase2);
   }
}
