#ifndef DetectorConstruction_H
#define DetectorConstruction_H 1

#include "G4VUserDetectorConstruction.hh"
#include "Materials.hh"
#include "Experimental_Hall.hh"
#include "Experimental_Hall_Messenger.hh"
#include "CeBr3_Array.hh"
#include "CeBr3_Array_Messenger.hh"
#include "Cradle.hh"
#include "Cradle_Messenger.hh"
#include "Lead_Brick.hh"
#include "Lead_Brick_Messenger.hh"
#include "Lab_Bench.hh"
#include "Lab_Bench_Messenger.hh"
#include "Target.hh"
#include "Target_Messenger.hh"
#include "Source_Capsule.hh"
#include "Source_Capsule_Messenger.hh"
#include "Source_Cradle.hh"
#include "Source_Cradle_Messenger.hh"
#include "G4LogicalVolume.hh"
#include "G4VPhysicalVolume.hh"
#include "TrackerGammaSD.hh"
#include "TrackerGammaSD_Messenger.hh"
#include "G4SDManager.hh"
#include "G4Tubs.hh"

class DetectorConstruction : public G4VUserDetectorConstruction
{
public:

  DetectorConstruction();
  ~DetectorConstruction();

  G4VPhysicalVolume* Construct();
  Source_Capsule* getSourceCapsule(){return capsule;};
  Cradle* getCradle(){return cradle;};
  G4LogicalVolume* HallLog(){return ExpHall_log;};

private:
  
  CeBr3_Array* the_CeBr3_Array;

  Source_Capsule* capsule;
  Source_Cradle* source_cradle;
  Lead_Brick* brick;
  Lab_Bench* bench;
  Cradle* cradle;
  Target* target;

  // Logical volumes
  G4LogicalVolume* ExpHall_log;

  // Physical volumes
  G4VPhysicalVolume* ExpHall_phys;

  Experimental_Hall_Messenger* ExperimentalHallMessenger;
  TrackerGammaSD* TrackerGamma;
  TrackerGammaSD_Messenger* TrackerGammaSDMessenger;
  CeBr3_Array_Messenger* the_CeBr3_Array_Messenger;
  Source_Capsule_Messenger* capsule_Messenger;
  Source_Cradle_Messenger* source_cradle_Messenger;
  Lead_Brick_Messenger* brick_Messenger;
  Lab_Bench_Messenger* bench_Messenger;
  Cradle_Messenger* cradle_Messenger;
  Target_Messenger* target_Messenger;

  Materials* materials;
};

#endif
