/*********************************************************************
Copyright 2013 Karl Jones
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

For Further Information Please Contact me at
Karljj1@yahoo.com
http://p.sf.net/kdis/UserGuide
*********************************************************************/

/********************************************************************
    KDefines
    created:    17/09/2008
    author:     Karl Jones

    purpose:    Defines some of the core data types that KDIS uses.
*********************************************************************/

#ifndef KDIS_KDEFINES_HPP_
#define KDIS_KDEFINES_HPP_

#include <cstdint>
#include <cstring>
#include <exception>
#include <sstream>
#include <string>

#include "KDIS/KExport.hpp"
#include "KDIS/KSymbolicNames.hpp"

#define MAX_PDU_SIZE MAX_PDU_SIZE_OCTETS

// Comment out the following line to enable Enum descriptors or declare
// KDIS_USE_ENUM_DESCRIPTORS in your project pre-processor definitions (-D
// KDIS_USE_ENUM_DESCRIPTORS).
// #define KDIS_USE_ENUM_DESCRIPTORS

#if defined(WIN32) || defined(_WIN32) || defined(WIN64) || defined(_WIN64)
  // Disable this warning, it simply warns us about any functions that have a
  // throw qualifier.
  #pragma warning(disable : 4290)

  // Warning about conversion from size_t
  #pragma warning(disable : 4267)

  // Safe to ignore this error as we are only exporting STL objects
  #pragma warning(disable : 4251)
#endif

// DIS version
#ifndef DIS_VERSION
  #error DIS_VERSION must be defined. Possible values are 5 (IEEE 1278.1-1995), 6 (IEEE 1278.1A-1998), or 7 (IEEE 1278.1x-2012)
#endif

/************************************************************************/
/* Type Definitions                                                     */
/************************************************************************/

namespace KDIS {

typedef unsigned char KUINT8;
typedef char KINT8;
typedef uint16_t KUINT16;
typedef int16_t KINT16;
typedef uint32_t KUINT32;
typedef int32_t KINT32;
typedef uint64_t KUINT64;
typedef int64_t KINT64;

typedef char KOCTET;
typedef unsigned char KUOCTET;
typedef char KCHAR8;
typedef unsigned char KUCHAR8;

typedef float KFLOAT32;
typedef double KFLOAT64;

typedef std::string KString;
typedef std::stringstream KStringStream;

typedef bool KBOOL;

/************************************************************************/
/* Error Code Definitions                                               */
/************************************************************************/

enum ErrorCodes {
  NO_ERRORS = 0,
  BUFFER_TOO_SMALL = 1,
  NOT_ENOUGH_DATA_IN_BUFFER = 2,
  STRING_PDU_SIZE_TOO_BIG = 3,
  DATA_TYPE_TOO_LARGE = 4,
  WRONG_PDU_TYPE_IN_HEADER = 5,
  FILE_NOT_OPEN = 6,
  OUT_OF_BOUNDS = 7,
  INVALID_DATA = 8,
  UNSUPPORTED_DATATYPE = 9,
  INVALID_OPERATION = 10,
  PDU_TOO_LARGE = 11,
  CONNECTION_SOCKET_ERROR = 12
};

/************************************************************************/
/* Error Code As String                                                 */
/************************************************************************/

static KString GetErrorText(KUINT16 ErrorCode) {
  switch (ErrorCode) {
    case NO_ERRORS:
      return "No Errors";
    case BUFFER_TOO_SMALL:
      return "Buffer Is Too Small";
    case NOT_ENOUGH_DATA_IN_BUFFER:
      return "Buffer Does Not Contain Enough Information To Decode";
    case STRING_PDU_SIZE_TOO_BIG:
      return "String Size Too Big";
    case DATA_TYPE_TOO_LARGE:
      return "Data Type Is Too Large";
    case WRONG_PDU_TYPE_IN_HEADER:
      return "Incorrect PDU Type Specified In Header";
    case FILE_NOT_OPEN:
      return "Could Not Open File For Reading/Writing";
    case OUT_OF_BOUNDS:
      return "Parameter Is Out Of Bounds/Range Of Acceptable Values";
    case INVALID_DATA:
      return "Invalid Data";
    case UNSUPPORTED_DATATYPE:
      return "Unsupported Data Type, Can Not Decode";
    case INVALID_OPERATION:
      return "Invalid Operation";
    case PDU_TOO_LARGE:
      return "PDU Is Too Large. PDU Must Not Exceed 8192 Bytes";
    case CONNECTION_SOCKET_ERROR:
      return "Socket error";
    default:
      return "Unknown KDIS Error";
  }
}

/************************************************************************/
/* Exception                                                            */
/************************************************************************/

class KException : public std::exception {
 public:
  KUINT16 m_ui16ErrorCode;
  KString m_sErrorText;

  explicit KException(KUINT16 EC)
      : m_ui16ErrorCode(EC), m_sErrorText(GetErrorText(EC)) {}

  KException(KString Text, KUINT16 EC)
      : m_ui16ErrorCode(EC), m_sErrorText(Text + ": " + GetErrorText(EC)) {}

  template <class T>
  KException(KString Text, KUINT16 EC, T AdditonalInfo) : m_ui16ErrorCode(EC) {
    KStringStream ss;
    ss << Text << ": " << GetErrorText(EC) << m_sErrorText << AdditonalInfo;
    m_sErrorText = ss.str();
  }

  virtual ~KException() throw() {}

  virtual const KCHAR8* what() const throw() { return m_sErrorText.c_str(); }
};

/************************************************************************/
/* Endian                                                               */
/************************************************************************/

enum Endian { Little_Endian = 0, Big_Endian = 1 };

}  // namespace KDIS

#endif  // KDIS_KDEFINES_HPP_
