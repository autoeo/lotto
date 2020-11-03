// NumberManager.cpp: implementation of the CNumberManager class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "LT.h"
#include "NumberManager.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CNumberManager::CNumberManager()
{

}

CNumberManager::~CNumberManager()
{
	Release();
}

BOOL				CNumberManager::Load						( const CString& strFileName )
{
	CXLEzAutomation*	pExcel = new CXLEzAutomation( FALSE );

	CString strValue;
	S_LT_NUM_SET stItem;
	int nRow = 4;
	int nCol = 0;

	CString strPathName = strFileName;


	if( pExcel->OpenExcelFile( strPathName ) == FALSE ) 
	{
		DWORD dwError = GetLastError();
		goto e;
	}

	m_ary.RemoveAll();

	while( 1 )
	{
		nCol = 14;
		stItem = S_LT_NUM_SET();
		strValue = pExcel->GetCellValue( nCol++, nRow );
		if( strValue.GetLength() == 0 )
			break;

		stItem.n1 = atoi( strValue );
		strValue = pExcel->GetCellValue( nCol++, nRow );
		stItem.n2 = atoi( strValue );
		strValue = pExcel->GetCellValue( nCol++, nRow );
		stItem.n3 = atoi( strValue );
		strValue = pExcel->GetCellValue( nCol++, nRow );
		stItem.n4 = atoi( strValue );
		strValue = pExcel->GetCellValue( nCol++, nRow );
		stItem.n5 = atoi( strValue );
		strValue = pExcel->GetCellValue( nCol++, nRow );
		stItem.n6 = atoi( strValue );

		m_ary.Add( stItem );
		nRow++;
	}

e:
	if( pExcel )
	{
		pExcel->ReleaseExcel();
		delete pExcel;
		pExcel = NULL;
	}

	return TRUE;
}

void				CNumberManager::SaveCSV						( const CString&	strFileName		,
																  const BYTE*		pData			,
																		int			nCount			)
{
	int i, nIndex = 1;
	char	szBuffer[64];
	DWORD dwWroten;
	HANDLE hFile = INVALID_HANDLE_VALUE;

	hFile = ::CreateFile( strFileName, GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	sprintf( szBuffer, "No,1st,2st,3st,4st,5st,6st,Sum\r\n");
	::WriteFile( hFile, szBuffer, strlen(szBuffer), &dwWroten, NULL );
	nCount *= 6;
	for( i=0 ; i<nCount ; i+=6, nIndex++ )
	{
		sprintf( szBuffer, "%d,%d,%d,%d,%d,%d,%d,%d,\r\n", 
							nIndex,
							pData[i+0] , pData[i+1] , pData[i+2] , pData[i+3] , pData[i+4] , pData[i+5] , 
							pData[i+0] + pData[i+1] + pData[i+2] + pData[i+3] + pData[i+4] + pData[i+5] );
		::WriteFile( hFile, szBuffer, strlen(szBuffer), &dwWroten, NULL );
	}
	::CloseHandle( hFile );
	hFile = INVALID_HANDLE_VALUE;

}


void				CNumberManager::Release						()
{
	m_ary.RemoveAll();
	Clear();

}

void				CNumberManager::AddCountToInt				( int nNum	)
{
	MapIntNum::iterator it = m_mapInt.find( nNum );
	if( it == m_mapInt.end() )
	{
		int * pNewInt = new int;
		*pNewInt	= 1;
		m_mapInt.insert( PairIntNum( nNum, pNewInt ) );

		return;
	}
	int * pValue = it->second;
	(*pValue)++;
}

void				CNumberManager::AddCountToStr				( const CString& strNum )
{
	MapStrNum::iterator it = m_mapStr.find( strNum );
	if( it == m_mapStr.end() )
	{
		int* pNewInt = new int;
		*pNewInt	= 1;
		m_mapStr.insert( PairStrNum( strNum, pNewInt ) );
		return;
	}
	int * pValue = it->second;
	(*pValue)++;
}

void				CNumberManager::Clear						()
{
	ClearIntNum();
	ClearStrNum();
	m_mapResult.clear();
}

void				CNumberManager::ClearIntNum					()

{
	MapIntNum::iterator it;
	for( it=m_mapInt.begin() ; it!=m_mapInt.end() ; it++ )
	{
		int * pNewInt = it->second;
		delete pNewInt;
		pNewInt = NULL;
	}
	m_mapInt.clear();
}

void				CNumberManager::ClearStrNum					()
{
	MapStrNum::iterator it;
	for( it=m_mapStr.begin() ; it!=m_mapStr.end() ; it++ )
	{
		int * pNewInt = it->second;
		delete pNewInt;
		pNewInt = NULL;
	}
	m_mapStr.clear();
}

void				CNumberManager::SetOption					( DWORD dwOption )
{
	if( dwOption & C_FLAGS_OPTION_4 )
	{
		SetHistoryNumbers( &m_ary );		
	}

	CNumberFilter::SetOption( dwOption );
}

MapSortNum*			CNumberManager::GetMaxUsedNum				()
{

	Clear();

	S_LT_NUM_SET stItem;
	int nCount = m_ary.GetSize();
	int i;
	for( i=0 ; i<nCount ; i++ )
	{
		stItem = m_ary.GetAt( i );
		AddCountToInt( stItem.n1 );
		AddCountToInt( stItem.n2 );
		AddCountToInt( stItem.n3 );
		AddCountToInt( stItem.n4 );
		AddCountToInt( stItem.n5 );
		AddCountToInt( stItem.n6 );
	}

	MapIntNum::iterator it;

	for( it=m_mapInt.begin() ; it!=m_mapInt.end() ; it++ )
	{
		m_mapResult.insert( PairSortNum( *it->second, it->first ) );
	}

	return &m_mapResult;
}

MapSortNum*			CNumberManager::GetMaxUsedNum				(int nCount)
{

	Clear();

	S_LT_NUM_SET stItem;

	int i;
	for( i=0 ; i<nCount ; i++ )
	{
		stItem = m_ary.GetAt( i );
		AddCountToInt( stItem.n1 );
		AddCountToInt( stItem.n2 );
		AddCountToInt( stItem.n3 );
		AddCountToInt( stItem.n4 );
		AddCountToInt( stItem.n5 );
		AddCountToInt( stItem.n6 );
	}

	MapIntNum::iterator it;

	for( it=m_mapInt.begin() ; it!=m_mapInt.end() ; it++ )
	{
		m_mapResult.insert( PairSortNum( *it->second, it->first ) );
	}

	return &m_mapResult;
}

MapSortNum*			CNumberManager::GetMaxIncludedNum			(int nCount, UINT nNum1 )
{
	Clear();

	S_LT_NUM_SET stItem;

	int i;
	for( i=0 ; i<nCount ; i++ )
	{
		stItem = m_ary.GetAt( i );

		if( stItem.IsInclude( nNum1 ) == FALSE )
			continue;

		AddCountToInt( stItem.n1 );
		AddCountToInt( stItem.n2 );
		AddCountToInt( stItem.n3 );
		AddCountToInt( stItem.n4 );
		AddCountToInt( stItem.n5 );
		AddCountToInt( stItem.n6 );
	}

	MapIntNum::iterator it;

	for( it=m_mapInt.begin() ; it!=m_mapInt.end() ; it++ )
	{
		m_mapResult.insert( PairSortNum( *it->second, it->first ) );
	}

	return &m_mapResult;
}

MapSortNum*			CNumberManager::GetMaxIncludedNum			(int nCount, UINT nNum1, UINT nNum2 )
{
	Clear();

	S_LT_NUM_SET stItem;
//	int nCount = m_ary.GetSize();
	int i;
	for( i=0 ; i<nCount ; i++ )
	{
		stItem = m_ary.GetAt( i );

		if( stItem.IsInclude( nNum1 ) == FALSE )
			continue;
		if( stItem.IsInclude( nNum2 ) == FALSE )
			continue;


		AddCountToInt( stItem.n1 );
		AddCountToInt( stItem.n2 );
		AddCountToInt( stItem.n3 );
		AddCountToInt( stItem.n4 );
		AddCountToInt( stItem.n5 );
		AddCountToInt( stItem.n6 );
	}

	MapIntNum::iterator it;

	for( it=m_mapInt.begin() ; it!=m_mapInt.end() ; it++ )
	{
		m_mapResult.insert( PairSortNum( *it->second, it->first ) );
	}


	return &m_mapResult;
}

MapSortNum*			CNumberManager::GetMaxIncludedNum			(int nCount, UINT nNum1, UINT nNum2, UINT nNum3 )
{
	Clear();

	S_LT_NUM_SET stItem;
//	int nCount = m_ary.GetSize();
	int i;
	for( i=0 ; i<nCount ; i++ )
	{
		stItem = m_ary.GetAt( i );

		if( stItem.IsInclude( nNum1 ) == FALSE )
			continue;
		if( stItem.IsInclude( nNum2 ) == FALSE )
			continue;
		if( stItem.IsInclude( nNum3 ) == FALSE )
			continue;

		AddCountToInt( stItem.n1 );
		AddCountToInt( stItem.n2 );
		AddCountToInt( stItem.n3 );
		AddCountToInt( stItem.n4 );
		AddCountToInt( stItem.n5 );
		AddCountToInt( stItem.n6 );
	}

	MapIntNum::iterator it;

	for( it=m_mapInt.begin() ; it!=m_mapInt.end() ; it++ )
	{
		m_mapResult.insert( PairSortNum( *it->second, it->first ) );
	}

	return &m_mapResult;
}

MapSortNum*			CNumberManager::GetStatiicsEachLocated		(int nLocatedIndex, CArrayNumber* pAry )
{
	Clear();

	S_LT_NUM_SET stItem;
	int nCount = pAry->GetSize();
	int i;
	for( i=0 ; i<nCount ; i++ )
	{
		stItem = pAry->GetAt( i );

//		if( stItem.IsInclude( nNum1 ) == FALSE )
//			continue;
//		if( stItem.IsInclude( nNum2 ) == FALSE )
//			continue;
//		if( stItem.IsInclude( nNum3 ) == FALSE )
//			continue;

		AddCountToInt( stItem.n1 );
		AddCountToInt( stItem.n2 );
		AddCountToInt( stItem.n3 );
		AddCountToInt( stItem.n4 );
		AddCountToInt( stItem.n5 );
		AddCountToInt( stItem.n6 );
	}

	MapIntNum::iterator it;

	for( it=m_mapInt.begin() ; it!=m_mapInt.end() ; it++ )
	{
		m_mapResult.insert( PairSortNum( *it->second, it->first ) );
	}

	return &m_mapResult;
}

int					CNumberManager::Get2ContinuedNumbers			(CArrayNumber* pAry )
{
	Clear();

	S_LT_NUM_SET stItem;

	int nCount = m_ary.GetSize();
	int i;
	for( i=0 ; i<nCount ; i++ )
	{
		stItem = m_ary.GetAt( i );

		if( stItem.n1 + 1 == stItem.n2 )
		{
			pAry->Add( stItem );
			continue;
		}
		if( stItem.n2 + 1 == stItem.n3 )
		{
			pAry->Add( stItem );
			continue;
		}
		if( stItem.n3 + 1 == stItem.n4 )
		{
			pAry->Add( stItem );
			continue;
		}
		if( stItem.n4 + 1 == stItem.n5 )
		{
			pAry->Add( stItem );
			continue;
		}
		if( stItem.n5 + 1 == stItem.n6 )
		{
			pAry->Add( stItem );
			continue;
		}

	}
	return pAry->GetSize();
}


int					CNumberManager::Get3ContinuedNumbers			(CArrayNumber* pAry )
{
	Clear();

	S_LT_NUM_SET stItem;

	int nCount = m_ary.GetSize();
	int i;
	for( i=0 ; i<nCount ; i++ )
	{
		stItem = m_ary.GetAt( i );

		if( stItem.n1 + 1 == stItem.n2 && stItem.n2 + 1 == stItem.n3 )
		{
			pAry->Add( stItem );
			continue;
		}
		if( stItem.n2 + 1 == stItem.n3 && stItem.n3 + 1 == stItem.n4 )
		{
			pAry->Add( stItem );
			continue;
		}
		if( stItem.n3 + 1 == stItem.n4 && stItem.n4 + 1 == stItem.n5 )
		{
			pAry->Add( stItem );
			continue;
		}
		if( stItem.n4 + 1 == stItem.n5 && stItem.n5 + 1 == stItem.n6 )
		{
			pAry->Add( stItem );
			continue;
		}


	}
	return pAry->GetSize();
}

int					CNumberManager::CreateAllNumber				(const BYTE*		pData			,
																int					nMaxCount		, 
																BOOL				bFilter			)
{
	int cnt = 6;
	int max = 45;
	BYTE byteNumber[6] = { NULL, };
	int nTotalCount = 0;
	BYTE* pCurData = (BYTE*)pData;
	register int a, b, c, d, e, f;
	BOOL bRet = TRUE;
	for ( a = 1; a <= max - cnt + 1; ++a ) 
	{
		byteNumber[0] = a;
		for ( b = a + 1; b <= max - cnt + 2; ++ b) 
		{
			byteNumber[1] = b;
			for ( c = b + 1; c <= max - cnt + 3; ++ c) 
			{
				byteNumber[2] = c;
				for ( d = c + 1; d <= max - cnt + 4; ++ d) 
				{
					byteNumber[3] = d;
					for ( e = d + 1; e <= max - cnt + 5; ++ e) 
					{
						byteNumber[4] = e;
						for ( f = e + 1; f <= max - cnt + 6; ++ f) 
						{
							
							byteNumber[5] = f;

							bRet = OnFilter( byteNumber );
							if( bRet == bFilter )
								continue;

							nTotalCount++;

							if( pCurData )
							{
								memcpy( pCurData, byteNumber, 6 );
								pCurData += 6;

							}
						}
					}
				}
			}
		}
	}

	return nTotalCount;
}

