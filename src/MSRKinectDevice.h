//@COPYRIGHT@//
//
// Copyright (c) 2012, Tomoto S. Washio
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//   * Redistributions of source code must retain the above copyright
//     notice, this list of conditions and the following disclaimer.
//   * Redistributions in binary form must reproduce the above copyright
//     notice, this list of conditions and the following disclaimer in the
//     documentation and/or other materials provided with the distribution.
//   * Neither the name of the Tomoto S. Washio nor the names of his
//     contributors may be used to endorse or promote products derived from
//     this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL TOMOTO S. WASHIO BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//@COPYRIGHT@//

#pragma once
#include "base.h"
#include "util.h"
#include "AbstractModuleGenerator.h"
#include "MSRKinectManager.h"

class MSRKinectDevice :
	public AbstractModuleGenerator<xn::ModuleDevice>,
	public virtual xn::ModuleDeviceIdentificationInterface
{
private:
	typedef AbstractModuleGenerator<xn::ModuleDevice> SuperClass;

private:
	std::string m_sensorID; // in Primesense format
	std::string m_connectionID;
	Properties m_props;

public:
	MSRKinectDevice(const XnChar* strCreationInfo)
	{
		m_sensorID = strCreationInfo;

		// Hack: most recently created one wins
		m_pMan->GetRequirement()->RequireSensorID(strCreationInfo);
	}

	virtual ~MSRKinectDevice()
	{
	}

	virtual XnBool IsCapabilitySupported(const XnChar* strCapabilityName)
	{
		return
			SuperClass::IsCapabilitySupported(strCapabilityName) ||
			streq(strCapabilityName, XN_CAPABILITY_DEVICE_IDENTIFICATION);
	}

	virtual ModuleDeviceIdentificationInterface* GetIdentificationInterface()
	{
		return this;
	}

	virtual XnStatus GetDeviceName(XnChar* strBuffer, XnUInt32& nBufferSize)
	{
		const char* value("KinectSDK Bridge");
		return copyToReturnString(strBuffer, nBufferSize, value, strlen(value));
	}

	virtual XnStatus GetVendorSpecificData(XnChar* strBuffer, XnUInt32& nBufferSize)
	{
		return XN_STATUS_OK;
	}

	virtual XnStatus GetSerialNumber(XnChar* strBuffer, XnUInt32& nBufferSize)
	{
		return copyToReturnString(strBuffer, nBufferSize, m_sensorID.c_str(), m_sensorID.length());
	}

};
