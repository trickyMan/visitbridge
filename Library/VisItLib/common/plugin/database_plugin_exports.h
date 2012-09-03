/*****************************************************************************
*
* Copyright (c) 2000 - 2010, Lawrence Livermore National Security, LLC
* Produced at the Lawrence Livermore National Laboratory
* LLNL-CODE-400124
* All rights reserved.
*
* This file is  part of VisIt. For  details, see https://visit.llnl.gov/.  The
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
*    documentation and/or other materials provided with the distribution.
*  - Neither the name of  the LLNS/LLNL nor the names of  its contributors may
*    be used to endorse or promote products derived from this software without
*    specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT  HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR  IMPLIED WARRANTIES, INCLUDING,  BUT NOT  LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND  FITNESS FOR A PARTICULAR  PURPOSE
* ARE  DISCLAIMED. IN  NO EVENT  SHALL LAWRENCE  LIVERMORE NATIONAL  SECURITY,
* LLC, THE  U.S.  DEPARTMENT OF  ENERGY  OR  CONTRIBUTORS BE  LIABLE  FOR  ANY
* DIRECT,  INDIRECT,   INCIDENTAL,   SPECIAL,   EXEMPLARY,  OR   CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT  LIMITED TO, PROCUREMENT OF  SUBSTITUTE GOODS OR
* SERVICES; LOSS OF  USE, DATA, OR PROFITS; OR  BUSINESS INTERRUPTION) HOWEVER
* CAUSED  AND  ON  ANY  THEORY  OF  LIABILITY,  WHETHER  IN  CONTRACT,  STRICT
* LIABILITY, OR TORT  (INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING IN ANY  WAY
* OUT OF THE  USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
* DAMAGE.
*
*****************************************************************************/

#ifndef DATABASE_PLUGIN_EXPORTS_H
#define DATABASE_PLUGIN_EXPORTS_H

#if defined(_WIN32) && defined(VISIT_BUILD_SHARED_LIBS)
# define DBP_EXPORT __declspec(dllexport)
#else
# if __GNUC__ >= 4
#   define DBP_EXPORT __attribute__((visibility("default")))
# else
#   define DBP_EXPORT /* nothing */
# endif
#endif

#if defined(_WIN32) && defined(_MSC_VER)
// Disable inheritance by dominance warning message.
# pragma warning(disable:4250)
// Disable DLL interface warning.
# pragma warning(disable:4251)
#endif

//
// This file makes sure that the entry point to each plugin is exported
// in the DLL. It must be exported to be visible to GetProcAddress.
//
extern "C" DBP_EXPORT const char *VisItPluginVersion;
#ifdef GENERAL_PLUGIN_EXPORTS
extern "C" DBP_EXPORT GeneralDatabasePluginInfo* GetGeneralInfo();
#endif
#ifdef MDSERVER_PLUGIN_EXPORTS
extern "C" DBP_EXPORT MDServerDatabasePluginInfo* GetMDServerInfo();
#endif
#ifdef ENGINE_PLUGIN_EXPORTS
extern "C" DBP_EXPORT EngineDatabasePluginInfo* GetEngineInfo();
#endif

#endif
