#pragma once

#include <wx/wx.h>
#include "../core/InputProcessor.h"
#include <memory>

/*
*Painel de configuração
*/

class InputPanel : public wxPanel {
public: 
    InputPanel(wxWindow* parent, std::shared_ptr<IInputProcessor> processor);

    virtual ~InputPanel() = default;


private:

    wxTextCtrl* m_ipInput;
    wxTextCtrl* m_portInput;
    wxButton* m_connectButton;
    wxButton* m_searchButton;
    wxStaticText* m_resultButton;
    wxStaticText* m_resultText;

    //processador de entrada INJETADOOOO TOMAAA FALA DELEEEEEE
    std::shared_ptr<IInputProcessor> m_processor;

    void OnProcessClick(wxCommandEvent& event);
    void OnClearClick(wxCommandEvent& event);

    enum {
        ID_BUTTON_CONNECT = 100, 
        ID_BUTTON_SEARCH
    };

    wxDECLARE_EVENT_TABLE();
};