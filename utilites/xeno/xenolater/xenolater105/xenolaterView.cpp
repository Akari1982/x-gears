// xenolaterView.cpp : implementation of the CXenolaterView class
//

#include "stdafx.h"
#include "xenolater.h"

#include "xenolaterDoc.h"
#include "xenolaterView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CXenolaterView

IMPLEMENT_DYNCREATE(CXenolaterView, CEditView)

BEGIN_MESSAGE_MAP(CXenolaterView, CEditView)
	//{{AFX_MSG_MAP(CXenolaterView)
	ON_CONTROL_REFLECT(EN_CHANGE, OnChange)
	ON_COMMAND(ID_FILE_UNCOMP, OnFileUncomp)
	ON_UPDATE_COMMAND_UI(ID_TABLE_DECODE_DEFAULT, OnUpdateTableDecodeDefault)
	ON_WM_CREATE()
	ON_UPDATE_COMMAND_UI(ID_DECODE_RECENT1, OnUpdateDecodeRecent1)
	ON_UPDATE_COMMAND_UI(ID_DECODE_RECENT2, OnUpdateDecodeRecent2)
	ON_UPDATE_COMMAND_UI(ID_DECODE_RECENT3, OnUpdateDecodeRecent3)
	ON_UPDATE_COMMAND_UI(ID_TABLE_DECODE_OTHER, OnUpdateTableDecodeOther)
	ON_COMMAND(ID_TABLE_DECODE_OTHER, OnTableDecodeOther)
	ON_COMMAND(ID_DECODE_RECENT1, OnDecodeRecent1)
	ON_COMMAND(ID_DECODE_RECENT2, OnDecodeRecent2)
	ON_COMMAND(ID_DECODE_RECENT3, OnDecodeRecent3)
	ON_COMMAND(ID_TABLE_DECODE_DEFAULT, OnTableDecodeDefault)
	ON_UPDATE_COMMAND_UI(ID_ENCODE_RECENT1, OnUpdateEncodeRecent1)
	ON_UPDATE_COMMAND_UI(ID_ENCODE_RECENT2, OnUpdateEncodeRecent2)
	ON_UPDATE_COMMAND_UI(ID_ENCODE_RECENT3, OnUpdateEncodeRecent3)
	ON_UPDATE_COMMAND_UI(ID_TABLE_ENCODE_NONE, OnUpdateTableEncodeNone)
	ON_UPDATE_COMMAND_UI(ID_TABLE_ENCODE_OTHER, OnUpdateTableEncodeOther)
	ON_COMMAND(ID_ENCODE_RECENT1, OnEncodeRecent1)
	ON_COMMAND(ID_ENCODE_RECENT2, OnEncodeRecent2)
	ON_COMMAND(ID_ENCODE_RECENT3, OnEncodeRecent3)
	ON_COMMAND(ID_TABLE_ENCODE_NONE, OnTableEncodeNone)
	ON_COMMAND(ID_TABLE_ENCODE_OTHER, OnTableEncodeOther)
	ON_COMMAND(ID_SCRIPT_IMPORTA, OnScriptImporta)
	ON_UPDATE_COMMAND_UI(ID_SCRIPT_IMPORTA, OnUpdateScriptImporta)
	ON_COMMAND(ID_SCRIPT_ESPORTA, OnScriptEsporta)
	ON_UPDATE_COMMAND_UI(ID_SCRIPT_ESPORTA, OnUpdateScriptEsporta)
	ON_UPDATE_COMMAND_UI(ID_SCRIPT_CONTEGGIOAUTOMATICO, OnUpdateScriptConteggioautomatico)
	ON_COMMAND(ID_SCRIPT_CONTEGGIOAUTOMATICO, OnScriptConteggioautomatico)
	ON_UPDATE_COMMAND_UI(ID_FILE_SAVE, OnUpdateFileSave)
	ON_UPDATE_COMMAND_UI(ID_FILE_SAVE_AS, OnUpdateFileSaveAs)
	ON_COMMAND(ID_MODIFICA_SELEZIONATUTTO, OnModificaSelezionatutto)
	ON_UPDATE_COMMAND_UI(ID_MODIFICA_SELEZIONATUTTO, OnUpdateModificaSelezionatutto)
	ON_UPDATE_COMMAND_UI(ID_FILE_UNCOMP, OnUpdateFileUncomp)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CXenolaterView construction/destruction

CXenolaterView::CXenolaterView()
{
	// TODO: add construction code here

}

CXenolaterView::~CXenolaterView()
{
}

BOOL CXenolaterView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	BOOL bPreCreated = CEditView::PreCreateWindow(cs);
	cs.style &= ~(ES_AUTOHSCROLL|WS_HSCROLL);	// Enable word-wrapping

	return bPreCreated;
}

/////////////////////////////////////////////////////////////////////////////
// CXenolaterView drawing

void CXenolaterView::OnDraw(CDC* pDC)
{
	CXenolaterDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CXenolaterView diagnostics

#ifdef _DEBUG
void CXenolaterView::AssertValid() const
{
	CEditView::AssertValid();
}

void CXenolaterView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}

CXenolaterDoc* CXenolaterView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CXenolaterDoc)));
	return (CXenolaterDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CXenolaterView message handlers

void CXenolaterView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	GetEditCtrl() .EnableWindow(GetDocument()->m_pDecompData != NULL);
	GetEditCtrl() .SetWindowText(GetDocument()->strText);

}

void CXenolaterView::OnChange() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CEditView::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	GetDocument() ->SetModifiedFlag(TRUE);
	GetEditCtrl().GetWindowText(GetDocument() ->strText);
	
}

void CXenolaterView::OnFileUncomp() 
{
	CFileDialog dlg(FALSE);
	if (dlg.DoModal() ==IDOK){
		GetDocument()->SaveScript(dlg.GetPathName());
	}
}




int CXenolaterView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CEditView::OnCreate(lpCreateStruct) == -1)
		return -1;

	//Legge tutte le table inserite
	UINT i = 0;
	CString path;
	CString version = "Version 0.95";
	//decode
	while (i < 3)
	{
		CString entry;
		entry.Format("dec%d", i++);
		path = AfxGetApp()->GetProfileString(version, entry, ""); 
		if (path != "") m_decTable.Add(path);
	}
	
	m_nSelectedDecTable = AfxGetApp()->GetProfileInt(version, "SelectedTable", 0);
	LoadDecodeTable();
	//encode
	i = 0;
	while (i < 3)
	{
		CString entry;
		entry.Format("enc%d", i++);
		path = AfxGetApp()->GetProfileString(version, entry, ""); 
		if (path != "") m_encTable.Add(path);
	}
	
	m_nSelectedEncTable = AfxGetApp()->GetProfileInt(version, "SelectedEncTable", 0);
	LoadEncodeTable();

	GetDocument()->AutoCount = AfxGetApp()->GetProfileInt(version, "AutoCount", 0);
	//if (m_nSelectedEncTable > 0)
	//	GetDocument()->ReadTable(m_encTable[m_nSelectedEncTable - 1], TABLE_ENCODE);	

	m_pfntMain.CreatePointFont(100, "Courier New");
	GetEditCtrl().SetFont(&m_pfntMain);

	return 0;
}

void CXenolaterView::OnUpdateTableDecodeDefault(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(TRUE);
	pCmdUI->SetCheck(m_nSelectedDecTable == 0);
}

void CXenolaterView::OnUpdateDecodeRecent1(CCmdUI* pCmdUI) 
{
	if (m_decTable.GetSize() > 0)
	{
		pCmdUI->SetText(m_decTable[m_decTable.GetUpperBound()]);
		pCmdUI->Enable();
	}
	else
	{
		pCmdUI->SetText("(Empty)");
		pCmdUI->Enable(FALSE);
	}
	pCmdUI->SetCheck(m_nSelectedDecTable == 1);
}

void CXenolaterView::OnUpdateDecodeRecent2(CCmdUI* pCmdUI) 
{
	if (m_decTable.GetSize() > 1)
	{
		pCmdUI->SetText(m_decTable[m_decTable.GetUpperBound() - 1]);
		pCmdUI->Enable();
	}
	else
	{
		pCmdUI->SetText("(Empty)");
		pCmdUI->Enable(FALSE);
	}	
	pCmdUI->SetCheck(m_nSelectedDecTable == 2);
}

void CXenolaterView::OnUpdateDecodeRecent3(CCmdUI* pCmdUI) 
{
	if (m_decTable.GetSize() > 2)
	{
		pCmdUI->SetText(m_decTable[m_decTable.GetUpperBound() - 2]);
		pCmdUI->Enable();
	}
	else
	{
		pCmdUI->SetText("(Empty)");
		pCmdUI->Enable(FALSE);
	}	
	pCmdUI->SetCheck(m_nSelectedDecTable == 3);
}

void CXenolaterView::OnUpdateTableDecodeOther(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable();	
}

void CXenolaterView::OnTableDecodeOther() 
{
	CFileDialog dlg(TRUE);
	
	if (dlg.DoModal() == IDOK){
		m_decTable.Add(dlg.GetPathName());
		m_nSelectedDecTable = 1;
		LoadDecodeTable();
	}
}



void CXenolaterView::OnDecodeRecent1() 
{
	m_nSelectedDecTable = 1;
	LoadDecodeTable();
}

void CXenolaterView::OnDecodeRecent2() 
{
	m_nSelectedDecTable = 2;
	LoadDecodeTable();
}

void CXenolaterView::OnDecodeRecent3() 
{
	m_nSelectedDecTable = 3;
	LoadDecodeTable();
}

void CXenolaterView::OnTableDecodeDefault() 
{
	m_nSelectedDecTable = 0;
	LoadDecodeTable();
}

void CXenolaterView::LoadDecodeTable()
{
	if (m_nSelectedDecTable == 0)
	{
		GetDocument() ->m_decDictionary.RemoveAll();
	}
	else {
		GetDocument()->ReadTable(m_decTable[m_decTable.GetSize() - m_nSelectedDecTable], TABLE_DECODE);
	}
	if (GetDocument()->IsModified()){
		if (MessageBox("Discard changes and reload?", "Xenolater", MB_YESNO | MB_ICONQUESTION) == IDNO)
			return;
	}
	if (GetDocument()->MainFileDecrypter())
		GetEditCtrl() .SetWindowText(GetDocument()->strText);

	UINT i = 0;
	CString path;
	INT nSize = m_decTable.GetSize();
	CString version = "Version 0.95";
	while (i < 3)
	{
		CString entry;
		entry.Format("dec%d", i++);
		if ((INT)(nSize - 3 + i) > 0)
			AfxGetApp()->WriteProfileString(version, entry, m_decTable[nSize - 3 + i - 1]); 
	}	
	AfxGetApp()->WriteProfileInt(version, "SelectedTable", m_nSelectedDecTable); 
}







void CXenolaterView::OnUpdateEncodeRecent1(CCmdUI* pCmdUI) 
{
	if (m_encTable.GetSize() > 0)
	{
		pCmdUI->SetText(m_encTable[m_encTable.GetUpperBound()]);
		pCmdUI->Enable();
	}
	else
	{
		pCmdUI->SetText("(Empty)");
		pCmdUI->Enable(FALSE);
	}
	pCmdUI->SetCheck(m_nSelectedEncTable == 1);
}

void CXenolaterView::OnUpdateEncodeRecent2(CCmdUI* pCmdUI) 
{
	if (m_encTable.GetSize() > 1)
	{
		pCmdUI->SetText(m_encTable[m_encTable.GetUpperBound() - 1]);
		pCmdUI->Enable();
	}
	else
	{
		pCmdUI->SetText("(Empty)");
		pCmdUI->Enable(FALSE);
	}
	pCmdUI->SetCheck(m_nSelectedEncTable == 2);
	
}

void CXenolaterView::OnUpdateEncodeRecent3(CCmdUI* pCmdUI) 
{
	if (m_encTable.GetSize() > 2)
	{
		pCmdUI->SetText(m_encTable[m_encTable.GetUpperBound() - 2]);
		pCmdUI->Enable();
	}
	else
	{
		pCmdUI->SetText("(Empty)");
		pCmdUI->Enable(FALSE);
	}
	pCmdUI->SetCheck(m_nSelectedEncTable == 2);
	
}

void CXenolaterView::OnUpdateTableEncodeNone(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(TRUE);
	pCmdUI->SetCheck(m_nSelectedEncTable == 0);
}

void CXenolaterView::OnUpdateTableEncodeOther(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable();	
}

void CXenolaterView::OnEncodeRecent1() 
{
	m_nSelectedEncTable = 1;
	LoadEncodeTable();
}

void CXenolaterView::OnEncodeRecent2() 
{
	m_nSelectedEncTable = 2;
	LoadEncodeTable();
}

void CXenolaterView::OnEncodeRecent3() 
{
	m_nSelectedEncTable = 3;
	LoadEncodeTable();
}

void CXenolaterView::OnTableEncodeNone() 
{
	m_nSelectedEncTable = 0;
	LoadEncodeTable();
}

void CXenolaterView::OnTableEncodeOther() 
{
	CFileDialog dlg(TRUE);
	
	if (dlg.DoModal() == IDOK){
		m_encTable.Add(dlg.GetPathName());
		m_nSelectedEncTable = 1;
		LoadEncodeTable();
	}
}

void CXenolaterView::LoadEncodeTable()
{
	if (m_nSelectedEncTable == 0)
	{
		GetDocument() ->m_encDictionary.RemoveAll();
	}
	else {
		GetDocument()->ReadTable(m_encTable[m_encTable.GetSize() - m_nSelectedEncTable], TABLE_ENCODE);
	}

	UINT i = 0;
	CString path;
	INT nSize = m_encTable.GetSize();
	CString version = "Version 0.95";
	while (i < 3)
	{
		CString entry;
		entry.Format("enc%d", i++);
		if ((INT)(nSize - 3 + i) > 0)
			AfxGetApp()->WriteProfileString(version, entry, m_encTable[nSize - 3 + i - 1]); 
	}	
	AfxGetApp()->WriteProfileInt(version, "SelectedEncTable", m_nSelectedEncTable); 

}

void CXenolaterView::OnScriptImporta() 
{
	CFileDialog dlg(TRUE, "txt", GetDocument()->GetTitle(), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, "File di Testo (*.txt)|*.txt");
	
	if (dlg.DoModal() == IDOK)
	{
		CFile file(dlg.GetPathName(), CFile::modeRead | CFile::typeText);
		CArchive ar(&file, CArchive::load);
		
		CString text;
		CString string;
		while (ar.ReadString(string))
			text+= (string + "\r\n");
		GetEditCtrl() .SetWindowText(text);

		ar.Close();
		file.Close();
	}
	
}

void CXenolaterView::OnUpdateScriptImporta(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(GetDocument()->m_pDecompData != NULL);	
}

void CXenolaterView::OnScriptEsporta() 
{
	CFileDialog dlg(FALSE, "txt", GetDocument()->GetTitle(), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, "File di Testo (*.txt)|*.txt");
	
	if (dlg.DoModal() == IDOK)
	{
		CFile file(dlg.GetPathName(), CFile::modeWrite | CFile::modeCreate | CFile::typeText);
		CArchive ar(&file, CArchive::store);
		
		CString string;
		GetEditCtrl() .GetWindowText(string);
		ar.WriteString(string);

		ar.Close();
		file.Close();
	}
}

void CXenolaterView::OnUpdateScriptEsporta(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(GetDocument()->m_pDecompData != NULL);	
}

void CXenolaterView::OnUpdateScriptConteggioautomatico(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(GetDocument()->AutoCount);
}

void CXenolaterView::OnScriptConteggioautomatico() 
{
	GetDocument()->AutoCount = !(GetDocument()->AutoCount);
	AfxGetApp()->WriteProfileInt("Version 0.95", "AutoCount", GetDocument()->AutoCount);
}

void CXenolaterView::OnUpdateFileSave(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(GetDocument()->m_pFileData != NULL);	
}

void CXenolaterView::OnUpdateFileSaveAs(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(GetDocument()->m_pFileData != NULL);	
}

void CXenolaterView::OnModificaSelezionatutto() 
{
	CEdit &e = GetEditCtrl();
	CString txt;
	e.GetWindowText(txt);
	e.SetSel(0, txt.GetLength());
		
}

void CXenolaterView::OnUpdateModificaSelezionatutto(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(GetDocument()->m_pDecompData != NULL);	
	
}


void CXenolaterView::OnUpdateFileUncomp(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(GetDocument()->m_pDecompData != NULL);	
	
}
