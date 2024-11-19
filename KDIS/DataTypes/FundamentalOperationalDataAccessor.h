/*********************************************************************
Copyright 2024 David Ely
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

*********************************************************************/

/********************************************************************
    class:      FundamentalOperationalDataAccessor
    created:    19/11/2024
    author:     David Ely

    purpose:    Access FundamentalOperationalData members
    size:       128 bits / 16 octets
*********************************************************************/

#pragma once

#include "./FundamentalOperationalData.h"

namespace KDIS {
namespace DATA_TYPE {

  class FundamentalOperationalDataWrapper : public FundamentalOperationalData
  {
  public:
    void SetSystemStatus(KUINT8 systemStatus) { m_ui8SystemStatus = systemStatus; }
    void SetAltParam4(KUINT8 altParam4) { m_ui8AltParam4 = altParam4; }
    void SetInfoLayers(KUINT8 infoLayers) { m_ui8InfoLayers = infoLayers; }
    void SetModifier(KUINT8 modifier) { m_ui8Modifier = modifier; }
    void SetParam1(KUINT16 param1) { m_ui16Param1 = param1; }
    void SetParam2(KUINT16 param2) { m_ui16Param2 = param2; }
    void SetParam3(KUINT16 param3) { m_ui16Param3 = param3; }
    void SetParam4(KUINT16 param4) { m_ui16Param4 = param4; }
    void SetParam5(KUINT16 param5) { m_ui16Param5 = param5; }
    void SetParam6(KUINT16 param6) { m_ui16Param6 = param6; }

    KUINT8 GetSystemStatus() const { return m_ui8SystemStatus; }
    KUINT8 GetAltParam4() const { return m_ui8AltParam4; }
    KUINT8 GetInfoLayers() const { return m_ui8InfoLayers; }
    KUINT8 GetModifier() const { return m_ui8Modifier; }
    KUINT16 GetParam1() const { return m_ui16Param1; }
    KUINT16 GetParam2() const { return m_ui16Param2; }
    KUINT16 GetParam3() const { return m_ui16Param3; }
    KUINT16 GetParam4() const { return m_ui16Param4; }
    KUINT16 GetParam5() const { return m_ui16Param5; }
    KUINT16 GetParam6() const { return m_ui16Param6; }
  };


} // END namespace DATA_TYPES
} // END namespace KDIS

