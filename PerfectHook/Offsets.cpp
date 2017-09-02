
#include "Offsets.h"
#include "Utilities.h"

void Offsets::Initialise()
{
	// Modules
	Modules::Client = U::WaitOnModuleHandle("client.dll");
	Modules::Engine = U::WaitOnModuleHandle("engine.dll");
	Modules::VGUI2 = U::WaitOnModuleHandle("vgui2.dll");
	Modules::VGUISurface = U::WaitOnModuleHandle("vguimatsurface.dll");
	Modules::Material = U::WaitOnModuleHandle("materialsystem.dll");
	Modules::VPhysics = U::WaitOnModuleHandle("vphysics.dll");
	Modules::Stdlib = U::WaitOnModuleHandle("vstdlib.dll");
//	Modules::InputSystem = U::WaitOnModuleHandle("inputsystem.dll");
	Modules::scaleformui = U::WaitOnModuleHandle("scaleformui.dll");
	Modules::cache = U::WaitOnModuleHandle("datacache.dll");

	Functions::KeyValues_KeyValues = U::FindPattern("client.dll", (PBYTE)"\x68\x00\x00\x00\x00\x8B\xC8\xE8\x00\x00\x00\x00\x89\x45\xFC\xEB\x07\xC7\x45\x00\x00\x00\x00\x00\x8B\x03\x56", "x????xxx????xxxxxxx?????xxx");
	Functions::KeyValues_KeyValues += 7;
	Functions::KeyValues_KeyValues = Functions::KeyValues_KeyValues + *reinterpret_cast< PDWORD_PTR >(Functions::KeyValues_KeyValues + 1) + 5;

    Functions::KeyValues_LoadFromBuffer = (DWORD)U::pattern_scan(GetModuleHandleW(L"client.dll"), "55 8B EC 83 E4 F8 83 EC 34 53 8B 5D 0C 89 4C 24 04");

	Functions::dwCalcPlayerView = U::FindPattern("client.dll", (PBYTE)"\x84\xC0\x75\x08\x57\x8B\xCE\xE8\x00\x00\x00\x00\x8B\x06", "xxxxxxxx????xx");

}

namespace Offsets
{
	// Addresses of loaded game modules
	namespace Modules
	{
		DWORD Client;
		DWORD Engine;
		DWORD VGUI2;
		DWORD VGUISurface;
		DWORD Material;
		DWORD VPhysics;
		DWORD Stdlib;
		DWORD cache;
		//DWORD InputSystem;
		DWORD scaleformui;
	};


	// Addresses of engine functions to call
	namespace Functions
	{
		DWORD KeyValues_KeyValues;
		DWORD KeyValues_LoadFromBuffer;
		DWORD dwCalcPlayerView;
	};



};