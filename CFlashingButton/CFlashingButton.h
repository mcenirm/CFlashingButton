// CFlashingButton.h : main header file for the CFlashingButton DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CCFlashingButtonApp
// See CFlashingButton.cpp for the implementation of this class
//

class CCFlashingButtonApp : public CWinApp
{
public:
	CCFlashingButtonApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
