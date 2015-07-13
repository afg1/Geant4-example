#include "Physics.hh"

#include "G4EmStandardPhysics.hh"
#include "G4EmProcessOptions.hh"
#include "G4HadronPhysicsQGSP_BIC.hh"
#include "G4DecayPhysics.hh"
#include "G4SystemOfUnits.hh"



//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....
//
Physics::Physics(): G4VUserPhysicsList()
{
    defaultCutValue = 0.25*mm;
    cutForGamma = defaultCutValue;
    cutForElectron = defaultCutValue;
    cutForPositron = defaultCutValue;
    cutForProton = defaultCutValue;


    emPhysicsList = new G4EmStandardPhysics(0);
    hadrPhysicsList = new G4HadronPhysicsQGSP_BIC(0);
    decayPhysicsList = new G4DecayPhysics(0);
}
//
////....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....
//
Physics::~Physics()
{
    delete emPhysicsList;
    delete hadrPhysicsList;
    delete decayPhysicsList;
    emPhysicsList = NULL;
    hadrPhysicsList = NULL;
    decayPhysicsList = NULL;
    
}
//
////....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....
//
void Physics::ConstructParticle()
{
    emPhysicsList->ConstructParticle();
    hadrPhysicsList->ConstructParticle();
    decayPhysicsList->ConstructParticle();

}
//
////....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....
//
void Physics::ConstructProcess()
{
    AddTransportation();
    emPhysicsList->ConstructProcess();
    hadrPhysicsList->ConstructProcess();
    decayPhysicsList->ConstructProcess();

}


//
////....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....
//
void Physics::SetCuts()
{
    SetCutsWithDefault();
}

void Physics::SetCutsForRegion(G4double aCut, const G4String& rname)
{
    SetCutValue(aCut, "gamma", rname);
    SetCutValue(aCut, "e-", rname);
    SetCutValue(aCut, "e+", rname);
    SetCutValue(aCut, "proton", rname);
}
//

