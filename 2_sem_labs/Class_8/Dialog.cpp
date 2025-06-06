#include "Dialog.h"
#include <iostream>
#include <string>

Dialog::Dialog(void) : List(0) {
    EndState = 0;
}

Dialog::~Dialog(void) {}

void Dialog::GetEvent(TEvent& event) {
    string OpInt = "+-?sqm";
    string s;
    string param;
    
    char code;
    cout << '>';
    cin >> s;
    code = s[0];
    
    if (OpInt.find(code) {
        event.what = evMessage;
        switch (code) {
            case 'm': event.command = cmMake; break;
            case '+': event.command = cmAdd; break;
            case '-': event.command = cmDel; break;
            case 's': event.command = cmShow; break;
            case '?': event.command = cmShowOne; break;
            case 'q': event.command = cmQuit; break;
        }
        
        if (s.length() > 1) {
            param = s.substr(1);
            int A = atoi(param.c_str());
            event.a = A;
        }
    } else {
        event.what = evNothing;
    }
}

int Dialog::Execute() {
    TEvent event;
    do {
        EndState = 0;
        GetEvent(event);
        HandleEvent(event);
    } while (!Valid());
    return EndState;
}

void Dialog::HandleEvent(TEvent& event) {
    if (event.what == evMessage) {
        switch (event.command) {
            case cmMake:
                size = event.a;
                head = nullptr;
                cur = 0;
                ClearEvent(event);
                break;
            case cmAdd:
                Add();
                ClearEvent(event);
                break;
            case cmDel:
                Del();
                ClearEvent(event);
                break;
            case cmShow:
                Show();
                ClearEvent(event);
                break;
            case cmShowOne:
                Show(event.a);
                ClearEvent(event);
                break;
            case cmQuit:
                EndExec();
                ClearEvent(event);
                break;
            default:
                List::HandleEvent(event);
        }
    }
}

void Dialog::ClearEvent(TEvent& event) {
    event.what = evNothing;
}

int Dialog::Valid() {
    return EndState;
}

void Dialog::EndExec() {
    EndState = 1;
}
