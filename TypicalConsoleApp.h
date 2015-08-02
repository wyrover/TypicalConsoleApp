#ifndef TYPICALCONSOLEAPP_H
#define TYPICALCONSOLEAPP_H

// tstring
#ifdef UNICODE
    typedef std::wstring tstring;
#else
    typedef std::string tstring;
#endif

// the program name
#define PROGNAME "TypicalConsoleApp"

#endif  // ndef TYPICALCONSOLEAPP_H
