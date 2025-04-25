#include "InputPanel.h"

wxBEGIN_EVENT_TABLE(InputPanel, wxPanel)
    EVT_BUTTON(ID_BUTTON_CONNECT, InputPanel::OnProcessClick)
    EVT_BUTTON(ID_BUTTON_SEARCH, InputPanel::OnClearClick)
wxEND_EVENT_TABLE()


InputPanel::InputPanel(wxWindow* parent, std::shared_ptr<IInputProcessor> processor)
    : wxPanel(parent), m_processor(processor) {

    //config do layout principal 
    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);

    //criando os controles pro primeiro input 
    wxBoxSizer* ipSizer = new wxBoxSizer(wxHORIZONTAL);
    ipSizer->Add(new wxStaticText(this, wxID_ANY, "Insira o IP"), 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);
    m_ipInput = new wxTextCtrl(this, wxID_ANY);
    ipSizer->Add(m_ipInput, 1, wxALL | wxEXPAND, 5);
    mainSizer->Add(ipSizer, 0, wxEXPAND);

    wxBoxSizer* portSizer = new wxBoxSizer(wxHORIZONTAL);
    portSizer->Add(new wxStaticText(this, wxID_ANY, "Insira a porta"), 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);
    m_portInput = new wxTextCtrl(this, wxID_ANY);
    portSizer->Add(m_portInput, 1, wxALL | wxEXPAND, 5);
    mainSizer->Add(portSizer, 0, wxEXPAND);

    wxBoxSizer* buttonSizer = new wxBoxSizer(wxHORIZONTAL);
    m_connectButton = new wxButton(this, ID_BUTTON_CONNECT, "Conectar");
    m_searchButton = new wxButton(this, ID_BUTTON_SEARCH, "buscar");
    buttonSizer->Add(m_connectButton, 0, wxALL, 5);
    buttonSizer->Add(m_searchButton, 0, wxALL, 5);
    mainSizer->Add(buttonSizer, 0, wxALIGN_CENTER);

    wxBoxSizer* resultSizer = new wxBoxSizer(wxVERTICAL);
    resultSizer->Add(new wxStaticText(this, wxID_ANY, "Status:"), 0, wxALL, 5);
    m_resultText = new wxStaticText(this, wxID_ANY, "");
    mainSizer->Add(new wxStaticText(this, wxID_ANY, "Resultado"), 0, wxALL, 5);
    mainSizer->Add(m_resultText, 0, wxALL | wxEXPAND, 5);

    SetSizer(mainSizer);
    mainSizer->Fit(this);
}

void InputPanel::OnProcessClick(wxCommandEvent& event) {
    wxString ip = m_ipInput->GetValue();
    wxString port = m_portInput->GetValue();

    std::string result = m_processor->ProcessInput(ip.ToStdString(), port.ToStdString());

    m_resultButton->SetLabel(result);
}

void InputPanel::OnClearClick(wxCommandEvent& event) {
    m_resultText->SetLabel("Buscando....");
    std::string searchResult = "resultados da busca...";
    m_resultText->SetLabel(searchResult);
}