// SICXEAssemblerDoc.cpp : implementation of the CSICXEAssemblerDoc class
//

#include "stdafx.h"
#include "SICXEAssembler.h"
#include "DlgView.h"
#include "SICXEAssemblerDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSICXEAssemblerDoc

IMPLEMENT_DYNCREATE(CSICXEAssemblerDoc, CDocument)

BEGIN_MESSAGE_MAP(CSICXEAssemblerDoc, CDocument)
	//{{AFX_MSG_MAP(CSICXEAssemblerDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSICXEAssemblerDoc construction/destruction

CSICXEAssemblerDoc::CSICXEAssemblerDoc()
{
	// TODO: add one-time construction code here

}

CSICXEAssemblerDoc::~CSICXEAssemblerDoc()
{
}

BOOL CSICXEAssemblerDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	((CEditView*)m_viewList.GetHead())->SetWindowText(NULL);

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSICXEAssemblerDoc serialization

void CSICXEAssemblerDoc::Serialize(CArchive& ar)
{
	// CEditView contains an edit control which handles all serialization
	((CEditView*)m_viewList.GetHead())->SerializeRaw(ar);
}

/////////////////////////////////////////////////////////////////////////////
// CSICXEAssemblerDoc diagnostics

#ifdef _DEBUG
void CSICXEAssemblerDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSICXEAssemblerDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSICXEAssemblerDoc commands

BOOL CSICXEAssemblerDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;
	
	// TODO: Add your specialized creation code here
	
	return TRUE;
}
