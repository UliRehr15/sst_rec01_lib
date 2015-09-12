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
stash::stash(dREC01RECSIZTYP Size) {
  poRec01Intern = new sstRec01InternCls(Size);
}
//==============================================================================
stash::~stash() {
    delete(poRec01Intern);
}
//==============================================================================
dREC01RECNUMTYP stash::add(void* element) {

    // return(poRec01Intern->WritNew( 0, element) - 1); // Index number
    dREC01RECNUMTYP index=0;
    poRec01Intern->WritNew(0,element,&index);
    return index;
}
//==============================================================================
int stash::WritNew(int iKey, void* element, dREC01RECNUMTYP *index) {

    // return(poRec01Intern->WritNew(iKey, element) - 1); // Index number
    return poRec01Intern->WritNew( iKey, element, index);
}
//==============================================================================
void* stash::fetch(dREC01RECNUMTYP index)
{ return (poRec01Intern->fetch(index));
}
//==============================================================================
int stash::Read(int iKey, dREC01RECNUMTYP index, void *vAdr) {
    int iStat = poRec01Intern->Read(iKey, index, vAdr);
    return iStat;
}
//==============================================================================
int stash::count() {
    return poRec01Intern->count();
}
//==============================================================================
int stash::OpenFile(int   iKey,
                    char *cSysNam)
{
  if ( iKey != 0) return -1;

  int iStat = 0;
  iStat = this->poRec01Intern->OpenFile(iKey,cSysNam);
  return iStat;
}
//==============================================================================
int stash::NewFile(int   iKey,
                   char *cSysNam)
{
  if ( iKey != 0) return -1;

  int iStat = 0;
  iStat = this->poRec01Intern->NewFile(iKey,cSysNam);
  return iStat;
}
//==============================================================================
int stash::SetStoreFile(int iKey)
{
  if ( iKey != 0) return -1;
  int iStat = this->poRec01Intern->SetStoreFile(iKey);
  return iStat;
}
//==============================================================================
