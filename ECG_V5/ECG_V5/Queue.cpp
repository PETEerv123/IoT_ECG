#include "Queue.h"


void Queue::push_back(Queue_types *Queue, int32_t Data) {
  if (!Is_Full(Queue)) {
    Queue->QueueArr[Queue->Rear + 1] = Data;
    Queue->Capacity++;
    Queue->Rear++;
  }
}

bool Queue::Is_Full(Queue_types *Queue) {
  if (Queue->Capacity == Queue->Size) {
    return true;
  } else return false;
}