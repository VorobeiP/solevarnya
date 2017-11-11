// dllmain.h: объ€вление класса модул€.

class CDriveExModule : public ATL::CAtlDllModuleT< CDriveExModule >
{
public :
	DECLARE_LIBID(LIBID_DriveExLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_DRIVEEX, "{D81AA214-E8BC-410C-AC5A-CAFFF00F9316}")
};

extern class CDriveExModule _AtlModule;
