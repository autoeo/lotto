// Defines.h: interface for the Defines class.
//
//////////////////////////////////////////////////////////////////////

#pragma warning ( disable : 4987 )
#pragma warning ( disable : 4786 )

#include "afxtempl.h"
#include <map>
using namespace std;

#pragma once


typedef struct tagS_LT_NUM_SET
{
	tagS_LT_NUM_SET()
	{
		n1	= 0;
		n2	= 0;
		n3	= 0;
		n4	= 0;
		n5	= 0;
		n6	= 0;
	}
	tagS_LT_NUM_SET(const tagS_LT_NUM_SET& st )
	{
		n1	= st.n1;
		n2	= st.n2;
		n3	= st.n3;
		n4	= st.n4;
		n5	= st.n5;
		n6	= st.n6;
	}
	tagS_LT_NUM_SET& operator =(const tagS_LT_NUM_SET& st )
	{
		n1	= st.n1;
		n2	= st.n2;
		n3	= st.n3;
		n4	= st.n4;
		n5	= st.n5;
		n6	= st.n6;
		return *this;
	}
	inline BOOL IsInclude( int nNum )
	{
		if( nNum == n1 )			return TRUE;
		if( nNum == n2 )			return TRUE;
		if( nNum == n3 )			return TRUE;
		if( nNum == n4 )			return TRUE;
		if( nNum == n5 )			return TRUE;
		if( nNum == n6 )			return TRUE;

		return FALSE;
	}

	BYTE	n1	;
	BYTE	n2	;
	BYTE	n3	;
	BYTE	n4	;
	BYTE	n5	;
	BYTE	n6	;
}S_LT_NUM_SET;

typedef pair<int, int*>			PairIntNum	;
typedef map<int, int*>			MapIntNum	;
typedef pair<CString, int*>		PairStrNum	;
typedef map<CString, int*>		MapStrNum	;
typedef pair<int, int>			PairSortNum	;
typedef multimap<int, int>		MapSortNum	;

typedef CArray< S_LT_NUM_SET, S_LT_NUM_SET > CArrayNumber;
