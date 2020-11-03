#if !defined(AFX_DLGGETNUMBERLIST_H__F2124998_63A6_4683_B1E4_B095822DEFA3__INCLUDED_)
#define AFX_DLGGETNUMBERLIST_H__F2124998_63A6_4683_B1E4_B095822DEFA3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgGetNumberList.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgGetNumberList dialog

class CDlgGetNumberList : public CDialog
{
// Construction
public:
	CDlgGetNumberList(CWnd* pParent, const CByteArray& ary );   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgGetNumberList)
	enum { IDD = IDD_DLG_GET_NUMBER_LIST };
	BOOL	m_bNumber_01;
	BOOL	m_bNumber_02;
	BOOL	m_bNumber_03;
	BOOL	m_bNumber_04;
	BOOL	m_bNumber_05;
	BOOL	m_bNumber_06;
	BOOL	m_bNumber_07;
	BOOL	m_bNumber_08;
	BOOL	m_bNumber_09;
	BOOL	m_bNumber_10;
	BOOL	m_bNumber_11;
	BOOL	m_bNumber_12;
	BOOL	m_bNumber_13;
	BOOL	m_bNumber_14;
	BOOL	m_bNumber_15;
	BOOL	m_bNumber_16;
	BOOL	m_bNumber_17;
	BOOL	m_bNumber_18;
	BOOL	m_bNumber_19;
	BOOL	m_bNumber_20;
	BOOL	m_bNumber_21;
	BOOL	m_bNumber_22;
	BOOL	m_bNumber_23;
	BOOL	m_bNumber_24;
	BOOL	m_bNumber_25;
	BOOL	m_bNumber_26;
	BOOL	m_bNumber_27;
	BOOL	m_bNumber_28;
	BOOL	m_bNumber_29;
	BOOL	m_bNumber_30;
	BOOL	m_bNumber_31;
	BOOL	m_bNumber_32;
	BOOL	m_bNumber_33;
	BOOL	m_bNumber_34;
	BOOL	m_bNumber_35;
	BOOL	m_bNumber_36;
	BOOL	m_bNumber_37;
	BOOL	m_bNumber_38;
	BOOL	m_bNumber_39;
	BOOL	m_bNumber_40;
	BOOL	m_bNumber_41;
	BOOL	m_bNumber_42;
	BOOL	m_bNumber_43;
	BOOL	m_bNumber_44;
	BOOL	m_bNumber_45;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgGetNumberList)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgGetNumberList)
	virtual void OnCancel();
	virtual void OnOK();
	afx_msg void OnBtnSelectAll();
	afx_msg void OnBtnDeselectAll();
	afx_msg void OnBtnSelectOddNumber();
	afx_msg void OnBtnDeselectOddNumber();
	afx_msg void OnBtnSelectEvenNumber();
	afx_msg void OnBtnDeselectEvenNumber();
	afx_msg void OnBtnSelectMultiOf3();
	afx_msg void OnBtnDeselectMultiOf3();
	afx_msg void OnBtnSelectMultiOf5();
	afx_msg void OnBtnDeselectMultiOf5();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
	CByteArray		m_aryBytes;
	LOGFONT				m_logFont			;
	CFont				m_font_Normal		;
	CFont				m_font_Large		;
public:
	BOOL			IsExistNumberInArray( const CByteArray& ary, BYTE bNumber );

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGGETNUMBERLIST_H__F2124998_63A6_4683_B1E4_B095822DEFA3__INCLUDED_)
