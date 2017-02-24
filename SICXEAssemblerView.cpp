// SICXEAssemblerView.cpp : implementation of the CSICXEAssemblerView class
//

#include "stdafx.h"
#include "SICXEAssembler.h"
#include "DlgView.h"
#include "SICXEAssemblerDoc.h"
#include "SICXEAssemblerView.h"

#include "sicxeisa.h"
#include <fstream>
#include <string>

using namespace std ;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////

int  TotalLines ;
string sStr[MAX_LINE_OF_FILE] ;
string sErrorMsg ;
bool PASS1DOWN ;


/////////////////////////////////////////////////////////////////////////////
// CSICXEAssemblerView

IMPLEMENT_DYNCREATE(CSICXEAssemblerView, CEditView)

BEGIN_MESSAGE_MAP(CSICXEAssemblerView, CEditView)
	//{{AFX_MSG_MAP(CSICXEAssemblerView)
	ON_COMMAND(ID_MENUPASS1, OnMenupass1)
	ON_COMMAND(ID_MENUPASS2, OnMenupass2)
	ON_WM_KEYUP()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CEditView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSICXEAssemblerView construction/destruction

CSICXEAssemblerView::CSICXEAssemblerView()
{
	// TODO: add construction code here

}

CSICXEAssemblerView::~CSICXEAssemblerView()
{
}

BOOL CSICXEAssemblerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	BOOL bPreCreated = CEditView::PreCreateWindow(cs);
	cs.style &= ~(ES_AUTOHSCROLL|WS_HSCROLL);	// Enable word-wrapping

	return bPreCreated;
}

/////////////////////////////////////////////////////////////////////////////
// CSICXEAssemblerView drawing

void CSICXEAssemblerView::OnDraw(CDC* pDC)
{
	CSICXEAssemblerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CSICXEAssemblerView printing

BOOL CSICXEAssemblerView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default CEditView preparation
	return CEditView::OnPreparePrinting(pInfo);
}

void CSICXEAssemblerView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// Default CEditView begin printing.
	CEditView::OnBeginPrinting(pDC, pInfo);
}

void CSICXEAssemblerView::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// Default CEditView end printing
	CEditView::OnEndPrinting(pDC, pInfo);
}

/////////////////////////////////////////////////////////////////////////////
// CSICXEAssemblerView diagnostics

#ifdef _DEBUG
void CSICXEAssemblerView::AssertValid() const
{
	CEditView::AssertValid();
}

void CSICXEAssemblerView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}

CSICXEAssemblerDoc* CSICXEAssemblerView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSICXEAssemblerDoc)));
	return (CSICXEAssemblerDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSICXEAssemblerView message handlers

void CSICXEAssemblerView::ResetDataStruct()
{
	TotalLines    = 0 ;

	START_ADDRESS = 0 ;
	PROGRAM_LENGH = 0 ;
	PROGRAM_NAME  = "";
	BASE          = 0 ;

	SYMTAB_LENGTH = 0 ;
	LITERAL_LENGTH= 0 ;

	PASS1DOWN = false ;
	USE_SICXE = false ;
	DeleteAllSymtab() ;

	for(int i=0 ; i<MAX_LINE_OF_FILE ; i++)
	{
		haveLoc[i]	= false ;
		OBJPROG[i]  = ""    ;
		OBJCodeALL[i]= ""   ;
	}
}

CString StringToCString(string str)
{
	CString r ;
	for( int i=0 ; i<str.length() ; i++ )
		r += str.at(i) ;
	return r ;
}

void CSICXEAssemblerView::InsertToSymtab(int in,string s,string a)
{
	CSICXEAssemblerDoc* pDoc = GetDocument() ;
	POSITION pos = pDoc->GetFirstViewPosition() ;
	CDlgView *DlgView ;

	while( pos != NULL )
	{
		CView *pView = pDoc->GetNextView(pos) ;
		
		if(pView->IsKindOf( RUNTIME_CLASS(CDlgView) ) != NULL )
		{
			DlgView = (CDlgView*) pView ;
			break ;
		}
	}
	DlgView->m_symtab.InsertItem(in,StringToCString(s)) ;
	DlgView->m_symtab.SetItemText(in,1,StringToCString(FillChar(a,'0',4,0))) ;
}

void CSICXEAssemblerView::DeleteAllSymtab()
{
	CSICXEAssemblerDoc* pDoc = GetDocument() ;
	POSITION pos = pDoc->GetFirstViewPosition() ;
	CDlgView *DlgView ;

	while( pos != NULL )
	{
		CView *pView = pDoc->GetNextView(pos) ;
		
		if(pView->IsKindOf( RUNTIME_CLASS(CDlgView) ) != NULL )
		{
			DlgView = (CDlgView*) pView ;
			break ;
		}
	}
	DlgView->m_symtab.DeleteAllItems() ;
	DlgView->m_srctab.DeleteAllItems() ;
	DlgView->m_objprog = "" ;
	DlgView->UpdateData(false) ;
}

void CSICXEAssemblerView::CreateSrctab(bool method=true)
{
	CSICXEAssemblerDoc* pDoc = GetDocument() ;
	POSITION pos = pDoc->GetFirstViewPosition() ;
	CDlgView *DlgView ;

	while( pos != NULL )
	{
		CView *pView = pDoc->GetNextView(pos) ;
		
		if(pView->IsKindOf( RUNTIME_CLASS(CDlgView) ) != NULL )
		{
			DlgView = (CDlgView*) pView ;
			break ;
		}
	}

	for( int i=0 ; i<TotalLines ; i++)
	{
		if( method==true)
		{
			string lable,op,addr ;
			SourceCodeParse(sStr[i],lable,op,addr) ;

			DlgView->m_srctab.InsertItem(i,StringToCString(IntToDecString(i+1))); 

			if( haveLoc[i] == true )
				DlgView->m_srctab.SetItemText(i,1,StringToCString(FillChar(IntToHexString(LOC[i]),'0',4,0))) ;

			DlgView->m_srctab.SetItemText(i,2,StringToCString(lable)) ;
			DlgView->m_srctab.SetItemText(i,3,StringToCString(op)) ;
			DlgView->m_srctab.SetItemText(i,4,StringToCString(addr)) ;
		}
		else
		{
			DlgView->m_srctab.SetItemText(i,5,StringToCString(OBJCodeALL[i])) ;
		}
	}

	if( USE_SICXE == true )
		DlgView->m_machine.SetWindowText("SIC/XE") ;
	else
		DlgView->m_machine.SetWindowText("SIC") ;
}

void CSICXEAssemblerView::InsertObjectProgram()
{
	
	CSICXEAssemblerDoc* pDoc = GetDocument() ;
	POSITION pos = pDoc->GetFirstViewPosition() ;
	CDlgView *DlgView ;

	while( pos != NULL )
	{
		CView *pView = pDoc->GetNextView(pos) ;
		
		if(pView->IsKindOf( RUNTIME_CLASS(CDlgView) ) != NULL )
		{
			DlgView = (CDlgView*) pView ;
			break ;
		}
	}

	DlgView->m_objprog = "" ;
	for( int i=0 ; i<objprog_length ; i++)
	{
		DlgView->m_objprog += OBJPROG[i].data() ;
		DlgView->m_objprog += "\r\n" ;
	}
	
	DlgView->UpdateData(false) ;
}

void CSICXEAssemblerView::OnMenupass1() 
{
	// TODO: Add your command handler code here
	CSICXEAssemblerDoc *pDoc = GetDocument() ;

	if( pDoc->IsModified() != 0 )
	{
		if(pDoc->SaveModified()==0)
			return ;
	}

	ResetDataStruct() ;
	PathName = pDoc->GetPathName() ;

	ifstream Fin ;

	Fin.open(PathName.GetBuffer(100),ios::in) ;
	while( true )
	{
		if( Fin.eof() ) 
			break ;
		char sTmp[MAX_CHAR_OF_LINE] ;
		Fin.getline(sTmp,MAX_CHAR_OF_LINE) ;
		if( strlen(sTmp) == 0 )
			continue ;
		sStr[TotalLines++] = sTmp ;
	}
	Fin.close() ;

	if( SICXEPass1( sStr , TotalLines , sErrorMsg ) == false )
	{
		CString tmp = "Error!!\n" ;
		tmp += sErrorMsg.data() ;
		AfxMessageBox(tmp) ;
		return ;
	}

	for( int i=0 ; i<SYMTAB_LENGTH ; i++)
	{
		InsertToSymtab(i, 
			symtab[i].SymName,
			IntToHexString(symtab[i].data)) ;
	}
	CreateSrctab() ;
	PASS1DOWN = true ;
	AfxMessageBox("Pass 1 done") ;
}

void CSICXEAssemblerView::OnMenupass2() 
{
	// TODO: Add your command handler code here
	if( PASS1DOWN == false )
	{
		AfxMessageBox("Please do Pass1 first!") ;
		return ;
	}
		
	if( SICXEPass2( sStr , TotalLines , sErrorMsg ) == false )
	{
		CString tmp = "Error!!\n" ;
		tmp += sErrorMsg.data() ;
		AfxMessageBox(tmp) ;
		return ;
	}
	CreateSrctab(false) ;
	CreateSICXEObjectProgram(TotalLines) ;
	InsertObjectProgram();
	AfxMessageBox("Pass 2 done") ;
}

void CSICXEAssemblerView::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default

	PASS1DOWN = false ;
	CEditView::OnKeyUp(nChar, nRepCnt, nFlags);
}
