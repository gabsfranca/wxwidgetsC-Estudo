//pragma once serve pra que o compilador só leia esse arquivo 1 vez
#pragma once

#include <wx/wx.h>

/**
* Classe responsável pela inicialização da aplicação
*/

//aqui eu to definindo a classe app que herda wxApp
class App : public wxApp {
public:
    virtual bool OnInit() override;
};

//define a aplicação para o wxwidgets
wxIMPLEMENT_APP(App);