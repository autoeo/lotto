#if !defined(AFX_LISTCTRLNUMALL_H__4D92546F_6346_4092_AE4D_6663FBB0AAE8__INCLUDED_)
#define AFX_LISTCTRLNUMALL_H__4D92546F_6346_4092_AE4D_6663FBB0AAE8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// listctrlnumall.h : header file
//
#include ".\CommonSrc\NumberManager.h"

/////////////////////////////////////////////////////////////////////////////
// CListCtrlNumAll window

class CListCtrlNumAll : public CListCtrl
{
// Construction
public:
	CListCtrlNumAll();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CListCtrlNumAll)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CListCtrlNumAll();

	// Generated message map functions
protected:
	//{{AFX_MSG(CListCtrlNumAll)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

public:
	BOOL			InitListCtrl						();
	void			UpdateListCtrl						( CArrayNumber* pAry );
	void			UpdateListCtrl						( BYTE* pData, int nCount );

};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LISTCTRLNUMALL_H__4D92546F_6346_4092_AE4D_6663FBB0AAE8__INCLUDED_)
