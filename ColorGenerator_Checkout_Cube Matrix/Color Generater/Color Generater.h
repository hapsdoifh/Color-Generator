
// Color Generater.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CColorGeneraterApp:
// See Color Generater.cpp for the implementation of this class
//

class CColorGeneraterApp : public CWinApp
{
public:
	CColorGeneraterApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CColorGeneraterApp theApp;
