// NumberFilter.h: interface for the CNumberFilter class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NUMBERFILTER_H__90C0F231_250F_45D3_A233_B240A7EFE2A2__INCLUDED_)
#define AFX_NUMBERFILTER_H__90C0F231_250F_45D3_A233_B240A7EFE2A2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Defines.h"




#define			C_FLAGS_OPTION_1		0x00000001		
#define			C_FLAGS_OPTION_2		0x00000002		
#define			C_FLAGS_OPTION_3		0x00000004		
#define			C_FLAGS_OPTION_4		0x00000008		
#define			C_FLAGS_OPTION_5		0x00000010		
#define			C_FLAGS_OPTION_6		0x00000020		
#define			C_FLAGS_OPTION_7		0x00000040		
#define			C_FLAGS_OPTION_8		0x00000080		
#define			C_FLAGS_OPTION_9		0x00000100		
#define			C_FLAGS_OPTION_10		0x00000200		
#define			C_FLAGS_OPTION_11		0x00000400		
#define			C_FLAGS_OPTION_12		0x00000800		

typedef pair<__int64, __int64>	PairHistory;
typedef map<__int64, __int64>	MapHistory;
typedef pair<BYTE,BYTE>			PairBytes;
typedef map<BYTE,BYTE>			MapBytes;

class CNumberFilter  
{
public:
	CNumberFilter();
	virtual ~CNumberFilter();
public:
	DWORD			m_dwOption				;
	MapHistory		m_mapExist				;
	int				m_nLessNum				;
	int				m_nOverNum				;
	MapBytes		m_mapExceptNumbers		;
	MapBytes		m_mapAcceptNumbers		;
protected:

public:
	virtual void		SetOption					( DWORD dwOption ); 
	virtual void		SetLessNum					( int nNum ) { m_nLessNum = nNum; } 
	virtual void		SetOverNum					( int nNum ) { m_nOverNum = nNum; }
	virtual void		SetExceptNumbers			( const CByteArray& ary );
	virtual void		SetAcceptNumbers			( const CByteArray& ary );
	void				SetHistoryNumbers			( CArrayNumber* pAry );
public:
	inline __int64	GetNumber						( const BYTE* pData )
	{
		__int64 i64Number = 0;
		i64Number += pData[0] * 10000000000;
		i64Number += pData[1] * 100000000;
		i64Number += pData[2] * 1000000;
		i64Number += pData[3] * 10000;
		i64Number += pData[4] * 100;
		i64Number += pData[5];
		return i64Number;
	}

	inline BOOL				OnFilter( const BYTE* pData )
	{
		BOOL bRet = FALSE;
		
		if( ( m_dwOption & C_FLAGS_OPTION_1 ) && IsOption_1( pData ) == TRUE )
			goto e;
		
		if( ( m_dwOption & C_FLAGS_OPTION_2 )  && IsOption_2( pData ) == TRUE )
			goto e;
		
		if( ( m_dwOption & C_FLAGS_OPTION_3 )  && IsOption_3( pData ) == TRUE )
			goto e;

		if( ( m_dwOption & C_FLAGS_OPTION_4 )  && IsOption_4( pData ) == TRUE )
			goto e;

		if( ( m_dwOption & C_FLAGS_OPTION_5 )  && IsOption_5( pData, m_nLessNum ) == TRUE )
			goto e;

		if( ( m_dwOption & C_FLAGS_OPTION_6 )  && IsOption_6( pData, m_nOverNum ) == TRUE )
			goto e;

		if( ( m_dwOption & C_FLAGS_OPTION_7 )  && IsOption_7( pData, &m_mapExceptNumbers ) == TRUE )
			goto e;

		if( ( m_dwOption & C_FLAGS_OPTION_8 )  && IsOption_8( pData, &m_mapAcceptNumbers ) == FALSE )
			goto e;

		if( ( m_dwOption & C_FLAGS_OPTION_9 )  && IsOption_9( pData ) == FALSE )
			goto e;

		if( ( m_dwOption & C_FLAGS_OPTION_10 )  && IsOption_10( pData ) == FALSE )
			goto e;

		if( ( m_dwOption & C_FLAGS_OPTION_11 )  && IsOption_11( pData ) == FALSE )
			goto e;

		bRet = TRUE;
	e:

		return bRet;
	}

	inline BOOL				IsOption_1				(const BYTE* pData )
	{
		register int i = 0;
		if( pData[i] + 1 == pData[i+1] && pData[i+1] + 1 == pData[i+2] )
			return TRUE;
		i++;
		if( pData[i] + 1 == pData[i+1] && pData[i+1] + 1 == pData[i+2] )
			return TRUE;
		i++;
		if( pData[i] + 1 == pData[i+1] && pData[i+1] + 1 == pData[i+2] )
			return TRUE;
		i++;
		if( pData[i] + 1 == pData[i+1] && pData[i+1] + 1 == pData[i+2] )
			return TRUE;
		return FALSE;

	}

	inline BOOL			IsOption_2				(const BYTE* pData )
	{
		int nPartCount = 0;
		register int i = 0;
		if( pData[i] + 1 == pData[i+1] )
			nPartCount++;
		i++;
		if( pData[i] + 1 == pData[i+1] )
			nPartCount++;
		i++;
		if( pData[i] + 1 == pData[i+1] )
			nPartCount++;
		i++;
		if( pData[i] + 1 == pData[i+1] )
			nPartCount++;
		i++;
		if( pData[i] + 1 == pData[i+1] )
			nPartCount++;
		i++;
		if( pData[i] + 1 == pData[i+1] )
			nPartCount++;
		i++;

		if( 1 < nPartCount )
			return TRUE;

		return FALSE;

	}

	inline BOOL			IsOption_3			(const BYTE* pData )
	{
		int nPartCount = 0;
		register int i = 0;
		if( ( pData[i] % 2 ) == 0 )
			nPartCount++;
		i++;
		if( ( pData[i] % 2 ) == 0 )
			nPartCount++;
		i++;
		if( ( pData[i] % 2 ) == 0 )
			nPartCount++;
		i++;
		if( ( pData[i] % 2 ) == 0 )
			nPartCount++;
		i++;
		if( ( pData[i] % 2 ) == 0 )
			nPartCount++;
		i++;
		if( ( pData[i] % 2 ) == 0 )
			nPartCount++;
		i++;

		if( nPartCount < 2 || 4 < nPartCount )
			return TRUE;

		return FALSE;
	}

	inline BOOL			IsOption_4			(const BYTE* pData )
	{
		MapHistory::iterator it;
		__int64 i64Number = GetNumber( pData );
		it = m_mapExist.find( i64Number );
		if( it == m_mapExist.end() )
			return FALSE;
		return TRUE;

	}
	inline BOOL			IsOption_5				(const BYTE* pData, const int nNum )
	{
		int nSum = 0;
		nSum += pData[0];
		nSum += pData[1];
		nSum += pData[2];
		nSum += pData[3];
		nSum += pData[4];
		nSum += pData[5];

		return nSum <= nNum;
	}
	inline BOOL			IsOption_6				(const BYTE* pData, const int nNum )
	{
		int nSum = 0;
		nSum += pData[0];
		nSum += pData[1];
		nSum += pData[2];
		nSum += pData[3];
		nSum += pData[4];
		nSum += pData[5];

		return nNum <= nSum;
	}
	inline BOOL			IsOption_7				(const BYTE* pData, MapBytes* pMap )
	{
		if( pMap->find( pData[0] ) != pMap->end() )
			return TRUE;
		if( pMap->find( pData[1] ) != pMap->end() )
			return TRUE;
		if( pMap->find( pData[2] ) != pMap->end() )
			return TRUE;
		if( pMap->find( pData[3] ) != pMap->end() )
			return TRUE;
		if( pMap->find( pData[4] ) != pMap->end() )
			return TRUE;
		if( pMap->find( pData[5] ) != pMap->end() )
			return TRUE;
		return FALSE;
	}
	inline BOOL			IsOption_8				(const BYTE* pData, MapBytes* pMap )
	{
		int nMaxCount = pMap->size();
		int nCount = 0;
		if( pMap->find( pData[0] ) != pMap->end() )
			nCount++;
		if( pMap->find( pData[1] ) != pMap->end() )
			nCount++;
		if( pMap->find( pData[2] ) != pMap->end() )
			nCount++;
		if( pMap->find( pData[3] ) != pMap->end() )
			nCount++;
		if( pMap->find( pData[4] ) != pMap->end() )
			nCount++;
		if( pMap->find( pData[5] ) != pMap->end() )
			nCount++;

		return nMaxCount == nCount;
	}

	inline BOOL			IsOption_9				(const BYTE* pData )
	{
		int nCount = 0;
		if( pData[0] % 3 == 0 )
			nCount++;
		if( pData[1] % 3 == 0 )
			nCount++;
		if( pData[2] % 3 == 0 )
			nCount++;
		if( pData[3] % 3 == 0 )
			nCount++;
		if( pData[4] % 3 == 0 )
			nCount++;
		if( pData[5] % 3 == 0 )
			nCount++;

		if( 1 <= nCount && nCount <= 3 )
			return TRUE;
		return FALSE;
	}

	inline BOOL			IsOption_10				(const BYTE* pData )
	{
		int nCount = 0;
		if( pData[0] % 5 == 0 )
			nCount++;
		if( pData[1] % 5 == 0 )
			nCount++;
		if( pData[2] % 5 == 0 )
			nCount++;
		if( pData[3] % 5 == 0 )
			nCount++;
		if( pData[4] % 5 == 0 )
			nCount++;
		if( pData[5] % 5 == 0 )
			nCount++;

		if( nCount <= 2 )
			return TRUE;
		return FALSE;
	}

	inline BOOL			IsOption_11				(const BYTE* pData )
	{
		int nCount = 0;
		if( pData[0] % 7 == 0 )
			nCount++;
		if( pData[1] % 7 == 0 )
			nCount++;
		if( pData[2] % 7 == 0 )
			nCount++;
		if( pData[3] % 7 == 0 )
			nCount++;
		if( pData[4] % 7 == 0 )
			nCount++;
		if( pData[5] % 7 == 0 )
			nCount++;

		if( nCount <= 1 )
			return TRUE;
		return FALSE;
	}
};

#endif // !defined(AFX_NUMBERFILTER_H__90C0F231_250F_45D3_A233_B240A7EFE2A2__INCLUDED_)
