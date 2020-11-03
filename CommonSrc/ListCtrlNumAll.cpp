// listctrlnumall.cpp : implementation file
//

#include "stdafx.h"
#include "..\LT.h"
#include "listctrlnumall.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CListCtrlNumAll

CListCtrlNumAll::CListCtrlNumAll()
{
}

CListCtrlNumAll::~CListCtrlNumAll()
{
}


BEGIN_MESSAGE_MAP(CListCtrlNumAll, CListCtrl)
	//{{AFX_MSG_MAP(CListCtrlNumAll)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CListCtrlNumAll message handlers
BOOL			CListCtrlNumAll::InitListCtrl						()
{
	CRect rcClient;
	GetClientRect( &rcClient );

	int nCol = 0;
	InsertColumn( nCol++, "No"		, LVCFMT_LEFT, 30 );
	InsertColumn( nCol++, "1st"	, LVCFMT_LEFT, 32 );
	InsertColumn( nCol++, "2st"	, LVCFMT_LEFT, 32 );
	InsertColumn( nCol++, "3st"	, LVCFMT_LEFT, 32 );
	InsertColumn( nCol++, "4st"	, LVCFMT_LEFT, 32 );
	InsertColumn( nCol++, "5st"	, LVCFMT_LEFT, 32 );
	InsertColumn( nCol++, "6st"	, LVCFMT_LEFT, 32 );
	InsertColumn( nCol++, "Sum"	, LVCFMT_LEFT, 40 );

	DWORD dwStyle = GetExtendedStyle();
	SetExtendedStyle( dwStyle | LVS_EX_FULLROWSELECT  | LVS_EX_GRIDLINES );
	
	return TRUE;
}

void			CListCtrlNumAll::UpdateListCtrl						(CArrayNumber* pAry )
{
	CString strValue;
	
	int i=0;
	int nCount = pAry->GetSize();
	int nNo = nCount;
	int nCol;

	DeleteAllItems();

	for( i=0 ; i<nCount ; i++, nNo-- )
	{
		S_LT_NUM_SET stSet = pAry->GetAt( i );
		strValue.Format( "%d", nNo );
		InsertItem( i, strValue, 0 );

		nCol = 1;
		strValue.Format( "%d", stSet.n1 );
		SetItemText( i, nCol++, strValue );
		strValue.Format( "%d", stSet.n2 );
		SetItemText( i, nCol++, strValue );
		strValue.Format( "%d", stSet.n3 );
		SetItemText( i, nCol++, strValue );
		strValue.Format( "%d", stSet.n4 );
		SetItemText( i, nCol++, strValue );
		strValue.Format( "%d", stSet.n5 );
		SetItemText( i, nCol++, strValue );
		strValue.Format( "%d", stSet.n6 );
		SetItemText( i, nCol++, strValue );
		strValue.Format( "%d", stSet.n1 + stSet.n2 + stSet.n3 + stSet.n4 + stSet.n5 + stSet.n6 );
		SetItemText( i, nCol++, strValue );
	}

}

void			CListCtrlNumAll::UpdateListCtrl						( BYTE* pData, int nCount )
{
	CString strValue;
	
	int i=0;
	int nNo = nCount;
	int nCol;
	BYTE* pCurData = pData;

	DeleteAllItems();

	SetRedraw( FALSE );
	SetItemCount( nCount );

	for( i=0 ; i<nCount ; i++, nNo--, pCurData += 6 )
	{
		strValue.Format( "%d", nNo );
		InsertItem( i, strValue, 0 );

		nCol = 1;
		strValue.Format( "%d", pCurData[nCol-1] );
		SetItemText( i, nCol++, strValue );
		strValue.Format( "%d", pCurData[nCol-1] );
		SetItemText( i, nCol++, strValue );
		strValue.Format( "%d", pCurData[nCol-1] );
		SetItemText( i, nCol++, strValue );
		strValue.Format( "%d", pCurData[nCol-1] );
		SetItemText( i, nCol++, strValue );
		strValue.Format( "%d", pCurData[nCol-1] );
		SetItemText( i, nCol++, strValue );
		strValue.Format( "%d", pCurData[nCol-1] );
		SetItemText( i, nCol++, strValue );
		strValue.Format( "%d", pCurData[0] + pCurData[1] + pCurData[2] + pCurData[3] + pCurData[4] + pCurData[5] );
		SetItemText( i, nCol++, strValue );
	}
	SetRedraw();

}