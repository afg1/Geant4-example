#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "G4UIExecutive.hh"
#include "G4VisExecutive.hh"
#include "G4ScoringManager.hh"


#include "DetectorConstruction.hh"
#include "Physics.hh"
#include "Initialization.hh"


int main(int argc, char** argv)
{
    // Create the run manager
    G4RunManager* runManager = new G4RunManager;

    // Set the mandatory initialization classes
    runManager->SetUserInitialization(new DetectorConstruction);
    runManager->SetUserInitialization(new Physics);
    runManager->SetUserInitialization(new Initialization);
    
    // Activate command based scorer
    G4ScoringManager::GetScoringManager();
    
    // Start the visualisation driver
    G4VisManager* visManager = new G4VisExecutive;
    visManager->Initialize();
    
    
    // Start an interactive GUI (if Qt is enabled)
    G4UIExecutive* ui = new G4UIExecutive(argc, argv);
    ui->SessionStart();
    delete ui;

    return 0;
}
