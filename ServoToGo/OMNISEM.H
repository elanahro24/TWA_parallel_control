//
// OmniSem.h
//
// A semaphore class that will work with VtoolsD in a Windows
// 95 VxD, with a Kernel Mode driver in NT, and with a console app
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
// 12 December 1997, Don McLane
//

#ifndef _OMNISEM_H_
#define _OMNISEM_H_

//#define DRIVER_TEST_PROGRAM


    #include <windows.h>
    //#include "C:\MATLAB6p5\sys\lcc\include\windows.h"

    /***************************************************************************/
    /*                                                                         */
    /*                        OmniSem for Win32                                */
    /*                                                                         */
    /***************************************************************************/
    class OmniSem
    {
        HANDLE hSemaphore;
        long lDupCount;
    public:
        OmniSem(long lCount);
        ~OmniSem();
        void Wait();
        void Signal();
        long Count();
    };

    class OmnEvent
    {
        HANDLE hEvent;
    public:
        OmnEvent();
        ~OmnEvent();
        void  Wait();
        void  MoveDone();
        void  MoveStart();
        DWORD Poll();
    };




#endif // _OMNISEM_H_
