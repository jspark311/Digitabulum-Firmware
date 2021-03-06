/*
File:   ExpansionPort.cpp
Author: J. Ian Lindsay
Date:   2016.05.26

Copyright 2016 Manuvr, Inc

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

*/


#include "ExpansionPort.h"
#include <DataStructures/StringBuilder.h>

#include "stm32f7xx_hal.h"



// If your driver represents a statically-allocated unit, you can do something
//   like this...
//volatile ExpansionPort* ExpansionPort::INSTANCE = NULL;


ExpansionPort::ExpansionPort() : EventReceiver("ExpansionPort") {
  INSTANCE = this;
}


ExpansionPort::~ExpansionPort() {
}


void ExpansionPort::gpioSetup() {
}


/*******************************************************************************
* ######## ##     ## ######## ##    ## ########  ######
* ##       ##     ## ##       ###   ##    ##    ##    ##
* ##       ##     ## ##       ####  ##    ##    ##
* ######   ##     ## ######   ## ## ##    ##     ######
* ##        ##   ##  ##       ##  ####    ##          ##
* ##         ## ##   ##       ##   ###    ##    ##    ##
* ########    ###    ######## ##    ##    ##     ######
*
* These are overrides from EventReceiver interface...
*******************************************************************************/

/**
* This is called when the kernel attaches the module.
* This is the first time the class can be expected to have kernel access.
*
* @return 0 on no action, 1 on action, -1 on failure.
*/
int8_t ExpansionPort::attached() {
  return EventReceiver::attached();
}


/**
* Debug support function.
*
* @param A pointer to a StringBuffer object to receive the output.
*/
void ExpansionPort::printDebug(StringBuilder* output) {
  EventReceiver::printDebug(output);
}


/**
* If we find ourselves in this fxn, it means an event that this class built (the argument)
*   has been serviced and we are now getting the chance to see the results. The argument
*   to this fxn will never be NULL.
*
* Depending on class implementations, we might choose to handle the completed Event differently. We
*   might add values to event's Argument chain and return RECYCLE. We may also free() the event
*   ourselves and return DROP. By default, we will return REAP to instruct the EventManager
*   to either free() the event or return it to it's preallocate queue, as appropriate. If the event
*   was crafted to not be in the heap in its own allocation, we will return DROP instead.
*
* @param  event  The event for which service has been completed.
* @return A callback return code.
*/
int8_t ExpansionPort::callback_proc(ManuvrMsg* event) {
  /* Setup the default return code. If the event was marked as mem_managed, we return a DROP code.
     Otherwise, we will return a REAP code. Downstream of this assignment, we might choose differently. */
  int8_t return_value = (0 == event->refCount()) ? EVENT_CALLBACK_RETURN_REAP : EVENT_CALLBACK_RETURN_DROP;

  /* Some class-specific set of conditionals below this line. */
  switch (event->eventCode()) {
    default:
      break;
  }

  return return_value;
}



int8_t ExpansionPort::notify(ManuvrMsg* active_event) {
  int8_t return_value = 0;

  switch (active_event->eventCode()) {
    default:
      return_value += EventReceiver::notify(active_event);
      break;
  }

  flushLocalLog();
  return return_value;
}


#if defined(MANUVR_CONSOLE_SUPPORT)
void ExpansionPort::procDirectDebugInstruction(StringBuilder *input) {
  char* str = input->position(0);

  switch (*(str)) {
    default:
      #ifdef __MANUVR_DEBUG
      EventReceiver::procDirectDebugInstruction(input);
      #endif
      break;
  }

  flushLocalLog();
}
#endif  //MANUVR_CONSOLE_SUPPORT
