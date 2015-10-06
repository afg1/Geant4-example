# Geant4-example
A (very) simple but powerful example of the Geant4 simulation system.

## Features
* Very simple geometry (a box of water inside a box of vacuum).
* Visualisation using OpenGL and a GUI using Qt4.
* Command based scoring.

## How to use
You will need the following:
* CMake 2.8+
* Geant4 10.1+ 
* Qt4
* openGL

To build, cd into the "build" directory and issue the following commands:

    cmake ../
    make 

You should than have an executable called G4-ex.exe. Run the application.

You should be presented with the Geant4 Qt GUI. A tutorial for the GUI is linked from the "Useful tips" page you start on. 
Commands are entered in the text box at the bottom of this window. To run the simulation, you can do:

    /run/initialize
    /control/execute vis.mac
    /control/execute source.mac
    /run/beamOn 1
  
This will generate the geometry and run a single particle into it. To use command based scorers, you will need to do a little more:

    (/run/initialize)
    /control/execute score.mac
    /vis/disable # Stops geant4 showing trajectories for everything
    /run/beamOn 2000
    /vis/enable
    /vis/scene/create
    /vis/sceneHandler/attach scene-2
    /score/drawProjection boxMesh_1 eDep
   

This will draw your geometry, and then overlay a representation of the energy deposited in it, along with a scale.

The command based scorers are incredibly powerful, and can be used to probe many things. Have a look at the documentation for them (or look though the help in the Geat4 Qt GUI).

This code was based on the examples shipped with the Geant4 toolkit, for further information (and better explanations) see the Geant4 examples.
