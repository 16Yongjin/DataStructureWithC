//
//  Slot.h
//  DataStructures
//
//  Created by JoYongJin on 2017. 3. 31..
//  Copyright © 2017년 JoYongJin. All rights reserved.
//

#ifndef Slot_h
#define Slot_h

#include "Person.h"

typedef int Key;
typedef Person * Value;

enum SlotStatus {EMPTY, DELETED, INUSE};

typedef struct _slot
{
    Key key;
    Value val;
    enum SlotStatus status;
} Slot;

#endif /* Slot_h */
