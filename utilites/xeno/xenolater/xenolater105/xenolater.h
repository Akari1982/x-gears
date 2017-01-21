// xenolater.h : main header file for the XENOLATER application
//

#if !defined(AFX_XENOLATER_H__BBD548A4_8FC7_11D7_BD86_00E098852DE0__INCLUDED_)
#define AFX_XENOLATER_H__BBD548A4_8FC7_11D7_BD86_00E098852DE0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CXenolaterApp:
// See xenolater.cpp for the implementation of this class
//

class CXenolaterApp : public CWinApp
{
public:
	CXenolaterApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CXenolaterApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CXenolaterApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_XENOLATER_H__BBD548A4_8FC7_11D7_BD86_00E098852DE0__INCLUDED_)
