////////////////////////////////
// func19a50
S0 = A0;
if( w[8005895c] != S0 )
{
    [8005895c] = w(S0);

    S2 = hu[GP + 1ac];

    A0 = SP + 10;
    A1 = SP + 14;
    80019A8C	jal    func282c4 [$800282c4]

    A0 = 6;
    80019A94	jal    func319b8 [$800319b8]

    A0 = 0;
    A1 = 1;
    80019AA0	jal    func28280 [$80028280]

    A0 = 1;
    80019AA8	jal    func319c4 [$800319c4]

    S1 = V0;

    A0 = w[8004e948 + S0 * 4]; // 00000000 0E000000 10000000 0F000000 0D000000 11000000 12000000 00000000
    func28548();

    A0 = V0;
    A1 = 1;
    system_memory_allocate();
    [80058958] = w(V0);

    if( V0 != 0 )
    {
        A0 = w[8004e948 + S0 * 4];
        A1 = V0;
        A2 = 0;
        A3 = 0;
        80019AF0	jal    func293e8 [$800293e8]
    }
    else
    {
        [8005895c] = w(-1);
    }

    A0 = S1;
    80019B0C	jal    func319c4 [$800319c4]

    A0 = w[SP + 10];
    A1 = w[SP + 14];
    80019B1C	jal    func28280 [$80028280]

    A0 = S2;
    80019B24	jal    func319b8 [$800319b8]
}

return w[80058958];
////////////////////////////////



////////////////////////////////
// func28548()
S2 = A0;

if( w[8004f4ec] != 0 )
{
    A0 = S2;
    func287a8();

    A0 = V0;
    A1 = 0;
    A2 = 0;
    8002857C	jal    func4c1c0 [$8004c1c0]

    80028584	addu   s0, v0, zero

    A0 = S0;
    A1 = 0;
    A2 = 2;
    80028590	jal    func4c1f0 [$8004c1f0]

    80028598	addu   s1, v0, zero

    A0 = S0;
    8002859C	jal    func4c1e0 [$8004c1e0]

    if( S1 > 0 )
    {
        return S1;
    }
}

A0 = w[8004f494]; // pointer to 0x80010004
V0 = w[8004f4b8] + S2 - 1; // 0x01a7 + S2 - 1
// some files stored here at offset 0x1a7 * 7
// D5D101FEFFFFFF STRIPCD1\7 dir
// D5D101DC110200 STRIPCD1\7\0424
// 18D201D4EA0000 STRIPCD1\7\0425
// 36D201DFFFFFFF STRIPCD1\8 dir
// 36D20138DD0000 STRIPCD1\8\0427
// and so on up to
// 11D30114D70000 STRIPCD1\8\0436
// 2CD30120D60000 STRIPCD1\8\0437 S2 = 0D
// 47D301309E0000 STRIPCD1\8\0438 S2 = 0E
// 5BD30138DD0000 STRIPCD1\8\0439 S2 = 0F
// 77D30138DD0000 STRIPCD1\8\0440 S2 = 10
// 93D30138DD0000 STRIPCD1\8\0441 S2 = 11
// AFD30138DD0000 STRIPCD1\8\0442 S2 = 12
// and so on up to
// 42D5019CAA0000 STRIPCD1\8\0459
return w[A0 + V0 * 7 + 3];
////////////////////////////////



////////////////////////////////
// func287a8()
if( w[8004f4ec] != 0 )
{
    V0 = w[8004f4b8] + A0 - 1;
    return w[8004f4ec] + V0 * 40;
}
return 0;
////////////////////////////////
