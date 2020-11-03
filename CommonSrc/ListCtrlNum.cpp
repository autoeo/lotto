// ListCtrlNum.cpp : implementation file
//

#include "stdafx.h"
#include "LT.h"
#include "ListCtrlNum.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CListCtrlNum

CListCtrlNum::CListCtrlNum()
{
}

CListCtrlNum::~CListCtrlNum()
{
}


BEGIN_MESSAGE_MAP(CListCtrlNum, CListCtrl)
	//{{AFX_MSG_MAP(CListCtrlNum)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CListCtrlNum message handlers

void			CListCtrlNum::RemoveAllColumn				()
{
	LVCOLUMN lvCol;
	memset( &lvCol, 0x00, sizeof(lvCol));
	char szName[128] = { NULL };

	lvCol.mask			= LVCF_TEXT ;
	lvCol.pszText		= szName;
	lvCol.cchTextMax	= 128;
	while( 1 )
	{
		if( GetColumn( 0, &lvCol ) == FALSE )
			break;
		DeleteColumn( 0 );

	}
}

BOOL			CListCtrlNum::InitListCtrl_SortOfCount		()
{
	CRect rcClient;
	GetClientRect( &rcClient );
	int nCol = 0;
	InsertColumn( nCol++, "순위"		, LVCFMT_LEFT, 40 );
	InsertColumn( nCol++, "횟수"		, LVCFMT_LEFT, 40 );
	InsertColumn( nCol++, "출현 번호"	, LVCFMT_LEFT, 80 );

	DWORD dwStyle = GetExtendedStyle();
	SetExtendedStyle( dwStyle | LVS_EX_FULLROWSELECT  | LVS_EX_GRIDLINES );
	
	return TRUE;
}

void			CListCtrlNum::UpdateListCtrl						(MapSortNum* pMap )
{
	CString strValue;
	MapSortNum::iterator it;
	int nNo = pMap->size();

	DeleteAllItems();

	for( it=pMap->begin() ; it!=pMap->end() ; it++, nNo-- )
	{
		strValue.Format( "%d", nNo );
		InsertItem( 0, strValue, 0 );
		strValue.Format( "%d", it->first );
		SetItemText( 0, 1, strValue );
		strValue.Format( "%d", it->second );
		SetItemText( 0, 2, strValue );
	}

}