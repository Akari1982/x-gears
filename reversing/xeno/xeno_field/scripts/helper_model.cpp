////////////////////////////////////////////////////////
// set_position_by_x_z
x = A0;
z = A1;
offset_to_current_entity   = w[800af54c];
curently_initing_entity_id = w[800af1f0];
entity_data                = w[800aefe4];
S3 = w[entity_data + curently_initing_entity_id * 5c + 4];

V1 = h[800af028];
V1 = V1 - 1;
if (V1 <= 0)
{
    walkmesh_id = 0;
    S2 = SP + 18;
    S1 = SP + 58;

    loop9db74:	; 8009DB74
        A0 = x;
        A1 = z;
        A2 = walkmesh_id;
        A3 = S1;
        [SP + 10] = w(S2);
        func7a7d8;

        [offset_to_current_entity + 8 + walkmesh_id * 2] = h(V0);

        walkmesh_id = walkmesh_id + 1;
        S1 = S1 + 8;
        S2 = S2 + 10;
        V0 = walkmesh_id < h[800af028] - 1;
    8009DBB8	bne    v0, zero, loop9db74 [$8009db74]
}

A0 = offset_to_current_entity;
get_current_triangle_material;
[offset_to_current_entity + 14] = w(V0);

V1 = h[offset_to_current_entity + 10];
[offset_to_current_entity + 50] = w(w[SP + 18 + V1 * 10 + 0]);
[offset_to_current_entity + 54] = w(w[SP + 18 + V1 * 10 + 4]);
[offset_to_current_entity + 58] = w(w[SP + 18 + V1 * 10 + 8]);

[entity_data + curently_initing_entity_id * 5c + 20] = w(x);
[entity_data + curently_initing_entity_id * 5c + 40] = w(x);
[entity_data + curently_initing_entity_id * 5c + 24] = w(h[SP + 58 + V1 * 8 + 2]);
[entity_data + curently_initing_entity_id * 5c + 44] = w(h[SP + 58 + V1 * 8 + 2]);
[entity_data + curently_initing_entity_id * 5c + 28] = w(z);
[entity_data + curently_initing_entity_id * 5c + 48] = w(z);

[S3 + 84] = h(hu[SP + 58 + V1 * 8 + 2]);

[offset_to_current_entity + 20] = w(x << 10);
[offset_to_current_entity + 24] = w(h[SP + 58 + V1 * 8 + 2] << 10);
[offset_to_current_entity + 28] = w(z << 10);

[offset_to_current_entity + 72] = h(hu[SP + 58 + V1 * 8 + 2]);

[S3 + 0] = w(w[offset_to_current_entity + 20]);
[S3 + 4] = w(w[offset_to_current_entity + 24]);
[S3 + 8] = w(w[offset_to_current_entity + 28]);

[offset_to_current_entity + 40] = w(0);
[offset_to_current_entity + 44] = w(0);
[offset_to_current_entity + 48] = w(0);

[offset_to_current_entity + 30] = w(0);
[offset_to_current_entity + 34] = w(0);
[offset_to_current_entity + 38] = w(0);

[offset_to_current_entity + d0] = w(0);
[offset_to_current_entity + d4] = w(0);
[offset_to_current_entity + d8] = w(0);

[offset_to_current_entity + 60] = h(0);
[offset_to_current_entity + 62] = h(0);
[offset_to_current_entity + 64] = h(0);

[S3 + 0c] = w(0);
[S3 + 10] = w(0);
[S3 + 14] = w(0);

[offset_to_current_entity + ec] = w(0);
[offset_to_current_entity + f0] = w(0);

[offset_to_current_entity + 72] = h(h[offset_to_current_entity + 26]);

V1 = w[offset_to_current_entity + 0];
V1 = V1 & fffbffff
V1 = V1 | 00400000;
[offset_to_current_entity] = w(V1);
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// func7a7d8

x = A0;
z = A1;
walkmesh_id = A2;
ret_normal = A4;
ret_position = A3;

[SP + 60] = h(x);
[SP + 62] = h(0);
[SP + 64] = h(z);

triangle_data = w[800aeff8 + walkmesh_id * 4];
number_of_triangles = w[800af018 + walkmesh_id * 4];
vertex_data = w[800af008 + walkmesh_id * 4];

if( number_of_triangles > 0 )
{
    S0 = 0;
    L7a838:	; 8007A838
        T0 = (x << 10) + z;
        V0 = vertex_data + h[triangle_data + S0 * e + 0] * 8;
        A1 = (h[V0 + 0] << 10) + h[V0 + 4];
        V1 = vertex_data + h[triangle_data + S0 * e + 2] * 8;
        A0 = (h[V1 + 0] << 10) + h[V1 + 4];
        V0 = vertex_data + h[triangle_data + S0 * e + 4] * 8;
        V1 = (h[V0 + 0] << 10) + h[V0 + 4];

        SXY0 = A1;
        SXY1 = A0;
        SXY2 = T0;
        gte_NCLIP; // Normal clipping.
        [SP + 68] = w(MAC0);
        if( w[SP + 68] >= 0 )
        {
            SXY0 = A0;
            SXY1 = V1;
            SXY2 = T0;
            gte_NCLIP; // Normal clipping.
            [SP + 6c] = w(MAC0);
            if( w[SP + 6c] >= 0 )
            {
                SXY0 = V1;
                SXY1 = A1;
                SXY2 = T0;
                gte_NCLIP; // Normal clipping.
                [SP + 70] = w(MAC0);
                if( w[SP + 70] >= 0 )
                {
                    // if we inside this triangle
                    V0 = h[triangle_data + S0 * e + 0];
                    [SP + 48] = h(hu[vertex_data + V0 * 8 + 0]);
                    [SP + 4a] = h(hu[vertex_data + V0 * 8 + 2]);
                    [SP + 4c] = h(hu[vertex_data + V0 * 8 + 4]);

                    V0 = h[triangle_data + S0 * e + 2];
                    [SP + 50] = h(hu[vertex_data + V0 * 8 + 0]);
                    [SP + 52] = h(hu[vertex_data + V0 * 8 + 2]);
                    [SP + 54] = h(hu[vertex_data + V0 * 8 + 4]);

                    V0 = h[triangle_data + S0 * e + 4];
                    [SP + 58] = h(hu[vertex_data + V0 * 8 + 0]);
                    [SP + 5a] = h(hu[vertex_data + V0 * 8 + 2]);
                    [SP + 5c] = h(hu[vertex_data + V0 * 8 + 4]);

                    A0 = SP + 48;
                    A1 = SP + 50;
                    A2 = SP + 58;
                    A3 = SP + 60; // store height here
                    A4 = ret_normal; // normal
                    field_calculate_walkmesh_height; // calculate height

                    [ret_position + 0] = h(hu[SP + 60]);
                    [ret_position + 2] = h(hu[SP + 62]);
                    [ret_position + 4] = h(hu[SP + 64]);
                    return S0;
                }
            }
        }

        S0 = S0 + 1;
        V0 = S0 < number_of_triangles;
    8007AA50	bne    v0, zero, L7a838 [$8007a838]
}

[ret_position + 0] = h(0);
[ret_position + 2] = h(0);
[ret_position + 4] = h(0);
[ret_normal + 0] = w(0);
[ret_normal + 4] = w(0);
[ret_normal + 8] = w(0);
return 0;
////////////////////////////////////////////////////////