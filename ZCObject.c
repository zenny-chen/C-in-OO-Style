//
//  ZCObject.c
//  CObjective
//
//  Created by Zenny Chen on 2017/8/13.
//  Copyright © 2017年 CodeLearning Studio. All rights reserved.
//

#include "ZCObject.h"

#include <stdio.h>
#include <string.h>
#include <Block.h>

/// object type vtable index
enum ZCVTABLE_LIST
{
    ZCVTABLE_LIST_OBJECT,
    ZCVTABLE_LIST_TEST
};

/// vtable for ZCGetDescription methods
static const uintptr_t sZCGetDescriptionVTable[] = {
    (uintptr_t)(const char* (^(*)(struct ZCObject*))(void))&ZCGetDescription,
    (uintptr_t)(const char* (^(*)(struct ZCObjectTest*))(void))&ZCGetDescription
};


void ZCInitializeObject(struct ZCObject *pObj)
{
    pObj->vtbl_index = ZCVTABLE_LIST_OBJECT;
    pObj->description = "ZCObject";
    pObj->tag = 0;
}

void ZCInitializeTest(struct ZCObjectTest *pObj)
{
    pObj->vtbl_index = ZCVTABLE_LIST_TEST;
    pObj->description = "ZCObjectTest";
    pObj->tag = 0;
    pObj->value = 0;
}

const char* (^ __attribute__((overloadable)) ZCGetDescription(struct ZCObject *pObj))(void)
{
    if(pObj->vtbl_index == 0)
    {
        __block const char* (^block)(void) = ^const char* (void) {
            var result = pObj->description;
            Block_release(block);
            return result;
        };
        
        return Block_copy(block);
    }
    
    var pFunc = (const char* (^(*)(struct ZCObject *pObj))(void))sZCGetDescriptionVTable[pObj->vtbl_index];
    
    return pFunc(pObj);
}

const char* _Nonnull (^ _Nonnull __attribute__((overloadable)) ZCGetDescription(struct ZCObjectTest* _Nonnull pObj))(void)
{
    __block const char* (^block)(void) = ^const char* (void) {
        var result = pObj->description;
        printf("test value is: %d\n", pObj->value);
        Block_release(block);
        return result;
    };
    
    return Block_copy(block);
}

