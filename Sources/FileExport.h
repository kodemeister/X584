﻿/*
 * Copyright (C) 2005-2025 X584 developers
 *
 * This file is part of X584.
 *
 * X584 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * X584 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with X584. If not, see <https://www.gnu.org/licenses/>.
 */

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
