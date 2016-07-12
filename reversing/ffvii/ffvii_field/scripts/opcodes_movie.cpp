////////////////////////////////
// 0xF8 PMVIE
800CCD7C	lui    v0, $8007
800CCD80	lbu    v0, $16cc(v0)
800CCD84	nop
800CCD88	beq    v0, zero, Lccdbc [$800ccdbc]
800CCD8C	nop
800CCD90	lui    v1, $8007
800CCD94	lbu    v1, $22c4(v1)
800CCD98	lui    v0, $8008
800CCD9C	addiu  v0, v0, $31fc
800CCDA0	sll    v1, v1, $01
800CCDA4	addu   v1, v1, v0
800CCDA8	lhu    a0, $0000(v1)
800CCDB0	addiu  a0, a0, $0002
800CCDB8	sh     a0, $0000(v1)
return 0;

Lccdbc:	; 800CCDBC
800CCDBC	lui    v1, $800a
800CCDC0	lw     v1, $c6e0(v1)
800CCDC4	nop
800CCDC8	lbu    a0, $0001(v1)
800CCDCC	nop
800CCDD0	beq    a0, zero, Lcce34 [$800cce34]
800CCDD4	ori    v0, zero, $0003
800CCDD8	bne    a0, v0, Lcce84 [$800cce84]
800CCDDC	ori    v0, zero, $0001
800CCDE0	lh     a0, $0026(v1)
800CCDE4	nop
800CCDE8	beq    a0, v0, Lcce80 [$800cce80]
800CCDEC	ori    v0, zero, $0002
800CCDF0	bne    a0, v0, Lcce84 [$800cce84]
800CCDF4	ori    v0, zero, $0001
800CCDF8	sb     zero, $0001(v1)
800CCDFC	lui    v0, $800a
800CCE00	lw     v0, $c6e0(v0)
800CCE04	lui    a0, $8007
800CCE08	lbu    a0, $22c4(a0)
800CCE0C	sh     zero, $0026(v0)
800CCE10	lui    v0, $8008
800CCE14	addiu  v0, v0, $31fc
800CCE18	sll    a0, a0, $01
800CCE1C	addu   a0, a0, v0
800CCE20	lhu    v1, $0000(a0)
800CCE28	addiu  v1, v1, $0002
800CCE30	sh     v1, $0000(a0)
return 0;

Lcce34:	; 800CCE34
800CCE34	ori    v0, zero, $0003
800CCE38	sb     v0, $0001(v1)
800CCE3C	lui    v0, $8007
800CCE40	lbu    v0, $22c4(v0)
800CCE44	nop
800CCE48	sll    v0, v0, $01
800CCE4C	lui    at, $8008
800CCE50	addiu  at, at, $31fc
800CCE54	addu   at, at, v0
800CCE58	lhu    v1, $0000(at)
800CCE5C	lui    v0, $800a
800CCE60	lw     v0, $c6dc(v0)
800CCE64	nop
800CCE68	addu   v0, v0, v1
800CCE6C	lui    v1, $800a
800CCE70	lw     v1, $c6e0(v1)
800CCE74	lbu    v0, $0001(v0)
800CCE78	sh     zero, $0026(v1)
800CCE7C	sh     v0, $0002(v1)

Lcce80:	; 800CCE80
800CCE80	ori    v0, zero, $0001

Lcce84:	; 800CCE84
////////////////////////////////



////////////////////////////////
// 0xF9 MOVIE
[80071c1c] = b(1);

current_entity = bu[800722c4];
struct = w[8009c6e0];

if( bu[800716cc] != 0 ) // movie lock
{
    [801144d4] = h(0);
    [800831fc + current_entity * 2] = h(hu[800831fc + current_entity * 2] + 1);
    return 0;
}
else
{
    V1 = bu[struct + 1];
    if( V1 == 0 ) // normal field
    {
        [struct + 1] = b(4);
        [struct + 26] = b(0);
        return 0;
    }
    if( V1 == 14 )
    {
        [800831fc + current_entity * 2] = h(hu[800831fc + current_entity * 2] + 1);
        return 0;
    }
    if( V1 == 4 )
    {
        V1 = h[struct + 26];
        if( V1 == 1 )
        {
            return 0;
        }
        if( V1 != 2 )
        {
            return 1;
        }

        [struct + 1] = b(0);
        [struct + 26] = h(0);
        [800831fc + current_entity * 2] = h(hu[800831fc + current_entity * 2] + 1);
        return 0;
    }
    return 1;
}
////////////////////////////////



////////////////////////////////
// 0xFA MVIEF

struct = w[8009c6e0];

if( bu[800716cc] != 0 ) // movie lock
{
    A0 = 2;
    A1 = 2;
    A2 = h[801144d4];
    store_memory_block_two_bytes;

    [801144d4] = h(h[801144d4] + 1);
}
else
{
    A0 = 2;
    A1 = 2;
    A2 = h[struct + 88];
    store_memory_block_two_bytes;
}

[800831fc + current_entity * 2] = h(hu[800831fc + current_entity * 2] + 3);
return 0;
////////////////////////////////



////////////////////////////////
// 0xFB MVCAM
800C558C	lui    v0, $8007
800C5590	lbu    v0, $22c4(v0)
800C5594	nop
800C5598	sll    v0, v0, $01
800C559C	lui    at, $8008
800C55A0	addiu  at, at, $31fc
800C55A4	addu   at, at, v0
800C55A8	lhu    v1, $0000(at)
800C55AC	lui    v0, $800a
800C55B0	lw     v0, $c6dc(v0)
800C55B4	nop
800C55B8	addu   v0, v0, v1
800C55BC	lui    v1, $800a
800C55C0	lw     v1, $c6e0(v1)
800C55C4	lbu    v0, $0001(v0)
800C55C8	nop
800C55CC	sb     v0, $0039(v1)
800C55D0	lui    v1, $8007
800C55D4	lbu    v1, $22c4(v1)
800C55D8	lui    v0, $8008
800C55DC	addiu  v0, v0, $31fc
800C55E0	sll    v1, v1, $01
800C55E4	addu   v1, v1, v0
800C55E8	lhu    v0, $0000(v1)
800C55EC	nop
800C55F0	addiu  v0, v0, $0002
800C55F4	sh     v0, $0000(v1)
return 0;
////////////////////////////////
