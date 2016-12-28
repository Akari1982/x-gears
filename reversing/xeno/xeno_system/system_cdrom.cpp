////////////////////////////////
// func4142c()

cd_1800 = w[80055e10]; // 1f801800
cd_1801 = w[80055e14]; // 1f801801
cd_1802 = w[80055e18]; // 1f801802
cd_1803 = w[80055e1c]; // 1f801803

[cd_1800] = b(01); // set index to 1



// get interrupt and check it
V0 = bu[cd_1803] & 07; // response received INT1..INT7
[SP + 10] = b(V0);
if( V0 == 0 )
{
    return 0;
}



// get last interrupt
80041478	j      L41490 [$80041490]
loop41480:	; 80041480
    [SP + 10] = b(bu[cd_1803] & 07);
    L41490:	; 80041490
    V0 = bu[cd_1803] & 07;
    V1 = bu[SP + 10];
8004149C	bne    v1, v0, loop41480 [$80041480]



// store response fifo
S0 = 0;
loop414a8:	; 800414A8
    if( ( bu[cd_1800] & 20 ) == 0 ) // response fifo empty (0 = Empty)
    {
        break;
    }
    // store index1 - response fifo
    [SP + 18 + S0] = b(bu[cd_1801]);
    S0 = S0 + 1;
    V0 = S0 < 8;
800414E4	bne    v0, zero, loop414a8 [$800414a8]



// store rest of fifo stored data as 0
if( S0 < 8 )
{
    V1 = S0;
    loop41500:	; 80041500
        [SP + 18 + V1] = b(0);
        V1 = V1 + 1;
        V0 = V1 < 8;
    8004150C	bne    v0, zero, loop41500 [$80041500]
}



[cd_1800] = b(01);
[cd_1803] = b(07);
[cd_1802] = b(07);



S1 = 0;
V0 = bu[80055b69];
if( ( bu[SP + 10] != 3 ) || ( w[80055d10 + V0 * 4] != 0 ) )
{
    if( ( w[80055b58] & 00000010 ) == 0 )
    {
        // shell open once shell open (0 = closed, 1 = is/was open)
        if( bu[SP + 18] & 10 )
        {
            [80055b60] = w(w[80055b60] + 1);
        }
    }

    S1 = bu[SP + 18] & 1d;
    [80055b58] = w(bu[SP + 18]);
    [80055b5c] = w(bu[SP + 19]);
}



// CdlDiskError
if( bu[SP + 10] == 5 )
{
    if( w[80055b54] > 0 )
    {
        A0 = 80018ee8; // "DiskError:"
        80041614	jal    func199e8 [$800199e8]

        if( w[80055b54] > 0 )
        {
            A0 = 80018ef4; // "com=%s,code=(%02x:%02x)"
            V0 = bu[80055b69];
            A1 = w[80055b70 + V0 * 4];
            A2 = w[80055b58];
            A3 = w[80055b5c];
            80041660	jal    func199e8 [$800199e8]
        }
    }
}



switch( bu[SP + 10] )
{
    case 1: // CdlDataReady
    {
        if( S1 == 0 )
        {
            [80055e29] = b(1); // CdlDataReady
        }
        else
        {
            if( S0 == 1 )
            {
                S1 = 0;
            }

            if( S1 == 0 )
            {
                [80055e29] = b(1); // CdlDataReady
            }
            else
            {
                [80055e29] = b(5); // CdlDiskError
            }
        }

        A1 = 0;
        A0 = 7;
        loop41828:	; 80041828
            [800598b4 + A1] = b(bu[SP + 18 + A1]);
            A1 = A1 + 1;
            A0 = A0 - 1;
        80041838	bne    a0, -1, loop41828 [$80041828]

        [cd_1800] = b(0);
        [cd_1803] = b(0);
        return 4;
    }
    break;

    case 2: // CdlComplete
    {
        if( S1 == 0 )
        {
            [80055e29] = b(2); // CdlComplete
        }
        else
        {
            [80055e29] = b(5); // CdlDiskError
        }

        A1 = 0;
        A0 = 7;
        loop41828:	; 80041828
            [800598ac + A1] = b(bu[SP + 18 + A1]);
            A1 = A1 + 1;
            A0 = A0 - 1;
        80041838	bne    a0, -1, loop41828 [$80041828]

        return 2;
    }
    break;

    case 3: // CdlAcknowledge
    {
        80041698	beq    s1, zero, L416e4 [$800416e4]
        8004169C	addiu  v0, zero, $0005
        800416A0	lui    v1, $8005
        800416A4	addiu  v1, v1, $5e28
        800416A8	sb     v0, $0000(v1)
        800416AC	lui    v1, $8006
        800416B0	addiu  v1, v1, $98ac (=-$6754)
        800416B4	beq    v1, zero, L417dc [$800417dc]
        800416B8	addiu  a1, sp, $0018
        800416BC	addiu  a0, zero, $0007
        800416C0	addiu  a2, zero, $ffff (=-$1)

        loop416c4:	; 800416C4
            800416C4	lbu    v0, $0000(a1)
            800416C8	addiu  a1, a1, $0001
            800416CC	addiu  a0, a0, $ffff (=-$1)
            800416D0	sb     v0, $0000(v1)
            800416D8	addiu  v1, v1, $0001
        800416D4	bne    a0, a2, loop416c4 [$800416c4]

        return 2;

        L416e4:	; 800416E4
        800416E4	lui    v0, $8005
        800416E8	lbu    v0, $5b69(v0)
        800416EC	nop
        800416F0	sll    v0, v0, $02
        800416F4	lui    at, $8005
        800416F8	addu   at, at, v0
        800416FC	lw     v0, $5c10(at)
        80041700	nop
        80041704	beq    v0, zero, L41750 [$80041750]
        80041708	addiu  v0, zero, $0003
        8004170C	lui    v1, $8005
        80041710	addiu  v1, v1, $5e28
        80041714	sb     v0, $0000(v1)
        80041718	lui    v1, $8006
        8004171C	addiu  v1, v1, $98ac (=-$6754)
        80041720	beq    v1, zero, L41748 [$80041748]
        80041724	addiu  a1, sp, $0018
        80041728	addiu  a0, zero, $0007
        8004172C	addiu  a2, zero, $ffff (=-$1)

        loop41730:	; 80041730
        80041730	lbu    v0, $0000(a1)
        80041734	addiu  a1, a1, $0001
        80041738	addiu  a0, a0, $ffff (=-$1)
        8004173C	sb     v0, $0000(v1)
        80041740	bne    a0, a2, loop41730 [$80041730]
        80041744	addiu  v1, v1, $0001

        L41748:	; 80041748
        return 1;

        L41750:	; 80041750
        80041750	lui    v1, $8005
        80041754	addiu  v1, v1, $5e28
        80041758	addiu  v0, zero, $0002
        8004175C	sb     v0, $0000(v1)
        80041760	lui    v1, $8006
        80041764	addiu  v1, v1, $98ac (=-$6754)
        80041768	beq    v1, zero, L417dc [$800417dc]
        8004176C	addiu  a1, sp, $0018
        80041770	addiu  a0, zero, $0007
        80041774	addiu  a2, zero, $ffff (=-$1)

        loop41778:	; 80041778
        80041778	lbu    v0, $0000(a1)
        8004177C	addiu  a1, a1, $0001
        80041780	addiu  a0, a0, $ffff (=-$1)
        80041784	sb     v0, $0000(v1)
        80041788	bne    a0, a2, loop41778 [$80041778]
        8004178C	addiu  v1, v1, $0001
        return 2;
    }
    break;

    case 4: // CdlDataEnd
    {
        80041868	lui    a0, $8006
        8004186C	addiu  a0, a0, $98bc (=-$6744)
        80041870	addiu  v0, zero, $0004
        80041874	lui    at, $8005
        80041878	sb     v0, $5e2a(at)
        8004187C	lui    v0, $8005
        80041880	lbu    v0, $5e2a(v0)
        80041884	addiu  a1, sp, $0018
        80041888	lui    at, $8005
        8004188C	sb     v0, $5e29(at)
        80041890	beq    a0, zero, L418b4 [$800418b4]
        80041894	addiu  v1, zero, $0007
        80041898	addiu  a2, zero, $ffff (=-$1)

        loop4189c:	; 8004189C
        8004189C	lbu    v0, $0000(a1)
        800418A0	addiu  a1, a1, $0001
        800418A4	addiu  v1, v1, $ffff (=-$1)
        800418A8	sb     v0, $0000(a0)
        800418AC	bne    v1, a2, loop4189c [$8004189c]
        800418B0	addiu  a0, a0, $0001

        L418b4:	; 800418B4
        800418B4	lui    v1, $8006
        800418B8	addiu  v1, v1, $98b4 (=-$674c)
        800418BC	beq    v1, zero, L418e4 [$800418e4]
        800418C0	addiu  a1, sp, $0018
        800418C4	addiu  a0, zero, $0007
        800418C8	addiu  a2, zero, $ffff (=-$1)

        loop418cc:	; 800418CC
        800418CC	lbu    v0, $0000(a1)
        800418D0	addiu  a1, a1, $0001
        800418D4	addiu  a0, a0, $ffff (=-$1)
        800418D8	sb     v0, $0000(v1)
        800418DC	bne    a0, a2, loop418cc [$800418cc]
        800418E0	addiu  v1, v1, $0001

        L418e4:	; 800418E4
        return 4;
    }
    break;

    case 5: // CdlDiskError
    {
        800418EC	lui    a0, $8006
        800418F0	addiu  a0, a0, $98ac (=-$6754)
        800418F4	addiu  a1, sp, $0018
        800418F8	addiu  v0, zero, $0005
        800418FC	lui    at, $8005
        80041900	sb     v0, $5e29(at)
        80041904	lui    v1, $8005
        80041908	lbu    v1, $5e29(v1)
        8004190C	lui    v0, $8005
        80041910	addiu  v0, v0, $5e28
        80041914	sb     v1, $0000(v0)
        80041918	beq    a0, zero, L4193c [$8004193c]
        8004191C	addiu  v1, zero, $0007
        80041920	addiu  a2, zero, $ffff (=-$1)

        loop41924:	; 80041924
        80041924	lbu    v0, $0000(a1)
        80041928	addiu  a1, a1, $0001
        8004192C	addiu  v1, v1, $ffff (=-$1)
        80041930	sb     v0, $0000(a0)
        80041934	bne    v1, a2, loop41924 [$80041924]
        80041938	addiu  a0, a0, $0001

        L4193c:	; 8004193C
        8004193C	lui    v1, $8006
        80041940	addiu  v1, v1, $98b4 (=-$674c)
        80041944	beq    v1, zero, L4196c [$8004196c]
        80041948	addiu  a1, sp, $0018
        8004194C	addiu  a0, zero, $0007
        80041950	addiu  a2, zero, $ffff (=-$1)

        loop41954:	; 80041954
        80041954	lbu    v0, $0000(a1)
        80041958	addiu  a1, a1, $0001
        8004195C	addiu  a0, a0, $ffff (=-$1)
        80041960	sb     v0, $0000(v1)
        80041964	bne    a0, a2, loop41954 [$80041954]
        80041968	addiu  v1, v1, $0001

        L4196c:	; 8004196C
        return 6;
    }

    default:
    {
        A0 = 80018f10; // "CDROM: unknown intr"
        8004197C	jal    func42c04 [$80042c04]

        A0 = 80018f24; // "(%d)"
        A1 = bu[SP + 10];
        80041990	jal    func199e8 [$800199e8]

        return 0;
    }
}
////////////////////////////////
