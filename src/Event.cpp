#include "Event.h"



void Saltador::CridaEmit()
{
	JumpEvent.Emit(33);
}

void Saltador::Update()
{

	JumpEvent.Connect(this, &Saltador::HeSaltat);
}

void Saltador::CridaEmitPublic()
{
	CridaEmit();
}
