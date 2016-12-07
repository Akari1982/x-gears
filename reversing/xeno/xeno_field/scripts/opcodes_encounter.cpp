////////////////////////////////
// 0x0C
data_138 = w[800af54c];
S0 = hu[data_138 + cc];

// encounter check
func9eb84();

[data_138 + cc] = h(S0);
// this is infinite wait opcode
// will do encouner check every call
[800af594] = w(1);
////////////////////////////////



////////////////////////////////
// 0xF7
A0 = 1;
read_two_bytes_with_80();
[800b176c] = w(V0);

A0 = 3;
read_two_bytes_with_80();
[800b1770] = w(V0);
if( V0 >= 21 )
{
    [800b1770] = w(20);
}

func8dcec(); // reinit 800b1774

data_138 = w[800af54c];
[data_138 + cc] = h(hu[data_138 + cc] + 5);
////////////////////////////////



////////////////////////////////
// 0xF6
data_138 = w[800af54c];

8008DEA4	lui    v1, $800b
8008DEA8	lw     v1, $d0d8(v1)
V0 = hu[data_138 + cc];
8008DEB4	addu   v0, v0, v1
8008DEB8	lbu    v1, $0001(v0)
8008DEBC	ori    v0, zero, $0001
8008DEC0	beq    v1, v0, L8df84 [$8008df84]
8008DEC4	slti   v0, v1, $0002
8008DEC8	beq    v0, zero, L8dee0 [$8008dee0]
8008DECC	nop
8008DED0	beq    v1, zero, L8def4 [$8008def4]
8008DED4	nop
8008DED8	j      L8dfac [$8008dfac]
8008DEDC	nop

L8dee0:	; 8008DEE0
8008DEE0	ori    v0, zero, $0002
8008DEE4	beq    v1, v0, L8df9c [$8008df9c]
8008DEE8	lui    v1, $0008
8008DEEC	j      L8dfac [$8008dfac]
8008DEF0	nop

L8def4:	; 8008DEF4
V1 = w[data_138 + 0];
8008DEFC	andi   v0, v1, $8000
8008DF00	beq    v0, zero, L8df14 [$8008df14]
8008DF04	lui    v0, $ffff
8008DF08	ori    v0, v0, $7fff
8008DF0C	and    v0, v1, v0
[data_138 + 0] = w(V0);

L8df14:	; 8008DF14
V0 = w[data_138 + 4];
8008DF24	lui    v1, $0008
8008DF28	and    v0, v0, v1
8008DF2C	beq    v0, zero, L8dfac [$8008dfac]
8008DF30	nop
8008DF34	lui    v1, $800b
8008DF38	lw     v1, $f1f0(v1)
8008DF3C	nop
8008DF40	sll    v0, v1, $01
8008DF44	addu   v0, v0, v1
8008DF48	sll    v0, v0, $03
8008DF4C	subu   v0, v0, v1
8008DF50	lui    v1, $800b
8008DF54	lw     v1, $efe4(v1)
8008DF58	sll    v0, v0, $02
8008DF5C	addu   v0, v0, v1
8008DF60	lw     v0, $0004(v0)
8008DF64	lui    v1, $fff7
8008DF68	sw     zero, $0018(v0)
8008DF6C	sw     zero, $0014(v0)
8008DF70	sw     zero, $000c(v0)
V0 = w[data_138 + 4];
8008DF78	ori    v1, v1, $ffff
[data_138 + 4] = w(V0 & V1);
8008DF7C	j      L8dfac [$8008dfa8]

L8df84:	; 8008DF84
V1 = hu[data_138 + 106];
[data_138 + 0] = w(w[data_138 + 0] | 00008000);
[data_138 + 11c] = h(V1);
8008DF94	j      L8dfac [$8008dfac]

L8df9c:	; 8008DF9C
[data_138 + 4] = w(w[data_138 + 4] & V1);

L8dfac:	; 8008DFAC
[data_138 + cc] = h(hu[data_138 + cc] + 2);
////////////////////////////////



////////////////////////////////
// 0xA7 func9eb84()
data_138 = w[800af54c];

if( ( w[data_138 + 0] & 00004000 ) == 0 )
{
    if( bu[800b16a2] == 0 )
    {
        [data_138 + 0] = w(w[data_138 + 0] | 01000000); // stop movement
    }
    [data_138 + cc] = h(hu[data_138 + cc] + 1); // move script pointer
    return;
}

V1 = 0;
loop9ebb0:	; 8009EBB0
    if( h[800c1b6c + V1 * 498 + 37c] == 0 )
    {
        break;
    }
    V1 = V1 + 1;
    V0 = V1 < 4;
8009EBD0	bne    v0, zero, loop9ebb0 [$8009ebb0]

if( ( V1 != 4 ) || ( h[800b164a] != 0 ) )
{
    [data_138 + 104] = h(8000);
    [data_138 + cc] = h(hu[data_138 + cc] + 1); // move script pointer
    return;
}

if( ( hu[800af370] >> c ) != 0 )
{
    func7889c();
}

[800ad040] = w(1);

if( w[data_138 + 14] & 00400000 )
{
    if( ( h[data_138 + 68] == h[data_138 + 22] ) && ( h[data_138 + 6a] == h[data_138 + 26] ) && ( h[data_138 + 6c] == h[data_138 + 2a] ) )
    {
        [800acfda] = h(hu[800acfda] + 1);
    }
}
else
{
    [800acfda] = h(0);
}

8009ECB0	lui    v0, $800b
8009ECB4	lh     v0, $cfda(v0)
8009ECB8	nop
8009ECBC	slti   v0, v0, $0021
8009ECC0	bne    v0, zero, L9ed18 [$8009ed18]
8009ECC4	ori    v1, zero, $0020
8009ECC8	lui    v0, $800b
8009ECCC	lhu    v0, $f370(v0)
8009ECD0	lui    at, $800b
8009ECD4	sh     v1, $cfda(at)
8009ECD8	andi   v0, v0, $0080
8009ECDC	beq    v0, zero, L9ed18 [$8009ed18]
8009ECE0	nop
8009ECE4	lui    v0, $800b
8009ECE8	lw     v0, $f54c(v0)
8009ECEC	nop
8009ECF0	lw     v0, $0000(v0)
8009ECF4	nop
8009ECF8	andi   v0, v0, $1800
8009ECFC	bne    v0, zero, L9ed18 [$8009ed18]
8009ED00	ori    v0, zero, $00ff
8009ED04	lui    v1, $800b
8009ED08	lw     v1, $d03c(v1)
8009ED0C	nop
8009ED10	beq    v1, v0, L9ed8c [$8009ed8c]
8009ED14	nop

L9ed18:	; 8009ED18
8009ED18	lui    v0, $800b
8009ED1C	lh     v0, $1818(v0)
8009ED20	nop
8009ED24	bne    v0, zero, L9edd8 [$8009edd8]
8009ED28	nop
8009ED2C	lui    v0, $800c
8009ED30	lhu    v0, $1b68(v0)
8009ED34	nop
8009ED38	andi   v0, v0, $0080
8009ED3C	beq    v0, zero, L9eea0 [$8009eea0]
8009ED40	nop
8009ED44	lui    v1, $800b
8009ED48	lw     v1, $f54c(v1)
8009ED4C	nop
8009ED50	lw     v0, $0000(v1)
8009ED54	nop
8009ED58	andi   v0, v0, $1800
8009ED5C	bne    v0, zero, L9eea0 [$8009eea0]
8009ED60	nop
8009ED64	lw     v0, $0014(v1)
8009ED68	lui    v1, $0040
8009ED6C	and    v0, v0, v1
8009ED70	bne    v0, zero, L9eea0 [$8009eea0]
8009ED74	ori    v0, zero, $00ff
8009ED78	lui    v1, $800b
8009ED7C	lw     v1, $d03c(v1)
8009ED80	nop
8009ED84	bne    v1, v0, L9eea0 [$8009eea0]
8009ED88	nop

L9ed8c:	; 8009ED8C
A0 = data_138;
8009ED94	jal    func81570 [$80081570]
8009ED98	nop
8009ED9C	bne    v0, zero, L9eea0 [$8009eea0]
8009EDA0	nop
8009EDA4	lui    v0, $800b
8009EDA8	lw     v0, $f54c(v0)
8009EDAC	nop
8009EDB0	lw     v1, $0000(v0)
8009EDB4	nop
8009EDB8	ori    v1, v1, $0800
8009EDBC	sw     v1, $0000(v0)
8009EDC0	lui    v0, $800b
8009EDC4	lw     v0, $1834(v0)
8009EDC8	lui    at, $800b
8009EDCC	sw     v0, $d000(at)
8009EDD0	j      L9eea0 [$8009eea0]
8009EDD4	nop

L9edd8:	; 8009EDD8
8009EDD8	lui    v0, $800c
8009EDDC	lhu    v0, $1b68(v0)
8009EDE0	nop
8009EDE4	andi   v0, v0, $0080
8009EDE8	beq    v0, zero, L9ee74 [$8009ee74]
8009EDEC	nop
8009EDF0	lui    v0, $800b
8009EDF4	lh     v0, $1816(v0)
8009EDF8	nop
8009EDFC	bne    v0, zero, L9ee88 [$8009ee88]
8009EE00	ori    v0, zero, $00ff
8009EE04	lui    v1, $800b
8009EE08	lw     v1, $d03c(v1)
8009EE0C	nop
8009EE10	bne    v1, v0, L9ee74 [$8009ee74]
8009EE14	nop
A0 = data_138;
8009EE20	jal    func81570 [$80081570]
8009EE24	nop
8009EE28	bne    v0, zero, L9ee74 [$8009ee74]
8009EE2C	nop
8009EE30	lui    v1, $800b
8009EE34	lw     v1, $f54c(v1)
8009EE38	nop
8009EE3C	lw     v0, $0000(v1)
8009EE40	nop
8009EE44	ori    v0, v0, $0800
8009EE48	sw     v0, $0000(v1)
8009EE4C	lui    a0, $800b
8009EE50	lw     a0, $1834(a0)
8009EE54	ori    v0, zero, $00ff
8009EE58	sh     v0, $00e8(v1)
8009EE5C	lui    v0, $800b
8009EE60	lhu    v0, $1814(v0)
8009EE64	lui    at, $800b
8009EE68	sw     a0, $d000(at)
8009EE6C	lui    at, $800b
8009EE70	sh     v0, $1816(at)

L9ee74:	; 8009EE74
8009EE74	lui    v0, $800b
8009EE78	lh     v0, $1816(v0)
8009EE7C	nop
8009EE80	beq    v0, zero, L9eea0 [$8009eea0]
8009EE84	nop

L9ee88:	; 8009EE88
8009EE88	lui    v1, $800b
8009EE8C	addiu  v1, v1, $1816
8009EE90	lhu    v0, $0000(v1)
8009EE94	nop
8009EE98	addiu  v0, v0, $ffff (=-$1)
8009EE9C	sh     v0, $0000(v1)

L9eea0:	; 8009EEA0
V0 = (hu[800af370] >> c) XOR f;

if( bu[800b1828] == 0 )
{
    A1 = hu[800ad440 + V0 * 2];
}
else
{
    A1 = hu[800ad460 + V0 * 2];
}

if( ( A1 & 8000 ) == 0 )
{
    A1 = (A1 - h[800aee60]) & 0fff;
}

[data_138 + 104] = h(A1);
[data_138 + cc] = h(hu[data_138 + cc] + 1); // move script pointer
////////////////////////////////



////////////////////////////////
// func7889c()
if( ( w[800ad0b4] == 0 ) || ( w[800ad0bc] == 0 ) || ( w[800adoc4] == 0 ) || ( w[8004e9ac] == -1 ) )
{
    return;
}

if( ( w[800b176c] == 0 ) || ( h[800b164a] == -1 ) || ( w[800ad004] == 1 ) || ( bu[800acfdc] == 0 ) )
{
    return;
}

[800b1768] = w(w[800b1768] - 1);
if( w[800b1768] == 0 )
{
    func8dcec(); // reinit 800b1774
}

if( w[800b1770] > 0 )
{
    S0 = 0;
    loop78994:	; 80078994
        if( hu[800b1774 + S0 * 2] != ffff )
        {
            [800b1774 + S0 * 2] = h(hu[800b1774 + S0 * 2] - 1);
        }
        S0 = S0 + 1;
        V0 = S0 < w[800b1770];
    800789B4	bne    v0, zero, loop78994 [$80078994]
}

if( w[800b1770] > 0 )
{
    S0 = 0;
    loop789dc:	; 800789DC
        if( hu[800b1774 + S0 * 2] == 0 )
        {
            [800b1774 + S0 * 2] = h(ffff);

            max_chance = 0;

            // get total encounter chance and
            // store chance for current encounter
            A0 = 0;
            loop78a50:	; 80078A50
                [SP + 10 + A0 * 4] = w(max_chance);
                max_chance = max_chance + bu[8006516c + A0]; // last row in encounter file
                A0 = A0 + 1;
                V0 = A0 < 10;
            80078A68	bne    v0, zero, loop78a50 [$80078a50]

            // calculate current chance value
            system_get_random_2_bytes();
            cur_chance = (V0 * (max_chance + 1)) >> f;

            // find encounter
            found = 0;
            encounter = f;
            loop78a94:	; 80078A94
                if( ( bu[8006516c + encounter] != 0 ) && ( w[SP + 10 + encounter * 4] < cur_chance ) ) // last row in encounter file
                {
                    found = 1;
                    break;
                }
                encounter = encounter - 1;
            80078AC8	bgez   encounter, loop78a94 [$80078a94]

            if( found != 0 )
            {
                [80058ba4] = b(encounter);
                [80058b94] = b(0);
                [800b1764] = h(hu[800b1774 + encounter * 2]);

                if( w[8004ea14] == 0 )
                {
                    A0 = 2;
                    func19a50();
                }

                [800ad0b4] = w(0);
                [800adoa8] = w(1);

                if( w[800c1b60] == 0 )
                {
                    A0 = encounter;
                    80078B3C	0C0A0487	‡...
                }
            }
        }

        S0 = S0 + 1;
        V0 = S0 < w[800b1770];
    800789F8	bne    v0, zero, loop789dc [$800789dc]
}
////////////////////////////////



////////////////////////////////
// func8dcec()
[800b1768] = w(w[800b176c]);

if( w[800b1770] == 0 )
{
    [800b176c] = w(0);
    return;
}

S0 = 1f;
loop8dd3c:	; 8008DD3C
    [800b1774 + S0 * 2] = h(ffff);
    S0 = S0 - 1;
8008DD44	bgez   s0, loop8dd3c [$8008dd3c]

// generate unique random calue to array 800b1774
if( w[800b1770] > 0 )
{
    S0 = 0;
    loop8dd6c:	; 8008DD6C
        // gen random from 0 - w[800b176c]
        system_get_random_2_bytes();
        A1 = (((w[800b176c] + 1) * V0) >> f) & ffff;
        A0 = 0;
        loop8dd9c:	; 8008DD9C
            // if this randim value already exist - generate other one
            if( hu[800b1774 + A0 * 2] == A1 )
            {
                8008DDA4	j      loop8dd6c [$8008dd6c]
            }
            A0 = A0 + 1;
            V0 = A0 < 20;
        8008DDB0	bne    v0, zero, loop8dd9c [$8008dd9c]

        [800b1774 + S0 * 2] = h(A1);
        S0 = S0 + 1;
        V0 = S0 < w[800b1770];
    8008DDC8	bne    v0, zero, loop8dd6c [$8008dd6c]
}

if( w[800b1770] > 0 )
{
    S0 = 0;
    loop8ddf0:	; 8008DDF0
        [800b1774 + S0 * 2] = h(hu[800b1774 + S0 * 2] + 1);
        S0 = S0 + 1;
        V0 = S0 < w[800b1770];
    8008DE0C	bne    v0, zero, loop8ddf0 [$8008ddf0]
}
////////////////////////////////
