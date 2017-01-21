// xenolaterDoc.h : interface of the CXenolaterDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_XENOLATERDOC_H__BBD548AA_8FC7_11D7_BD86_00E098852DE0__INCLUDED_)
#define AFX_XENOLATERDOC_H__BBD548AA_8FC7_11D7_BD86_00E098852DE0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#define	N			4096
#define F			18
#define THRESHOLD	3
#define NIL			N	/* index for root of binary search trees */

#define TABLE_DECODE 1
#define TABLE_ENCODE 2

class CXenolaterDoc : public CDocument
{
protected: // create from serialization only
	CXenolaterDoc();
	DECLARE_DYNCREATE(CXenolaterDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CXenolaterDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual void DeleteContents();
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CXenolaterDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CXenolaterDoc)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	BOOL ReadTable(CString filename, INT type);
	CMapStringToString m_decDictionary;
	CMapStringToString m_encDictionary;
	BOOL AutoCount;
	BOOL SaveScript(CString filename);
	BOOL MainFileCompressor();
	BOOL MainFileEncrypter();
	BOOL MainFileDecrypter();
	CString strText;
	BOOL MainFileDecompressor();
	UINT m_nDocLength;
	UINT m_nDecompLength;
	BYTE* m_pFileData;
	BYTE* m_pDecompData;
private:
	INT lzss_Search(UINT nCurrent, INT* nFind);
	INT encrypt_Default(CString val, BYTE* pTempData, WORD* wPos);
	INT encrypt_OpCodes(CString strTemp, BYTE* pTempData, WORD* wPos);
	INT decrypt_Default(BYTE Val);
	INT decrypt_OpCodes(WORD* wPos);
	UINT nSchifo;
	INT lzss_Search(BYTE *MemBuff, BYTE *ReadBuff, INT *pos, UINT r, UINT nReadEnd);

public:
	afx_msg void OnFileAprisolotesto();
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_XENOLATERDOC_H__BBD548AA_8FC7_11D7_BD86_00E098852DE0__INCLUDED_)
