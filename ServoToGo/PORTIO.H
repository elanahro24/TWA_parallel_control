//
// portio.h -- defines the functions which talk directly to I/O ports,
//             they differ in 95 and NT
//
//    Copyright (C) 2000 Servo To Go, Inc.
//    8117 Groton Ln.
//    Indianapolis, IN  46260
//    phone: 317-506-8843, fax: 317-251-3958
//
//    This program is free software; you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation; version 2 of the License.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program; if not, write to the Free Software
//    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//
// For linting, this is sort-of a library, so turn off messages about
// things not being used.  I don't make it a real library, because the
// warning level is different for real libraries.
//lint -e755 -e756 -e757 -e758 -e769


/*
#if defined( VTOOLSD ) || defined ( DRIVER_TEST_PROGRAM )  || defined ( NO_TEST_PROGRAM )
// if we're making the Windows 95 driver
//
// The function to write to an I/O port is different for different OS's,
// compilers, etc.  Specify it here.  I use an inline function, instead
// of a macro for improved type checking.
//

#if defined ( DRIVER_TEST_PROGRAM ) || defined ( NO_TEST_PROGRAM )
#include <conio.h>
#endif
*/


#include <conio.h>
//void fOutP(unsigned short port, unsigned char data)
void fOutP(unsigned short port, int data)
{
	_outp(port, data);
}

void fOutPW(unsigned short port, unsigned short data)
{
	_outpw(port, data);
}

//unsigned char fInP(unsigned short port)
int fInP(unsigned short port)
{
	return _inp(port);
}

unsigned short fInPW(unsigned short port)
{
		  return _inpw(port);
}


/*
#else        // we're making the Windows NT driver

extern "C"
{
#include <ntddk.h>
#ifdef _lint
	// lint will have choked on ntddk.h (because microsoft produced a royally screwed up
	// header file).  Some things won't be defined, so we'll just define them here.
#include "ioproto.l"
#endif  // _lint
	
				// these should be inline, but there seem to be some problems (MS bug?)
				
	//#define fOutP(a, b)  WRITE_PORT_UCHAR( (unsigned char *)(a), (b) )
	
	inline void fOutP(unsigned short port, unsigned char data)
	{
		WRITE_PORT_UCHAR( (unsigned char *)port, data);
	}
	
	//#define fOutPW(a, b)  WRITE_PORT_USHORT( (unsigned short *)(a), (b) )
	
	inline void fOutPW(unsigned short port, unsigned short data)
	{
		WRITE_PORT_USHORT( (unsigned short *)port, data);
	}
	
	//#define fInP(a)  READ_PORT_UCHAR( (unsigned char *)(a) )
	
	inline unsigned char fInP(unsigned short port)
	{
		return READ_PORT_UCHAR( (unsigned char *)port);
	}
	
	//#define fInPW(a)  READ_PORT_USHORT( (unsigned short *)(a) )
	
	inline unsigned short fInPW(unsigned short port)
	{
								return READ_PORT_USHORT( (unsigned short *)port);
	}
} // extern "C"
#endif  //VTOOLSD

inline void ToggleSpeaker(void)
{
	// toggle the speaker for audio output
	fOutP( 0x61, 0x02 ^ fInP(0x61) );
}


//lint -restore
*/