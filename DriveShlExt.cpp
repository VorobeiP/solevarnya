
// DriveShlExt.cpp: реализация CDriveShlExt


#include "stdafx.h"
#include "DriveShlExt.h"

#pragma comment(lib, "shlwapi.lib")
#pragma comment(lib, "comctl32.lib")



BOOL CALLBACK PropPageDlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg) {
	case WM_INITDIALOG:

		PROPSHEETPAGE*  ppsp = (PROPSHEETPAGE*)lParam;
		LPCTSTR         szFile = (LPCTSTR)ppsp->lParam;
		HANDLE          hFind;
		WIN32_FIND_DATA rFind;
		wchar_t autStr[] = L"\\autorun.inf";
		int len = wcslen(szFile) + wcslen(autStr);
		wchar_t *m_szFilename = new wchar_t[len + 4];
		wcscpy(m_szFilename, szFile);
		wcscat(m_szFilename, autStr);
		HANDLE hFile = CreateFile(m_szFilename,
								  GENERIC_READ,
								  FILE_SHARE_READ,
								  NULL,
								  OPEN_EXISTING,
								  FILE_ATTRIBUTE_NORMAL,
								  NULL);
		if (INVALID_HANDLE_VALUE == hFile) {
			PathSetDlgItemPath(hwnd, IDC_TEXT, L"не труЪ");
		} else { 
			PathSetDlgItemPath(hwnd, IDC_TEXT, L"труЪ"); }

		break;

	}

	return FALSE;
}

UINT CALLBACK PropPageCallbackProc(HWND hwnd, UINT uMsg, LPPROPSHEETPAGE ppsp) {
	if (PSPCB_RELEASE == uMsg) {
		free((void*)ppsp->lParam);
	}

	return 1;                           // used for PSPCB_CREATE - let the page be created
}

HRESULT CDriveShlExt::Initialize(LPCITEMIDLIST pidlFolder,
								 LPDATAOBJECT  pDataObj,
								 HKEY          hProgID) {
	TCHAR     szFile[MAX_PATH];
	UINT      uNumFiles;
	HDROP     hdrop;
	FORMATETC etc = { CF_HDROP, NULL, DVASPECT_CONTENT, -1, TYMED_HGLOBAL };
	STGMEDIUM stg;
	INITCOMMONCONTROLSEX iccex = { sizeof(INITCOMMONCONTROLSEX), ICC_DATE_CLASSES };

	// Init the common controls.
	InitCommonControlsEx(&iccex);

	if (FAILED(pDataObj->GetData(&etc, &stg)))
		return E_INVALIDARG;

	// Get an HDROP handle.

	hdrop = (HDROP)GlobalLock(stg.hGlobal);

	if (NULL == hdrop) {
		ReleaseStgMedium(&stg);
		return E_INVALIDARG;
	}

	// Determine how many files are involved in this operation.

	uNumFiles = DragQueryFile(hdrop, 0xFFFFFFFF, NULL, 0);

	for (UINT uFile = 0; uFile < uNumFiles; uFile++) {
		// Get the next filename.
		if (0 == DragQueryFile(hdrop, uFile, szFile, MAX_PATH))
			continue;
		if (PathIsDirectory(szFile))
			continue;

		// Add the filename to our list o' files to act on.

		m_lsFiles.push_back(szFile);
	}   // end for

		// Release resources.

	GlobalUnlock(stg.hGlobal);
	ReleaseStgMedium(&stg);

	// Check how many files were selected.  If the number is greater than the
	// maximum number of property pages, truncate our list.

	if (m_lsFiles.size() > MAXPROPPAGES) {
		m_lsFiles.resize(MAXPROPPAGES);
	}

	// If we found any files we can work with, return S_OK.  Otherwise,
	// return E_FAIL so we don't get called again for this right-click
	// operation.

	return (m_lsFiles.size() > 0) ? S_OK : E_FAIL;
}


/////////////////////////////////////////////////////////////////////////////
// CFileTimeShlExt IShellPropSheetExt methods

HRESULT CDriveShlExt::AddPages(LPFNADDPROPSHEETPAGE lpfnAddPageProc,
							   LPARAM lParam) {
	PROPSHEETPAGE  psp;
	HPROPSHEETPAGE hPage;
	TCHAR          szPageTitle[MAX_PATH];
	string_list::const_iterator it, itEnd;

	for (it = m_lsFiles.begin(), itEnd = m_lsFiles.end();
		 it != itEnd;
		 it++) {
		LPCTSTR szFile = _tcsdup(it->c_str());

		if (NULL == szFile)
			return E_OUTOFMEMORY;


		lstrcpy(szPageTitle, L"Bool autorun.inf");
		szPageTitle[24] = '\0';

		// Set up the PROPSHEETPAGE struct.

		ZeroMemory(&psp, sizeof(PROPSHEETPAGE));

		psp.dwSize = sizeof(PROPSHEETPAGE);
		psp.dwFlags = PSP_DEFAULT | PSP_USETITLE | PSP_USECALLBACK;
		psp.pszTemplate = MAKEINTRESOURCE(IDD_PROPPAGE);
		psp.hIcon = 0;
		psp.hInstance = _AtlBaseModule.GetModuleInstance();
		psp.pszTitle = szPageTitle;
		psp.pfnDlgProc = (DLGPROC)PropPageDlgProc;
		psp.lParam = (LPARAM)szFile;
		psp.pfnCallback = PropPageCallbackProc;
		psp.pcRefParent = NULL;

		// Create the page & get a handle.

		hPage = CreatePropertySheetPage(&psp);

		/*if (NULL != hPage) {
			// Call the shell's callback function, so it adds the page to
			// the property sheet.
			if (!lpfnAddPageProc(hPage, lParam)) {
				DestroyPropertySheetPage(hPage);
			}
		}*/
	}   // end for

	return S_OK;
}

