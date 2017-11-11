// DriveShlExt.h: объявление CDriveShlExt

#pragma once
#include "resource.h"       // основные символы
#include <comdef.h>
#include <shlobj.h>
#include <list>  

#include "DriveEx_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Однопотоковые COM-объекты не поддерживаются должным образом платформой Windows CE, например платформами Windows Mobile, в которых не предусмотрена полная поддержка DCOM. Определите _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA, чтобы принудить ATL поддерживать создание однопотоковых COM-объектов и разрешить использование его реализаций однопотоковых COM-объектов. Для потоковой модели в вашем rgs-файле задано значение 'Free', поскольку это единственная потоковая модель, поддерживаемая не-DCOM платформами Windows CE."
#endif

using namespace ATL;


// CDriveShlExt

class ATL_NO_VTABLE CDriveShlExt :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CDriveShlExt, &CLSID_DriveShlExt>,
	public IDispatchImpl<IDriveShlExt, &IID_IDriveShlExt, &LIBID_DriveExLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	public IShellExtInit,
	public IShellPropSheetExt {
public:
	CDriveShlExt() {

	}

	DECLARE_REGISTRY_RESOURCEID(IDR_DRIVESHLEXT)


	BEGIN_COM_MAP(CDriveShlExt)
		COM_INTERFACE_ENTRY(IDriveShlExt)
		COM_INTERFACE_ENTRY(IShellExtInit)
		COM_INTERFACE_ENTRY(IShellPropSheetExt)
	END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct() {
		return S_OK;
	}

	void FinalRelease() {
	}

	typedef std::list<std::basic_string<TCHAR> > string_list;

protected:
	// IFileTimeShlExt
	string_list m_lsFiles;

public:
	// IShellExtInit
	STDMETHOD(Initialize)(LPCITEMIDLIST, LPDATAOBJECT, HKEY);

	// IShellPropSheetExt
	STDMETHOD(AddPages)(LPFNADDPROPSHEETPAGE, LPARAM);
	STDMETHOD(ReplacePage)(UINT, LPFNADDPROPSHEETPAGE, LPARAM) {
		return E_NOTIMPL;
	}

};

OBJECT_ENTRY_AUTO(__uuidof(DriveShlExt), CDriveShlExt)
