////////////////////////////////
// func7889c
8007889C	lui    v0, $800b
800788A0	lw     v0, $d0b4(v0)
if( V0 == 0 )
{
    return;
}

800788BC	lui    v0, $800b
800788C0	lw     v0, $d0bc(v0)
800788C4	nop
800788C8	beq    v0, zero, L78b44 [$80078b44]
800788CC	nop
800788D0	lui    v0, $800b
800788D4	lw     v0, $d0c4(v0)
800788D8	nop
800788DC	beq    v0, zero, L78b44 [$80078b44]
800788E0	addiu  v1, zero, $ffff (=-$1)
800788E4	lui    v0, $8005
800788E8	lw     v0, $e9ac(v0)
800788EC	nop
800788F0	beq    v0, v1, L78b44 [$80078b44]
800788F4	nop
800788F8	lui    s1, $800b
800788FC	addiu  s1, s1, $176c
80078900	lw     v0, $0000(s1)
80078904	nop
80078908	beq    v0, zero, L78b44 [$80078b44]
8007890C	nop
80078910	lui    v0, $800b
80078914	lh     v0, $164a(v0)
80078918	nop
8007891C	beq    v0, v1, L78b44 [$80078b44]
80078920	nop
80078924	lui    v1, $800b
80078928	lw     v1, $d004(v1)
8007892C	ori    v0, zero, $0001
80078930	beq    v1, v0, L78b44 [$80078b44]
80078934	nop
80078938	lui    v0, $800b
8007893C	lbu    v0, $cfdc(v0)
80078940	nop
80078944	beq    v0, zero, L78b44 [$80078b44]
80078948	nop
8007894C	lui    v0, $800b
80078950	lw     v0, $1768(v0)
80078954	nop
80078958	addiu  v0, v0, $ffff (=-$1)
8007895C	lui    at, $800b
80078960	sw     v0, $1768(at)
80078964	bne    v0, zero, L78974 [$80078974]
80078968	nop
8007896C	jal    func8dcec [$8008dcec]
80078970	nop

L78974:	; 80078974
80078974	lui    v0, $800b
80078978	lw     v0, $1770(v0)
8007897C	nop
80078980	blez   v0, L789bc [$800789bc]
80078984	addu   s0, zero, zero
80078988	ori    a1, zero, $ffff
8007898C	addiu  a0, s1, $0008
80078990	addu   v1, a0, zero

loop78994:	; 80078994
    80078994	lhu    v0, $0000(v1)
    80078998	nop
    8007899C	beq    v0, a1, L789a8 [$800789a8]
    800789A0	addiu  v0, v0, $ffff (=-$1)
    800789A4	sh     v0, $0000(v1)

    L789a8:	; 800789A8
    800789B8	addiu  v1, v1, $0002
    800789A8	lw     v0, $fffc(a0)
    800789AC	addiu  s0, s0, $0001
    800789B0	slt    v0, s0, v0
800789B4	bne    v0, zero, loop78994 [$80078994]

L789bc:	; 800789BC

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
                if( bu[8006516c + encounter] != 0 && w[SP + 10 + encounter * 4] < cur_chance ) // last row in encounter file
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

return;
L78b44:	; 80078B44
////////////////////////////////