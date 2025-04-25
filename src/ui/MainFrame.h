#pragma once

#include <wx/wx.h>
#include <memory>
#include "../core/InputProcessor.h"
#include "InputPanel.h"

/**
 * classe pra UI da janela principal da minha aplicação 
 */

class MainFrame : public wxFrame {
public: 
    MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size);

private:
    InputPanel* m_inputPanel;

    std::shared_ptr<IInputProcessor> m_processor;

    //metodo para configurar os menus
    void SetupMenuBar();

    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);

    enum {
        ID_MENU_EXIT = 1000,
        ID_MENU_ABOUT
    };

    wxDECLARE_EVENT_TABLE();
};