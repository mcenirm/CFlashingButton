// CFlashingButtonDll.h : main header file for the CFlashingButton DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CFlashingButtonDll
// See CFlashingButtonDll.cpp for the implementation of this class
//

class CFlashingButtonDll : public CWinApp
{
public:
	CFlashingButtonDll();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
