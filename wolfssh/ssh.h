/* ssh.h
 *
 * Copyright (C) 2014 wolfSSL Inc.
 *
 * This file is part of wolfSSH.
 *
 * wolfSSH is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * wolfSSH is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA
 */


#pragma once

#include <wolfssh/settings.h>
#include <wolfssh/version.h>
#include <wolfssh/port.h>
#include <wolfssh/error.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct WOLFSSH_CTX  WOLFSSH_CTX;
typedef struct WOLFSSH      WOLFSSH;
typedef struct WOLFSSH_CHAN WOLFSSH_CHAN;

WOLFSSH_API int  wolfSSH_Init(void);
WOLFSSH_API int  wolfSSH_Cleanup(void);

/* debugging output functions */
WOLFSSH_API int  wolfSSH_Debugging_ON(void);
WOLFSSH_API void wolfSSH_Debugging_OFF(void);

WOLFSSH_API const char* wolfSSH_get_error(int);

/* I/O callbacks */
typedef int (*WS_CallbackIORecv)(WOLFSSH*, void* buf, uint32_t sz, void* ctx);
typedef int (*WS_CallbackIOSend)(WOLFSSH*, void* buf, uint32_t sz, void* ctx);

WOLFSSH_API void wolfSSH_SetIORecv(WOLFSSH_CTX*, WS_CallbackIORecv);
WOLFSSH_API void wolfSSH_SetIOSend(WOLFSSH_CTX*, WS_CallbackIOSend);

WOLFSSH_API void wolfSSH_SetIOReadCtx(WOLFSSH* ssh, void *ctx);
WOLFSSH_API void wolfSSH_SetIOWriteCtx(WOLFSSH* ssh, void *ctx);

WOLFSSH_API void* wolfSSH_GetIOReadCtx(WOLFSSH* ssh);
WOLFSSH_API void* wolfSSH_GetIOWriteCtx(WOLFSSH* ssh);



/* dynamic memory types */
enum WS_DynamicTypes {
    WOLFSSH_CTX_TYPE  = 1,
    WOLFSSH_TYPE      = 2,
    WOLFSSH_CHAN_TYPE = 3
};


/* defaults */
#ifndef WOLFSSH_PORT
    #define WOLFSSH_PORT 22222
#endif

#ifndef WOLFSSH_HOST
    #define WOLFSSH_HOST "localhost"
#endif

#ifdef __cplusplus
}
#endif
