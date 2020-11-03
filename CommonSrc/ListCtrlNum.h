#if !defined(AFX_LISTCTRLNUM_H__A2B034CF_83B9_4C79_B38C_629F0816AC5B__INCLUDED_)
#define AFX_LISTCTRLNUM_H__A2B034CF_83B9_4C79_B38C_629F0816AC5B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ListCtrlNum.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CListCtrlNum window
#include ".\CommonSrc\NumberManager.h"

class CListCtrlNum : public CListCtrl
{
// Construction
public:
	CListCtrlNum();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CListCtrlNum)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CListCtrlNum();

	// Generated message map functions
protected:
	//{{AFX_MSG(CListCtrlNum)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

public:
	void			RemoveAllColumn						();
	BOOL			InitListCtrl_SortOfCount			();
	void			UpdateListCtrl						( MapSortNum* pMap );

};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LISTCTRLNUM_H__A2B034CF_83B9_4C79_B38C_629F0816AC5B__INCLUDED_)
