#include <stdio.h>
#include <kernel.h>
#include <debug.h>

#include "memorydef.h"
#include "microprog.h"
#include "vifdef.h"

// Array that holds our vif packet
u32 vifdata[255];
int i = 0;

int main(void){

	// Get the size of our micro program
	u32 VU1codeSize = &vuESIN_CodeEnd - &vuESIN_CodeStart;
	u32 VU1codeBlocks = VU1codeSize / 2;

	// Wait for previous micro program (shouldn't be one honestly)
	//vifdata[i++] = VIFFLUSHE;
	vifdata[i++] = VIFNOP;
	vifdata[i++] = VIFMPG(VU1codeBlocks,0);

	// Put the micro program into the vif packet
	for(int codeSize = 0; codeSize < VU1codeSize; codeSize++){
		vifdata[i++] = ((u32*)&vuESIN_CodeStart)[codeSize];
	}

	// Activate the micro program
	vifdata[i++] = VIFMSCAL(0x0);
	// Wait for the micro program
	vifdata[i++] = VIFFLUSHE;

	// Set transfer source address and qword count
	VIF1MADR = (u32)&vifdata;
	VIF1QWC = (i / 4) + 1;

	FlushCache(0); 

	VIF1CHCR = 0x101; // Activate transfer

	FlushCache(0);  

	// Wait for DMA transfer
	while(VIF1CHCR & 0x100) {}

					// Change the iteration count based on the iterations in the micro program
	for(int i = 0; i < 20; i++)
	{
		u32 vuMemAddr = 0x1100C000 + (i * 0x10);
		printf("[iter %d] [VF01x %f] [VFO1y %f]\n",i,*(float*)(vuMemAddr),*(float*)(vuMemAddr + 4));
	}

	SleepThread();
}
