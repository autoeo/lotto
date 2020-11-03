#if !defined(AFX_CMBRECENTTHNUMBER_H__1ED13703_6B8D_4122_B6FE_0E67A6635DE5__INCLUDED_)
#define AFX_CMBRECENTTHNUMBER_H__1ED13703_6B8D_4122_B6FE_0E67A6635DE5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CmbRecentThNumber.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCmbRecentThNumber window

class CCmbRecentThNumber : public CComboBox
{
// Construction
public:
	CCmbRecentThNumber();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCmbRecentThNumber)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCmbRecentThNumber();

	// Generated message map functions
protected:
	//{{AFX_MSG(CCmbRecentThNumber)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

public:
	BOOL InitCmbCtrl(UINT nCount);
	int GetSelectedItemNumber();
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CMBRECENTTHNUMBER_H__1ED13703_6B8D_4122_B6FE_0E67A6635DE5__INCLUDED_)
