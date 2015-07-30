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
// sstRec01LibInt.h   28.07.15  Re.   22.07.15  Re.
//
// Intern Datastructures and Prototypes for system "sstRec01Lib"
//

#ifndef   _SST_REC01_LIB_INT_HEADER
#define   _SST_REC01_LIB_INT_HEADER

// Defines ---------------------------------------------------------------------

// Structures and Classes ------------------------------------------------------

//==============================================================================
class sstRec01InternCls
{
  public:   // Public functions
     sstRec01InternCls(int Size);  // Constructor
    ~sstRec01InternCls();  // Destructor
     int add(void* element);
     void* fetch(int index);
     int count();
  private:  // Private functions
    void inflate(int increase);
    int size;  // Size of each space
    int quantity; // Number of storage spaces
    int next; // Next empty space
    // Dynamically allocated array of bytes:
    unsigned char* storage;
};

#endif

// --------------------------------------------------------------- File End ----
