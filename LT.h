// LT.h : main header file for the LT application
//

#if !defined(AFX_LT_H__2ECF2C13_F2FD_4146_B960_DDB81CCDD926__INCLUDED_)
#define AFX_LT_H__2ECF2C13_F2FD_4146_B960_DDB81CCDD926__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CLTApp:
// See LT.cpp for the implementation of this class
//

class CLTApp : public CWinApp
{
public:
	CLTApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLTApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CLTApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LT_H__2ECF2C13_F2FD_4146_B960_DDB81CCDD926__INCLUDED_)
