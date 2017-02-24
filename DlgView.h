#if !defined(AFX_DLGVIEW_H__D5AD5F8B_1633_4170_9E5A_0FFEDBE6E2E8__INCLUDED_)
#define AFX_DLGVIEW_H__D5AD5F8B_1633_4170_9E5A_0FFEDBE6E2E8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgView form view

#include "SICXEAssemblerDoc.h"

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CDlgView : public CFormView
{
protected:
	CDlgView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CDlgView)

// Form Data
public:
	//{{AFX_DATA(CDlgView)
	enum { IDD = IDD_DLGVIEW_FORM };
	CEdit	m_machine;
	CListCtrl	m_srctab;
	CListCtrl	m_symtab;
	CString	m_objprog;
	//}}AFX_DATA

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgView)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CDlgView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CDlgView)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGVIEW_H__D5AD5F8B_1633_4170_9E5A_0FFEDBE6E2E8__INCLUDED_)
