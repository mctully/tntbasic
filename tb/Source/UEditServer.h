// **************************************************************************************************************************
// TNT Basic
// UEditServer.h
// � Mark Tully 2012
// 11/4/12
// **************************************************************************************************************************

/* ***** BEGIN LICENSE BLOCK *****
*
* Copyright (c) 2012, Mark Tully
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without modification,
* are permitted provided that the following conditions are met:
*
* * Redistributions of source code must retain the above copyright notice, this list
*   of conditions and the following disclaimer.
* * Redistributions in binary form must reproduce the above copyright notice, this
*   list of conditions and the following disclaimer in the documentation and/or other
*   materials provided with the distribution.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
* EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
* IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
* NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
* PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
* WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
* OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
* THE POSSIBILITY OF SUCH DAMAGE.
*
* ***** END LICENSE BLOCK ***** */

#ifndef __UEDITSERVER_H__
#define __UEDITSERVER_H__

#include "jansson.h"		// for json_t type, which can't be fwd declared

struct libwebsocket;

namespace UEditServer
{
	struct SCmdConnection
	{
		json_t					*curCmd;
		struct libwebsocket		*wsi;
	};

	typedef void (*TCmdCallback)(json_t *inCmd, SCmdConnection *inClient);


	void /*e*/		Initialise();
	void			Shutdown();

	void /*e*/		RegisterCmdHandler(
						const char			*inCommandName,
						TCmdCallback		inCallback);
	void /*e*/		UnregisterCmdHandler(
						const char			*inCommandName,
						TCmdCallback		inCallback);

	void /*e*/		OpenForEdit(
						FSSpec				*inSpec);

	void			Tick();
};

#endif
