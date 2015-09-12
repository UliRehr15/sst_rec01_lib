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
// sst_rec01_lib_test.cpp    19.06.15  Re.    19.06.15  Re.
//
// test frame for sstRec01Lib

#include <stdio.h>
#include <assert.h>

#include <sstRec01Lib.h>

#define BUFSIZE 100

int main() {
//=============================================================================
    {
    stash intStash(sizeof(int));
    for(int j = 0; j < 100; j++)
      intStash.add(&j);

    FILE* file = fopen("sstRec01LibTest.cpp", "r");
    assert(file);
    // Holds 80-character strings:
    stash stringStash(sizeof(char) * BUFSIZE);
    char buf[BUFSIZE];
    while(fgets(buf, BUFSIZE, file))
      stringStash.add(buf);
    fclose(file);

    for(int k = 0; k < intStash.count(); k++)
      printf("intStash.fetch(%d) = %d\n", k,
             *(int*)intStash.fetch(k));

    for(int i = 0; i < stringStash.count(); i++)
      printf("stringStash.fetch(%d) = %s",
             i, (char*)stringStash.fetch(i++));
    putchar('\n');
    }
//=============================================================================
    {
    stash intStash(sizeof(int));
    dREC01RECNUMTYP index = 0;
    for(int j = 0; j < 100; j++)
      // intStash.add(&j);
      intStash.WritNew(0,&j,&index);

    FILE* file = fopen("sstRec01LibTest.cpp", "r");
    assert(file);
    // Holds 80-character strings:
    stash stringStash(sizeof(char) * BUFSIZE);
    index = 0;
    char buf[BUFSIZE];
    while(fgets(buf, BUFSIZE, file))
        //stringStash.add(buf);
        stringStash.WritNew(0,buf,&index);
    fclose(file);

    for(int k = 0; k < intStash.count(); k++)
    { int iVal=0;
      intStash.Read(0,k,&iVal);
//      printf("intStash.fetch(%d) = %d\n", k,
//             *(int*)intStash.fetch(k));
      printf("intStash.fetch(%d) = %d\n", k, iVal);
    }

    for(int i = 0; i < stringStash.count(); i++)
    {
        stringStash.Read(0,i++,buf);
//        printf("stringStash.fetch(%d) = %s",
//               i, (char*)stringStash.fetch(i++));
        printf("stringStash.fetch(%d) = %s", i, buf);
    }
    putchar('\n');
    }

//=============================================================================
    // Test with storing in file
    {
      stash intStash(sizeof(int));

      int iStat = intStash.NewFile( 0, (char*)"TestInt");
      assert (iStat >= 0);

      dREC01RECNUMTYP index = 0;
      for(int j = 0; j < 100; j++)
        intStash.WritNew(0,&j,&index);
      iStat = intStash.SetStoreFile(0);
    }

    {
      stash intStash(sizeof(int));
      int iStat = intStash.OpenFile(0,(char*)"TestInt");
      assert (iStat >= 0);

      for(int k = 0; k < intStash.count(); k++)
      { int iVal=0;
        intStash.Read(0,k,&iVal);
        printf("intStash.fetch(%d) = %d\n", k, iVal);
      }

    putchar('\n');
    }

    //=============================================================================
  return 0;
}
