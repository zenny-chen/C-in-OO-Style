//
//  main.c
//  CObjective
//
//  Created by Zenny Chen on 2017/8/13.
//  Copyright © 2017年 CodeLearning Studio. All rights reserved.
//

#include <stdio.h>
#include "ZCObject.h"

int main(int argc, const char * argv[])
{
    struct ZCObject obj;
    
    ZCInitializeObject(&obj);
    
    var str = ZCGetDescription(&obj)();
    printf("str = %s\n", str);

    struct ZCObjectTest test;
    ZCInitializeTest(&test);
    
    str = ZCGetDescription(&test)();
    printf("str = %s\n", str);
    
    // Test for polymorphism
    struct ZCObject *pObj = (struct ZCObject*)&test;
    test.value = 100;
    str = ZCGetDescription(pObj)();
    printf("str = %s\n", str);

    return 0;
}

