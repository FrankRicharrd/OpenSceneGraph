/**********************************************************************
 *
 *    FILE:            DrawArrays.cpp
 *
 *    DESCRIPTION:    Read/Write osg::DrawArrays in binary format to disk.
 *
 *    CREATED BY:        Auto generated by iveGenerated
 *                    and later modified by Rune Schmidt Jensen.
 *
 *    HISTORY:        Created 18.3.2003
 *
 *    Copyright 2003 VR-C
 **********************************************************************/

#include "Exception.h"
#include "DrawArrays.h"
#include "PrimitiveSet.h"

using namespace ive;

void DrawArrays::write(DataOutputStream* out){
    // Write DrawArrays's identification.
    out->writeInt(IVEDRAWARRAYS);
    // If the osg class is inherited by any other class we should also write this to file.
    osg::PrimitiveSet*  prim = dynamic_cast<osg::PrimitiveSet*>(this);
    if(prim){
        ((ive::PrimitiveSet*)(prim))->write(out);
    }
    else
        out_THROW_EXCEPTION("DrawArrays::write(): Could not cast this osg::DrawArrays to an osg::PrimitiveSet.");


    // Write DrawArrays's properties.
    out->writeInt(getFirst());
    out->writeInt(getCount());
}

void DrawArrays::read(DataInputStream* in){
    // Read DrawArrays's identification.
    int id = in->peekInt();
    if(id == IVEDRAWARRAYS){
        // Code to read DrawArrays's properties.
        id = in->readInt();
        // If the osg class is inherited by any other class we should also read this from file.
        osg::PrimitiveSet*  prim = dynamic_cast<osg::PrimitiveSet*>(this);
        if(prim){
            ((ive::PrimitiveSet*)(prim))->read(in);
        }
        else
            in_THROW_EXCEPTION("DrawArrays::read(): Could not cast this osg::DrawArrays to an osg::PrimitiveSet.");


        // Read DrawArrays properties
        setFirst(in->readInt());
        setCount(in->readInt());
    }
    else{
        in_THROW_EXCEPTION("DrawArrays::read(): Expected DrawArrays identification.");
    }
}
