// CNumberManager.h: interface for the CCNumberManager class.
//
//////////////////////////////////////////////////////////////////////



#pragma once



#include "XLEzAutomation.h"

#include "NumberFilter.h"



class CNumberManager  : public CNumberFilter
{
public:
	CNumberManager();
	virtual ~CNumberManager();
public:
	BOOL				Load						( const CString&	strFileName		);
	void				SaveCSV						( const CString&	strFileName		,
													  const BYTE*		pData			,
															int			nMaxCount		);
	void				Release						();
	void				AddCountToInt				( int nNum	);
	void				AddCountToStr				( const CString& strNum );
	void				Clear						();
	void				ClearIntNum					();
	void				ClearStrNum					();

public:
	virtual void		SetOption					( DWORD dwOption );
public:
	MapSortNum*			GetMaxUsedNum				();
	MapSortNum*			GetMaxUsedNum				(int nCount );
	MapSortNum*			GetMaxIncludedNum			(int nCount, UINT nNum1 );
	MapSortNum*			GetMaxIncludedNum			(int nCount, UINT nNum1, UINT nNum2 );
	MapSortNum*			GetMaxIncludedNum			(int nCount, UINT nNum1, UINT nNum2, UINT nNum3 );
	MapSortNum*			GetStatiicsEachLocated		(int nLocatedIndex, CArrayNumber* pAry );
	CArrayNumber*		GetHistoryNumbers			() { return &m_ary; }



	int					Get2ContinuedNumbers		(CArrayNumber* pAry );
	int					Get3ContinuedNumbers		(CArrayNumber* pAry );

	int					CreateAllNumber				(const BYTE*		pData			,
													int					nMaxCount		,
													BOOL				bFilter			);


public:
	CArrayNumber							m_ary			;
	MapIntNum								m_mapInt		;
	MapStrNum								m_mapStr		;
	MapSortNum								m_mapResult		;
	
};
