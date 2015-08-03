#ifndef TYPICALCONSOLEAPP_H
#define TYPICALCONSOLEAPP_H

// tstring
#ifdef UNICODE
    typedef std::wstring tstring;
#else
    typedef std::string tstring;
#endif

#endif  // ndef TYPICALCONSOLEAPP_H
