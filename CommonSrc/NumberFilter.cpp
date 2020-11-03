// NumberFilter.cpp: implementation of the CNumberFilter class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "LT.h"
#include "NumberFilter.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CNumberFilter::CNumberFilter()
{

}

CNumberFilter::~CNumberFilter()
{
	m_mapExist.clear();
}

void	CNumberFilter::SetOption			(	DWORD dwOption )
{
	m_dwOption = dwOption;

}

void	CNumberFilter::SetExceptNumbers			( const CByteArray& ary )
{
	m_mapExceptNumbers.clear();
	int i, nCount ;

	BYTE byteNew;
	nCount = ary.GetSize();
	for( i=0 ; i<nCount ; i++ )
	{
		byteNew = ary.GetAt(i);
		m_mapExceptNumbers.insert( PairBytes( byteNew, byteNew ) );
	}
	
}

void	CNumberFilter::SetAcceptNumbers			( const CByteArray& ary )
{
	m_mapAcceptNumbers.clear();
	int i, nCount ;

	BYTE byteNew;
	nCount = ary.GetSize();
	for( i=0 ; i<nCount ; i++ )
	{
		byteNew = ary.GetAt(i);
		m_mapAcceptNumbers.insert( PairBytes( byteNew, byteNew ) );
	}
}


void	CNumberFilter::SetHistoryNumbers	(   CArrayNumber* pAry )
{
	int nCount = pAry->GetSize();
	int i;
	BYTE btNumber[7] = { NULL, };
	__int64 i64Number ; 

	m_mapExist.clear();

	for( i=0 ; i<nCount ; i++ )
	{
		S_LT_NUM_SET stNumSet = pAry->GetAt( i );
		btNumber[0] = stNumSet.n1;
		btNumber[1] = stNumSet.n2;
		btNumber[2] = stNumSet.n3;
		btNumber[3] = stNumSet.n4;
		btNumber[4] = stNumSet.n5;
		btNumber[5] = stNumSet.n6;
		i64Number = GetNumber( btNumber );
		m_mapExist.insert( PairHistory( i64Number, i64Number ));
	}
		
}
