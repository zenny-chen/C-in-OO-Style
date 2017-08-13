//
//  ZCObject.h
//  CObjective
//
//  Created by Zenny Chen on 2017/8/13.
//  Copyright © 2017年 CodeLearning Studio. All rights reserved.
//

#ifndef ZCObject_h
#define ZCObject_h

#include <stdbool.h>
#include <stdint.h>

#ifndef var
#define var     __auto_type
#endif

/// The base object
struct ZCObject
{
    /// For polymorphism
    int vtbl_index;
    const char* _Nonnull description;
    int tag;
};

/// The object type for test
struct ZCObjectTest
{
    /// For polymorphism
    int vtbl_index;
    const char* _Nonnull description;
    int tag;
    
    /// ZCObjectTest specific member
    int value;
};

/// Initialize a ZCObject object
/// @param pObj a pointer to a ZCObject object
extern void ZCInitializeObject(struct ZCObject* _Nonnull pObj);

/// Get description about a ZCObject object.
///
/// This is a method of a ZCObject object.
/// @param pObj a pointer to a ZCObject object
/// @return a block reference to the ZCGetDescription implementation
extern const char* _Nonnull (^ _Nonnull __attribute__((overloadable)) ZCGetDescription(struct ZCObject* _Nonnull pObj))(void);

/// Initialize a ZCObjectTest object
/// @param pObj a pointer to a ZCObject object
extern void ZCInitializeTest(struct ZCObjectTest* _Nonnull pObj);

/// Get description about a ZCObjectTest object.
///
/// This is a method of a ZCObjectTest object.
/// @param pObj a pointer to a ZCObject object
/// @return a block reference to the ZCGetDescription implementation
extern const char* _Nonnull (^ _Nonnull __attribute__((overloadable)) ZCGetDescription(struct ZCObjectTest* _Nonnull pObj))(void);


#endif /* ZCObject_h */


