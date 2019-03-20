/*****************************************************************************
*
* Copyright (c) 2000 - 2018, Lawrence Livermore National Security, LLC
* Produced at the Lawrence Livermore National Laboratory
* All rights reserved.
*
* This file is part of VisIt. For details, see http://www.llnl.gov/visit/. The
* full copyright notice is contained in the file COPYRIGHT located at the root
* of the VisIt distribution or at http://www.llnl.gov/visit/copyright.html.
*
* Redistribution  and  use  in  source  and  binary  forms,  with  or  without
* modification, are permitted provided that the following conditions are met:
*
*  - Redistributions of  source code must  retain the above  copyright notice,
*    this list of conditions and the disclaimer below.
*  - Redistributions in binary form must reproduce the above copyright notice,
*    this  list of  conditions  and  the  disclaimer (as noted below)  in  the
*    documentation and/or materials provided with the distribution.
*  - Neither the name of the UC/LLNL nor  the names of its contributors may be
*    used to  endorse or  promote products derived from  this software without
*    specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT  HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR  IMPLIED WARRANTIES, INCLUDING,  BUT NOT  LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND  FITNESS FOR A PARTICULAR  PURPOSE
* ARE  DISCLAIMED.  IN  NO  EVENT  SHALL  THE  REGENTS  OF  THE  UNIVERSITY OF
* CALIFORNIA, THE U.S.  DEPARTMENT  OF  ENERGY OR CONTRIBUTORS BE  LIABLE  FOR
* ANY  DIRECT,  INDIRECT,  INCIDENTAL,  SPECIAL,  EXEMPLARY,  OR CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT  LIMITED TO, PROCUREMENT OF  SUBSTITUTE GOODS OR
* SERVICES; LOSS OF  USE, DATA, OR PROFITS; OR  BUSINESS INTERRUPTION) HOWEVER
* CAUSED  AND  ON  ANY  THEORY  OF  LIABILITY,  WHETHER  IN  CONTRACT,  STRICT
* LIABILITY, OR TORT  (INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING IN ANY  WAY
* OUT OF THE  USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
* DAMAGE.
*
*****************************************************************************/


// ************************************************************************* //
//                            avtparaDISFileFormat.h                           //
// ************************************************************************* //

#ifndef AVT_paraDIS_FILE_FORMAT_H
#define AVT_paraDIS_FILE_FORMAT_H

#include "paraDIS_lib/paradis_c_interface.h"
#include "parallelParaDIS.h"
#include "Dumpfile.h"
#include <avtSTSDFileFormat.h>
#include "avtparaDISOptions.h"
#include <vtkUnstructuredGrid.h>
#include <vtkFloatArray.h>
#include "RC_cpp_lib/Point.h"
#include <vector>
// ****************************************************************************
//  Class: avtparaDISFileFormat
//
//  Purpose:
//      Reads in paraDIS files as a plugin to VisIt.
//
//  Programmer: rcook -- generated by xml2avt
//  Creation:   Tue Jan 30 14:56:34 PST 2007
//
// ****************************************************************************

#define PARADIS_NO_FORMAT 0  // uninitialized
#define PARADIS_DUMPFILE_FORMAT 1  // Old serial data format
#define PARADIS_PARALLEL_FORMAT 2  // new parallel data format


class avtparaDISFileFormat : public avtSTSDFileFormat
{
  public:
                       avtparaDISFileFormat(const char *filename,
                                            DBOptionsAttributes *rdatts);
    virtual           ~avtparaDISFileFormat() {;};


 
    //
    // This is used to return unconvention data -- ranging from material
    // information to information about block connectivity.
    //
    // virtual void      *GetAuxiliaryData(const char *var, const char *type,
    //                                  void *args, DestructorFunction &);
    //

    //
    // These are used to declare what the current time and cycle are for the
    // file.  These should only be defined if the file format knows what the
    // time and/or cycle is.
    //
    // virtual int       GetCycle(void);
    // virtual double    GetTime(void);
    //
    
    virtual const char    *GetType(void)   { return "paraDIS"; };
    virtual void           FreeUpResources(void); 
    
    void Clear(void); 
    
    // These would tell the parent class to call PopulateDatabaseMetadata() for each timestep.  I decided against it. 
    //  virtual bool HasInvariantMetaData(void) const { return false; };
    //  virtual bool HasInvariantSIL(void)      const { return false; };

    virtual void           PopulateDatabaseMetaData(avtDatabaseMetaData *);
    bool PopulateMetaDataSerialFormat(avtDatabaseMetaData *md); 
    bool PopulateMetaDataParallelFormat(avtDatabaseMetaData *md); 

    virtual vtkDataSet    *GetMesh(const char *meshname);
    vtkDataSet    *GetMeshSerialFormat(const char *meshname);
    vtkDataSet    *GetMeshParallelFormat(const char *meshname);

    virtual vtkDataArray  *GetVar(const char *);
    virtual vtkDataArray  *GetVectorVar(const char *);
    virtual void          *GetAuxiliaryData(const char *var, const char *type, 
                                            void *args, DestructorFunction &);

  protected:
    // DATA MEMBERS
    std::string mFilename; 
    int mFormat; 
    int mVerbosity; 
    

    /*!
      paraDIS data PARALLEL
    */
    ParallelData mParallelData; 
    Dumpfile mDumpfile; 

};


#endif
