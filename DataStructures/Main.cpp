//
//  Main.cpp
//  DataStructures
//
//  Created by JoYongJin on 2016. 11. 1..
//  Copyright © 2016년 JoYongJin. All rights reserved.
//

#include "Stacking.hpp"

int main() {
    
    Stack stack;
    StackInit(stack);
    
    for(int i=0; i<10; i++){
        SPush(stack, i);
    }
    
    while(!SIsEmpty(stack))
        printf("%d, ", SPop(stack));
    
    return 0;
}



