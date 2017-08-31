#include "ConsoleGui.h"
#include "InputControl.h"

int ConsoleGui::getMenuOption()
{
   showMenu();
   try {
      showMessage("Escolha a opção: ");
      int option= doInput();
      clearDisplay();
      return option;
   } catch(std::runtime_error e) {
      showMessage(e.what());
      getMenuOption();
   }
   return 0;
}

int ConsoleGui::getPlanesOnLand()
{
   try{
      showMessage("Número máximo de aviões em solo: ");
      int planesOnLand= doInput();
      clearDisplay();
      return planesOnLand;
   } catch(std::runtime_error e) {
      clearDisplay();
      showMessage(e.what());
      getPlanesOnLand();
   }
   return 0;
}

int ConsoleGui::doInput()
{
   int input= InputControl::processInput();
   showMessage("\n");
   return input; 
}

void ConsoleGui::showMenu()
{
   std::cout << "  Airport Simulation Menu \n"
   << "|-------------------------| \n"
   << "1. Número de aviões pousados até o momento \n"
   << "2. Número de aviões em solo \n"
   << "3. Número de aviões aguardando e quanto tempo está neste estado \n"
   << "4. Horários das mudanças de vento \n"
   << "5. Horários com aviões aguardando maior que 5 \n"
   << "6. Horários com aviões em solo maior que 70% da capacidade \n"
   << "7. Horários com aviões enviados a outros aerportos \n"
   << "8. Horários com solicitações para decolagens pendentes acima de 5 \n"
   << "50. Limpar tela\n"
   << "99. Exit \n\n";
}

