#include "stdafx.h"

// the program name
#define PROGNAME    "TypicalConsoleApp"

// the application
struct ConsoleApp {
    int                         m_argc;     // number of command line parameters
    char **                     m_argv;     // command line parameters

    std::vector<std::string>    m_items;    // target items
    std::string                 m_option;

    // constructor
    ConsoleApp(int argc, char **argv) : m_argc(argc), m_argv(argv) {
        m_option = "(none)";
    }

    // show help
    void show_help(void) {
        using namespace std;
        printf(PROGNAME " by katahiromz\n");
        printf("Usage: " PROGNAME " [options] files...\n");
        printf("Options:\n");
        printf("--help          Show this help\n");
        printf("--version       Show version info\n");
        printf("--option arg    Set optional option\n");
        printf("\n");
        printf("Copyright (C) 2015 katahiromz. All Rights Reserved.\n");
    }

    // show version
    void show_version(void) {
        using namespace std;
        printf(PROGNAME " 0.0 by katahiromz\n");
    }

    int run() {
        using namespace std;

        if (m_argc <= 1) {
            // there is no parameter
            show_help();
            return 0;
        }

        // parse command line
        for (int i = 1; i < m_argc; ++i) {
            // check every parameter
            std::string str = m_argv[i];
            if (str.size() && str[0] == '-') {
                // str is option
                if (str == "--help") {
                    show_help();
                    return 0;
                }
                if (str == "--version") {
                    show_version();
                    return 0;
                }
                if (str == "--option") {
                    if (i + 1 < m_argc) {
                        m_option = m_argv[++i];
                        continue;
                    } else {
                        fprintf(stderr, PROGNAME
                            ": ERROR: option '--option' requires a parameter\n");
                        return 2;
                    }
                }
                fprintf(stderr, PROGNAME ": ERROR: invalid option '%s'\n",
                    str.c_str());
                return 1;
            } else {
                // str is not option
                m_items.push_back(str);
            }
        }

        return just_do_it();
    } // run

    int just_do_it() {
        using namespace std;
        printf("--option: %s\n", m_option.c_str());
        for (size_t i = 0; i < m_items.size(); ++i) {
            printf("item #%d: %s\n", int(i), m_items[i].c_str());
        }
        return 0;
    } // just_do_it
}; // ConsoleApp

// the main function
int main(int argc, char **argv) {
    ConsoleApp app(argc, argv);
    int ret;
    try {
        ret = app.run();
    } catch (const std::bad_alloc&) {
        using namespace std;
        fprintf(stderr, PROGNAME ": ERROR: out of memory\n");
        ret = -1;
    }
#ifdef _MSC_VER
    // for detecting memory leak (MSVC only)
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
    return ret;
} // main
