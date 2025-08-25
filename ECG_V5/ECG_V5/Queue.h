#ifndef _Queue_H
#define _Queue_H

#include "Arduino.h"

typedef struct {
  int8_t Front, Rear, Size;
  uint8_t Capacity;
  uint8_t *QueueArr;
}Queue_types;


class Queue {
  void push_back(Queue_types *Queue,int32_t Data);
  bool Is_Full(Queue_types *Queue);
};
extern Queue Queue;



#endif
