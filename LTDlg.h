// LTDlg.h : header file
//

#if !defined(AFX_LTDLG_H__89C1CF88_4817_403B_8992_8745F264168E__INCLUDED_)
#define AFX_LTDLG_H__89C1CF88_4817_403B_8992_8745F264168E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CommonSrc/NumberManager.h"
#include "CommonSrc/ListCtrlNum.h"
#include "CommonSrc/ListCtrlNumAll.h"
#include "CommonSrc/CmbRecentThNumber.h"
/////////////////////////////////////////////////////////////////////////////
// CLTDlg dialog

#define C_STR_FULL_DATA_FILE_NAME		"LT_FULL_DATA.DAT"
#define C_INT_FULL_DATA_COUNT			8145060

class CLTDlg : public CDialog
{
// Construction
public:
	CLTDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CLTDlg)
	enum { IDD = IDD_LT_DIALOG };
	CCmbRecentThNumber	m_ctrlCmbRecentThNumber;
	CListCtrlNumAll	m_ctrlListNumAll;
	CListCtrlNum	m_ctrlListNumCount;
	UINT	m_nParam_01;
	UINT	m_nParam_02;
	UINT	m_nParam_03;
	UINT	m_nTotalListCount;
	BOOL	m_bOption1;
	BOOL	m_bOption2;
	BOOL	m_bOption3;
	BOOL	m_bOption4;
	BOOL	m_bOption5;
	BOOL	m_bOption6;
	BOOL	m_bOption7;
	BOOL	m_bOption8;
	BOOL	m_bOption9;
	BOOL	m_bOption10;
	BOOL	m_bOption11;
	UINT	m_nLessNum;
	UINT	m_nOverNum;
	UINT	m_nIncludeNumber_1;
	UINT	m_nIncludeNumber_2;
	UINT	m_nIncludeNumber_3;
	CString	m_strFilterInfoFrom;
	BOOL	m_bChkEnableRecentThNumber;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLTDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CLTDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnBtnGetMostUsed();
	afx_msg void OnBtnGetIncluded();
	afx_msg void OnBtnSortBySum();
	afx_msg void OnBtnSaveResultToCsv();
	afx_msg void OnBtnGetAllNumber();
	afx_msg void OnBtnConvertExcelToBin();
	afx_msg void OnBtnSetExceptNumbers();
	afx_msg void OnChkFilterOption8();
	afx_msg void OnChkRecentThNumber();
	afx_msg void OnBtnSaveWithoutResultToCsv();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
	CNumberManager		m_stLoader			;
	LOGFONT				m_logFont			;
	CFont				m_font_Normal		;
	CFont				m_font_Large		;
	CByteArray			m_aryExceptNumbers	;
	CByteArray			m_aryAcceptNumbers	;

public:
	DWORD				GetOption			();
	void				SetAcceptNumbers	();
	int					GetRecentNumberCount();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LTDLG_H__89C1CF88_4817_403B_8992_8745F264168E__INCLUDED_)
