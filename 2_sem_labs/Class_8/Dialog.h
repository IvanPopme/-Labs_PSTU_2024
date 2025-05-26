#pragma once
#include "List.h"

class Dialog : public List {
public:
    Dialog(void);
    ~Dialog(void);
    
    void GetEvent(TEvent& event);
    int Execute();
    void HandleEvent(TEvent& event);
    void ClearEvent(TEvent& event);
    
    int Valid();
    void EndExec();
    
protected:
    int EndState;
};
