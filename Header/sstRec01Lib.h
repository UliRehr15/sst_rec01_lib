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
// sstRec01Lib.h   19.06.15  Re.   19.06.15  Re.
//
// Datastructures and Prototypes for system "sstRec01Lib"
//

#ifndef   _SST_REC01_LIB_HEADER
#define   _SST_REC01_LIB_HEADER

// forward declaration ---------------------------------------------------------

class sstRec01InternCls;

//------------------------------------------------------------------------------


class stash {
public:
  stash(int Size);
  ~stash();
  int add(void* element);
  void* fetch(int index);
  int count();
  sstRec01InternCls *poRec01Intern;   /**< Pointer to intern object */

};

#endif // SST_REC01_LIB
