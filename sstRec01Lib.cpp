/**********************************************************************
 *
 * sst_rec_lib - library for working with data records
 * Hosted on github
 *
 * Copyright (C) 2015 Hans Ulrich Rehr
 *
 * This is free software; you can redistribute and/or modify it under
 * the terms of the GNU Lesser General Public Licence as published
 * by the Free Software Foundation.
 * See the COPYING file for more information.
 *
 **********************************************************************/
// sstRec01Lib.cpp    28.07.15  Re.    19.06.15  Re.
//

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "sstRec01Lib.h"
#include "sstRec01LibInt.h"

//==============================================================================
stash::stash(int Size) {
  poRec01Intern = new sstRec01InternCls(Size);
}
//==============================================================================
stash::~stash() {
    delete(poRec01Intern);
}
//==============================================================================
int stash::add(void* element) {

    return(poRec01Intern->add(element) - 1); // Index number
}
//==============================================================================
void* stash::fetch(int index) {
    return poRec01Intern->fetch(index);
}
//==============================================================================
int stash::count() {
    return poRec01Intern->count();
}
//==============================================================================
