// SICXEAssembler.h : main header file for the SICXEASSEMBLER application
//

#if !defined(AFX_SICXEASSEMBLER_H__8059CB1E_6F67_4180_9883_B50863D80219__INCLUDED_)
#define AFX_SICXEASSEMBLER_H__8059CB1E_6F67_4180_9883_B50863D80219__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSICXEAssemblerApp:
// See SICXEAssembler.cpp for the implementation of this class
//

class CSICXEAssemblerApp : public CWinApp
{
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CSICXEAssemblerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSICXEAssemblerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CSICXEAssemblerApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SICXEASSEMBLER_H__8059CB1E_6F67_4180_9883_B50863D80219__INCLUDED_)
