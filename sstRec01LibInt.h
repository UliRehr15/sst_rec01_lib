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

/**
 * @defgroup sstRecord01InternLib sstRecord01InternLib: Intern cpp sst record library
 *
 * Intern cpp sst record library <BR>
 *
 */


// Defines ---------------------------------------------------------------------

// Structures and Classes ------------------------------------------------------

//==============================================================================
/**
* @brief Definition Class sstRec01InternCls
*
* Intern class for sstRecordLib <BR>
*
* Changed: 04.08.15  Re.
*
* @ingroup sstRecord01InternLib
*
* @author Re.
*
* @date 09.07.15
*/
// ----------------------------------------------------------------------------
class sstRec01InternCls
{
  public:   // Public functions
    //==============================================================================
    /**
    * @brief constructor with size of one record
    *
    * @param Size [in] Size of one record
    */
    // ----------------------------------------------------------------------------
     sstRec01InternCls(int Size);  // Constructor
    ~sstRec01InternCls();  // Destructor
     //==============================================================================
     /**
     * @brief Add record to sstRec memory
     *
     * @param element [in] Record to store
     *
     * @return Stored record number
     */
     // ----------------------------------------------------------------------------
     int add(void* element);
     //==============================================================================
     /**
     * @brief Get record from sstRec memory with index
     *
     * @param index [in] record number to read
     *
     * @return pointer to readed record
     */
     // ----------------------------------------------------------------------------
     void* fetch(int index);
     //==============================================================================
     /**
     * @brief return number of stored elements in sstRec memory
     *
     * @return number of records, which are stored
     */
     // ----------------------------------------------------------------------------
     int count();
  private:  // Private functions
     //==============================================================================
     /**
     * @brief Shortstory
     *
     * @param iKey [in] For the moment 0
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
    void inflate(int increase);
    int size;                 /**< Size of each record */
    int quantity;             /**< Number of storage spaces */
    int next;                 /**< Number of stored records */
    unsigned char* storage;   /**< Dynamically allocated array of bytes */
};

#endif

// --------------------------------------------------------------- File End ----
