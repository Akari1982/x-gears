////////////////////////////////
// func73d90
[800af370] = h(0); // current buttons c1
[800af374] = h(0); // current buttons c2
[800c1b68] = h(0); // pressed buttons c1
[800c2dcc] = h(0); // pressed buttons c2
[800c2dd4] = h(0); // repeated buttons c1
[800c2ddc] = h(0); // repeated buttons c2

// receive all button updates since last update
L73dc8:	; 80073DC8
    func35b88(); // get one button update
    if( V0 == 0 )
    {
        break;
    }
    [800af370] = h(hu[800af370] | (hu[80058с0с] & hu[800b164e]));
    [800af374] = h(hu[800af374] | hu[80058с10]);
    [800c1b68] = h(hu[800c1b68] | (hu[80058b28] & hu[800b164e]));
    [800c2dcc] = h(hu[800c2dcc] | hu[80058b2c]);
    [800c2dd4] = h(hu[800c2dd4] | (hu[80058b40] & hu[800b164e]));
    [800c2ddc] = h(hu[800c2ddc] | hu[80058b44]);
80073E94	j      L73dc8 [$80073dc8]

// filter buttons
[800af370] = h(hu[800af370] & hu[800acfd8]);
[800c2dd4] = h(hu[800c2dd4] & hu[800acfd8]);
[800c1b68] = h(hu[800c1b68] & hu[800acfd8]);

func35c84(); // clear system button masks

A0 = 1;
A1 = 80064ed8;
func7a48c();

if( w[800ad0f0] != 0 )
{
    [800af370] = h(0);
    [800af374] = h(0);
    [800c1b68] = h(0);
    [800c2dcc] = h(0);
    [800c2dd4] = h(0);
    [800c2ddc] = h(0);
}

// if battle started - disable jumping
if( w[800ad0b4] == 0 )
{
    [800c1b68] = h(hu[800c1b68] & ff7f);
}
////////////////////////////////



////////////////////////////////
// func7a48c()
8007A494	addu   s0, a0, zero
8007A4A4	addu   s1, a1, zero

8007A4A0	jal    func7a588 [$8007a588]
8007A4A8	sll    s0, s0, $02

V1 = hu[800af530];
V0 = w[800af53c + S0];
V0 = V0 / V1;

8007A4D0	sw     v0, $0000(s1)
8007A4D4	lui    v1, $800b
8007A4D8	lhu    v1, $f534(v1)
8007A4DC	lui    at, $800b
8007A4E0	addu   at, at, s0
8007A4E4	lw     v0, $f544(at)
8007A4E8	nop
8007A4EC	div    v0, v1
8007A4F0	mflo   v0
8007A4F4	addiu  v1, zero, $ff00 (=-$100)
8007A4F8	sw     v1, $0008(s1)
8007A4FC	sw     v0, $0004(s1)
8007A500	lui    v0, $800b
8007A504	addiu  v0, v0, $f528 (=-$ad8)
8007A508	addu   s0, s0, v0
8007A50C	lw     v0, $0000(s0)
8007A510	nop
8007A514	lb     v0, $0004(v0)
8007A518	nop
8007A51C	sw     v0, $000c(s1)
8007A520	lw     v0, $0000(s0)
8007A524	nop
8007A528	lb     v0, $0005(v0)
8007A52C	nop
8007A530	sw     v0, $0010(s1)
8007A534	lw     s0, $0000(s0)
8007A538	nop
8007A53C	lb     v0, $0000(s0)
8007A540	nop
8007A544	bne    v0, zero, L7a570 [$8007a570]
8007A548	nop
8007A54C	lb     v1, $0001(s0)
8007A550	ori    v0, zero, $0012
8007A554	bne    v1, v0, L7a570 [$8007a570]
8007A558	nop
8007A55C	lb     v0, $0003(s0)
8007A560	nop
8007A564	nor    v0, zero, v0
8007A568	andi   v0, v0, $000c
8007A56C	sw     v0, $0008(s1)

L7a570:	; 8007A570
////////////////////////////////
