// SICXEAssemblerView.h : interface of the CSICXEAssemblerView class
//
/////////////////////////////////////////////////////////////////////////////


#if !defined(AFX_SICXEASSEMBLERVIEW_H__A5384C58_F279_4E8F_B410_D55C96F2D769__INCLUDED_)
#define AFX_SICXEASSEMBLERVIEW_H__A5384C58_F279_4E8F_B410_D55C96F2D769__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#include "SICXEAssemblerDoc.h"
#endif // _MSC_VER > 1000

#include <string>
using namespace std ;


class CSICXEAssemblerView : public CEditView
{
protected: // create from serialization only
	CSICXEAssemblerView();
	DECLARE_DYNCREATE(CSICXEAssemblerView)

// Attributes
public:
	CSICXEAssemblerDoc* GetDocument();
	CString PathName ;

// Operations
public:

	void InsertToSymtab(int,string,string) ;
	void DeleteAllSymtab() ;
	void CreateSrctab(bool) ;
	void ResetDataStruct() ;
	void InsertObjectProgram() ;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSICXEAssemblerView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSICXEAssemblerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSICXEAssemblerView)
	afx_msg void OnMenupass1();
	afx_msg void OnMenupass2();
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in SICXEAssemblerView.cpp
inline CSICXEAssemblerDoc* CSICXEAssemblerView::GetDocument()
   { return (CSICXEAssemblerDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SICXEASSEMBLERVIEW_H__A5384C58_F279_4E8F_B410_D55C96F2D769__INCLUDED_)
