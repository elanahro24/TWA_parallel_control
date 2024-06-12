//
// ms-or-bc.h
//
// We attempt to have all the differences between the Microsoft
// and Borland compilers taken care of here.  The attempt isn't
// a total success, but most differences are here.
//
// Added linux too.

#ifndef __MS_OR_BC_H__
#define __MS_OR_BC_H__

//define one or the other below:
//
// no don't hardcode it here anymore.  Do it automatically!
//
//#define __MICROSOFT_DOS__
//#define __BORLAND_DOS__

//#define STG_LINUX

#ifdef __MICROSOFT_DOS__

    /*lint -esym(534, _outp, _outpw) suppress some lint messages */

    #include <dos.h>
    #include <conio.h>

    #define __CPPARGS void
    #define BOOL int

    inline void fOutP(unsigned short port, unsigned char data)
    {
       _outp(port, data);
    }

    inline void fOutPW(unsigned short port, unsigned short data)
    {
       _outpw(port, data);
    }

    inline unsigned char fInP(unsigned short port)
    {
       return _inp(port);
    }

    inline unsigned short fInPW(unsigned short port)
    {
       return _inpw(port);
    }

#endif  // __MICROSOFT_DOS__

#ifdef __BORLAND_DOS__

    #include <dos.h>
    #include <conio.h>

    #define BOOL bool
    #define __CPPARGS ...
    #define cdecl

    inline void fOutP(unsigned short port, unsigned char data)
    {
       outp(port, data);  //lint !e534  ignoring return value
    }

    inline void fOutPW(unsigned short port, unsigned short data)
    {
       outpw(port, data);  //lint !e534  ignoring return value
    }

    inline unsigned char fInP(unsigned short port)
    {
       return inp(port);    //lint !e734  loss of precision, return value
    }

    inline unsigned short fInPW(unsigned short port)
    {
       return inpw(port);
    }

#endif  // __BORLAND_COMPILER

#ifdef STG_LINUX

    #define __CPPARGS void
    #define far
    #define cdecl
    #define interrupt
    #define BOOL bool

    #include <asm/io.h>
    #include <sys/io.h>

    extern "C" {
        void init_misc();
        void close_misc();
        int kbhit();
        int readch();
        int readche();
    }  // extern "C"

    inline int getche() {return readche();}
    inline int getch()  {return readch();}

    inline void fOutP(unsigned short port, unsigned char data)
    {
       outb(data, port);
    }

    inline void fOutPW(unsigned short port, unsigned short data)
    {
       outw(data, port);
    }

    inline unsigned char fInP(unsigned short port)
    {
       return inb(port);
    }

    inline unsigned short fInPW(unsigned short port)
    {
       return inw(port);
    }

#endif  // STG_LINUX

#endif  // __MS_OR_BC_H__
