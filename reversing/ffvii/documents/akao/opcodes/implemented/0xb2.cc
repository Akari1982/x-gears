ch[0xE0] |= 0x4400;
ch[0x102] = p[0];

if(ch[0x38] & 0x0100)
	channel<ch[0x24]>[0x102] = p[0];
