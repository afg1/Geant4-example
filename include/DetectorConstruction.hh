#ifndef DETECTOR_CONSTRUCTION_H
#define DETECTOR_CONSTRUCTION_H 1

#include "G4VUserDetectorConstruction.hh"

class G4LogicalVolume;
class G4PhysicalVolume;
class G4Material;
class G4Box;

class DetectorConstruction : public G4VUserDetectorConstruction
{
    public:
        DetectorConstruction();
        ~DetectorConstruction();

        G4VPhysicalVolume* Construct();
        void ConstructSDandField();

    private:
        G4LogicalVolume* worldLog;
        G4VPhysicalVolume* worldPhys;
    
        G4LogicalVolume* logicPhantom;
        G4VPhysicalVolume* physPhantom;
        G4Box* World;
        G4Box* phantom;
};
#endif
