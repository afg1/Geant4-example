#include "G4RunManager.hh"
#include "G4MTRunManager.hh"
#include "G4UImanager.hh"
#include "G4UIExecutive.hh"
#include "G4UIterminal.hh"
#include "G4UItcsh.hh"

#include "G4VisExecutive.hh"
#include "G4ScoringManager.hh"


#include "DetectorConstruction.hh"
#include "Physics.hh"
#include "Initialization.hh"


int main(int argc, char** argv)
{
    // Create the run manager
    #ifdef G4MULTITHREADED
    G4MTRunManager* runManager = new G4MTRunManager;
    #else
    G4RunManager* runManager = new G4RunManager;
    #endif

    // Set the mandatory initialization classes
    runManager->SetUserInitialization(new DetectorConstruction);
    runManager->SetUserInitialization(new Physics);
    runManager->SetUserInitialization(new Initialization);
    
        // Activate command based scorer
    G4ScoringManager::GetScoringManager();
    
    std::string macro;
    if(argc == 2)
    {
        macro = std::string(argv[1]);
    }
    
    // Start the visualisation driver
    #ifdef G4VIS_USE
    G4VisManager* visManager = new G4VisExecutive;
    visManager->Initialize();
    #endif
    
    
    if(argc == 1)
    {
        #ifdef G4UI_USE
        // Start an interactive GUI (if Qt is enabled)
        G4UIExecutive* ui = new G4UIExecutive(argc, argv);
        ui->SessionStart();
        delete ui;
        #else
        G4UIsession* ui = new G4UIterminal(new G4UItcsh);
        ui->SessionStart();
        delete ui;
        #endif
    }
    else
    {
        G4UImanager* UI = G4UImanager::GetUIpointer();
        UI->ExecuteMacroFile(macro.c_str());
    }
    return 0;
}
