/*=========================================================================

   Program: ParaView
   Module:    vtkSTMDAvtFileFormatAlgorithm.cxx

   Copyright (c) 2005,2006 Sandia Corporation, Kitware Inc.
   All rights reserved.

   ParaView is a free software; you can redistribute it and/or modify it
   under the terms of the ParaView license version 1.2.

   See License_v1.2.txt for the full ParaView license.
   A copy of this license can be obtained by contacting
   Kitware Inc.
   28 Corporate Drive
   Clifton Park, NY 12065
   USA

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHORS OR
CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

========================================================================*/
#include "vtkSTMDAvtFileFormatAlgorithm.h"
#include "vtkInformation.h"
#include "vtkInformationVector.h"
#include "vtkObjectFactory.h"
#include "vtkMultiBlockDataSetAlgorithm.h"

#include "avtSTMDFileFormat.h"
#include "avtDatabaseMetaData.h"

vtkStandardNewMacro(vtkSTMDAvtFileFormatAlgorithm);

//-----------------------------------------------------------------------------
vtkSTMDAvtFileFormatAlgorithm::vtkSTMDAvtFileFormatAlgorithm()
{
  this->FileName = 0;
  this->SetNumberOfInputPorts(0);
  this->SetNumberOfOutputPorts(1);

  this->AvtFile = NULL;
  this->MetaData = NULL;
}

//-----------------------------------------------------------------------------
vtkSTMDAvtFileFormatAlgorithm::~vtkSTMDAvtFileFormatAlgorithm()
{
  this->SetFileName(0);
  if ( this->AvtFile )
    {
    delete this->AvtFile;
    }

  if ( this->MetaData )
    {
    delete this->MetaData;
    }
}
//-----------------------------------------------------------------------------
int vtkSTMDAvtFileFormatAlgorithm::CanReadFile(const char *fname)
{
  return 1;
}

//-----------------------------------------------------------------------------
int vtkSTMDAvtFileFormatAlgorithm::RequestInformation(vtkInformation *request, vtkInformationVector **inputVector, vtkInformationVector *outputVector)
{
  return 1;
}


//-----------------------------------------------------------------------------
int vtkSTMDAvtFileFormatAlgorithm::RequestData(vtkInformation *request, vtkInformationVector **inputVector, vtkInformationVector *outputVector)
{
  return 1;
}

//-----------------------------------------------------------------------------
void vtkSTMDAvtFileFormatAlgorithm::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os, indent);
}


