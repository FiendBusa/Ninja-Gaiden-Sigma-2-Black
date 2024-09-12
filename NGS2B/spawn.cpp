#include "pch.h"
#include "src\spawn\spawn.h"
#include "src\spawn\globals.h"

void __attribute__((naked)) InjectC() {
	
	__asm__ volatile(".intel_syntax noprefix;"
		//ORIGINAL CODE
		"mov rcx,[rbx+0x10];"
		"mov rdx,r10;"
		"call qword ptr [rbx+0x08];"
		//INJECTED CODE
		"push rbx;"
		"cmp byte ptr [rip+canSpawn], 0x01;"
		"je spawnme;"
		"cmp byte ptr [rip+canspawn2], 0x01;"
		"je spawnme;"
		"jmp codec;"
	"spawnme:"
		"mov eax,0x02;"
	"codec:"
		"pop rbx;"
		"inc eax;"
		"cmp eax,0x07;"
		"jmp qword ptr [rip + returnInjectC];"

		);
	
}

