/*bool SetupMoserDeBruijn(){
	memset(colors, 0, 0x400 * 4);

	for(uint32_t counter = 0; counter<0x400; counter++){
	
		//unk1 eax
		//unk2 edx
		//unk3 esi
		//unk4 ecx
		//loc_5115EB
		uint32_t unk1 = (counter >> 1) & 0x55555555;
		uint32_t unk3 = (unk1 * 2) ^ counter;
		uint32_t unk4 = ((unk3 >> 2) & 0x33333333) ^ ((counter >> 1) & 0x11111111);

		unk1 ^= unk4;
		unk3 ^= (unk4 << 2);

		unk4 = ((unk3 >> 4) & 0x0F0F0F0F) ^ (unk1 & 0x0F0F0F0F);
		unk1 ^= unk4;
		unk3 ^= (unk4 << 4);
		
		unk4 = ((unk3 >> 8) & 0x00FF00FF) ^ (unk1 & 0x00FF00FF);
		
		colors[counter] = (((unk4 & 0xFF) << 8) ^ (unk3 & 0xFFFF)) | ((unk4 ^ unk1) << 16);	
		
	}

	return true;
}*/

//Moser De Bruijn sequence, thanks to NoFate for telling me this
unsigned char _bruijn[0x400 * 4] = {
	0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
	0x05, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00,
	0x14, 0x00, 0x00, 0x00, 0x15, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00,
	0x41, 0x00, 0x00, 0x00, 0x44, 0x00, 0x00, 0x00, 0x45, 0x00, 0x00, 0x00,
	0x50, 0x00, 0x00, 0x00, 0x51, 0x00, 0x00, 0x00, 0x54, 0x00, 0x00, 0x00,
	0x55, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00,
	0x04, 0x01, 0x00, 0x00, 0x05, 0x01, 0x00, 0x00, 0x10, 0x01, 0x00, 0x00,
	0x11, 0x01, 0x00, 0x00, 0x14, 0x01, 0x00, 0x00, 0x15, 0x01, 0x00, 0x00,
	0x40, 0x01, 0x00, 0x00, 0x41, 0x01, 0x00, 0x00, 0x44, 0x01, 0x00, 0x00,
	0x45, 0x01, 0x00, 0x00, 0x50, 0x01, 0x00, 0x00, 0x51, 0x01, 0x00, 0x00,
	0x54, 0x01, 0x00, 0x00, 0x55, 0x01, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00,
	0x01, 0x04, 0x00, 0x00, 0x04, 0x04, 0x00, 0x00, 0x05, 0x04, 0x00, 0x00,
	0x10, 0x04, 0x00, 0x00, 0x11, 0x04, 0x00, 0x00, 0x14, 0x04, 0x00, 0x00,
	0x15, 0x04, 0x00, 0x00, 0x40, 0x04, 0x00, 0x00, 0x41, 0x04, 0x00, 0x00,
	0x44, 0x04, 0x00, 0x00, 0x45, 0x04, 0x00, 0x00, 0x50, 0x04, 0x00, 0x00,
	0x51, 0x04, 0x00, 0x00, 0x54, 0x04, 0x00, 0x00, 0x55, 0x04, 0x00, 0x00,
	0x00, 0x05, 0x00, 0x00, 0x01, 0x05, 0x00, 0x00, 0x04, 0x05, 0x00, 0x00,
	0x05, 0x05, 0x00, 0x00, 0x10, 0x05, 0x00, 0x00, 0x11, 0x05, 0x00, 0x00,
	0x14, 0x05, 0x00, 0x00, 0x15, 0x05, 0x00, 0x00, 0x40, 0x05, 0x00, 0x00,
	0x41, 0x05, 0x00, 0x00, 0x44, 0x05, 0x00, 0x00, 0x45, 0x05, 0x00, 0x00,
	0x50, 0x05, 0x00, 0x00, 0x51, 0x05, 0x00, 0x00, 0x54, 0x05, 0x00, 0x00,
	0x55, 0x05, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x01, 0x10, 0x00, 0x00,
	0x04, 0x10, 0x00, 0x00, 0x05, 0x10, 0x00, 0x00, 0x10, 0x10, 0x00, 0x00,
	0x11, 0x10, 0x00, 0x00, 0x14, 0x10, 0x00, 0x00, 0x15, 0x10, 0x00, 0x00,
	0x40, 0x10, 0x00, 0x00, 0x41, 0x10, 0x00, 0x00, 0x44, 0x10, 0x00, 0x00,
	0x45, 0x10, 0x00, 0x00, 0x50, 0x10, 0x00, 0x00, 0x51, 0x10, 0x00, 0x00,
	0x54, 0x10, 0x00, 0x00, 0x55, 0x10, 0x00, 0x00, 0x00, 0x11, 0x00, 0x00,
	0x01, 0x11, 0x00, 0x00, 0x04, 0x11, 0x00, 0x00, 0x05, 0x11, 0x00, 0x00,
	0x10, 0x11, 0x00, 0x00, 0x11, 0x11, 0x00, 0x00, 0x14, 0x11, 0x00, 0x00,
	0x15, 0x11, 0x00, 0x00, 0x40, 0x11, 0x00, 0x00, 0x41, 0x11, 0x00, 0x00,
	0x44, 0x11, 0x00, 0x00, 0x45, 0x11, 0x00, 0x00, 0x50, 0x11, 0x00, 0x00,
	0x51, 0x11, 0x00, 0x00, 0x54, 0x11, 0x00, 0x00, 0x55, 0x11, 0x00, 0x00,
	0x00, 0x14, 0x00, 0x00, 0x01, 0x14, 0x00, 0x00, 0x04, 0x14, 0x00, 0x00,
	0x05, 0x14, 0x00, 0x00, 0x10, 0x14, 0x00, 0x00, 0x11, 0x14, 0x00, 0x00,
	0x14, 0x14, 0x00, 0x00, 0x15, 0x14, 0x00, 0x00, 0x40, 0x14, 0x00, 0x00,
	0x41, 0x14, 0x00, 0x00, 0x44, 0x14, 0x00, 0x00, 0x45, 0x14, 0x00, 0x00,
	0x50, 0x14, 0x00, 0x00, 0x51, 0x14, 0x00, 0x00, 0x54, 0x14, 0x00, 0x00,
	0x55, 0x14, 0x00, 0x00, 0x00, 0x15, 0x00, 0x00, 0x01, 0x15, 0x00, 0x00,
	0x04, 0x15, 0x00, 0x00, 0x05, 0x15, 0x00, 0x00, 0x10, 0x15, 0x00, 0x00,
	0x11, 0x15, 0x00, 0x00, 0x14, 0x15, 0x00, 0x00, 0x15, 0x15, 0x00, 0x00,
	0x40, 0x15, 0x00, 0x00, 0x41, 0x15, 0x00, 0x00, 0x44, 0x15, 0x00, 0x00,
	0x45, 0x15, 0x00, 0x00, 0x50, 0x15, 0x00, 0x00, 0x51, 0x15, 0x00, 0x00,
	0x54, 0x15, 0x00, 0x00, 0x55, 0x15, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00,
	0x01, 0x40, 0x00, 0x00, 0x04, 0x40, 0x00, 0x00, 0x05, 0x40, 0x00, 0x00,
	0x10, 0x40, 0x00, 0x00, 0x11, 0x40, 0x00, 0x00, 0x14, 0x40, 0x00, 0x00,
	0x15, 0x40, 0x00, 0x00, 0x40, 0x40, 0x00, 0x00, 0x41, 0x40, 0x00, 0x00,
	0x44, 0x40, 0x00, 0x00, 0x45, 0x40, 0x00, 0x00, 0x50, 0x40, 0x00, 0x00,
	0x51, 0x40, 0x00, 0x00, 0x54, 0x40, 0x00, 0x00, 0x55, 0x40, 0x00, 0x00,
	0x00, 0x41, 0x00, 0x00, 0x01, 0x41, 0x00, 0x00, 0x04, 0x41, 0x00, 0x00,
	0x05, 0x41, 0x00, 0x00, 0x10, 0x41, 0x00, 0x00, 0x11, 0x41, 0x00, 0x00,
	0x14, 0x41, 0x00, 0x00, 0x15, 0x41, 0x00, 0x00, 0x40, 0x41, 0x00, 0x00,
	0x41, 0x41, 0x00, 0x00, 0x44, 0x41, 0x00, 0x00, 0x45, 0x41, 0x00, 0x00,
	0x50, 0x41, 0x00, 0x00, 0x51, 0x41, 0x00, 0x00, 0x54, 0x41, 0x00, 0x00,
	0x55, 0x41, 0x00, 0x00, 0x00, 0x44, 0x00, 0x00, 0x01, 0x44, 0x00, 0x00,
	0x04, 0x44, 0x00, 0x00, 0x05, 0x44, 0x00, 0x00, 0x10, 0x44, 0x00, 0x00,
	0x11, 0x44, 0x00, 0x00, 0x14, 0x44, 0x00, 0x00, 0x15, 0x44, 0x00, 0x00,
	0x40, 0x44, 0x00, 0x00, 0x41, 0x44, 0x00, 0x00, 0x44, 0x44, 0x00, 0x00,
	0x45, 0x44, 0x00, 0x00, 0x50, 0x44, 0x00, 0x00, 0x51, 0x44, 0x00, 0x00,
	0x54, 0x44, 0x00, 0x00, 0x55, 0x44, 0x00, 0x00, 0x00, 0x45, 0x00, 0x00,
	0x01, 0x45, 0x00, 0x00, 0x04, 0x45, 0x00, 0x00, 0x05, 0x45, 0x00, 0x00,
	0x10, 0x45, 0x00, 0x00, 0x11, 0x45, 0x00, 0x00, 0x14, 0x45, 0x00, 0x00,
	0x15, 0x45, 0x00, 0x00, 0x40, 0x45, 0x00, 0x00, 0x41, 0x45, 0x00, 0x00,
	0x44, 0x45, 0x00, 0x00, 0x45, 0x45, 0x00, 0x00, 0x50, 0x45, 0x00, 0x00,
	0x51, 0x45, 0x00, 0x00, 0x54, 0x45, 0x00, 0x00, 0x55, 0x45, 0x00, 0x00,
	0x00, 0x50, 0x00, 0x00, 0x01, 0x50, 0x00, 0x00, 0x04, 0x50, 0x00, 0x00,
	0x05, 0x50, 0x00, 0x00, 0x10, 0x50, 0x00, 0x00, 0x11, 0x50, 0x00, 0x00,
	0x14, 0x50, 0x00, 0x00, 0x15, 0x50, 0x00, 0x00, 0x40, 0x50, 0x00, 0x00,
	0x41, 0x50, 0x00, 0x00, 0x44, 0x50, 0x00, 0x00, 0x45, 0x50, 0x00, 0x00,
	0x50, 0x50, 0x00, 0x00, 0x51, 0x50, 0x00, 0x00, 0x54, 0x50, 0x00, 0x00,
	0x55, 0x50, 0x00, 0x00, 0x00, 0x51, 0x00, 0x00, 0x01, 0x51, 0x00, 0x00,
	0x04, 0x51, 0x00, 0x00, 0x05, 0x51, 0x00, 0x00, 0x10, 0x51, 0x00, 0x00,
	0x11, 0x51, 0x00, 0x00, 0x14, 0x51, 0x00, 0x00, 0x15, 0x51, 0x00, 0x00,
	0x40, 0x51, 0x00, 0x00, 0x41, 0x51, 0x00, 0x00, 0x44, 0x51, 0x00, 0x00,
	0x45, 0x51, 0x00, 0x00, 0x50, 0x51, 0x00, 0x00, 0x51, 0x51, 0x00, 0x00,
	0x54, 0x51, 0x00, 0x00, 0x55, 0x51, 0x00, 0x00, 0x00, 0x54, 0x00, 0x00,
	0x01, 0x54, 0x00, 0x00, 0x04, 0x54, 0x00, 0x00, 0x05, 0x54, 0x00, 0x00,
	0x10, 0x54, 0x00, 0x00, 0x11, 0x54, 0x00, 0x00, 0x14, 0x54, 0x00, 0x00,
	0x15, 0x54, 0x00, 0x00, 0x40, 0x54, 0x00, 0x00, 0x41, 0x54, 0x00, 0x00,
	0x44, 0x54, 0x00, 0x00, 0x45, 0x54, 0x00, 0x00, 0x50, 0x54, 0x00, 0x00,
	0x51, 0x54, 0x00, 0x00, 0x54, 0x54, 0x00, 0x00, 0x55, 0x54, 0x00, 0x00,
	0x00, 0x55, 0x00, 0x00, 0x01, 0x55, 0x00, 0x00, 0x04, 0x55, 0x00, 0x00,
	0x05, 0x55, 0x00, 0x00, 0x10, 0x55, 0x00, 0x00, 0x11, 0x55, 0x00, 0x00,
	0x14, 0x55, 0x00, 0x00, 0x15, 0x55, 0x00, 0x00, 0x40, 0x55, 0x00, 0x00,
	0x41, 0x55, 0x00, 0x00, 0x44, 0x55, 0x00, 0x00, 0x45, 0x55, 0x00, 0x00,
	0x50, 0x55, 0x00, 0x00, 0x51, 0x55, 0x00, 0x00, 0x54, 0x55, 0x00, 0x00,
	0x55, 0x55, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00,
	0x04, 0x00, 0x01, 0x00, 0x05, 0x00, 0x01, 0x00, 0x10, 0x00, 0x01, 0x00,
	0x11, 0x00, 0x01, 0x00, 0x14, 0x00, 0x01, 0x00, 0x15, 0x00, 0x01, 0x00,
	0x40, 0x00, 0x01, 0x00, 0x41, 0x00, 0x01, 0x00, 0x44, 0x00, 0x01, 0x00,
	0x45, 0x00, 0x01, 0x00, 0x50, 0x00, 0x01, 0x00, 0x51, 0x00, 0x01, 0x00,
	0x54, 0x00, 0x01, 0x00, 0x55, 0x00, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00,
	0x01, 0x01, 0x01, 0x00, 0x04, 0x01, 0x01, 0x00, 0x05, 0x01, 0x01, 0x00,
	0x10, 0x01, 0x01, 0x00, 0x11, 0x01, 0x01, 0x00, 0x14, 0x01, 0x01, 0x00,
	0x15, 0x01, 0x01, 0x00, 0x40, 0x01, 0x01, 0x00, 0x41, 0x01, 0x01, 0x00,
	0x44, 0x01, 0x01, 0x00, 0x45, 0x01, 0x01, 0x00, 0x50, 0x01, 0x01, 0x00,
	0x51, 0x01, 0x01, 0x00, 0x54, 0x01, 0x01, 0x00, 0x55, 0x01, 0x01, 0x00,
	0x00, 0x04, 0x01, 0x00, 0x01, 0x04, 0x01, 0x00, 0x04, 0x04, 0x01, 0x00,
	0x05, 0x04, 0x01, 0x00, 0x10, 0x04, 0x01, 0x00, 0x11, 0x04, 0x01, 0x00,
	0x14, 0x04, 0x01, 0x00, 0x15, 0x04, 0x01, 0x00, 0x40, 0x04, 0x01, 0x00,
	0x41, 0x04, 0x01, 0x00, 0x44, 0x04, 0x01, 0x00, 0x45, 0x04, 0x01, 0x00,
	0x50, 0x04, 0x01, 0x00, 0x51, 0x04, 0x01, 0x00, 0x54, 0x04, 0x01, 0x00,
	0x55, 0x04, 0x01, 0x00, 0x00, 0x05, 0x01, 0x00, 0x01, 0x05, 0x01, 0x00,
	0x04, 0x05, 0x01, 0x00, 0x05, 0x05, 0x01, 0x00, 0x10, 0x05, 0x01, 0x00,
	0x11, 0x05, 0x01, 0x00, 0x14, 0x05, 0x01, 0x00, 0x15, 0x05, 0x01, 0x00,
	0x40, 0x05, 0x01, 0x00, 0x41, 0x05, 0x01, 0x00, 0x44, 0x05, 0x01, 0x00,
	0x45, 0x05, 0x01, 0x00, 0x50, 0x05, 0x01, 0x00, 0x51, 0x05, 0x01, 0x00,
	0x54, 0x05, 0x01, 0x00, 0x55, 0x05, 0x01, 0x00, 0x00, 0x10, 0x01, 0x00,
	0x01, 0x10, 0x01, 0x00, 0x04, 0x10, 0x01, 0x00, 0x05, 0x10, 0x01, 0x00,
	0x10, 0x10, 0x01, 0x00, 0x11, 0x10, 0x01, 0x00, 0x14, 0x10, 0x01, 0x00,
	0x15, 0x10, 0x01, 0x00, 0x40, 0x10, 0x01, 0x00, 0x41, 0x10, 0x01, 0x00,
	0x44, 0x10, 0x01, 0x00, 0x45, 0x10, 0x01, 0x00, 0x50, 0x10, 0x01, 0x00,
	0x51, 0x10, 0x01, 0x00, 0x54, 0x10, 0x01, 0x00, 0x55, 0x10, 0x01, 0x00,
	0x00, 0x11, 0x01, 0x00, 0x01, 0x11, 0x01, 0x00, 0x04, 0x11, 0x01, 0x00,
	0x05, 0x11, 0x01, 0x00, 0x10, 0x11, 0x01, 0x00, 0x11, 0x11, 0x01, 0x00,
	0x14, 0x11, 0x01, 0x00, 0x15, 0x11, 0x01, 0x00, 0x40, 0x11, 0x01, 0x00,
	0x41, 0x11, 0x01, 0x00, 0x44, 0x11, 0x01, 0x00, 0x45, 0x11, 0x01, 0x00,
	0x50, 0x11, 0x01, 0x00, 0x51, 0x11, 0x01, 0x00, 0x54, 0x11, 0x01, 0x00,
	0x55, 0x11, 0x01, 0x00, 0x00, 0x14, 0x01, 0x00, 0x01, 0x14, 0x01, 0x00,
	0x04, 0x14, 0x01, 0x00, 0x05, 0x14, 0x01, 0x00, 0x10, 0x14, 0x01, 0x00,
	0x11, 0x14, 0x01, 0x00, 0x14, 0x14, 0x01, 0x00, 0x15, 0x14, 0x01, 0x00,
	0x40, 0x14, 0x01, 0x00, 0x41, 0x14, 0x01, 0x00, 0x44, 0x14, 0x01, 0x00,
	0x45, 0x14, 0x01, 0x00, 0x50, 0x14, 0x01, 0x00, 0x51, 0x14, 0x01, 0x00,
	0x54, 0x14, 0x01, 0x00, 0x55, 0x14, 0x01, 0x00, 0x00, 0x15, 0x01, 0x00,
	0x01, 0x15, 0x01, 0x00, 0x04, 0x15, 0x01, 0x00, 0x05, 0x15, 0x01, 0x00,
	0x10, 0x15, 0x01, 0x00, 0x11, 0x15, 0x01, 0x00, 0x14, 0x15, 0x01, 0x00,
	0x15, 0x15, 0x01, 0x00, 0x40, 0x15, 0x01, 0x00, 0x41, 0x15, 0x01, 0x00,
	0x44, 0x15, 0x01, 0x00, 0x45, 0x15, 0x01, 0x00, 0x50, 0x15, 0x01, 0x00,
	0x51, 0x15, 0x01, 0x00, 0x54, 0x15, 0x01, 0x00, 0x55, 0x15, 0x01, 0x00,
	0x00, 0x40, 0x01, 0x00, 0x01, 0x40, 0x01, 0x00, 0x04, 0x40, 0x01, 0x00,
	0x05, 0x40, 0x01, 0x00, 0x10, 0x40, 0x01, 0x00, 0x11, 0x40, 0x01, 0x00,
	0x14, 0x40, 0x01, 0x00, 0x15, 0x40, 0x01, 0x00, 0x40, 0x40, 0x01, 0x00,
	0x41, 0x40, 0x01, 0x00, 0x44, 0x40, 0x01, 0x00, 0x45, 0x40, 0x01, 0x00,
	0x50, 0x40, 0x01, 0x00, 0x51, 0x40, 0x01, 0x00, 0x54, 0x40, 0x01, 0x00,
	0x55, 0x40, 0x01, 0x00, 0x00, 0x41, 0x01, 0x00, 0x01, 0x41, 0x01, 0x00,
	0x04, 0x41, 0x01, 0x00, 0x05, 0x41, 0x01, 0x00, 0x10, 0x41, 0x01, 0x00,
	0x11, 0x41, 0x01, 0x00, 0x14, 0x41, 0x01, 0x00, 0x15, 0x41, 0x01, 0x00,
	0x40, 0x41, 0x01, 0x00, 0x41, 0x41, 0x01, 0x00, 0x44, 0x41, 0x01, 0x00,
	0x45, 0x41, 0x01, 0x00, 0x50, 0x41, 0x01, 0x00, 0x51, 0x41, 0x01, 0x00,
	0x54, 0x41, 0x01, 0x00, 0x55, 0x41, 0x01, 0x00, 0x00, 0x44, 0x01, 0x00,
	0x01, 0x44, 0x01, 0x00, 0x04, 0x44, 0x01, 0x00, 0x05, 0x44, 0x01, 0x00,
	0x10, 0x44, 0x01, 0x00, 0x11, 0x44, 0x01, 0x00, 0x14, 0x44, 0x01, 0x00,
	0x15, 0x44, 0x01, 0x00, 0x40, 0x44, 0x01, 0x00, 0x41, 0x44, 0x01, 0x00,
	0x44, 0x44, 0x01, 0x00, 0x45, 0x44, 0x01, 0x00, 0x50, 0x44, 0x01, 0x00,
	0x51, 0x44, 0x01, 0x00, 0x54, 0x44, 0x01, 0x00, 0x55, 0x44, 0x01, 0x00,
	0x00, 0x45, 0x01, 0x00, 0x01, 0x45, 0x01, 0x00, 0x04, 0x45, 0x01, 0x00,
	0x05, 0x45, 0x01, 0x00, 0x10, 0x45, 0x01, 0x00, 0x11, 0x45, 0x01, 0x00,
	0x14, 0x45, 0x01, 0x00, 0x15, 0x45, 0x01, 0x00, 0x40, 0x45, 0x01, 0x00,
	0x41, 0x45, 0x01, 0x00, 0x44, 0x45, 0x01, 0x00, 0x45, 0x45, 0x01, 0x00,
	0x50, 0x45, 0x01, 0x00, 0x51, 0x45, 0x01, 0x00, 0x54, 0x45, 0x01, 0x00,
	0x55, 0x45, 0x01, 0x00, 0x00, 0x50, 0x01, 0x00, 0x01, 0x50, 0x01, 0x00,
	0x04, 0x50, 0x01, 0x00, 0x05, 0x50, 0x01, 0x00, 0x10, 0x50, 0x01, 0x00,
	0x11, 0x50, 0x01, 0x00, 0x14, 0x50, 0x01, 0x00, 0x15, 0x50, 0x01, 0x00,
	0x40, 0x50, 0x01, 0x00, 0x41, 0x50, 0x01, 0x00, 0x44, 0x50, 0x01, 0x00,
	0x45, 0x50, 0x01, 0x00, 0x50, 0x50, 0x01, 0x00, 0x51, 0x50, 0x01, 0x00,
	0x54, 0x50, 0x01, 0x00, 0x55, 0x50, 0x01, 0x00, 0x00, 0x51, 0x01, 0x00,
	0x01, 0x51, 0x01, 0x00, 0x04, 0x51, 0x01, 0x00, 0x05, 0x51, 0x01, 0x00,
	0x10, 0x51, 0x01, 0x00, 0x11, 0x51, 0x01, 0x00, 0x14, 0x51, 0x01, 0x00,
	0x15, 0x51, 0x01, 0x00, 0x40, 0x51, 0x01, 0x00, 0x41, 0x51, 0x01, 0x00,
	0x44, 0x51, 0x01, 0x00, 0x45, 0x51, 0x01, 0x00, 0x50, 0x51, 0x01, 0x00,
	0x51, 0x51, 0x01, 0x00, 0x54, 0x51, 0x01, 0x00, 0x55, 0x51, 0x01, 0x00,
	0x00, 0x54, 0x01, 0x00, 0x01, 0x54, 0x01, 0x00, 0x04, 0x54, 0x01, 0x00,
	0x05, 0x54, 0x01, 0x00, 0x10, 0x54, 0x01, 0x00, 0x11, 0x54, 0x01, 0x00,
	0x14, 0x54, 0x01, 0x00, 0x15, 0x54, 0x01, 0x00, 0x40, 0x54, 0x01, 0x00,
	0x41, 0x54, 0x01, 0x00, 0x44, 0x54, 0x01, 0x00, 0x45, 0x54, 0x01, 0x00,
	0x50, 0x54, 0x01, 0x00, 0x51, 0x54, 0x01, 0x00, 0x54, 0x54, 0x01, 0x00,
	0x55, 0x54, 0x01, 0x00, 0x00, 0x55, 0x01, 0x00, 0x01, 0x55, 0x01, 0x00,
	0x04, 0x55, 0x01, 0x00, 0x05, 0x55, 0x01, 0x00, 0x10, 0x55, 0x01, 0x00,
	0x11, 0x55, 0x01, 0x00, 0x14, 0x55, 0x01, 0x00, 0x15, 0x55, 0x01, 0x00,
	0x40, 0x55, 0x01, 0x00, 0x41, 0x55, 0x01, 0x00, 0x44, 0x55, 0x01, 0x00,
	0x45, 0x55, 0x01, 0x00, 0x50, 0x55, 0x01, 0x00, 0x51, 0x55, 0x01, 0x00,
	0x54, 0x55, 0x01, 0x00, 0x55, 0x55, 0x01, 0x00, 0x00, 0x00, 0x04, 0x00,
	0x01, 0x00, 0x04, 0x00, 0x04, 0x00, 0x04, 0x00, 0x05, 0x00, 0x04, 0x00,
	0x10, 0x00, 0x04, 0x00, 0x11, 0x00, 0x04, 0x00, 0x14, 0x00, 0x04, 0x00,
	0x15, 0x00, 0x04, 0x00, 0x40, 0x00, 0x04, 0x00, 0x41, 0x00, 0x04, 0x00,
	0x44, 0x00, 0x04, 0x00, 0x45, 0x00, 0x04, 0x00, 0x50, 0x00, 0x04, 0x00,
	0x51, 0x00, 0x04, 0x00, 0x54, 0x00, 0x04, 0x00, 0x55, 0x00, 0x04, 0x00,
	0x00, 0x01, 0x04, 0x00, 0x01, 0x01, 0x04, 0x00, 0x04, 0x01, 0x04, 0x00,
	0x05, 0x01, 0x04, 0x00, 0x10, 0x01, 0x04, 0x00, 0x11, 0x01, 0x04, 0x00,
	0x14, 0x01, 0x04, 0x00, 0x15, 0x01, 0x04, 0x00, 0x40, 0x01, 0x04, 0x00,
	0x41, 0x01, 0x04, 0x00, 0x44, 0x01, 0x04, 0x00, 0x45, 0x01, 0x04, 0x00,
	0x50, 0x01, 0x04, 0x00, 0x51, 0x01, 0x04, 0x00, 0x54, 0x01, 0x04, 0x00,
	0x55, 0x01, 0x04, 0x00, 0x00, 0x04, 0x04, 0x00, 0x01, 0x04, 0x04, 0x00,
	0x04, 0x04, 0x04, 0x00, 0x05, 0x04, 0x04, 0x00, 0x10, 0x04, 0x04, 0x00,
	0x11, 0x04, 0x04, 0x00, 0x14, 0x04, 0x04, 0x00, 0x15, 0x04, 0x04, 0x00,
	0x40, 0x04, 0x04, 0x00, 0x41, 0x04, 0x04, 0x00, 0x44, 0x04, 0x04, 0x00,
	0x45, 0x04, 0x04, 0x00, 0x50, 0x04, 0x04, 0x00, 0x51, 0x04, 0x04, 0x00,
	0x54, 0x04, 0x04, 0x00, 0x55, 0x04, 0x04, 0x00, 0x00, 0x05, 0x04, 0x00,
	0x01, 0x05, 0x04, 0x00, 0x04, 0x05, 0x04, 0x00, 0x05, 0x05, 0x04, 0x00,
	0x10, 0x05, 0x04, 0x00, 0x11, 0x05, 0x04, 0x00, 0x14, 0x05, 0x04, 0x00,
	0x15, 0x05, 0x04, 0x00, 0x40, 0x05, 0x04, 0x00, 0x41, 0x05, 0x04, 0x00,
	0x44, 0x05, 0x04, 0x00, 0x45, 0x05, 0x04, 0x00, 0x50, 0x05, 0x04, 0x00,
	0x51, 0x05, 0x04, 0x00, 0x54, 0x05, 0x04, 0x00, 0x55, 0x05, 0x04, 0x00,
	0x00, 0x10, 0x04, 0x00, 0x01, 0x10, 0x04, 0x00, 0x04, 0x10, 0x04, 0x00,
	0x05, 0x10, 0x04, 0x00, 0x10, 0x10, 0x04, 0x00, 0x11, 0x10, 0x04, 0x00,
	0x14, 0x10, 0x04, 0x00, 0x15, 0x10, 0x04, 0x00, 0x40, 0x10, 0x04, 0x00,
	0x41, 0x10, 0x04, 0x00, 0x44, 0x10, 0x04, 0x00, 0x45, 0x10, 0x04, 0x00,
	0x50, 0x10, 0x04, 0x00, 0x51, 0x10, 0x04, 0x00, 0x54, 0x10, 0x04, 0x00,
	0x55, 0x10, 0x04, 0x00, 0x00, 0x11, 0x04, 0x00, 0x01, 0x11, 0x04, 0x00,
	0x04, 0x11, 0x04, 0x00, 0x05, 0x11, 0x04, 0x00, 0x10, 0x11, 0x04, 0x00,
	0x11, 0x11, 0x04, 0x00, 0x14, 0x11, 0x04, 0x00, 0x15, 0x11, 0x04, 0x00,
	0x40, 0x11, 0x04, 0x00, 0x41, 0x11, 0x04, 0x00, 0x44, 0x11, 0x04, 0x00,
	0x45, 0x11, 0x04, 0x00, 0x50, 0x11, 0x04, 0x00, 0x51, 0x11, 0x04, 0x00,
	0x54, 0x11, 0x04, 0x00, 0x55, 0x11, 0x04, 0x00, 0x00, 0x14, 0x04, 0x00,
	0x01, 0x14, 0x04, 0x00, 0x04, 0x14, 0x04, 0x00, 0x05, 0x14, 0x04, 0x00,
	0x10, 0x14, 0x04, 0x00, 0x11, 0x14, 0x04, 0x00, 0x14, 0x14, 0x04, 0x00,
	0x15, 0x14, 0x04, 0x00, 0x40, 0x14, 0x04, 0x00, 0x41, 0x14, 0x04, 0x00,
	0x44, 0x14, 0x04, 0x00, 0x45, 0x14, 0x04, 0x00, 0x50, 0x14, 0x04, 0x00,
	0x51, 0x14, 0x04, 0x00, 0x54, 0x14, 0x04, 0x00, 0x55, 0x14, 0x04, 0x00,
	0x00, 0x15, 0x04, 0x00, 0x01, 0x15, 0x04, 0x00, 0x04, 0x15, 0x04, 0x00,
	0x05, 0x15, 0x04, 0x00, 0x10, 0x15, 0x04, 0x00, 0x11, 0x15, 0x04, 0x00,
	0x14, 0x15, 0x04, 0x00, 0x15, 0x15, 0x04, 0x00, 0x40, 0x15, 0x04, 0x00,
	0x41, 0x15, 0x04, 0x00, 0x44, 0x15, 0x04, 0x00, 0x45, 0x15, 0x04, 0x00,
	0x50, 0x15, 0x04, 0x00, 0x51, 0x15, 0x04, 0x00, 0x54, 0x15, 0x04, 0x00,
	0x55, 0x15, 0x04, 0x00, 0x00, 0x40, 0x04, 0x00, 0x01, 0x40, 0x04, 0x00,
	0x04, 0x40, 0x04, 0x00, 0x05, 0x40, 0x04, 0x00, 0x10, 0x40, 0x04, 0x00,
	0x11, 0x40, 0x04, 0x00, 0x14, 0x40, 0x04, 0x00, 0x15, 0x40, 0x04, 0x00,
	0x40, 0x40, 0x04, 0x00, 0x41, 0x40, 0x04, 0x00, 0x44, 0x40, 0x04, 0x00,
	0x45, 0x40, 0x04, 0x00, 0x50, 0x40, 0x04, 0x00, 0x51, 0x40, 0x04, 0x00,
	0x54, 0x40, 0x04, 0x00, 0x55, 0x40, 0x04, 0x00, 0x00, 0x41, 0x04, 0x00,
	0x01, 0x41, 0x04, 0x00, 0x04, 0x41, 0x04, 0x00, 0x05, 0x41, 0x04, 0x00,
	0x10, 0x41, 0x04, 0x00, 0x11, 0x41, 0x04, 0x00, 0x14, 0x41, 0x04, 0x00,
	0x15, 0x41, 0x04, 0x00, 0x40, 0x41, 0x04, 0x00, 0x41, 0x41, 0x04, 0x00,
	0x44, 0x41, 0x04, 0x00, 0x45, 0x41, 0x04, 0x00, 0x50, 0x41, 0x04, 0x00,
	0x51, 0x41, 0x04, 0x00, 0x54, 0x41, 0x04, 0x00, 0x55, 0x41, 0x04, 0x00,
	0x00, 0x44, 0x04, 0x00, 0x01, 0x44, 0x04, 0x00, 0x04, 0x44, 0x04, 0x00,
	0x05, 0x44, 0x04, 0x00, 0x10, 0x44, 0x04, 0x00, 0x11, 0x44, 0x04, 0x00,
	0x14, 0x44, 0x04, 0x00, 0x15, 0x44, 0x04, 0x00, 0x40, 0x44, 0x04, 0x00,
	0x41, 0x44, 0x04, 0x00, 0x44, 0x44, 0x04, 0x00, 0x45, 0x44, 0x04, 0x00,
	0x50, 0x44, 0x04, 0x00, 0x51, 0x44, 0x04, 0x00, 0x54, 0x44, 0x04, 0x00,
	0x55, 0x44, 0x04, 0x00, 0x00, 0x45, 0x04, 0x00, 0x01, 0x45, 0x04, 0x00,
	0x04, 0x45, 0x04, 0x00, 0x05, 0x45, 0x04, 0x00, 0x10, 0x45, 0x04, 0x00,
	0x11, 0x45, 0x04, 0x00, 0x14, 0x45, 0x04, 0x00, 0x15, 0x45, 0x04, 0x00,
	0x40, 0x45, 0x04, 0x00, 0x41, 0x45, 0x04, 0x00, 0x44, 0x45, 0x04, 0x00,
	0x45, 0x45, 0x04, 0x00, 0x50, 0x45, 0x04, 0x00, 0x51, 0x45, 0x04, 0x00,
	0x54, 0x45, 0x04, 0x00, 0x55, 0x45, 0x04, 0x00, 0x00, 0x50, 0x04, 0x00,
	0x01, 0x50, 0x04, 0x00, 0x04, 0x50, 0x04, 0x00, 0x05, 0x50, 0x04, 0x00,
	0x10, 0x50, 0x04, 0x00, 0x11, 0x50, 0x04, 0x00, 0x14, 0x50, 0x04, 0x00,
	0x15, 0x50, 0x04, 0x00, 0x40, 0x50, 0x04, 0x00, 0x41, 0x50, 0x04, 0x00,
	0x44, 0x50, 0x04, 0x00, 0x45, 0x50, 0x04, 0x00, 0x50, 0x50, 0x04, 0x00,
	0x51, 0x50, 0x04, 0x00, 0x54, 0x50, 0x04, 0x00, 0x55, 0x50, 0x04, 0x00,
	0x00, 0x51, 0x04, 0x00, 0x01, 0x51, 0x04, 0x00, 0x04, 0x51, 0x04, 0x00,
	0x05, 0x51, 0x04, 0x00, 0x10, 0x51, 0x04, 0x00, 0x11, 0x51, 0x04, 0x00,
	0x14, 0x51, 0x04, 0x00, 0x15, 0x51, 0x04, 0x00, 0x40, 0x51, 0x04, 0x00,
	0x41, 0x51, 0x04, 0x00, 0x44, 0x51, 0x04, 0x00, 0x45, 0x51, 0x04, 0x00,
	0x50, 0x51, 0x04, 0x00, 0x51, 0x51, 0x04, 0x00, 0x54, 0x51, 0x04, 0x00,
	0x55, 0x51, 0x04, 0x00, 0x00, 0x54, 0x04, 0x00, 0x01, 0x54, 0x04, 0x00,
	0x04, 0x54, 0x04, 0x00, 0x05, 0x54, 0x04, 0x00, 0x10, 0x54, 0x04, 0x00,
	0x11, 0x54, 0x04, 0x00, 0x14, 0x54, 0x04, 0x00, 0x15, 0x54, 0x04, 0x00,
	0x40, 0x54, 0x04, 0x00, 0x41, 0x54, 0x04, 0x00, 0x44, 0x54, 0x04, 0x00,
	0x45, 0x54, 0x04, 0x00, 0x50, 0x54, 0x04, 0x00, 0x51, 0x54, 0x04, 0x00,
	0x54, 0x54, 0x04, 0x00, 0x55, 0x54, 0x04, 0x00, 0x00, 0x55, 0x04, 0x00,
	0x01, 0x55, 0x04, 0x00, 0x04, 0x55, 0x04, 0x00, 0x05, 0x55, 0x04, 0x00,
	0x10, 0x55, 0x04, 0x00, 0x11, 0x55, 0x04, 0x00, 0x14, 0x55, 0x04, 0x00,
	0x15, 0x55, 0x04, 0x00, 0x40, 0x55, 0x04, 0x00, 0x41, 0x55, 0x04, 0x00,
	0x44, 0x55, 0x04, 0x00, 0x45, 0x55, 0x04, 0x00, 0x50, 0x55, 0x04, 0x00,
	0x51, 0x55, 0x04, 0x00, 0x54, 0x55, 0x04, 0x00, 0x55, 0x55, 0x04, 0x00,
	0x00, 0x00, 0x05, 0x00, 0x01, 0x00, 0x05, 0x00, 0x04, 0x00, 0x05, 0x00,
	0x05, 0x00, 0x05, 0x00, 0x10, 0x00, 0x05, 0x00, 0x11, 0x00, 0x05, 0x00,
	0x14, 0x00, 0x05, 0x00, 0x15, 0x00, 0x05, 0x00, 0x40, 0x00, 0x05, 0x00,
	0x41, 0x00, 0x05, 0x00, 0x44, 0x00, 0x05, 0x00, 0x45, 0x00, 0x05, 0x00,
	0x50, 0x00, 0x05, 0x00, 0x51, 0x00, 0x05, 0x00, 0x54, 0x00, 0x05, 0x00,
	0x55, 0x00, 0x05, 0x00, 0x00, 0x01, 0x05, 0x00, 0x01, 0x01, 0x05, 0x00,
	0x04, 0x01, 0x05, 0x00, 0x05, 0x01, 0x05, 0x00, 0x10, 0x01, 0x05, 0x00,
	0x11, 0x01, 0x05, 0x00, 0x14, 0x01, 0x05, 0x00, 0x15, 0x01, 0x05, 0x00,
	0x40, 0x01, 0x05, 0x00, 0x41, 0x01, 0x05, 0x00, 0x44, 0x01, 0x05, 0x00,
	0x45, 0x01, 0x05, 0x00, 0x50, 0x01, 0x05, 0x00, 0x51, 0x01, 0x05, 0x00,
	0x54, 0x01, 0x05, 0x00, 0x55, 0x01, 0x05, 0x00, 0x00, 0x04, 0x05, 0x00,
	0x01, 0x04, 0x05, 0x00, 0x04, 0x04, 0x05, 0x00, 0x05, 0x04, 0x05, 0x00,
	0x10, 0x04, 0x05, 0x00, 0x11, 0x04, 0x05, 0x00, 0x14, 0x04, 0x05, 0x00,
	0x15, 0x04, 0x05, 0x00, 0x40, 0x04, 0x05, 0x00, 0x41, 0x04, 0x05, 0x00,
	0x44, 0x04, 0x05, 0x00, 0x45, 0x04, 0x05, 0x00, 0x50, 0x04, 0x05, 0x00,
	0x51, 0x04, 0x05, 0x00, 0x54, 0x04, 0x05, 0x00, 0x55, 0x04, 0x05, 0x00,
	0x00, 0x05, 0x05, 0x00, 0x01, 0x05, 0x05, 0x00, 0x04, 0x05, 0x05, 0x00,
	0x05, 0x05, 0x05, 0x00, 0x10, 0x05, 0x05, 0x00, 0x11, 0x05, 0x05, 0x00,
	0x14, 0x05, 0x05, 0x00, 0x15, 0x05, 0x05, 0x00, 0x40, 0x05, 0x05, 0x00,
	0x41, 0x05, 0x05, 0x00, 0x44, 0x05, 0x05, 0x00, 0x45, 0x05, 0x05, 0x00,
	0x50, 0x05, 0x05, 0x00, 0x51, 0x05, 0x05, 0x00, 0x54, 0x05, 0x05, 0x00,
	0x55, 0x05, 0x05, 0x00, 0x00, 0x10, 0x05, 0x00, 0x01, 0x10, 0x05, 0x00,
	0x04, 0x10, 0x05, 0x00, 0x05, 0x10, 0x05, 0x00, 0x10, 0x10, 0x05, 0x00,
	0x11, 0x10, 0x05, 0x00, 0x14, 0x10, 0x05, 0x00, 0x15, 0x10, 0x05, 0x00,
	0x40, 0x10, 0x05, 0x00, 0x41, 0x10, 0x05, 0x00, 0x44, 0x10, 0x05, 0x00,
	0x45, 0x10, 0x05, 0x00, 0x50, 0x10, 0x05, 0x00, 0x51, 0x10, 0x05, 0x00,
	0x54, 0x10, 0x05, 0x00, 0x55, 0x10, 0x05, 0x00, 0x00, 0x11, 0x05, 0x00,
	0x01, 0x11, 0x05, 0x00, 0x04, 0x11, 0x05, 0x00, 0x05, 0x11, 0x05, 0x00,
	0x10, 0x11, 0x05, 0x00, 0x11, 0x11, 0x05, 0x00, 0x14, 0x11, 0x05, 0x00,
	0x15, 0x11, 0x05, 0x00, 0x40, 0x11, 0x05, 0x00, 0x41, 0x11, 0x05, 0x00,
	0x44, 0x11, 0x05, 0x00, 0x45, 0x11, 0x05, 0x00, 0x50, 0x11, 0x05, 0x00,
	0x51, 0x11, 0x05, 0x00, 0x54, 0x11, 0x05, 0x00, 0x55, 0x11, 0x05, 0x00,
	0x00, 0x14, 0x05, 0x00, 0x01, 0x14, 0x05, 0x00, 0x04, 0x14, 0x05, 0x00,
	0x05, 0x14, 0x05, 0x00, 0x10, 0x14, 0x05, 0x00, 0x11, 0x14, 0x05, 0x00,
	0x14, 0x14, 0x05, 0x00, 0x15, 0x14, 0x05, 0x00, 0x40, 0x14, 0x05, 0x00,
	0x41, 0x14, 0x05, 0x00, 0x44, 0x14, 0x05, 0x00, 0x45, 0x14, 0x05, 0x00,
	0x50, 0x14, 0x05, 0x00, 0x51, 0x14, 0x05, 0x00, 0x54, 0x14, 0x05, 0x00,
	0x55, 0x14, 0x05, 0x00, 0x00, 0x15, 0x05, 0x00, 0x01, 0x15, 0x05, 0x00,
	0x04, 0x15, 0x05, 0x00, 0x05, 0x15, 0x05, 0x00, 0x10, 0x15, 0x05, 0x00,
	0x11, 0x15, 0x05, 0x00, 0x14, 0x15, 0x05, 0x00, 0x15, 0x15, 0x05, 0x00,
	0x40, 0x15, 0x05, 0x00, 0x41, 0x15, 0x05, 0x00, 0x44, 0x15, 0x05, 0x00,
	0x45, 0x15, 0x05, 0x00, 0x50, 0x15, 0x05, 0x00, 0x51, 0x15, 0x05, 0x00,
	0x54, 0x15, 0x05, 0x00, 0x55, 0x15, 0x05, 0x00, 0x00, 0x40, 0x05, 0x00,
	0x01, 0x40, 0x05, 0x00, 0x04, 0x40, 0x05, 0x00, 0x05, 0x40, 0x05, 0x00,
	0x10, 0x40, 0x05, 0x00, 0x11, 0x40, 0x05, 0x00, 0x14, 0x40, 0x05, 0x00,
	0x15, 0x40, 0x05, 0x00, 0x40, 0x40, 0x05, 0x00, 0x41, 0x40, 0x05, 0x00,
	0x44, 0x40, 0x05, 0x00, 0x45, 0x40, 0x05, 0x00, 0x50, 0x40, 0x05, 0x00,
	0x51, 0x40, 0x05, 0x00, 0x54, 0x40, 0x05, 0x00, 0x55, 0x40, 0x05, 0x00,
	0x00, 0x41, 0x05, 0x00, 0x01, 0x41, 0x05, 0x00, 0x04, 0x41, 0x05, 0x00,
	0x05, 0x41, 0x05, 0x00, 0x10, 0x41, 0x05, 0x00, 0x11, 0x41, 0x05, 0x00,
	0x14, 0x41, 0x05, 0x00, 0x15, 0x41, 0x05, 0x00, 0x40, 0x41, 0x05, 0x00,
	0x41, 0x41, 0x05, 0x00, 0x44, 0x41, 0x05, 0x00, 0x45, 0x41, 0x05, 0x00,
	0x50, 0x41, 0x05, 0x00, 0x51, 0x41, 0x05, 0x00, 0x54, 0x41, 0x05, 0x00,
	0x55, 0x41, 0x05, 0x00, 0x00, 0x44, 0x05, 0x00, 0x01, 0x44, 0x05, 0x00,
	0x04, 0x44, 0x05, 0x00, 0x05, 0x44, 0x05, 0x00, 0x10, 0x44, 0x05, 0x00,
	0x11, 0x44, 0x05, 0x00, 0x14, 0x44, 0x05, 0x00, 0x15, 0x44, 0x05, 0x00,
	0x40, 0x44, 0x05, 0x00, 0x41, 0x44, 0x05, 0x00, 0x44, 0x44, 0x05, 0x00,
	0x45, 0x44, 0x05, 0x00, 0x50, 0x44, 0x05, 0x00, 0x51, 0x44, 0x05, 0x00,
	0x54, 0x44, 0x05, 0x00, 0x55, 0x44, 0x05, 0x00, 0x00, 0x45, 0x05, 0x00,
	0x01, 0x45, 0x05, 0x00, 0x04, 0x45, 0x05, 0x00, 0x05, 0x45, 0x05, 0x00,
	0x10, 0x45, 0x05, 0x00, 0x11, 0x45, 0x05, 0x00, 0x14, 0x45, 0x05, 0x00,
	0x15, 0x45, 0x05, 0x00, 0x40, 0x45, 0x05, 0x00, 0x41, 0x45, 0x05, 0x00,
	0x44, 0x45, 0x05, 0x00, 0x45, 0x45, 0x05, 0x00, 0x50, 0x45, 0x05, 0x00,
	0x51, 0x45, 0x05, 0x00, 0x54, 0x45, 0x05, 0x00, 0x55, 0x45, 0x05, 0x00,
	0x00, 0x50, 0x05, 0x00, 0x01, 0x50, 0x05, 0x00, 0x04, 0x50, 0x05, 0x00,
	0x05, 0x50, 0x05, 0x00, 0x10, 0x50, 0x05, 0x00, 0x11, 0x50, 0x05, 0x00,
	0x14, 0x50, 0x05, 0x00, 0x15, 0x50, 0x05, 0x00, 0x40, 0x50, 0x05, 0x00,
	0x41, 0x50, 0x05, 0x00, 0x44, 0x50, 0x05, 0x00, 0x45, 0x50, 0x05, 0x00,
	0x50, 0x50, 0x05, 0x00, 0x51, 0x50, 0x05, 0x00, 0x54, 0x50, 0x05, 0x00,
	0x55, 0x50, 0x05, 0x00, 0x00, 0x51, 0x05, 0x00, 0x01, 0x51, 0x05, 0x00,
	0x04, 0x51, 0x05, 0x00, 0x05, 0x51, 0x05, 0x00, 0x10, 0x51, 0x05, 0x00,
	0x11, 0x51, 0x05, 0x00, 0x14, 0x51, 0x05, 0x00, 0x15, 0x51, 0x05, 0x00,
	0x40, 0x51, 0x05, 0x00, 0x41, 0x51, 0x05, 0x00, 0x44, 0x51, 0x05, 0x00,
	0x45, 0x51, 0x05, 0x00, 0x50, 0x51, 0x05, 0x00, 0x51, 0x51, 0x05, 0x00,
	0x54, 0x51, 0x05, 0x00, 0x55, 0x51, 0x05, 0x00, 0x00, 0x54, 0x05, 0x00,
	0x01, 0x54, 0x05, 0x00, 0x04, 0x54, 0x05, 0x00, 0x05, 0x54, 0x05, 0x00,
	0x10, 0x54, 0x05, 0x00, 0x11, 0x54, 0x05, 0x00, 0x14, 0x54, 0x05, 0x00,
	0x15, 0x54, 0x05, 0x00, 0x40, 0x54, 0x05, 0x00, 0x41, 0x54, 0x05, 0x00,
	0x44, 0x54, 0x05, 0x00, 0x45, 0x54, 0x05, 0x00, 0x50, 0x54, 0x05, 0x00,
	0x51, 0x54, 0x05, 0x00, 0x54, 0x54, 0x05, 0x00, 0x55, 0x54, 0x05, 0x00,
	0x00, 0x55, 0x05, 0x00, 0x01, 0x55, 0x05, 0x00, 0x04, 0x55, 0x05, 0x00,
	0x05, 0x55, 0x05, 0x00, 0x10, 0x55, 0x05, 0x00, 0x11, 0x55, 0x05, 0x00,
	0x14, 0x55, 0x05, 0x00, 0x15, 0x55, 0x05, 0x00, 0x40, 0x55, 0x05, 0x00,
	0x41, 0x55, 0x05, 0x00, 0x44, 0x55, 0x05, 0x00, 0x45, 0x55, 0x05, 0x00,
	0x50, 0x55, 0x05, 0x00, 0x51, 0x55, 0x05, 0x00, 0x54, 0x55, 0x05, 0x00,
	0x55, 0x55, 0x05, 0x00
};