/**********************************************************************
 *
 * sst_rec_lib - library for working with data records
 * Hosted on github
 *
 * Copyright (C) 2015 Uli Rehr
 *
 * This is free software; you can redistribute and/or modify it under
 * the terms of the GNU Lesser General Public Licence as published
 * by the Free Software Foundation. 
 * See the COPYING file for more information.
 *
 **********************************************************************/
// sstRec01LibInt.cpp    28.07.15  Re.    27.07.15  Re.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "sstRec01Lib.h"
#include "sstRec01LibInt.h"

//=============================================================================
sstRec01InternCls::sstRec01InternCls(int Size)
{
    size = Size;
    quantity = 0;
    storage = 0;
    next = 0;
}
//=============================================================================
sstRec01InternCls::~sstRec01InternCls()
{
    if(storage) {
      puts("freeing storage");
      free(storage);
    }
}
//=============================================================================
int sstRec01InternCls::add(void* element) {
  if(next >= quantity) // Enough space left?
    inflate(100);
  // Copy element into storage,
  // starting at next empty space:
  memcpy(&(storage[next * size]),
         element, size);
  next++;
  return(next - 1); // Index number
}
//=============================================================================
void* sstRec01InternCls::fetch(int index) {
  if(index >= next || index < 0)
    return 0;  // Not out of bounds?
  // Produce pointer to desired element:
  return &(storage[index * size]);
}
//=============================================================================
int sstRec01InternCls::count() {
  return next; // Number of elements in stash
}
//=============================================================================
void sstRec01InternCls::inflate(int increase) {
  void* v =
    realloc(storage, (quantity+increase)*size);
  assert(v);  // Was it successful?
  storage = (unsigned char*)v;
  quantity += increase;
}
//=============================================================================


