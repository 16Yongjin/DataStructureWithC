//
//  Person.h
//  DataStructures
//
//  Created by JoYongJin on 2017. 3. 31..
//  Copyright © 2017년 JoYongJin. All rights reserved.
//

#ifndef Person_h
#define Person_h


#define STR_LEN 30

typedef struct _person {
    int ssn;
    char name[STR_LEN];
    char addr[STR_LEN];
} Person;

int GetSSN(Person * p);
void ShowPerInfo(Person * p);
Person * MakePersonData(int ssn, char * name, char * addr);

#endif /* Person_h */
