// CmbRecentThNumber.cpp : implementation file
//

#include "stdafx.h"
#include "LT.h"
#include "CmbRecentThNumber.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCmbRecentThNumber

CCmbRecentThNumber::CCmbRecentThNumber()
{
}

CCmbRecentThNumber::~CCmbRecentThNumber()
{
}


BEGIN_MESSAGE_MAP(CCmbRecentThNumber, CComboBox)
	//{{AFX_MSG_MAP(CCmbRecentThNumber)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCmbRecentThNumber message handlers

BOOL CCmbRecentThNumber::InitCmbCtrl(UINT nCount)
{
	ResetContent();
	CString strValue = _T("");
	int nIndex = -1;
	for( UINT i=1 ; i<=nCount ; i++ )
	{
		strValue.Format("%3d", i );
		nIndex = AddString( strValue );
		SetItemData( nIndex, i );
	}
	SetCurSel(nIndex);

	return TRUE;
}

int CCmbRecentThNumber::GetSelectedItemNumber()
{
	int nIndex = GetCurSel();
	if( nIndex == -1 )
		return -1;

	int nCount = GetItemData( nIndex );
	return nCount;
}