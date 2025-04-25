#include "MainFrame.h"

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_MENU(ID_MENU_EXIT, MainFrame::OnExit)
    EVT_MENU(ID_MENU_ABOUT, MainFrame::OnAbout)
wxEND_EVENT_TABLE()

MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
    : wxFrame(nullptr, wxID_ANY, title, pos, size) {
    
    SetupMenuBar();

    m_processor = std::make_shared<InputProcessor>();
    
    m_inputPanel = new InputPanel(this, m_processor);
    
    CreateStatusBar();
    SetStatusText("Bem-vindo ao wxWidgets SOLID Demo");
}

void MainFrame::SetupMenuBar() {
    wxMenu* menuFile = new wxMenu;
    menuFile->Append(ID_MENU_ABOUT, "&Sobre\tF1", "Mostrar informações sobre esta aplicação");
    menuFile->AppendSeparator();
    menuFile->Append(ID_MENU_EXIT, "S&air\tAlt-X", "Fechar esta aplicação");
    
    wxMenuBar* menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&Arquivo");
    
    SetMenuBar(menuBar);
}

void MainFrame::OnExit(wxCommandEvent& event) {
    Close(true);
}

void MainFrame::OnAbout(wxCommandEvent& event) {
    wxMessageBox("bucetinha suja",
                 "teste", wxOK | wxICON_INFORMATION);
}
