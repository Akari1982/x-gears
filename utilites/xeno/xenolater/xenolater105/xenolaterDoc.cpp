// xenolaterDoc.cpp : implementation of the CXenolaterDoc class
//

#include "stdafx.h"
#include "xenolater.h"

#include "xenolaterDoc.h"
#include ".\xenolaterdoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define MAX_WIDTH	34
#define MAX_HEIGHT	13

/////////////////////////////////////////////////////////////////////////////
// CXenolaterDoc

IMPLEMENT_DYNCREATE(CXenolaterDoc, CDocument)

BEGIN_MESSAGE_MAP(CXenolaterDoc, CDocument)
	//{{AFX_MSG_MAP(CXenolaterDoc)
	//}}AFX_MSG_MAP
	ON_COMMAND(ID_FILE_APRISOLOTESTO, OnFileAprisolotesto)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CXenolaterDoc construction/destruction

CXenolaterDoc::CXenolaterDoc()
{
	// TODO: add one-time construction code here
	m_pFileData = NULL;
	m_nDocLength = 0;
    m_pDecompData = NULL;
    m_nDecompLength = 0;
	AutoCount = FALSE;

}

CXenolaterDoc::~CXenolaterDoc()
{
}

BOOL CXenolaterDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	((CEditView*)m_viewList.GetHead())->SetWindowText(NULL);

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CXenolaterDoc serialization

void CXenolaterDoc::Serialize(CArchive& ar)
{
    if (ar.IsLoading ()) {
        CFile* pFile = ar.GetFile ();
        m_nDocLength = (UINT) pFile->GetLength ();

        //
        // Allocate a buffer for the file data.
        //
        try {
            m_pFileData = new BYTE[m_nDocLength];
        }
        catch (CMemoryException* e) {
            m_nDocLength = 0;
            throw e;
        }

        //
        // Read the file data into the buffer.
        //
        try {
            pFile->Read (m_pFileData, m_nDocLength);
        }
        catch (CFileException* e) {
            delete[] m_pFileData;
            m_pFileData = NULL;
            m_nDocLength = 0;
            throw e;
        }
    }
	else{
		//
        //Salvataggio
		//
		CFile* pFile = ar.GetFile ();
		pFile->Write(m_pFileData, m_nDocLength);		
	}
}

/////////////////////////////////////////////////////////////////////////////
// CXenolaterDoc diagnostics

#ifdef _DEBUG
void CXenolaterDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CXenolaterDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CXenolaterDoc commands

BOOL CXenolaterDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;
	
	UpdateAllViews(NULL);

	if (m_nDocLength == 0){
		AfxMessageBox("The file is empty");
		return FALSE;	
	}

	MainFileDecompressor();
	MainFileDecrypter();
	
	return TRUE;
}

BOOL CXenolaterDoc::MainFileDecompressor()
{
	//
	//Estrae il file numero 7 e lo decomprime
	//

	//
	//Legge offset e lunghezza reale
	//
	DWORD dwOffset = 0;
	DWORD dwTrueLength = 0;
	BYTE tempdata[4];
	memcpy(tempdata, m_pFileData + 0x130 + (7 * 4), 4);
	dwOffset = tempdata[0] + (tempdata[1] << 8) + (tempdata[2] << 16) + (tempdata[3] << 24);
	memcpy(tempdata, m_pFileData + 0x10C + (7 * 4), 4);
	dwTrueLength = tempdata[0] + (tempdata[1] << 8) + (tempdata[2] << 16) + (tempdata[3] << 24);

	/*
	//DBG
	DWORD dwOffset8 = 0;
	memcpy(tempdata, m_pFileData + 0x130 + (8 * 4), 4);
	dwOffset8 = tempdata[0] + (tempdata[1] << 8) + (tempdata[2] << 16) + (tempdata[3] << 24);
	if ((dwOffset8-dwOffset) % 4 == 0)
		AfxMessageBox("Multiplo di 4!");
	//end DBG
	*/

	DWORD initemp = dwOffset;

	//
	//Alloca un buffer per il file decompresso
	//
	try {
	    m_pDecompData = new BYTE[dwTrueLength];
    }
    catch (CMemoryException* e) {
		return FALSE;
        throw e;
    }
	m_nDecompLength = dwTrueLength;
	
	//
	//Decompressione
	//
	BYTE txtbuff[N];
	int r = 0;
	memset(txtbuff, 0, N);
	r = N - F;
	
	//
	//Leggi la lunghezza fittizia
	//
	DWORD dwFalseLength = 0;
	dwFalseLength |= m_pFileData[dwOffset];
	dwFalseLength |= (m_pFileData[dwOffset + 1] << 8);
	dwFalseLength |= (m_pFileData[dwOffset + 2] << 16);
	dwFalseLength |= (m_pFileData[dwOffset + 3] << 24);

	//
	//Alloca un buffer per il file decompresso temporaneo
	//
	BYTE* pTempData;
	try {
	    pTempData = new BYTE[dwFalseLength];
    }
    catch (CMemoryException* e) {
		return FALSE;
        throw e;
    }

	
	//
	//Inizio decompressione
	//
	dwOffset += 4;

	DWORD debug = 0;
	DWORD flagPos = 0;
	DWORD dwDestPos = 0;
	BYTE	shift = 0;
	while (dwDestPos != dwFalseLength){
		if (dwDestPos > dwFalseLength)
			TRACE("");
		//
		//Leggi la flag
		//
		BYTE	flag;
		flagPos = dwOffset;
		flag = m_pFileData[dwOffset++];
		//
		//Leggi tutti gli 8 bit della flag per capire se ho 
		//testo compresso o no.
		//Si parte dal bit meno significativo.
		//
		for(shift = 0; (shift < 8) /*&& (dwDestPos != dwFalseLength)*/; shift++){
			if((dwOffset) > 0x136B0)
				TRACE("");
			if((dwDestPos) == dwTrueLength)
				debug = shift;
			
			if ((flag & (1 << shift)) == 0){
				//Non compresso.
				//Copio un byte in uscita e nel memory buffer
				BYTE temp = 0;
				temp = m_pFileData[dwOffset++];
				pTempData[dwDestPos++] = temp;
				txtbuff[r++] = temp;
				r &= N - 1;
			}
			else{
				//Compresso
				//Leggo due byte e calcolo posizione e lunghezza
				//Formato: 7P 6P 5P 4P 3P 2P 1P 0P | 3L 2L 1L 0L 11P 10P 9P 8P
				BYTE temp = 0;
				WORD pos = 0;
				BYTE length = 0;
				
				//Genera posizione e lunghezza
				pos  = m_pFileData[dwOffset++];
				temp = m_pFileData[dwOffset++];
				pos |= ((temp & 0x0f) << 8);
				length = ((temp &0xf0) >> 4) + THRESHOLD;

				//Copia length byte in uscita e nel memory buffer
				for (UINT i = 0; i < length; i++){
					temp = txtbuff[((r - pos) & (N - 1))];
					pTempData[dwDestPos++] = temp;
					txtbuff[r++] = temp;
					r &= N - 1;
				}
			
			}

		}
	}
	/*----DEBUG----
	CString strTemp;
	strTemp.Format("Ultima flag a indirizzo %x: %X", flagPos, m_pFileData[flagPos]);
	AfxMessageBox(strTemp);
	strTemp.Format("dwOffset:%x dwOffset8:%x", dwOffset, dwOffset8);
	AfxMessageBox(strTemp);
	strTemp.Format("Lungh decompresso:%X Lunghezza Fittizia:%X Lunghezza reale:%X Differenza:%d", dwDestPos, dwFalseLength, dwTrueLength, dwFalseLength - dwTrueLength);
	AfxMessageBox(strTemp);
	strTemp.Format("Ho processato %d bit", shift);
	AfxMessageBox(strTemp);
	strTemp.Format("Dovrebbero esserci %d byte in +", 8-debug);
	AfxMessageBox(strTemp);
	*/
	//
	//Copia solo la lunghezza del reale del file
	//
	memcpy(m_pDecompData, pTempData, dwTrueLength);
	delete[] pTempData;

	//---DBG---
	
	//CFile file;
	//file.Open("xenodec.dat",CFile::modeCreate|CFile::modeReadWrite);
	//file.Write(m_pDecompData, m_nDecompLength);
	//file.Close();
	
	return TRUE;

}

void CXenolaterDoc::DeleteContents() 
{
    if (m_pFileData != NULL) {
        delete[] m_pFileData;
        m_pFileData = NULL;
        m_nDocLength = 0;
    }
    if (m_pDecompData != NULL) {
        delete[] m_pDecompData;
        m_pDecompData = NULL;
        m_nDecompLength = 0;
    }
	strText = "";
	
	CDocument::DeleteContents();
}

BOOL CXenolaterDoc::MainFileDecrypter()
{
	//
	//Routine principale per la decodifica del file decompresso.
	//Si occupa di identificare i blocchi di testo, estrarli e convertirli
	//in ascii
	//
	
	CWordArray arPointer;
	DWORD dwNumOfPointers;

	//Se non c'è testo esci
	if (m_nDecompLength == 0){
		//AfxMessageBox("Can't find any text!!!");
		return FALSE;
	}
	
	//Leggi il numero di puntatori
	dwNumOfPointers = (m_pDecompData[0] + (m_pDecompData[1] << 8) + (m_pDecompData[2] << 16) + (m_pDecompData[3] << 24)) + 1;
	arPointer.SetSize(0, dwNumOfPointers);

	//Leggi tutti i puntatori
	for(DWORD i=0; i<dwNumOfPointers; i++){
		WORD wPoint = 0;
		wPoint = m_pDecompData[4 + i * 2] + (m_pDecompData[4 + (i * 2) + 1] << 8);
		TRACE ("%x\n", wPoint);
		arPointer.Add(wPoint);
	}
	//Aggiungi l'ultimo pointer
	dwNumOfPointers++;
	arPointer.Add(m_nDecompLength);

	//Converti il testo in ascii
	strText = "";
	for (i=0; i < dwNumOfPointers -1; i++){
		//Loop su tutti i blocchi di testo
		
		//Inizia ogni blocco con <TextBlock + numero>
		CString strTemp;
		strTemp.Format ("<TextBlock %d w:%d h:%d>\r\n", i+1, m_pDecompData[(dwNumOfPointers - 1) * 2 + i * 2 + 4], m_pDecompData[(dwNumOfPointers - 1) * 2 + i * 2 + 4 + 1]);
		strText += strTemp;
		
		//Converti ogni carattere in ASCII e aggiungilo alla stringa
		for (WORD wIndex = arPointer[i]; wIndex < arPointer[i+1]; wIndex++){
			BYTE byTemp = 0;
			strTemp.Format("%.2X", m_pDecompData[wIndex]);
			if (m_decDictionary.Lookup(strTemp, strTemp))		//Dizionario
				strText += strTemp;
			else if (decrypt_OpCodes(&wIndex));					//OpCode
			else (decrypt_Default(m_pDecompData[wIndex]));		//Default
		}
		
		//Chiudi il blocco
		strText += "<End of Block>\r\n";
	
	}
	return TRUE;
}

BOOL CXenolaterDoc::MainFileEncrypter()
{
	//
	//Converto il testo contenuto in strText da ASCII alla
	//tabella utilizzata dal gioco
	//

	//
	//Alloca un buffer temporaneo di lunghezza strlen()
	//(Il file codificato sarà sicuramente <= di quello in ascii)
	//
	UINT nTempOffset = 0;
	BYTE* pTempData;
    try {
		pTempData = new BYTE[strText.GetLength()];
    }
    catch (CMemoryException* e) {
		throw e;
		return FALSE;
    }
	memset(pTempData, 0, strText.GetLength());

	//Copia i primi 4 byte così come sono (numero di pointer)
	memcpy(pTempData, m_pDecompData, 4);

	//Copia (per adesso) larghezza e numero di righe
	WORD wNumOfBlocks =  (m_pDecompData[0] + (m_pDecompData[1] << 8) + (m_pDecompData[2] << 16) + (m_pDecompData[3] << 24)) + 1;
	memcpy(pTempData + wNumOfBlocks * 2 + 4, m_pDecompData + wNumOfBlocks * 2 + 4, wNumOfBlocks * 2);

	//
	//Per ogni blocco trova l'inizio e la fine e converti
	//tutti i byte in mezzo
	//
	INT nStartPos = 0;
	INT nEndPos = 0;
	nTempOffset = m_pDecompData[4] + (m_pDecompData[5] << 8);
	for (UINT nCurrentBlock = 0; nCurrentBlock < wNumOfBlocks; nCurrentBlock++){
		//
		//Loop sui blocchi
		//
		//
		//Scrivi nella posizione opportuna il nuovo pointer
		//
		pTempData[nCurrentBlock  * 2 + 4] = (BYTE)(nTempOffset & 0xFF);
		pTempData[nCurrentBlock  * 2 + 4 + 1] = (BYTE)(nTempOffset >> 8);

		nStartPos = strText.Find("<TextBlock", nEndPos);
		nEndPos = strText.Find("<End of Block", nStartPos);

		//Controllo esistenza fine blocco
		if (nEndPos == -1){
			CString strTemp;
			strTemp.Format("Il blocco %d non ha una fine", nCurrentBlock+1);
			AfxMessageBox(strTemp);
		}


		//Trova la fine della stringa "<TextBlock  >"
		CString strBlock;
		while(strText[nStartPos] != '\n')
		{
			strBlock += strText[nStartPos++];
		}
		//Leggi i valori di altezza e larghezza
		INT n=0, w=0, h=0;
		sscanf(strBlock, "<TextBlock %d w:%d h:%d", &n, &w, &h);

		nStartPos++;
		INT max_width=0, max_height=0, width=0, height=0, inc_w=0;	//Per calcolare max larghezza e altezza
		for(INT nIndex = nStartPos; nIndex < nEndPos; nIndex++){
			//
			//Loop sui caratteri
			//
			//Inizia la conversione
			CString strTemp1;
			strTemp1 = strText[nIndex];
			//Verifico se nuova riga per contare larghezza e altezza
			if (strText[nIndex] == 0x0A)
			{
				//Nuova riga
				height++;
				if (width > MAX_WIDTH)
				{
					CString strErr;
					strErr.Format("Line Too Long in Text Block %d",n);
					AfxMessageBox(strErr);
				}
				if (width > max_width) max_width = width;
				width=0;
			}
			//Prima cerca nel dizionario
			if (m_encDictionary.Lookup(strTemp1, strTemp1))
			{
				WORD wVal = (WORD) strtol(strTemp1, NULL, 16);
				if (wVal & 0xFF00)
					pTempData[nTempOffset++] = (wVal & 0xFF00) >> 8;
				pTempData[nTempOffset++] = (BYTE) (wVal & 0xFF);
				width++;
			}
			//Altrimenti usa defualt
			else if((inc_w = encrypt_Default(strText[nIndex], pTempData, (WORD*)&nTempOffset)) != -1) width+=inc_w;
			//
			//Se invece leggo un < devo trovare un >
			//
			else if (strText[nIndex] == '<')
			{
				//Stringa "<...>"
				CString strTemp;
				//Ottengo la stringa
				while((strText[nIndex] != '>') && (nIndex<nEndPos))
					strTemp += strText[nIndex++];
				strTemp += strText[nIndex];
				if (strTemp == "<New>")
					nIndex +=2;
				//Verifico se nuova riga per contare larghezza e altezza
				if ((strTemp == "<Close>") || (strTemp == "<New>"))
				{
					//Nuova riga
					height++;
					if (height > MAX_HEIGHT)
					{
						CString strErr;
						strErr.Format("Too many lines in Text Block %d",n);
						AfxMessageBox(strErr);
					}
					if (height > max_height) max_height = height;
					height = 0;
					if (width > MAX_WIDTH)
					{
						CString strErr;
						strErr.Format("Line Too Long in Text Block %d",n);
						AfxMessageBox(strErr);
					}
					if (width > max_width) max_width = width;
					width=0;
				}
				//Cerco nel dizionario
				if (m_encDictionary.Lookup(strTemp, strTemp))
				{
					WORD wVal = (WORD) strtol(strTemp, NULL, 16);
					if (wVal & 0xFF00)
						pTempData[nTempOffset++] = (wVal & 0xFF00) >> 8;
					pTempData[nTempOffset++] = wVal & 0xFF;
					width += strTemp.GetLength() - 2;
				}
				//Altrimenti default
				else if ((inc_w = encrypt_Default(strTemp, pTempData,(WORD*) &nTempOffset)) != -1) width+=inc_w;
				//Infine negli opcode
				else if ((inc_w = encrypt_OpCodes(strTemp, pTempData, (WORD*)&nTempOffset))!= -1) width +=inc_w;
				//Altrimenti Errore!
				else
				{
					CString strErr;
					strErr.Format("Can't find appropiate code for %s in block %d", strTemp, n);
					AfxMessageBox(strErr);
					return FALSE;
				}
			}
			//Carattere non trovato!
			else
			{
				CString strTmpDft;
				strTmpDft.Format("Unsupported char detected %c in block %d", strText[nIndex],n);
				AfxMessageBox(strTmpDft);
				return FALSE;
			}
		
		}// loop sui caratteri
		//Verifico larghezza e altezza
/*	
		if (max_height != h)
		{
			CString strErr;
			strErr.Format("L' Altezza calcolata per il blocco %d è %d mentre quella specificata è %d.", nCurrentBlock + 1, max_height, h);
			AfxMessageBox(strErr);
		}
		if (max_width * 2 != w)
		{
			CString strErr;
			strErr.Format("La larghezza calcolata per il blocco %d è %d mentre quella specificata è %d.", nCurrentBlock + 1, max_width*2, w);
			AfxMessageBox(strErr);
		}
*/
		if (AutoCount)
		{
			pTempData[nCurrentBlock * 2 + wNumOfBlocks * 2 + 4] = max_width * 2;
			pTempData[nCurrentBlock * 2 + wNumOfBlocks * 2 + 4 + 1] = max_height;
		}
		else
		{
			pTempData[nCurrentBlock * 2 + wNumOfBlocks * 2 + 4] = w;
			pTempData[nCurrentBlock * 2 + wNumOfBlocks * 2 + 4 + 1] = h;
		}
			
	}//loop sui blocchi

	//
	//Alloca un nuovo Buffer e cancella quello temporaneo
	//
	delete[] m_pDecompData;
	m_pDecompData = NULL;
    try {
		m_pDecompData = new BYTE[nTempOffset];
    }
    catch (CMemoryException* e) {
		throw e;
		m_nDecompLength = 0;
		return FALSE;
    }
	m_nDecompLength = nTempOffset;
	memcpy(m_pDecompData, pTempData, nTempOffset);
	delete[] pTempData;


	
	return TRUE;
}

BOOL CXenolaterDoc::OnSaveDocument(LPCTSTR lpszPathName) 
{
	//
	//Esegue una serie elementare di controlli sul file,
	//Effettua la riconversione da ascii alla tabella del gioco,
	//Effettua la ricompressione.
	//
	
	
	//
	//Controlli sul file
	//

	INT nFindIndex = 0;
	UINT nNumOfStartingBlocks = 0;
	UINT nNumOfEndingBlocks = 0;
	nFindIndex = strText.Find("<TextBlock", 0);
	
	//Conta le frasi "<TextBlock"
	while(nFindIndex != -1){
		nNumOfStartingBlocks++;
		nFindIndex = strText.Find("<TextBlock", nFindIndex + 1);
	}
	nFindIndex = strText.Find("<End of Block", 0);
	
	//Conta le frasi "<End of Block>"
	while(nFindIndex != -1){
		nNumOfEndingBlocks++;
		nFindIndex = strText.Find("<End of Block", nFindIndex + 1);
	}
	
/*	//Verifica che ci siano tanti TextBlock quanti End of Block
	if (nNumOfStartingBlocks != nNumOfEndingBlocks){
		AfxMessageBox("<TextBlock > and <End Of Block> don't match!");
		return FALSE;
	}
*/	
	if(!MainFileEncrypter())
		return FALSE;
	if(!MainFileCompressor())
		return FALSE;

	MainFileDecrypter();
	UpdateAllViews(NULL);
	return CDocument::OnSaveDocument(lpszPathName);
}

BOOL CXenolaterDoc::MainFileCompressor()
{
	//
	//Comprime il buffer m_pDecompData creando un nuovo buffer e riscrivendolo
	//nel buffer m_pFileData
	//

	BYTE	MemoryBuff[N];
	BYTE	ReadAhead[F];
	INT		r = 0;
	memset(MemoryBuff, 0, N);
	memset(ReadAhead, 0, F);

	
	UINT nDecompPos = 0;

	//
	//Alloca un buffer temporaneo di lunghezza m_nDecompLength 
	//per contenere il file compresso
	//
	UINT nTempOffset = 0;
	BYTE* pTempData;
    try {
		pTempData = new BYTE[m_nDecompLength * 2];
    }
    catch (CMemoryException* e) {
		throw e;
		return FALSE;
    }
	memset(pTempData, 0, m_nDecompLength*2);
	nTempOffset = 4; //Salta i primi 4 byte (lunghezza fittizia file)
	UINT k =0;

	do{
		UINT nFlagPos = nTempOffset++;	//Salva la posizione della flag
		for (k = 0; (k < 8) && (nDecompPos < m_nDecompLength); k++){
			//Loop sugli 8 bite della flag
			
			if(nTempOffset >= 0x2da)
				TRACE("");


			//
			//Carica il read ahead con al più i 18 byte seguenti
			//
			UINT nEndOfReadAhead = (nDecompPos + F > m_nDecompLength) ? (m_nDecompLength - nDecompPos) : F;
			memcpy(ReadAhead, m_pDecompData + nDecompPos, nEndOfReadAhead);

			//
			//Effettua la ricerca sul memory buffer
			//
			BYTE nLungh = 0;
			INT nSearchPos = 0;
			//nLungh = lzss_Search(MemoryBuff, ReadAhead, &nSearchPos, r, nEndOfReadAhead);
			nLungh = lzss_Search(nDecompPos, &nSearchPos);
			if ((CHAR)nLungh == -1){
				//
				//Non ho trovato nulla nel memory buffer:
				//Copio un byte in uscita e nel memory buffer
				//
				pTempData[nTempOffset++] = ReadAhead[0];
				MemoryBuff[r++] = ReadAhead[0];
				r &= (N - 1);
				nDecompPos++;
			}
			else{
				//
				//Ho trovato qualcosa:
				//Copia puntatore-lunghezza in uscita e aggiorna il memory buffer
				//
				nSearchPos = (r - nSearchPos)  & 0xFFF;
				pTempData[nFlagPos] |= (1 << k);
				pTempData[nTempOffset++] = (BYTE)(nSearchPos & 0x00FF);
				pTempData[nTempOffset] = (BYTE)((nSearchPos & 0x0F00) >> 8);
				pTempData[nTempOffset++] += (BYTE)(((nLungh - THRESHOLD) & 0x000F) << 4);

				for (UINT it = 0; it < nLungh; it++){
					MemoryBuff[r++] = ReadAhead[it];
					r &= (N - 1);
				}
				nDecompPos += nLungh;
			}


		}
	}while(nDecompPos < m_nDecompLength);
	
	/*-----DEBUG----
	CString strTemp;
	strTemp.Format("Ho processato %d bit", k);
	AfxMessageBox(strTemp);
	*/
	//
	//Padda con degli 0 la fine del file
	//
	while (nTempOffset % 4 != 0)
		pTempData[nTempOffset++] = 0;
	
	while (k != 8){
		nDecompPos++;
		k++;
	}

	
	//Copia la lunghezza fittizia del file all'inizio
	DWORD dwTemp = nDecompPos;
	memcpy(pTempData, &dwTemp, 4);	



	//
	//Reinserisci il buffer pTempData nel file
	//
	
	//Calcola la nuova lunghezza
	DWORD dwNewFileLength = 0;
	DWORD dwOffset7 = m_pFileData[0x130 + 7 * 4] + (m_pFileData[0x130 + 7 * 4 + 1] << 8) + (m_pFileData[0x130 + 7 * 4 + 2] << 16) + (m_pFileData[0x130 + 7 * 4 + 3] << 24);
	DWORD dwOffset8 = m_pFileData[0x130 + 8 * 4] + (m_pFileData[0x130 + 8 * 4 + 1] << 8) + (m_pFileData[0x130 + 8 * 4 + 2] << 16) + (m_pFileData[0x130 + 8 * 4 + 3] << 24);
	dwNewFileLength = m_nDocLength - (dwOffset8 - dwOffset7) + nTempOffset;

	//Crea il nuovo buffer per il file
	BYTE* pTempComp;
    try {
		pTempComp = new BYTE[dwNewFileLength];
    }
    catch (CMemoryException* e) {
		throw e;
		return FALSE;
    }
	memset(pTempComp, 0, dwNewFileLength);
	
	//Copia dall'originale fino all'offset del file 7
	memcpy(pTempComp, m_pFileData, dwOffset7);

	//Copia il file 7
	memcpy(pTempComp + dwOffset7, pTempData, nTempOffset);

	//Copia il file 8
	memcpy(pTempComp + dwOffset7 + nTempOffset, m_pFileData + dwOffset8, m_nDocLength - dwOffset8);

	//Modifca il puntatore del file 8
	pTempComp[0x130 + 8 * 4 + 0] = (BYTE)(((dwOffset7 + nTempOffset) & 0x000000FF));
	pTempComp[0x130 + 8 * 4 + 1] = (BYTE)(((dwOffset7 + nTempOffset) & 0x0000FF00) >> 8);
	pTempComp[0x130 + 8 * 4 + 2] = (BYTE)(((dwOffset7 + nTempOffset) & 0x00FF0000) >> 16);
	pTempComp[0x130 + 8 * 4 + 3] = (BYTE)(((dwOffset7 + nTempOffset) & 0xFF000000) >> 24);
	
	//Modifca la lunghezza del file 7
	pTempComp[0x10C + 7 * 4 + 0] = (BYTE)((m_nDecompLength & 0x000000FF));
	pTempComp[0x10C + 7 * 4 + 1] = (BYTE)((m_nDecompLength & 0x0000FF00) >> 8);
	pTempComp[0x10C + 7 * 4 + 2] = (BYTE)((m_nDecompLength & 0x00FF0000) >> 16);
	pTempComp[0x10C + 7 * 4 + 3] = (BYTE)((m_nDecompLength & 0xFF000000) >> 24);

	//Cancella il vecchio file e riscrivi quello nuovo
	delete[] m_pFileData;
	m_pFileData = NULL;
	m_nDocLength = 0;
    try {
		m_pFileData = new BYTE[dwNewFileLength];
    }
    catch (CMemoryException* e) {
		throw e;
		return FALSE;
    }

	memcpy(m_pFileData, pTempComp, dwNewFileLength);
	m_nDocLength = dwNewFileLength;

	//Cancella i buffer inutili
	delete[] pTempComp;

	return TRUE;
}

INT CXenolaterDoc::lzss_Search(BYTE *MemBuff, BYTE *ReadBuff, INT *pos, UINT r, UINT nReadEnd)
{
	if (nSchifo > r)
		nSchifo = N;
	else
		nSchifo = r;
	TRACE("%d\n", nSchifo);

	
	//
	//Ricerca in MemBuff il ReadBuff
	//
	INT best_result = 0;
	UINT best_pos = 0;
	INT temp_result = 0;
	UINT i = 0, j = 0, k = 0;

	for (i=0; i< r; i++){
		temp_result = 0;
		k = 0;
		do{
			if ((MemBuff[i + k] == ReadBuff[k]) && (((i + k) < r) || (i > r)))
				temp_result++;
			else
				break;
			k++;
		}while(k < nReadEnd);
//
		if ((i + k) == r){
			j = 0;
			while (k < nReadEnd){
				if (ReadBuff[k] == ReadBuff[j++])
					temp_result++;
				else 
					break;
				k++;
			}
		}
//
		if (temp_result >= best_result){
			best_result= temp_result;
			best_pos=i;
		}
	}
	
	if ((best_result>=THRESHOLD))
	{
		*pos =best_pos;
		return(best_result);
	}

	return -1;

}

BOOL CXenolaterDoc::SaveScript(CString filename)
{
	
	INT nFindIndex = 0;
	UINT nNumOfStartingBlocks = 0;
	UINT nNumOfEndingBlocks = 0;
	nFindIndex = strText.Find("<TextBlock", 0);
	
	//Conta le frasi "<TextBlock"
	while(nFindIndex != -1){
		nNumOfStartingBlocks++;
		nFindIndex = strText.Find("<TextBlock", nFindIndex + 1);
	}
	nFindIndex = strText.Find("<End of Block", 0);
	
	//Conta le frasi "<End of Block>"
	while(nFindIndex != -1){
		nNumOfEndingBlocks++;
		nFindIndex = strText.Find("<End of Block", nFindIndex + 1);
	}
	
	//Verifica che ci siano tanti TextBlock quanti End of Block
	if (nNumOfStartingBlocks != nNumOfEndingBlocks){
		AfxMessageBox("<TextBlock > and <End Of Block> don't match!");
		return FALSE;
	}
	
	if(!MainFileEncrypter())
		return FALSE;

	CFile file;
	file.Open(filename, CFile::modeCreate|CFile::modeWrite);
	file.Write(m_pDecompData, m_nDecompLength);
	file.Close();
	return TRUE;
}




INT CXenolaterDoc::decrypt_OpCodes(WORD *wPos)
{
	WORD wIndex = *wPos;
	UINT res = 1;
	BYTE byTemp;
	CString strTemp;
	
	switch(m_pDecompData[wIndex])
	{
		case 0x00:
			strText += "<Close>";
			break;
		case 0x01:
			strText += "\r\n";
			break;
		case 0x02:
			strText += "<New>\r\n";
			break;
		case 0x03:
			strText += "<Wait>";
			break;
		case 0xFE:
			wIndex++;
			byTemp = m_pDecompData[wIndex];
			strTemp.Format("<Extra1 %d>", byTemp);
			strText += strTemp;
			break;
		case 0xFF:
			wIndex++;
			byTemp = m_pDecompData[wIndex];
			strTemp.Format("<Extra2 %d>", byTemp);
			strText += strTemp;
			break;
		case 0x0F:
			//Codifiche deiverse
			wIndex++;
			byTemp = m_pDecompData[wIndex];
			if (byTemp == 0){
				//Delay
				wIndex++;
				byTemp = m_pDecompData[wIndex];
				strTemp.Format("<Delay %d>", byTemp);
				strText += strTemp;
			}
			else if (byTemp == 5){
				//Delay
				wIndex++;
				byTemp = m_pDecompData[wIndex];
				switch(byTemp){
				case 0:
					strText += "<Fei>";
					break;
				case 1:
					strText += "<Elly>";
					break;
				case 2:
					strText += "<Citan>";
					break;
				case 3:
					strText += "<Bart>";
					break;
				case 4:
					strText += "<Billy>";
					break;
				case 5:
					strText += "<Rico>";
					break;
				case 6:
					strText += "<Emeralda>";
					break;
				case 7:
					strText += "<Chu-Chu>";
					break;
				case 8:
					strText += "<Maria>";
					break;
				case 9:
					strText += "<Citan2>";
					break;
				case 10:
					strText += "<Emeralda2>";
					break;
				case 11:
					strText += "<Weltall>";
					break;
				case 12:
					strText += "<Weltall-2>";
					break;
				case 13:
					strText += "<Vierge>";
					break;
				case 14:
					strText += "<Heimdal>";
					break;
				case 15:
					strText += "<Brigandier>";
					break;
				case 16:
					strText += "<Renmazuo>";
					break;
				case 17:
					strText += "<Stier>";
					break;
				case 18:
					strText += "<BigChu-chu>";
					break;
				case 19:
					strText += "<Seibzehn>";
					break;
				case 20:
					strText += "<Crescens>";
					break;
				case 21:
					strText += "<Regurus>";
					break;
				case 22:
					strText += "<Fenrir>";
					break;
				case 23:
					strText += "<Andvari>";
					break;
				case 24:
					strText += "<Renmazuo2>";
					break;
				case 25:
					strText += "<Stier-2>";
					break;
				case 26:
					strText += "<Xenogears>";
					break;
				case 27:
					strText += "<BARTHOS>";
					break;
				case 28:
					strText += "<Yggdra>";
					break;
				case 128:
					strText += "<Perso1>";
					break;
				case 129:
					strText += "<Perso2>";
					break;
				case 130:
					strText += "<Perso3>";
					break;
				default:
					strTemp.Format("<Char %d>",byTemp);
					strText += strTemp;
					break;
				}
			}
			else {
				BYTE byTemp2 = 0;
				wIndex++;
				byTemp2 = m_pDecompData[wIndex];
				strTemp.Format("<Opcode %d %d>",byTemp, byTemp2);
				strText += strTemp;
			}
			break;
			default:
				res = 0;	
				break;
	}
	
	*wPos = wIndex;
	return res;
}

BOOL CXenolaterDoc::ReadTable(CString filename, INT type)
{
	if (type == TABLE_DECODE) m_decDictionary.RemoveAll();
	if (type == TABLE_ENCODE) m_encDictionary.RemoveAll();

	CFile file;
	if (!file.Open(filename, CFile::modeRead)){
		filename = "Cannot Open file " + filename;
		AfxMessageBox(filename);
		return FALSE;
	}

	CArchive ar(&file, CArchive::load);

	CString temp;
	ar.ReadString(temp);
	while (temp != "")
	{
		INT index = temp.Find('=');
		if (index == -1){
			ar.ReadString(temp);
			continue;
		}

		CString val;
		CString text;

		val = temp.Mid(0, index);
		text = temp.Mid(index + 1, temp.GetLength() - index);
		if (type == TABLE_DECODE)
			m_decDictionary.SetAt(val, text);
		else
			m_encDictionary.SetAt(text,val);
		ar.ReadString(temp);
	}
	ar.Close();
	file.Close();
	return TRUE;
}

INT CXenolaterDoc::decrypt_Default(BYTE Val)
{
	//
	//Default Table
	//
	
	CString strTemp;

	if ((Val >= 0x16) && (Val <= 0x1F))
	{
		//0-9
		strTemp.Format("%d", (Val - 0x16));
		strText += strTemp;
	}
	else if ((Val >= 0x20) && (Val <= 0x39))
	{	
		//A-Z
		strText = strText+  (char)('A' + (Val - 0x20));
	}
	else if ((Val >= 0x3D) && (Val <= 0x56))
	{	
		//a-z
		strText = strText+ (char)('a' + (Val - 0x3D));
	}

	else
	{
		//Tutti gli altri simboli
		switch (Val){
		case 0x10:	
			strText += " "; 
			break;
		case 0x11:	
			strText += "+";	
			break;
		case 0x12:	
			strText += ",";
			break;
		case 0x13:
			strText += "-";
			break;
		case 0x14:	
			strText += ".";
			break;
		case 0x15:
			strText += "/";
			break;
		case 0x3A:
			strText += "[";
			break;
		case 0x3B:	
			strText += "]";
			break;
		case 0x3C:
			strText += "=";
			break;
		case 0x57:
			strText += "!";
			break;
		case 0x58:	
			strText += "\"";
			break;
		case 0x59:
			strText += "#";
			break;
		case 0x5A:	
			strText += "%";
			break;
		case 0x5B:
			strText += "&";
			break;
		case 0x5C:	
			strText += "'";
			break;
		case 0x5D:
			strText += "(";
			break;
		case 0x5E:
			strText += ")";
			break;
		case 0x5F:
			strText += ":";
			break;
		case 0x60:
			strText += "?";
			break;
		case 0x61:
			strText += "<0>";
			break;
		case 0x62:
			strText += "<1>";
			break;
		case 0x63:
			strText += "<2>";
			break;
		case 0x64:
			strText += "<3>";
			break;
		case 0x65:
			strText += "<4>";
			break;
		case 0x66:
			strText += "<5>";
			break;
		case 0x67:
			strText += "<6>";
			break;
		case 0x68:
			strText += "<7>";
			break;
		case 0x69:
			strText += "<8>";
			break;
		case 0x6A:
			strText += "<9>";
			break;
		case 0x6B:
			strText += "<%%>";
			break;
		case 0x6C:
			strText += "<&>";
			break;
		case 0x6D:
			strText += "*";
			break;
		case 0x6E:
			strText += "<C>";
			break;
		case 0x6F:
			strText += "<S>";
			break;
		case 0x70:
			strText += "<T>";
			break;
		case 0x71:
			strText += "<*>";
			break;
		case 0x72:
			strText += "<R>";
			break;
		case 0x73:
			strText += "<L>";
			break;
		case 0x74:
			strText += "<U>";
			break;
		case 0x75:
			strText += "<D>";
			break;
		case 0x76:
			strText += "<.>";
			break;
		case 0x77:
			strText += "<:>";
			break;
		case 0x79:
			strText += "</>";
			break;
		case 0x7A:
			strText += "<..>";
			break;
		case 0x7B:
			strText += "<`>";
			break;
		case 0x7D:
			strText += "<+>";
			break;
		case 0x7E:
			strText += "<->";
			break;
		case 0x7F:
			strText += "<X>";
			break;
		case 0x80:
			strText += "<[>";
			break;
		case 0x81:
			strText += "<]>";
			break;
		case 0x82:
			strText += "<%%>";
			break;
		case 0x83:
			strText += "<&>";
			break;
		case 0x84:
			strText += "<(>";
			break;
		case 0x85:
			strText += "<)>";
			break;
		case 0x86:
			strText += "<#>";
			break;
		case 0x87:
			strText += "<`>";
			break;
		case 0x88:
			strText += "<°>";
			break;
		case 0x89:
			strText += "<=>";
			break;
		case 0x8A:
			strText += "<?>";
			break;
		case 0x8B:
			strText += "<!>";
			break;
		case 0x8C:
			strText += "<_>";
			break;
		case 0x8D:
			strText += "<~>";
			break;
		case 0x8E:
			strText += "<...>";
			break;
		case 0x8F:
			strText += "<'>";
			break;
		default:
			strTemp.Format("<UNKNOWN CHUNK %d>", Val);
			strText += strTemp;
			break;
		}
	}
	return 1;
}

INT CXenolaterDoc::encrypt_OpCodes(CString strTemp, BYTE* pTempData, WORD *wPos)
{
	UINT nTempOffset = *wPos;
	INT byTemp=0;
	INT byTemp2=0;
	INT	nLen=0;

	if (strTemp == "<Close>")
		pTempData[nTempOffset++] = 0x00;
	else if (strTemp == "<New>")
	{
		pTempData[nTempOffset++] = 0x02;
	}
	else if (strTemp == "<Wait>")
		pTempData[nTempOffset++] = 0x03;
	else if (sscanf(strTemp, "<Delay %d>", &byTemp) == 1)
	{
		pTempData[nTempOffset++] = 0x0F;
		pTempData[nTempOffset++] = 0x00;
		pTempData[nTempOffset++] = byTemp;
	}
	else if (strTemp == "<Fei>")
	{
		pTempData[nTempOffset++] = 0x0F;
		pTempData[nTempOffset++] = 0x05;
		pTempData[nTempOffset++] = 0x00;
		nLen = 3;
	}
	else if (strTemp == "<Elly>")
	{
		pTempData[nTempOffset++] = 0x0F;
		pTempData[nTempOffset++] = 0x05;
		pTempData[nTempOffset++] = 0x01;
		nLen = 4;
	}
	else if (strTemp == "<Citan>")
	{
		pTempData[nTempOffset++] = 0x0F;
		pTempData[nTempOffset++] = 0x05;
		pTempData[nTempOffset++] = 0x02;
		nLen = 5;
	}
	else if (strTemp == "<Bart>"){
		pTempData[nTempOffset++] = 0x0F;
		pTempData[nTempOffset++] = 0x05;
		pTempData[nTempOffset++] = 0x03;
		nLen = 4;
	}
	else if (strTemp == "<Billy>")
	{
		pTempData[nTempOffset++] = 0x0F;
		pTempData[nTempOffset++] = 0x05;
		pTempData[nTempOffset++] = 0x04;
		nLen = 5;
	}
	else if (strTemp == "<Rico>")
	{
		pTempData[nTempOffset++] = 0x0F;
		pTempData[nTempOffset++] = 0x05;
		pTempData[nTempOffset++] = 0x05;
		nLen = 4;
	}
	else if (strTemp == "<Emeralda>")
	{
		pTempData[nTempOffset++] = 0x0F;
		pTempData[nTempOffset++] = 0x05;
		pTempData[nTempOffset++] = 0x06;
		nLen = 8;
	}
	else if (strTemp == "<Chu-Chu>")
	{
		pTempData[nTempOffset++] = 0x0F;
		pTempData[nTempOffset++] = 0x05;
		pTempData[nTempOffset++] = 0x07;
		nLen = 7;
	}
	else if (strTemp == "<Maria>")
	{
		pTempData[nTempOffset++] = 0x0F;
		pTempData[nTempOffset++] = 0x05;
		pTempData[nTempOffset++] = 0x08;
		nLen = 5;
	}
	else if (strTemp == "<Citan2>")
	{
		pTempData[nTempOffset++] = 0x0F;
		pTempData[nTempOffset++] = 0x05;
		pTempData[nTempOffset++] = 0x09;
		nLen = 5;
	}
	else if (strTemp == "<Emeralda2>")
	{
		pTempData[nTempOffset++] = 0x0F;
		pTempData[nTempOffset++] = 0x05;
		pTempData[nTempOffset++] = 0x0A;
		nLen = 8;
	}
	else if (strTemp == "<Weltall>")
	{
		pTempData[nTempOffset++] = 0x0F;
		pTempData[nTempOffset++] = 0x05;
		pTempData[nTempOffset++] = 0x0B;
		nLen = 7;
	}
	else if (strTemp == "<Weltall-2>")
	{
		pTempData[nTempOffset++] = 0x0F;
		pTempData[nTempOffset++] = 0x05;
		pTempData[nTempOffset++] = 0x0C;
		nLen = 7;
	}
	else if (strTemp == "<Vierge>")
	{
		pTempData[nTempOffset++] = 0x0F;
		pTempData[nTempOffset++] = 0x05;
		pTempData[nTempOffset++] = 0x0D;
		nLen = 6;
	}
	else if (strTemp == "<Heimdal>")
	{
		pTempData[nTempOffset++] = 0x0F;
		pTempData[nTempOffset++] = 0x05;
		pTempData[nTempOffset++] = 0x0E;
		nLen = 7;
	}
	else if (strTemp == "<Brigandier>")
	{
		pTempData[nTempOffset++] = 0x0F;
		pTempData[nTempOffset++] = 0x05;
		pTempData[nTempOffset++] = 0x0F;
		nLen = 9;
	}
	else if (strTemp == "<Renmazuo>")
	{
		pTempData[nTempOffset++] = 0x0F;
		pTempData[nTempOffset++] = 0x05;
		pTempData[nTempOffset++] = 0x10;
		nLen = 8;
	}
	else if (strTemp == "<Stier>")
	{
		pTempData[nTempOffset++] = 0x0F;
		pTempData[nTempOffset++] = 0x05;
		pTempData[nTempOffset++] = 0x11;
		nLen = 5;
	}
	else if (strTemp == "<BigChu-chu>")
	{
		pTempData[nTempOffset++] = 0x0F;
		pTempData[nTempOffset++] = 0x05;
		pTempData[nTempOffset++] = 0x12;
		nLen = 10;
	}
	else if (strTemp == "<Seibzehn>")
	{
		pTempData[nTempOffset++] = 0x0F;
		pTempData[nTempOffset++] = 0x05;
		pTempData[nTempOffset++] = 0x13;
		nLen = 8;
	}
	else if (strTemp == "<Crescens>")
	{
		pTempData[nTempOffset++] = 0x0F;
		pTempData[nTempOffset++] = 0x05;
		pTempData[nTempOffset++] = 0x14;
		nLen = 8;
	}
	else if (strTemp == "<Regurus>")
	{
		pTempData[nTempOffset++] = 0x0F;
		pTempData[nTempOffset++] = 0x05;
		pTempData[nTempOffset++] = 0x15;
		nLen = 7;
	}
	else if (strTemp == "<Fenrir>")
	{
		pTempData[nTempOffset++] = 0x0F;
		pTempData[nTempOffset++] = 0x05;
		pTempData[nTempOffset++] = 0x16;
		nLen = 6;
	}
	else if (strTemp == "<Andvari>")
	{
		pTempData[nTempOffset++] = 0x0F;
		pTempData[nTempOffset++] = 0x05;
		pTempData[nTempOffset++] = 23;
		nLen = 7;
	}
	else if (strTemp == "<Renmazuo2>")
	{
		pTempData[nTempOffset++] = 0x0F;
		pTempData[nTempOffset++] = 0x05;
		pTempData[nTempOffset++] = 24;
		nLen = 8;
	}
	else if (strTemp == "<Stier-2>")
	{
		pTempData[nTempOffset++] = 0x0F;
		pTempData[nTempOffset++] = 0x05;
		pTempData[nTempOffset++] = 25;
		nLen = 5;
	}
	else if (strTemp == "<Xenogears>")
	{
		pTempData[nTempOffset++] = 0x0F;
		pTempData[nTempOffset++] = 0x05;
		pTempData[nTempOffset++] = 26;
		nLen = 9;
	}
	else if (strTemp == "<BARTHOS>")
	{
		pTempData[nTempOffset++] = 0x0F;
		pTempData[nTempOffset++] = 0x05;
		pTempData[nTempOffset++] = 27;
		nLen = 7;
	}
	else if (strTemp == "<Yggdra>")
	{
		pTempData[nTempOffset++] = 0x0F;
		pTempData[nTempOffset++] = 0x05;
		pTempData[nTempOffset++] = 28;
		nLen = 6;
	}
	else if (strTemp == "<Perso1>")
	{
		pTempData[nTempOffset++] = 0x0F;
		pTempData[nTempOffset++] = 0x05;
		pTempData[nTempOffset++] = 128;
		nLen = 5;
	}
	else if (strTemp == "<Perso2>")
	{
		pTempData[nTempOffset++] = 0x0F;
		pTempData[nTempOffset++] = 0x05;
		pTempData[nTempOffset++] = 129;
		nLen = 5;
	}
	else if (strTemp == "<Perso3>")
	{
		pTempData[nTempOffset++] = 0x0F;
		pTempData[nTempOffset++] = 0x05;
		pTempData[nTempOffset++] = 130;
		nLen = 5;
	}
	else if (sscanf(strTemp, "<Char %d>", &byTemp) == 1)
	{
		pTempData[nTempOffset++] = 0x0F;
		pTempData[nTempOffset++] = 0x05;
		pTempData[nTempOffset++] = byTemp;
	}
	else if (sscanf(strTemp, "<Space %d>", &byTemp) == 1)
	{
		nLen = byTemp;
	}
	else if (sscanf(strTemp, "<Opcode %d %d>", &byTemp, &byTemp2) == 2)
	{
		pTempData[nTempOffset++] = 0x0F;
		pTempData[nTempOffset++] = byTemp;
		pTempData[nTempOffset++] = byTemp2;
	}
	else if (sscanf(strTemp, "<Extra1 %d>", &byTemp) == 1)
	{
		pTempData[nTempOffset++] = 0xFE;
		pTempData[nTempOffset++] = byTemp;
	}
	else if (sscanf(strTemp, "<Extra2 %d>", &byTemp) == 1)
	{
		pTempData[nTempOffset++] = 0xFF;
		pTempData[nTempOffset++] = byTemp;
	}
	else if (sscanf(strTemp, "<UNKNOWN CHUNK %d>", &byTemp) == 1)
	{
		pTempData[nTempOffset++] = byTemp;
	}
	else{
		return -1;
	}

	*wPos = (WORD)nTempOffset;
	return nLen;
}

INT CXenolaterDoc::encrypt_Default(CString val, BYTE *pTempData, WORD *wPos)
{
	UINT nTempOffset = *wPos;

	if (val[0] >= '0' && val[0] <= '9')	//0-9
		pTempData[nTempOffset++] = 0x16 + (val[0] - '0');
	else if (val[0] >= 'A' && val[0] <= 'Z')	//A-Z
		pTempData[nTempOffset++] = 0x20 + (val[0] - 'A');
	else if (val[0] >= 'a' && val[0]<= 'z')	//a-z
		pTempData[nTempOffset++] = 0x3D + (val[0] - 'a');
	else if (val == "<0>")
		pTempData[nTempOffset++] = 0x61;
	else if (val == "<1>")
		pTempData[nTempOffset++] = 0x62;
	else if (val == "<2>")
		pTempData[nTempOffset++] = 0x63;
	else if (val == "<3>")
		pTempData[nTempOffset++] = 0x64;
	else if (val == "<4>")
		pTempData[nTempOffset++] = 0x65;
	else if (val == "<5>")
		pTempData[nTempOffset++] = 0x66;
	else if (val == "<6>")
		pTempData[nTempOffset++] = 0x67;
	else if (val == "<7>")
		pTempData[nTempOffset++] = 0x68;
	else if (val == "<8>")
		pTempData[nTempOffset++] = 0x69;
	else if (val == "<9>")
		pTempData[nTempOffset++] = 0x6A;
	else if (val == "<%>")
		pTempData[nTempOffset++] = 0x6B;
	else if (val == "<&>")
		pTempData[nTempOffset++] = 0x6C;
	else if (val == "<C>")
		pTempData[nTempOffset++] = 0x6E;
	else if (val == "<S>")
		pTempData[nTempOffset++] = 0x6F;
	else if (val == "<T>")
		pTempData[nTempOffset++] = 0x70;
	else if (val == "<*>")
		pTempData[nTempOffset++] = 0x71;
	else if (val == "<R>")
		pTempData[nTempOffset++] = 0x72;
	else if (val == "<L>")
		pTempData[nTempOffset++] = 0x73;
	else if (val == "<U>")
		pTempData[nTempOffset++] = 0x74;
	else if (val == "<D>")
		pTempData[nTempOffset++] = 0x75;
	else if (val == "<.>")
		pTempData[nTempOffset++] = 0x76;
	else if (val == "<:>")
		pTempData[nTempOffset++] = 0x77;
	else if (val == "<..>")
		pTempData[nTempOffset++] = 0x79;
	else if (val == "<..>")
		pTempData[nTempOffset++] = 0x7A;
	else if (val == "<`>")
		pTempData[nTempOffset++] = 0x7B;
	else if (val == "<+>")
		pTempData[nTempOffset++] = 0x7D;
	else if (val == "<->")
		pTempData[nTempOffset++] = 0x7E;
	else if (val == "<X>")
		pTempData[nTempOffset++] = 0x7F;
	else if (val == "<[>")
		pTempData[nTempOffset++] = 0x80;
	else if (val == "<]>")
		pTempData[nTempOffset++] = 0x81;
	else if (val == "<%%>")
		pTempData[nTempOffset++] = 0x82;
	else if (val == "<&>")
		pTempData[nTempOffset++] = 0x83;
	else if (val == "<(>")
		pTempData[nTempOffset++] = 0x84;
	else if (val == "<)>")
		pTempData[nTempOffset++] = 0x85;
	else if (val == "<#>")
		pTempData[nTempOffset++] = 0x86;
	else if (val == "<`>")
		pTempData[nTempOffset++] = 0x87;
	else if (val == "<°>")
		pTempData[nTempOffset++] = 0x88;
	else if (val == "<=>")
		pTempData[nTempOffset++] = 0x89;
	else if (val == "<?>")
		pTempData[nTempOffset++] = 0x8A;
	else if (val == "<!>")
		pTempData[nTempOffset++] = 0x8B;
	else if (val == "<_>")
		pTempData[nTempOffset++] = 0x8C;
	else if (val == "<~>")
		pTempData[nTempOffset++] = 0x8D;
	else if (val == "<...>")
		pTempData[nTempOffset++] = 0x8E;
	else if (val == "<'>")
		pTempData[nTempOffset++] = 0x8F;
	else{
		//Punteggiatura e altro
	switch (val[0]){
		case 0x20:
			pTempData[nTempOffset++] = 0x10;
		break;
		case '+':
			pTempData[nTempOffset++] = 0x11;
		break;
		case 0x0A:
			pTempData[nTempOffset++] = 0x01;
			*wPos = nTempOffset;
			return 0; //non incrementare il numero di caratteri per riga
		break;
		case ',':
			pTempData[nTempOffset++] = 0x12;
		break;
		case '-':
			pTempData[nTempOffset++] = 0x13;
		break;
		case '.':
			pTempData[nTempOffset++] = 0x14;
		break;
		case '/':
			pTempData[nTempOffset++] = 0x15;
		break;
		case '[':
			pTempData[nTempOffset++] = 0x3A;
		break;
		case ']':
			pTempData[nTempOffset++] = 0x3B;
		break;
		case '=':
			pTempData[nTempOffset++] = 0x3C;
		break;
		case '!':
			pTempData[nTempOffset++] = 0x57;
		break;
		case '"':
			pTempData[nTempOffset++] = 0x58;
		break;
		case '#':
			pTempData[nTempOffset++] = 0x59;
		break;
		case '%':
			pTempData[nTempOffset++] = 0x5A;
		break;
		case '&':
			pTempData[nTempOffset++] = 0x5B;
		break;
		case '\'':
			pTempData[nTempOffset++] = 0x5C;
		break;
		case '(':
			pTempData[nTempOffset++] = 0x5D;
		break;
		case ')':
			pTempData[nTempOffset++] = 0x5E;
		break;
		case ':':
			pTempData[nTempOffset++] = 0x5F;
		break;
		case '?':
			pTempData[nTempOffset++] = 0x60;
		break;
		case 13://A capo (già trattato con 0x0A)
		case 0:
			return 0;
		break;
		default:
			return -1;
		break;
		}
	}
	*wPos = nTempOffset;
	return 1;
	
}

INT CXenolaterDoc::lzss_Search(UINT nCurrent, INT *nFind)
{
	//Ricerca v2

	//Determina il massimo valore di k
	INT maxk;
	maxk = nCurrent + F > m_nDecompLength ? m_nDecompLength - nCurrent : F; //m_nDecompLength - 1 ???

	//Determina la posizione iniziale
	UINT nStart;
	nStart = (INT)nCurrent - (N-F) < 0 ? 0 : nCurrent - (N-F);
	
	UINT nPos = nStart;
	INT best_pos = -1;
	INT best_length = THRESHOLD - 1;
	//Ricerca
	while (nPos < nCurrent)
	{
		INT k = 0;
		while ((m_pDecompData[nPos + k] == m_pDecompData[nCurrent + k]) && (k < maxk))
		{
			k++;
		}
		if (k > best_length)
		{
			best_length = k;
			best_pos = nPos;
		}
		nPos++;
	}

	if (best_pos != -1)
	{
		*nFind = (best_pos & (N - 1));
		return best_length;
	}
	else
		return -1;
}



void CXenolaterDoc::OnFileAprisolotesto()
{
	DeleteContents();

	CFileDialog dlg(TRUE);

	

	if (dlg.DoModal()==IDOK){
		CFile file;
		file.Open(dlg.GetPathName(), CFile::modeRead);
		m_nDecompLength = (UINT)file.GetLength();
		m_nDocLength = m_nDecompLength;
		m_pDecompData = new BYTE[m_nDecompLength];
		file.Read(m_pDecompData,m_nDecompLength);
		file.Close();

		MainFileDecrypter();
	}

	UpdateAllViews(NULL);

	return;

}
