//---------------------------------------------------------------------------
#ifndef FileExportH
#define FileExportH

#include "Main.h"
//---------------------------------------------------------------------------

class TExportThread : public TThread
{
public:
    TExportThread(bool CreateSuspended);
protected:
    void __fastcall Execute();
};

#endif
