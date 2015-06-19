/**********************************************************************
 *
 * sst_rec_lib - library for working with data records
 * Hosted on github
 *
 * Copyright (C) 2014 Hans Ulrich Rehr
 *
 * This is free software; you can redistribute and/or modify it under
 * the terms of the GNU Lesser General Public Licence as published
 * by the Free Software Foundation.
 * See the COPYING file for more information.
 *
 **********************************************************************/
// sst_rec01_lib.h   19.06.15  Re.   19.06.15  Re.
//
// Datastructures and Prototypes for system "sstRec01Lib"
//

#ifndef   _SST_REC01_LIB_HEADER
#define   _SST_REC01_LIB_HEADER

class stash {
  int size;  // Size of each space
  int quantity; // Number of storage spaces
  int next; // Next empty space
  // Dynamically allocated array of bytes:
  unsigned char* storage;
  void inflate(int increase);
public:
  stash(int Size);
  ~stash();
  int add(void* element);
  void* fetch(int index);
  int count();
};
#endif // SST_REC01_LIB
