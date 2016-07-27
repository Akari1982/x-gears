////////////////////////////////
// load_poly_00_18
// A2 = 0 - not calculate light
//      1 - calculate light but not store it
//      3 - calculate light and store it
//      4 - use calculated stored light

texture_data_offset = A0;
mesh_data_offset = A1;
packet = w[80058ac0];

[packet + 3] = b(04);

if( A2 & 1 )
{
    if( A2 & 2 ) // calculate notmal and store it
    {
        V1 = w[80058b34]; // precalculated normal pointer
        [V1] = w(w[texture_data_offset + 0]);
        [80058b34] = w(w[80058b34] + 4);

        // pointers to vertexes
        A0 = w[80058bd8] + h[mesh_data_offset + 0] * 8;
        A1 = w[80058bd8] + h[mesh_data_offset + 2] * 8;
        A2 = w[80058bd8] + h[mesh_data_offset + 4] * 8;
        A3 = w[80058b34]; // store result here
        system_calculate_normal_for_lighting;

        A0 = w[80058b34];
        A1 = texture_data_offset;
        A2 = packet + 4;
        system_gte_calculate_normal_color_by_vector_and_color;

        [80058b34] = w(w[80058b34] + 8);
        [packet + 7] = b(bu[texture_data_offset + 3]);
    }
    else // calculate and use normal but not store it
    {
        A0 = w[80058bd8] + h[mesh_data_offset + 0] * 8;
        A1 = w[80058bd8] + h[mesh_data_offset + 2] * 8;
        A2 = w[80058bd8] + h[mesh_data_offset + 4] * 8;
        A3 = SP + 10;
        system_calculate_normal_for_lighting;

        A0 = SP + 10;
        A1 = texture_data_offset;
        A2 = packet + 4;
        system_gte_calculate_normal_color_by_vector_and_color;

        [packet + 7] = b(bu[texture_data_offset + 3]);
    }
}
else if( A2 & 4 ) // use stored normal
{
    A0 = w[80058b34] + 4;
    A1 = texture_data_offset;
    A2 = packet + 4;
    [80058b34] = w(A0);
    system_gte_calculate_normal_color_by_vector_and_color;

    [80058b34] = w(w[80058b34] + 8);
    [packet + 7] = b(bu[texture_data_offset + 3]);
}
else // not calculate light
{
    [packet + 4] = w(w[texture_data_offset + 0]);
}
return 1;
////////////////////////////////



////////////////////////////////
// load_poly_01_18
// A2 = 0 - not calculate light
//      1 - calculate light but not store it
//      3 - calculate light and store it
//      4 - use calculated stored light

texture_data_offset = A0;
mesh_data_offset = A1;
S2 = A2;

A0 = texture_data_offset
func2cb74; // check 0xc4 0xc8 in textures data
if( V0 == 0 )
{
    return 0;
}

packet = w[80058ac0];
[packet +  3] = b(07);
[packet +  c] = w((hu[800589ac] << 10) | hu[texture_data_offset + 4]); // clut and UV for vertex 1
[packet + 14] = w((hu[800589a8] << 10) | hu[texture_data_offset + 6]);
[packet + 1c] = h(hu[texture_data_offset + 0]);

if( S2 & 1 )
{
    if( S2 & 2 )
    {
        A0 = w[80058bd8] + h[mesh_data_offset + 0] * 8;
        A1 = w[80058bd8] + h[mesh_data_offset + 2] * 8;
        A2 = w[80058bd8] + h[mesh_data_offset + 4] * 8;
        A3 = w[80058b34];
        system_calculate_normal_for_lighting;

        A0 = w[80058b34];
        A1 = packet + 4;
        system_gte_calculate_normal_color_by_vector_only;
    }
    else
    {
        A0 = w[80058bd8] + h[mesh_data_offset + 0] * 8;
        A1 = w[80058bd8] + h[mesh_data_offset + 2] * 8;
        A2 = w[80058bd8] + h[mesh_data_offset + 4] * 8;
        A3 = SP + 10;
        system_calculate_normal_for_lighting;

        A0 = SP + 10;
        A1 = packet + 4;
        system_gte_calculate_normal_color_by_vector_only;
    }
}
else if (S2 & 4)
{
    A0 = w[80058b34];
    A1 = packet + 4;
    system_gte_calculate_normal_color_by_vector_only;
}

[80058b34] = w(w[80058b34] + 8);
[packet + 7] = b(bu[texture_data_offset + 3]);

return 1;
////////////////////////////////



////////////////////////////////
// load_poly_02_18
// A2 = 0 - not calculate light
//      1 - calculate light but not store it
//      3 - calculate light and store it
//      4 - use calculated stored light

texture_data_offset = A0;
mesh_data_offset = A1;

packet = w[80058ac0];
[packet +  3] = b(06);

if( A2 & 2 )
{
    V1 = w[80058b34]; // precalculated normal pointer
    [V1] = w(w[texture_data_offset + 0]);
    [80058b34] = w(w[80058b34] + 4);
}

A0 = w[80058bd8] + h[mesh_data_offset + 0] * 8;
A1 = w[80058bd8] + h[mesh_data_offset + 2] * 8;
A2 = w[80058bd8] + h[mesh_data_offset + 4] * 8;
A3 = texture_data_offset;
A4 = packet + 4;  // out0
A5 = packet + c;  // out1
A6 = packet + 14; // out2
system_gte_calculate_normals_color_by_3vectors_and_color;

[packet + 7] = b(bu[texture_data_offset + 3]);

return 1;
////////////////////////////////



////////////////////////////////
// load_poly_03_18

texture_data_offset = A0; // texture data offset
mesh_data_offset = A1; // polygon data pointer

A0 = texture_data_offset
func2cb74; // check 0xc4 0xc8 in textures data
if( V0 == 0 )
{
    return 0;
}

packet = w[80058ac0];
[packet + 3] = b(09);

A0 = w[80058bd8] + h[mesh_data_offset + 0] * 8; // vertex data 1
A1 = w[80058bd8] + h[mesh_data_offset + 2] * 8; // vertex data 2
A2 = w[80058bd8] + h[mesh_data_offset + 4] * 8; // vertex data 3
A3 = packet + 4;
A4 = packet + 10;
A5 = packet + 1c;
system_gte_calculate_normals_color_by_3vectors_only;

[packet +  c] = w((hu[800589ac] << 10) | hu[texture_data_offset + 4]); // clut and UV for vertex 1
[packet + 18] = w((hu[800589a8] << 10) | hu[texture_data_offset + 6]);
[packet + 24] = h(hu[texture_data_offset + 0]);

[S0 +  7] = b(bu[texture_data_offset + 3]);

return 1;
////////////////////////////////



////////////////////////////////
// load_poly_04_18

texture_data_offset = A0;
packet = w[80058ac0]; // place for packets
[packet + 3] = b(04);
[packet + 4] = w(w[texture_data_offset + 0]);
return 1;
////////////////////////////////



////////////////////////////////
// load_poly_05_18
S0 = A0; // texture data offset

func2cb74;
if (V0 == 0)
{
    return 0;
}

A0 = w[80058ac0]; // place for packets
[A0 +  3] = b(07);

[A0 +  c] = w((hu[800589ac] << 10) | hu[S0 + 4]); Clut and UV for vertex 1
[A0 + 14] = w((hu[800589a8] << 10) | hu[S0 + 6]);
[A0 + 1c] = h(hu[S0 + 0]);
[A0 +  7] = b(bu[S0 + 3]);

return 1;
////////////////////////////////



////////////////////////////////
// load_poly_09_18
S3 = A0; // texture data offset
S1 = A1; // polygon data pointer
S2 = A2; // flags

func2cb74;
if (V0 == 0)
{
    return 0;
}

S0 = w[80058ac0]; // place for packets
[S0 +  3] = b(09);
[S0 +  c] = w((hu[800589ac] << 10) | hu[S3 + 4]); Clut and UV for vertex 1
[S0 + 14] = w((hu[800589a8] << 10) | hu[S3 + 6]);
[S0 + 1c] = h(hu[S3 + 8]);
[S0 + 24] = h(hu[S3 + a]);

if (S2 & 1)
{
    A0 = w[80058bd8] + h[S1 + 0] * 8; // vertex data 1
    A1 = w[80058bd8] + h[S1 + 2] * 8; // vertex data 2
    A2 = w[80058bd8] + h[S1 + 4] * 8; // vertex data 3

    if (S2 & 2)
    {
        A3 = w[80058b34];
        system_calculate_normal_for_lighting;

        A0 = w[80058b34];
    }
    else
    {
        A3 = SP + 10;
        system_calculate_normal_for_lighting;

        A0 = SP + 10;
    }

    A1 = S0 + 4;
    system_gte_calculate_normal_color_by_vector_only;
}
else if (S2 & 4)
{
    A0 = w[80058b34];
    A1 = S0 + 4;
    system_gte_calculate_normal_color_by_vector_only;
}

[80058b34] = w(w[80058b34] + 8);

[S0 + 7] = b(bu[S3 + 3]);

return 1;
////////////////////////////////



////////////////////////////////
// load_poly_0c_18
V0 = w[80058ac0]; // place for packets
[V0 + 3] = b(05);
[V0 + 4] = w(w[A0 + 0]);

return 1;
////////////////////////////////



////////////////////////////////
// load_poly_0d_18
8002CF00	jal    func2cb74 [$8002cb74]
8002CF04	addu   s0, a0, zero
8002CF08	beq    v0, zero, L2cf78 [$8002cf78]
8002CF0C	ori    v0, zero, $0009
8002CF10	lui    a0, $8006
8002CF14	lw     a0, $8ac0(a0)
8002CF18	nop
8002CF1C	sb     v0, $0003(a0)
8002CF20	lw     v0, $0000(s0)
8002CF24	nop
8002CF28	sw     v0, $0004(a0)
8002CF2C	lui    v0, $8006
8002CF30	lhu    v0, $89ac(v0)
8002CF34	lhu    v1, $0004(s0)
8002CF38	sll    v0, v0, $10
8002CF3C	or     v1, v1, v0
8002CF40	sw     v1, $000c(a0)
8002CF44	lui    v0, $8006
8002CF48	lhu    v0, $89a8(v0)
8002CF4C	lhu    v1, $0006(s0)
8002CF50	sll    v0, v0, $10
8002CF54	or     v1, v1, v0
8002CF58	sw     v1, $0014(a0)
8002CF5C	lhu    v0, $0008(s0)
8002CF60	nop
8002CF64	sh     v0, $001c(a0)
8002CF68	lhu    v1, $000a(s0)
8002CF6C	ori    v0, zero, $0001
8002CF70	j      L2cf7c [$8002cf7c]
8002CF74	sh     v1, $0024(a0)

L2cf78:	; 8002CF78
8002CF78	addu   v0, zero, zero

L2cf7c:	; 8002CF7C
////////////////////////////////



////////////////////////////////
// func2cb74
A1 = bu[A0 + 3];
if( A1 == c4 )
{
    system_set_texture_page_settings;
    return 0;
}
if( A1 == c8 )
{
    system_set_clut_settings;
    return 0;
}

return 1;
////////////////////////////////



////////////////////////////////
// system_set_texture_page_settings
[800589a8] = h(hu[A0 + 0]);

if (w[8004f7ac] == 1)
{
    [800589a8] = h(w[800589b0] | (hu[[800589a8]] & ffe0));
}
else if (V1 == 2)
{
    [800589a8] = h(w[800589b0]);
}
////////////////////////////////



////////////////////////////////
// system_set_clut_settings
[800589ac] = h(hu[A0 + 0]);

if (w[8004f7b0] == 0)
{
    [800589ac] = h(w[800589b4] | (hu[[800589ac]] & 000f));
}
////////////////////////////////
