// xenolaterView.h : interface of the CXenolaterView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_XENOLATERVIEW_H__BBD548AC_8FC7_11D7_BD86_00E098852DE0__INCLUDED_)
#define AFX_XENOLATERVIEW_H__BBD548AC_8FC7_11D7_BD86_00E098852DE0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CXenolaterView : public CEditView
{
protected: // create from serialization only
	CXenolaterView();
	DECLARE_DYNCREATE(CXenolaterView)

// Attributes
public:
	CXenolaterDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CXenolaterView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// Implementation
public:
	void LoadEncodeTable();
	void LoadDecodeTable();
	INT m_nSelectedDecTable;
	INT m_nSelectedEncTable;
	CStringArray m_decTable;
	CStringArray m_encTable;
	virtual ~CXenolaterView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	CFont m_pfntMain;
	//{{AFX_MSG(CXenolaterView)
	afx_msg void OnChange();
	afx_msg void OnFileUncomp();
	afx_msg void OnUpdateTableDecodeDefault(CCmdUI* pCmdUI);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnUpdateDecodeRecent1(CCmdUI* pCmdUI);
	afx_msg void OnUpdateDecodeRecent2(CCmdUI* pCmdUI);
	afx_msg void OnUpdateDecodeRecent3(CCmdUI* pCmdUI);
	afx_msg void OnUpdateTableDecodeOther(CCmdUI* pCmdUI);
	afx_msg void OnTableDecodeOther();
	afx_msg void OnDecodeRecent1();
	afx_msg void OnDecodeRecent2();
	afx_msg void OnDecodeRecent3();
	afx_msg void OnTableDecodeDefault();
	afx_msg void OnUpdateEncodeRecent1(CCmdUI* pCmdUI);
	afx_msg void OnUpdateEncodeRecent2(CCmdUI* pCmdUI);
	afx_msg void OnUpdateEncodeRecent3(CCmdUI* pCmdUI);
	afx_msg void OnUpdateTableEncodeNone(CCmdUI* pCmdUI);
	afx_msg void OnUpdateTableEncodeOther(CCmdUI* pCmdUI);
	afx_msg void OnEncodeRecent1();
	afx_msg void OnEncodeRecent2();
	afx_msg void OnEncodeRecent3();
	afx_msg void OnTableEncodeNone();
	afx_msg void OnTableEncodeOther();
	afx_msg void OnScriptImporta();
	afx_msg void OnUpdateScriptImporta(CCmdUI* pCmdUI);
	afx_msg void OnScriptEsporta();
	afx_msg void OnUpdateScriptEsporta(CCmdUI* pCmdUI);
	afx_msg void OnUpdateScriptConteggioautomatico(CCmdUI* pCmdUI);
	afx_msg void OnScriptConteggioautomatico();
	afx_msg void OnUpdateFileSave(CCmdUI* pCmdUI);
	afx_msg void OnUpdateFileSaveAs(CCmdUI* pCmdUI);
	afx_msg void OnModificaSelezionatutto();
	afx_msg void OnUpdateModificaSelezionatutto(CCmdUI* pCmdUI);
	afx_msg void OnUpdateFileUncomp(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in xenolaterView.cpp
inline CXenolaterDoc* CXenolaterView::GetDocument()
   { return (CXenolaterDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_XENOLATERVIEW_H__BBD548AC_8FC7_11D7_BD86_00E098852DE0__INCLUDED_)
