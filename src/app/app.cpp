#include "app.h"
#include "../ui/MainFrame.h"

bool App::OnInit() {
    MainFrame* mainFrame = new MainFrame("Leitor de redes neurais", wxPoint(50, 50), wxSize(300, 300));
    mainFrame->Show(true);
    return true;
}