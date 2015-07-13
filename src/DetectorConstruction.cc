#include "DetectorConstruction.hh"

#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4NistManager.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"


DetectorConstruction::DetectorConstruction():worldLog(NULL), worldPhys(NULL), logicPhantom(NULL), physPhantom(NULL)
{
}

DetectorConstruction::~DetectorConstruction()
{
}


G4VPhysicalVolume* DetectorConstruction::Construct()
{
    G4NistManager* matMan = G4NistManager::Instance();
    G4Material* vac = matMan->FindOrBuildMaterial("G4_Galactic");// For the world
    G4Material* h2o = matMan->FindOrBuildMaterial("G4_WATER");// For the phantom

    // Construction of the world
    // Create the world, default material is vaccuum
    G4double world_dim = 2000.*mm;
    World = new G4Box("world", world_dim, world_dim, world_dim);
    worldLog = new G4LogicalVolume(World, vac, "worldLog");
    worldPhys = new G4PVPlacement(0, G4ThreeVector(),worldLog,"world1",0,false,0);
    

    G4double phantom_dim = 1000.*mm;
    
    phantom = new G4Box("phantom", phantom_dim, phantom_dim, phantom_dim);
    logicPhantom = new G4LogicalVolume(phantom, h2o, "Phantom", 0, 0, 0);
    physPhantom = new G4PVPlacement(0, G4ThreeVector(), logicPhantom, "Phantom", worldLog, false, 0);

    return worldPhys;
}


void DetectorConstruction::ConstructSDandField()
{

}



