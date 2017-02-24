// DlgView.cpp : implementation file
//

#include "stdafx.h"
#include "SICXEAssembler.h"
#include "DlgView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgView

IMPLEMENT_DYNCREATE(CDlgView, CFormView)

CDlgView::CDlgView()
	: CFormView(CDlgView::IDD)
{
	//{{AFX_DATA_INIT(CDlgView)
	m_objprog = _T("");
	//}}AFX_DATA_INIT
}

CDlgView::~CDlgView()
{
}

void CDlgView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgView)
	DDX_Control(pDX, IDC_EDIT1, m_machine);
	DDX_Control(pDX, IDC_LIST2, m_srctab);
	DDX_Control(pDX, IDC_LIST1, m_symtab);
	DDX_Text(pDX, IDC_EDIT2, m_objprog);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgView, CFormView)
	//{{AFX_MSG_MAP(CDlgView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgView diagnostics

#ifdef _DEBUG
void CDlgView::AssertValid() const
{
	CFormView::AssertValid();
}

void CDlgView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDlgView message handlers

void CDlgView::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	m_srctab.DeleteAllItems() ;
	m_symtab.DeleteAllItems() ;
	m_machine.SetWindowText("") ;

	m_symtab.DeleteColumn(1) ;
	m_symtab.DeleteColumn(0) ;
	m_symtab.InsertColumn(0,_T("Symbol") ,LVCFMT_LEFT,70,0) ;
	m_symtab.InsertColumn(1,_T("Address"),LVCFMT_LEFT,70,1) ;

	m_srctab.DeleteColumn(5) ;
	m_srctab.DeleteColumn(4) ;
	m_srctab.DeleteColumn(3) ;
	m_srctab.DeleteColumn(2) ;
	m_srctab.DeleteColumn(1) ;
	m_srctab.DeleteColumn(0) ;
	m_srctab.InsertColumn(0,_T("Lines"),LVCFMT_LEFT,40,0) ;
	m_srctab.InsertColumn(1,_T("Loc"),LVCFMT_LEFT,40,0) ;
	m_srctab.InsertColumn(2,_T("Lable"),LVCFMT_LEFT,70,0) ;
	m_srctab.InsertColumn(3,_T("Opcode"),LVCFMT_LEFT,70,0) ;
	m_srctab.InsertColumn(4,_T("Operand"),LVCFMT_LEFT,70,0) ;
	m_srctab.InsertColumn(5,_T("Object Code"),LVCFMT_LEFT,100,0) ;

	m_objprog = "" ;
	UpdateData(false) ;
}
