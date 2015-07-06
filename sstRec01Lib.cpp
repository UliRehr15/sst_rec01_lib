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
// sstRec01Lib.cpp    19.06.15  Re.    19.06.15  Re.
//

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include <header/sstRec01Lib.h>

stash::stash(int Size) {
  size = Size;
  quantity = 0;
  storage = 0;
  next = 0;
}

stash::~stash() {
  if(storage) {
    puts("freeing storage");
    free(storage);
  }
}

int stash::add(void* element) {
  if(next >= quantity) // Enough space left?
    inflate(100);
  // Copy element into storage, 
  // starting at next empty space:
  memcpy(&(storage[next * size]), 
         element, size);
  next++;
  return(next - 1); // Index number
}

void* stash::fetch(int index) {
  if(index >= next || index < 0)
    return 0;  // Not out of bounds?
  // Produce pointer to desired element:
  return &(storage[index * size]);
}

int stash::count() {
  return next; // Number of elements in stash
}

void stash::inflate(int increase) {
  void* v = 
    realloc(storage, (quantity+increase)*size);
  assert(v);  // Was it successful?
  storage = (unsigned char*)v;
  quantity += increase;
}
