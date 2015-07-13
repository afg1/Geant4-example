#include "Initialization.hh"

#include "Generator.hh"

Initialization::Initialization()
{
}

Initialization::~Initialization()
{
}

void Initialization::Build() const
{
    SetUserAction(new Generator);
}

void Initialization::BuildForMaster() const
{
}
