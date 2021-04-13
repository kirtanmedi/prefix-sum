#include "barrier.h"
#include <boost/thread.hpp>
#include <boost/thread/barrier.hpp>
#include <mutex>
#include <semaphore.h>

namespace synchronization {
   
   barrier::barrier( int numberOfThreads ) {
      threadCount = numberOfThreads;   //initializing total thread count to thread count specified by user
      currCount = 0;                   //setting the current executed thread count to 0
      sem_init(&mutexSem, 0, 1);       //initializing semaphore for synchronization
      //implementing two phase barrier for reusability
      sem_init(&phase1, 0, 0);         
      sem_init(&phase2, 0, 1);

      return;
   }

   barrier::~barrier( ) {
      //deleting semaphores of barrier 
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
