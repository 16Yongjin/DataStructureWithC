//
//  SimpleHashMain.c
//  DataStructures
//
//  Created by JoYongJin on 2017. 3. 31..
//  Copyright © 2017년 JoYongJin. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "Person.h"
#include "Table.h"

int MyHashFunc(int k)
{
    return k % 100;
}

int main()
{
    Table myTbl;
    Person * np;
    Person * sp;
    Person * rp;
    
    TBLInit(&myTbl, MyHashFunc);
    np = MakePersonData(20170331, "kim", "HUFS");
    TBLInsert(&myTbl, GetSSN(np), np);
    np = MakePersonData(19970203, "Jo", "DBD");
    TBLInsert(&myTbl, GetSSN(np), np);
    np = MakePersonData(17781229, "Lee", "JONGRO");
    TBLInsert(&myTbl, GetSSN(np), np);
    
    sp = TBLSearch(&myTbl, 20170331);
    if (sp != NULL)
        ShowPerInfo(sp);
    
    sp = TBLSearch(&myTbl, 19970203);
    if (sp != NULL)
        ShowPerInfo(sp);
    
    sp = TBLSearch(&myTbl, 17781229);
    if (sp != NULL)
        ShowPerInfo(sp);
    
    rp = TBLDelete(&myTbl, 20170331);
    if(rp != NULL)
        free(rp);
    
    rp = TBLDelete(&myTbl, 19970203);
    if(rp != NULL)
        free(rp);
    
    rp = TBLDelete(&myTbl, 17781229);
    if(rp != NULL)
        free(rp);
    
    return 0;
}

















