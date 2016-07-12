////////////////////////////////
// func42044
if (A1 & 1)
{
    [A0] = w(w[A0] & f7ffffff);
}
else
{
    [A0] = w(w[A0] | 08000000);
}

if (A1 & 2)
{
    [A0] = w(w[A0] | 02000000);
}
else
{
    [A0] = w(w[A0] & fdffffff);
}

A1 = hu[A0];
func42270;
////////////////////////////////



////////////////////////////////
// func42168
8004216C	addu   a1, a0, zero
80042170	beq    a1, zero, L4218c [$8004218c]

80042178	ori    v0, zero, $0001
8004217C	beq    a1, v0, L421f0 [$800421f0]
80042180	lui    v0, $8000
80042184	j      L42248 [$80042248]
80042188	nop

L4218c:	; 8004218C
8004218C	lui    v1, $8005
80042190	lw     v1, $1b88(v1)
80042194	lui    v0, $8000
80042198	sw     v0, $0000(v1)
8004219C	lui    v0, $8005
800421A0	lw     v0, $1b5c(v0)
800421A4	lui    a0, $8005
800421A8	addiu  a0, a0, $1a4c
800421AC	sw     zero, $0000(v0)
800421B0	lui    v0, $8005
800421B4	lw     v0, $1b68(v0)
800421B8	ori    a1, zero, $0020
800421BC	sw     zero, $0000(v0)
800421C0	lui    v1, $8005
800421C4	lw     v1, $1b88(v1)
800421C8	lui    v0, $6000
800421CC	sw     v0, $0000(v1)
// Set Quant Table
800421D0	jal    func42270 [$80042270]
800421D4	nop
800421D8	lui    a0, $8005
800421DC	addiu  a0, a0, $1ad0
// Set Scale Table
800421E0	jal    func42270 [$80042270]
800421E4	ori    a1, zero, $0020
800421E8	j      L42260 [$80042260]
800421EC	nop

L421f0:	; 800421F0
800421F0	lui    v1, $8005
800421F4	lw     v1, $1b88(v1)
800421F8	nop
800421FC	sw     v0, $0000(v1)
80042200	lui    v0, $8005
80042204	lw     v0, $1b5c(v0)
80042208	nop
8004220C	sw     zero, $0000(v0)
80042210	lui    v0, $8005
80042214	lw     v0, $1b68(v0)
80042218	nop
8004221C	sw     zero, $0000(v0)
80042220	lui    v0, $8005
80042224	lw     v0, $1b68(v0)
80042228	lui    v1, $8005
8004222C	lw     v1, $1b88(v1)
80042230	lw     v0, $0000(v0)
80042234	nop
80042238	lui    v0, $6000
8004223C	sw     v0, $0000(v1)
80042240	j      L42260 [$80042260]
80042244	nop

L42248:	; 80042248
80042248	lui    a0, $8001
8004224C	addiu  a0, a0, $0b10
80042250	jal    func42dc8 [$80042dc8]
80042254	nop
80042258	jal    func42d38 [$80042d38]
8004225C	nop

L42260:	; 80042260
////////////////////////////////



////////////////////////////////
// func42270
S1 = A0; // data
S0 = A1; // size?

80042284	jal    func42394 [$80042394]

V1 = w[80051b8c]; // 1f8010f0  DMA Primary Control Register
[V1] = w(w[V1] | 00000088); // enable DMA0 MDECin and DMA1 MDECout

V1 = w[80051b54]; // 1f801080 MDECin base address
[V1] = w(S1 + 4); // set dma base address

V0 = w[80051b58]; // 1f801084 MDECin block size
S0 = (((S0 >> 5) << 10) | 20);
[V0] = w(S0);

V1 = w[80051b84]; // 1f801820 MDEC command
[V1] = w(w[S1]);

V0 = w[80051b5c]; // 1f801088 MDECin channel control
// 0    Transfer Direction    (1=From Main RAM)
// 1    Memory Address Step   (0=Forward;+4)
// 8    Chopping Enable       (0=Normal)
// 9-10 SyncMode, Transfer Synchronisation/Mode (0-3): 1  Sync blocks to DMA requests   (used for MDEC, SPU, and GPU-data)
// 24   Start/Busy            (1=Start/Enable/Busy)
// 28   Start/Trigger         (0=Normal)
// 29   Unknown (R/W) Pause?  (0=No)(For SyncMode=0 only?)
[V0] = w(01000201);
////////////////////////////////
