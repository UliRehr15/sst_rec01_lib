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

#define BUFSIZE 80

int main() {
  stash intStash(sizeof(int));
  for(int j = 0; j < 100; j++)
    intStash.add(&j);

  FILE* file = fopen("sst_rec01_lib_test.cpp", "r");
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

  return 0;
}
