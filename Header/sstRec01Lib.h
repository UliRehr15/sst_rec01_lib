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

/**
 * @defgroup sstRecord01Lib sstRecord01Lib: cpp sst record library
 *
 * cpp sst record library <BR>
 *
 */


// forward declaration ---------------------------------------------------------

class sstRec01InternCls;

//------------------------------------------------------------------------------


//==============================================================================
/**
* @brief Definition stash
*
* record storage <BR>
*
* Changed: 04.08.15  Re.
*
* @ingroup sstRecord01Lib
*
* @author Re.
*
* @date 09.07.15
*/
// ----------------------------------------------------------------------------
class stash {
public:
    //==============================================================================
    /**
    * @brief stash constructor with size of one record
    *
    * @param Size [in] Size of one record
    */
    // ----------------------------------------------------------------------------
  stash(int Size);
  ~stash();
  //==============================================================================
  /**
  * @brief Add Record to stash memory
  *
  * @param element [in] record to store
  *
  * @return stored record number
  */
  // ----------------------------------------------------------------------------
  int add(void* element);
  //==============================================================================
  /**
  * @brief get Record from stash memory with index
  *
  * @param index [in] record number to read
  *
  * @return Pointer to readed record
  */
  // ----------------------------------------------------------------------------
  void* fetch(int index);
  //==============================================================================
  /**
  * @brief Get number of stored records
  *
  * @return number of elements in stash memory
  */
  // ----------------------------------------------------------------------------
  int count();
  //==============================================================================
  /**
  * @brief Write new record into sstRec memory
  *
  * @param iKey    [in]  For the moment 0
  * @param element [in]  Record to store
  * @param index   [out] New Record number
  *
  * @return Errorstate
  *
  * @retval   = 0: OK
  * @retval   < 0: Unspecified Error
  */
  // ----------------------------------------------------------------------------
  int WritNew(int iKey, void* element, int *index);
  //==============================================================================
  /**
  * @brief Read record from sstRec memory with Record number
  *
  * @param iKey  [in]  For the moment 0
  * @param index [in]  record number to read
  * @param vAdr  [out] read Record
  *
  * @return Errorstate
  *
  * @retval   = 0: OK
  * @retval   < 0: Unspecified Error
  */
  // ----------------------------------------------------------------------------
  int Read(int iKey, int index, void *vAdr);
  //==============================================================================
private:
  sstRec01InternCls *poRec01Intern;   /**< Pointer to intern object */

};

#endif // SST_REC01_LIB
