////////////////////////////////
// get_current_triangle_material()
walkmesh_id = h[A0 + 10];
if( ( ( w[A0 + 4] >> walkmesh_id + 3 ) & 1 ) == 0 )
{
    triangle_data = w[800aeff8 + walkmesh_id * 4];
    material_data = w[800aeff4];
    triangle_id = h[A0 + 8 + walkmesh_id * 2];
    V0 = bu[triangle_data + triangle_id * e + c];
    return w[material_data + V0 * 4];
}
return 0;
////////////////////////////////



////////////////////////////////
// func7ac28()
V0 = h[800b1660]; // base walking speed
res = A0;
rot = A2 & 0fff;

S0 = ((A1 << 4) * V0) >> c;

A0 = rot;
system_cos();
[res + 0] = w(V0 * S0);

A0 = rot;
system_sin();

[res + 4] = w(0);
[res + 8] = w(0 - V0 * S0);
////////////////////////////////



////////////////////////////////
// get_distance_between_entities()
entity_id1 = A0;
entity_id2 = A1;

struct_5c = w[800aefe4];
struct_138_1 = w[struct_5c + entity_id1 * 5c + 4c];
struct_138_2 = w[struct_5c + entity_id2 * 5c + 4c];

A0 = h[struct_138_2 + 22] - h[struct_138_1 + 22];
A1 = h[struct_138_2 + 2a] - h[struct_138_1 + 2a];
length_of_vector_by_x_y();
////////////////////////////////



////////////////////////////////////////////////////////
// length_of_vector_by_x_y()
[SP + 10] = w(A0);
[SP + 14] = w(A1);
[SP + 18] = w(0);

A0 = SP + 10;
A1 = SP + 20;
system_gte_square_of_vector;

V0 = w[SP + 20];
A0 = w[SP + 24];
A0 = V0 + A0;
system_square_root;

return V0;
////////////////////////////////////////////////////////



////////////////////////////////
// func83f40()
struct_138 = A0;

if( ( w[struct_138 + 14] & 00420000 ) == 0 && 
    w[800ad070] == 0 &&
    w[struct_138 + 30] == 0 && // X
    w[struct_138 + 34] == 0 && // Y
    w[struct_138 + 38] == 0 && // Z
    w[800ad0e4] == 1 &&
    bu[struct_138 + 74] == ff &&
    (w[struct_138 + 0] & 00401800) == 0 &&
    ((w[struct_138 + 4] & 00000001) == 0 || h[struct_138 + 10] != 0) &&
    ((w[struct_138 + 4] & 00000002) == 0 || h[struct_138 + 10] != 1))
{
    if ((w[struct_138 + 4] & 00000004) == 0)
    {
        return 0;
    }

    return (h[struct_138 + 10] ^ 0002) < 1; // -1 if bit 0x0002 set, 0 otherwise
}

return -1;
////////////////////////////////



////////////////////////////////
// func81594()
struct_164 = A0;
rotation = A1;
struct_5c = A2;

struct_138 = w[struct_5c + 4c];

if( rotation & 8000 )
{
    [struct_164 + c] = w(0);
    [struct_164 + 14] = w(0);
    return;
}

if( ( hu[struct_5c + 58] & 0040 ) == 0 ) // this is model
{
    S1 = ((40000 / hu[struct_138 + 76]) >> 8) << 5;

    A0 = rotation & 0fff;
    system_cos();
    [struct_164 + c] = w(((V0 * S1) >> c) * h[struct_138 + f4]);
    [struct_164 + c] = w(w[struct_164 + c] & fffff000);

    A0 = rotation & 0fff;
    system_sin();
    [struct_164 + 14] = w(((0 - (V0 * S1)) >> c) * h[struct_138 + f8]);
    [struct_164 + 14] = w(w[struct_164 + 14] & fffff000);
}
else if( ( w[struct_138 + 4] & 00002000 ) == 0 )
{
    if( ( w[struct_138 + 4] & 00080000 ) == 0 )
    {
        A0 = struct_164;
        A1 = rotation;
        func21e40();

        [struct_164 + c] = w(w[struct_164 + c] & fffff000);
        [struct_164 + 14] = w(w[struct_164 + 14] & fffff000);
    }
    else
    {
        S1 = ((40000 / hu[struct_138 + 76]) >> 8) << 5;

        A0 = rotation & 0fff;
        system_cos();
        [struct_164 + c] = w(((V0 * S1) >> c) * h[struct_138 + f4]);
        [struct_164 + c] = w(w[struct_164 + c] & fffff000);

        A0 = rotation & 0fff;
        system_sin();
        [struct_164 + 14] = w(((0 - (V0 * S1)) >> c) * h[struct_138 + f8]);
        [struct_164 + 14] = w(w[struct_164 + 14] & fffff000);

        [struct_164 + 18] = w(4000000 / hu[struct_138 + 76]);
    }
}
else if( ( w[struct_138 + 4] & 00020000 ) == 0 )
{
    S1 = ((80000 / hu[struct_138 + 76]) >> 8) << 5;

    A0 = rotation & 0fff;
    system_cos();
    [struct_164 + c] = w(((V0 * S1) >> c) * h[struct_138 + f4]);
    [struct_164 + c] = w(w[struct_164 + c] & fffff000);

    A0 = rotation & 0fff;
    system_sin();
    [struct_164 + 14] = w(((0 - (V0 * S1)) >> c) * h[struct_138 + f8]);
    [struct_164 + 14] = w(w[struct_164 + 14] & fffff000);
}
else
{
    V0 = w[801e8670 + ((w[struct_138 + 12c] >> b) & 1c)]; // 0x0000e000 flags
    [struct_164 + c] = w((0 - w[V0 + 128]) << 10);
    [struct_164 + c] = w(w[struct_164 + c] & fffff000);
    [struct_164 + 14] = w((0 - w[V0 + 130]) << 10);
    [struct_164 + 14] = w(w[struct_164 + 14] & fffff000);
}
////////////////////////////////



////////////////////////////////
// func81aa8()
move_vector = A0;
struct_138 = A1;

if( ( w[struct_138 + 12c] & 00001000 ) == 0 )
{
    return 0;
}

new_point = (((w[struct_138 + 20] + w[move_vector + 0]) >> 10) << 10) + ((w[struct_138 + 28] + w[move_vector + 8]) >> 10);

V1 = w[struct_138 + 114];
p1 = (h[V1 + 0] << 10) + h[V1 + 2];
p2 = (h[V1 + 4] << 10) + h[V1 + 6];
p3 = (h[V1 + 8] << 10) + h[V1 + a];
p4 = (h[V1 + c] << 10) + h[V1 + e];

A0 = p1;
A1 = p2;
A2 = new_point;
system_side_of_vector();
if( V0 >= 0 )
{
    A0 = p2;
    A1 = p3;
    A2 = new_point;
    system_side_of_vector();
    if( V0 >= 0 )
    {
        A0 = p3;
        A1 = p4;
        A2 = new_point;
        system_side_of_vector();
        if( V0 >= 0 )
        {
            A0 = p4;
            A1 = p1;
            A2 = new_point;
            system_side_of_vector();
            if( V0 >= 0 )
            {
                return 0;
            }
        }
    }
}
return -1;
////////////////////////////////



////////////////////////////////
// field_check_walkmesh_triangle_and_calculate_height()
// return -1 if we can't move, 0 otherwise.
move_vector = A0;
current_pos = A1;
struct_138 = A2;
intersect_line = A3;
final_pos = A4;
flag = A5; // if -1 then we don't need to really calculate height of final point. If 00000080 then we can go only down. Simulate material 00400000.
material_ret = A6;

walkmesh_id = h[struct_138 + 10];
triangle_id = h[struct_138 + 08 + walkmesh_id * 2];

walkmesh_vertex_data = w[800af008 + walkmesh_id * 4];
walkmesh_triangle_data = w[800aeff8 + walkmesh_id * 4];
walkmesh_material_data = w[800aeff4];

if( triangle_id == -1 )
{
    return -1;
}

start_x = w[current_pos + 0];
start_y = w[current_pos + 4];
start_z = w[current_pos + 8];
end_x = (start_x + w[move_vector + 0]) >> 10;
end_z = (start_z + w[move_vector + 8]) >> 10;
start_x_z = ((start_x >> 10) << 10) + (start_z >> 10);
ending_point_x_z = (end_x << 10) + end_z;

[final_pos + 0] = h(end_x);
[final_pos + 2] = h(0);
[final_pos + 4] = h(end_z);

if( ( ( w[struct_138 + 4] >> ( walkmesh_id + 3 ) ) & 1 ) == 0 && bu[800b16a0] == 0 )
{
    material_mask = ffffffff;
}
else
{
    material_mask = 00000000;
}

material_id = bu[walkmesh_triangle_data + triangle_id * e + c];
material = w[walkmesh_material_data + material_id * 4];

if( ( material & material_mask & 00400000 ) || ( flag == 00000080 ) )
{
    material_go_only_down = 1;
}
else
{
    material_go_only_down = 0;
}



triangle_check_count = 0;
L7b68c:	; 8007B68C
    current_triangle_id = triangle_id;
    S2 = 0;

    V0 = h[walkmesh_triangle_data + triangle_id * e + 00];
    a_x_z = (h[walkmesh_vertex_data + V0 * 8 + 00] << 10) + h[walkmesh_vertex_data + V0 * 8 + 04];

    V0 = h[walkmesh_triangle_data + triangle_id * e + 02];
    b_x_z = (h[walkmesh_vertex_data + V0 * 8 + 00] << 10) + h[walkmesh_vertex_data + V0 * 8 + 04];

    V0 = h[walkmesh_triangle_data + triangle_id * e + 04];
    c_x_z = (h[walkmesh_vertex_data + V0 * 8 + 00] << 10) + h[walkmesh_vertex_data + V0 * 8 + 04];

    A0 = a_x_z;
    A1 = b_x_z;
    A2 = ending_point_x_z;
    system_side_of_vector();
    if( V0 < 0 )
    {
        S2 = S2 | 1;
    }

    A0 = b_x_z;
    A1 = c_x_z;
    A2 = ending_point_x_z;
    system_side_of_vector();
    if( V0 < 0 )
    {
        S2 = S2 | 2;
    }

    A0 = c_x_z;
    A1 = a_x_z;
    A2 = ending_point_x_z;
    system_side_of_vector();
    if( V0 < 0 )
    {
        S2 = S2 | 4;
    }

    switch( S2 )
    {
        case 0: // we not cross anything
        {
            triangle_check_count = ff;
        }
        break;
        case 1:
        {
            triangle_id = h[walkmesh_triangle_data + triangle_id * e + 06];
        }
        case 2:
        {
            triangle_id = h[walkmesh_triangle_data + triangle_id * e + 08];
        }
        break;
        case 3:
        {
            A0 = b_x_z;
            A1 = ending_point_x_z;
            A2 = start_x_z;
            system_side_of_vector();
            if( V0 >= 0 )
            {
                triangle_id = h[walkmesh_triangle_data + triangle_id * e + 8];
                S2 = 2;
            }
            else
            {
                triangle_id = h[walkmesh_triangle_data + triangle_id * e + 6];
                S2 = 1;
            }
        }
        break;
        case 4:
        {
            triangle_id = h[walkmesh_triangle_data + triangle_id * e + a];
        }
        break;
        case 5:
        {
            A0 = a_x_z;
            A1 = ending_point_x_z;
            A2 = start_x_z;
            system_side_of_vector();
            if( V0 >= 0 )
            {
                triangle_id = h[walkmesh_triangle_data + triangle_id * e + 6];
                S2 = 1;
            }
            else
            {
                triangle_id = h[walkmesh_triangle_data + triangle_id * e + a];
                S2 = 4;
            }
        }
        break;
        case 6:
        {
            A0 = c_x_z;
            A1 = ending_point_x_z;
            A2 = start_x_z;
            system_side_of_vector();
            if( V0 >= 0 )
            {
                triangle_id = h[walkmesh_triangle_data + triangle_id * e + a];
                S2 = 4;
            }
            else
            {
                triangle_id = h[walkmesh_triangle_data + triangle_id * e + 8];
                S2 = 2;
            }
        }
        break;
        case 7:
        {
            triangle_id = -1;
        }
        break;
    }

    if( triangle_id == -1 )
    {
        break;
    }

    material_id = bu[walkmesh_triangle_data + triangle_id * e + c];
    material = w[walkmesh_material_data + material_id * 4];

    [material_ret] = w(material & material_mask);
    type_of_unpassability = (w[material_ret] >> 5)

    type_of_entity = ((w[struct_138 + 0] & 00000700) >> 8);

    if( ( type_of_entity & type_of_unpassability ) || ( ( w[material_ret] & 10000000 ) && ( walkmesh_id == 0 ) ) )
    {
        triangle_id = -1;
    }
    else if( ( w[material_ret] & 00400000 ) && material_go_only_down == 0 ) // we check both triangles start and end.
    {
        A0 = h[walkmesh_triangle_data + triangle_id * e + 0];
        A1 = h[walkmesh_triangle_data + triangle_id * e + 2];
        A2 = h[walkmesh_triangle_data + triangle_id * e + 4];

        A0 = walkmesh_vertex_data + A0 * 8;
        A1 = walkmesh_vertex_data + A1 * 8;
        A2 = walkmesh_vertex_data + A2 * 8;
        A3 = final_pos;
        A4 = SP + 18; // address to store normal
        field_calculate_walkmesh_height();

        new_y = h[final_pos + 2];

        if( new_y < ( start_y >> 10 ) ) // Y is less on top
        {
            triangle_id = -1;
        }
    }

    if( triangle_id == -1 )
    {
        break;
    }

    triangle_check_count = triangle_check_count + 1;
    V0 = triangle_check_count < 20;
8007B970	bne    v0, zero, L7b68c [$8007b68c]



if( triangle_id != -1 && triangle_check_count != 20 )
{
    if( flag != -1 )
    {
        A0 = walkmesh_vertex_data + h[walkmesh_triangle_data + triangle_id * e + 0] * 8;
        A1 = walkmesh_vertex_data + h[walkmesh_triangle_data + triangle_id * e + 2] * 8;
        A2 = walkmesh_vertex_data + h[walkmesh_triangle_data + triangle_id * e + 4] * 8;
        A3 = final_pos;
        A4 = SP + 18; // address to store normal
        field_calculate_walkmesh_height();
    }
    return 0;
}



if( S2 == 1 )
{
    V0 = h[walkmesh_triangle_data + current_triangle_id * e + 0];
    [intersect_line + 0] = h(hu[walkmesh_vertex_data + V0 * 8 + 0]);
    [intersect_line + 2] = h(hu[walkmesh_vertex_data + V0 * 8 + 2]);
    [intersect_line + 4] = h(hu[walkmesh_vertex_data + V0 * 8 + 4]);

    V0 = h[walkmesh_triangle_data + current_triangle_id * e + 2];
    [intersect_line + 8] = h(hu[walkmesh_vertex_data + V0 * 8 + 0]);
    [intersect_line + a] = h(hu[walkmesh_vertex_data + V0 * 8 + 2]);
    [intersect_line + c] = h(hu[walkmesh_vertex_data + V0 * 8 + 4]);
}
else if( S2 == 2 )
{
    V0 = h[walkmesh_triangle_data + current_triangle_id * e + 2];
    [intersect_line + 0] = h(hu[walkmesh_vertex_data + V0 * 8 + 0]);
    [intersect_line + 2] = h(hu[walkmesh_vertex_data + V0 * 8 + 2]);
    [intersect_line + 4] = h(hu[walkmesh_vertex_data + V0 * 8 + 4]);

    V0 = h[walkmesh_triangle_data + current_triangle_id * e + 4];
    [intersect_line + 8] = h(hu[walkmesh_vertex_data + V0 * 8 + 0]);
    [intersect_line + a] = h(hu[walkmesh_vertex_data + V0 * 8 + 2]);
    [intersect_line + c] = h(hu[walkmesh_vertex_data + V0 * 8 + 4]);
}
else if( S2 == 4 )
{
    V0 = h[walkmesh_triangle_data + current_triangle_id * e + 4];
    [intersect_line + 0] = h(hu[walkmesh_vertex_data + V0 * 8 + 0]);
    [intersect_line + 2] = h(hu[walkmesh_vertex_data + V0 * 8 + 2]);
    [intersect_line + 4] = h(hu[walkmesh_vertex_data + V0 * 8 + 4]);

    V0 = h[walkmesh_triangle_data + current_triangle_id * e + 0];
    [intersect_line + 8] = h(hu[walkmesh_vertex_data + V0 * 8 + 0]);
    [intersect_line + a] = h(hu[walkmesh_vertex_data + V0 * 8 + 2]);
    [intersect_line + c] = h(hu[walkmesh_vertex_data + V0 * 8 + 4]);
}

return -1;
////////////////////////////////



////////////////////////////////
// field_calculate_walkmesh_height()
A_vec = A0;
B_vec = A1;
C_vec = A2;
P_vec = A3;
S4 = A4; // address for normal

[SP + 30] = w(h[B_vec + 0] - h[A_vec + 0]);
[SP + 34] = w(h[B_vec + 2] - h[A_vec + 2]);
[SP + 38] = w(h[B_vec + 4] - h[A_vec + 4]);
A0 = SP + 30;
A1 = SP + 10;
system_normalize_word_vector_T0_T1_T2_to_word();

[SP + 30] = w(h[C_vec + 0] - h[A_vec + 0]);
[SP + 34] = w(h[C_vec + 2] - h[A_vec + 2]);
[SP + 38] = w(h[C_vec + 4] - h[A_vec + 4]);
A0 = SP + 30;
A1 = SP + 20;
system_normalize_word_vector_T0_T1_T2_to_word();

A0 = SP + 10;
A1 = SP + 20;
A2 = S4; // normal
system_outer_product2_A0_A1_to_A2();

if (w[S4 + 4] == 0)
{
    [P_vec + 2] = h(0);
}
else
{
    [P_vec + 2] = h(hu[A_vec + 2] - (w[S4 + 0] * (h[P_vec + 0] - h[A_vec + 0]) + w[S4 + 8] * (h[P_vec + 4] - h[A_vec + 4])) / w[S4 + 4]);
}
////////////////////////////////



////////////////////////////////
// field_get_move_vector_to_move_along_with_line()
rotation = A0;
intersect_line = A1;
move_vector = A2;

S1 = (c00 - rotation) & fff;

A0 = h[intersect_line + c] - h[intersect_line + 4];
A1 = h[intersect_line + 8] - h[intersect_line + 0];
system_get_rotation_based_on_vector_x_y();

A0 = (0 - V0) & fff; // rotation along line that we can't intersect 
S1 = (S1 + A0) & fff;

if( ( S1 - 80 ) >= f01)
{
    [move_vector + 0] = w(0);
    [move_vector + 4] = w(0);
    [move_vector + 8] = w(0);
    return A0;
}
else
{
    if( S1 < 800 )
    {
        [SP + 10] = w(h[intersect_line + 0] - h[intersect_line + 8]);
        [SP + 14] = w(0);
        [SP + 18] = w(h[intersect_line + 4] - h[intersect_line + c]);
        A0 = A0 + 800;
    }
    else
    {
        [SP + 10] = w(h[intersect_line + 8] - h[intersect_line + 0]);
        [SP + 14] = w(0);
        [SP + 18] = w(h[intersect_line + c] - h[intersect_line + 4]);
    }

    S3 = A0 & fff;

    A0 = SP + 10;
    A1 = SP + 20;
    system_normalize_word_vector_T0_T1_T2_to_word();

    A0 = w[move_vector + 0] >> c;
    A1 = w[move_vector + 8] >> c;
    length_of_vector_by_x_y();

    [move_vector + 0] = w(w[SP + 20] * V0);
    [move_vector + 4] = w(0);
    [move_vector + 8] = w(w[SP + 28] * V0);

    return S3;
}
////////////////////////////////



////////////////////////////////
// func7bca8()
T1 = move_vector = A0;
T0 = current_pos = A1;
[SP + 28] = struct_138 = A2;
S7 = intersect_line = A3;
final_pos = A4;
flag = A5; // if -1 then we don't need to really calculate height of final point. If 00000080 then we can go only down. Simulate material 00400000.
material_ret = A6;

walkmesh_id = h[struct_138 + 10];
S0 = triangle_id = h[struct_138 + 08 + walkmesh_id * 2];

S6 = walkmesh_vertex_data = w[800af008 + walkmesh_id * 4];
S5 = walkmesh_triangle_data = w[800aeff8 + walkmesh_id * 4];

if( triangle_id == -1 )
{
    return -1;
}

start_x = w[current_pos + 0];
start_z = w[current_pos + 8];
end_x = (start_x + w[move_vector + 0]) >> 10;
end_z = (start_z + w[move_vector + 8]) >> 10;
[SP + 40] = start_x_z = ((start_x >> 10) << 10) + (start_z >> 10);
FP = ending_point_x_z = (end_x << 10) + end_z;

[final_pos + 0] = h(end_x);
[final_pos + 2] = h(0);
[final_pos + 4] = h(end_z);

if( ( ( w[struct_138 + 4] >> ( walkmesh_id + 3 ) ) & 1 ) == 0 && bu[800b16a0] == 0 )
{
    [SP + 38] = material_mask = ffffffff;
}
else
{
    [SP + 38] = material_mask = 00000000;
}

[SP + 48] = triangle_check_count = 0;
L7bdc8:	; 8007BDC8
    [SP + 30] = w(S0);

    V0 = walkmesh_vertex_data + h[S5 + S0 * e + 0] * 8;
    S4 = (h[V0 + 0] << 10) + h[V0 + 4];
    V0 = (walkmesh_vertex_data + h[S5 + S0 * e + 2]) * 8;
    S3 = (h[V0 + 0] << 10) + h[V0 + 4];
    V0 = walkmesh_vertex_data + h[S5 + S0 * e + 4] * 8;
    S2 = (h[V0 + 0] << 10) + h[V0 + 4];

    A0 = S4;
    A1 = S3;
    A2 = FP;
    system_side_of_vector();
    S1 = V0 >> 1f;

    A0 = S3;
    A1 = S2;
    A2 = FP;
    system_side_of_vector();

    if( V0 < 0 )
    {
        S1 = S1 | 2;
    }

    A0 = S2;
    A1 = S4;
    A2 = FP;
    system_side_of_vector();

    if( V0 < 0 )
    {
        S1 = S1 | 4;
    }

    8007BE70	sltiu  v0, s1, $0008
    8007BE7C	beq    v0, zero, L7bf98 [$8007bf98]
    8007BE80	sll    v0, s1, $02
    8007BE84	lui    at, $8007
    8007BE88	addu   at, at, v0
    8007BE8C	lw     v0, $f23c(at)
    8007BE90	nop
    8007BE94	jr     v0 
    8007BE98	nop

    8007BE9C	ori    t2, zero, $00ff
    8007BEA0	j      L7bf98 [$8007bf98]
    8007BEA4	sw     t2, $0048(sp)
    8007BEA8	sll    v0, s0, $03
    8007BEAC	subu   v0, v0, s0
    8007BEB0	sll    v0, v0, $01
    8007BEB4	addu   v0, v0, s5
    8007BEB8	lh     s0, $0006(v0)
    8007BEBC	j      L7bf9c [$8007bf9c]
    8007BEC0	sll    v0, s0, $03
    8007BEC4	sll    v0, s0, $03
    8007BEC8	subu   v0, v0, s0
    8007BECC	sll    v0, v0, $01
    8007BED0	addu   v0, v0, s5
    8007BED4	lh     s0, $0008(v0)
    8007BED8	j      L7bf9c [$8007bf9c]
    8007BEDC	sll    v0, s0, $03
    8007BEE0	addu   a0, s3, zero
    8007BEE4	lw     a2, $0040(sp)
    8007BEE8	jal    system_side_of_vector [$8004a5b4]
    8007BEEC	addu   a1, fp, zero
    8007BEF0	bltz   v0, L7bf34 [$8007bf34]
    8007BEF4	sll    v0, s0, $03
    8007BEF8	j      L7bf68 [$8007bf68]
    8007BEFC	subu   v0, v0, s0
    8007BF00	sll    v0, s0, $03
    8007BF04	subu   v0, v0, s0
    8007BF08	sll    v0, v0, $01
    8007BF0C	addu   v0, v0, s5
    8007BF10	lh     s0, $000a(v0)
    8007BF14	j      L7bf9c [$8007bf9c]
    8007BF18	sll    v0, s0, $03
    8007BF1C	addu   a0, s4, zero
    8007BF20	lw     a2, $0040(sp)
    8007BF24	jal    system_side_of_vector [$8004a5b4]
    8007BF28	addu   a1, fp, zero
    8007BF2C	bltz   v0, L7bf7c [$8007bf7c]
    8007BF30	sll    v0, s0, $03

    L7bf34:	; 8007BF34
    8007BF34	subu   v0, v0, s0
    8007BF38	sll    v0, v0, $01
    8007BF3C	addu   v0, v0, s5
    8007BF40	lh     s0, $0006(v0)
    8007BF44	j      L7bf98 [$8007bf98]
    8007BF48	ori    s1, zero, $0001
    8007BF4C	addu   a0, s2, zero
    8007BF50	lw     a2, $0040(sp)
    8007BF54	jal    system_side_of_vector [$8004a5b4]
    8007BF58	addu   a1, fp, zero
    8007BF5C	bgez   v0, L7bf7c [$8007bf7c]
    8007BF60	sll    v0, s0, $03
    8007BF64	subu   v0, v0, s0

    L7bf68:	; 8007BF68
    8007BF68	sll    v0, v0, $01
    8007BF6C	addu   v0, v0, s5
    8007BF70	lh     s0, $0008(v0)
    8007BF74	j      L7bf98 [$8007bf98]
    8007BF78	ori    s1, zero, $0002

    L7bf7c:	; 8007BF7C
    8007BF7C	subu   v0, v0, s0
    8007BF80	sll    v0, v0, $01
    8007BF84	addu   v0, v0, s5
    8007BF88	lh     s0, $000a(v0)
    8007BF8C	j      L7bf98 [$8007bf98]
    8007BF90	ori    s1, zero, $0004
    8007BF94	addiu  s0, zero, $ffff (=-$1)

    L7bf98:	; 8007BF98
    8007BF98	sll    v0, s0, $03

    L7bf9c:	; 8007BF9C
    8007BF9C	subu   v0, v0, s0
    8007BFA0	sll    v0, v0, $01
    8007BFA4	addu   v0, v0, s5
    8007BFA8	lbu    v0, $000c(v0)
    8007BFAC	lui    v1, $800b
    8007BFB0	lw     v1, $eff4(v1)
    8007BFB4	lw     t2, $0028(sp)
    8007BFB8	sll    v0, v0, $02
    8007BFBC	addu   v0, v0, v1
    8007BFC0	lw     v0, $0000(v0)
    8007BFC4	lw     a1, $0000(t2)
    8007BFC8	lw     t2, $0038(sp)
    8007BFCC	nop
    8007BFD0	and    a0, v0, t2
    8007BFD4	srl    v0, a1, $09
    8007BFD8	andi   v0, v0, $0003
    8007BFDC	srl    v1, a0, $03
    8007BFE0	and    v0, v0, v1
    if( V0 != 0 )
    {
        8007BD24	j      L7c044 [$8007c044]
        8007BD28	addiu  s0, zero, $ffff (=-$1)
    }

    8007BFE8	srl    v0, a1, $08
    8007BFEC	andi   v0, v0, $0007
    8007BFF0	srl    v1, a0, $05
    8007BFF4	and    v0, v0, v1
    if( V0 != 0 )
    {
        8007BD24	j      L7c044 [$8007c044]
        8007BD28	addiu  s0, zero, $ffff (=-$1)
    }

    8007BFFC	lui    v0, $0080
    8007C000	and    v0, a0, v0
    8007C004	beq    v0, zero, L7c024 [$8007c024]
    8007C008	addiu  v0, zero, $ffff (=-$1)
    8007C00C	lw     t2, $0028(sp)
    8007C010	nop
    8007C014	lh     v0, $0010(t2)
    if( V0 == 0 )
    {
        8007BD24	j      L7c044 [$8007c044]
        8007BD28	addiu  s0, zero, $ffff (=-$1)
    }

    8007C020	addiu  v0, zero, $ffff (=-$1)

    L7c024:	; 8007C024
    8007C024	beq    s0, v0, L7c0c4 [$8007c0c4]
    8007C028	ori    v0, zero, $0002
    8007C02C	lw     t2, $0048(sp)
    8007C030	nop
    8007C034	addiu  t2, t2, $0001
    8007C038	slti   v0, t2, $0020
    8007C040	sw     t2, $0048(sp)
8007C03C	bne    v0, zero, L7bdc8 [$8007bdc8]

L7c044:	; 8007C044
8007C044	addiu  v1, zero, $ffff (=-$1)
8007C048	beq    s0, v1, L7c0c0 [$8007c0c0]
8007C04C	ori    v0, zero, $0020
8007C050	lw     t2, $0048(sp)
8007C054	nop
8007C058	beq    t2, v0, L7c0c0 [$8007c0c0]
8007C05C	nop
8007C060	lw     t2, $0094(sp)
8007C064	nop
8007C068	bne    t2, v1, L7c078 [$8007c078]
8007C06C	sll    v0, s0, $03
return 0;

L7c078:	; 8007C078
8007C078	subu   v0, v0, s0
8007C07C	sll    v0, v0, $01
8007C080	addu   v0, v0, s5
A0 = h[V0 + 0];
A1 = h[V0 + 2];
A2 = h[V0 + 4];
A3 = w[SP + 90];
V0 = SP + 18;
[SP + 10] = w(V0);
8007C09C	sll    a0, a0, $03
8007C0A0	addu   a0, s6, a0
8007C0A4	sll    a1, a1, $03
8007C0A8	addu   a1, s6, a1
8007C0AC	sll    a2, a2, $03
8007C0B0	jal    field_calculate_walkmesh_height [$8007a690]
8007C0B4	addu   a2, s6, a2
return 0;

L7c0c0:	; 8007C0C0
8007C0C0	ori    v0, zero, $0002

L7c0c4:	; 8007C0C4
8007C0C4	beq    s1, v0, L7c1a8 [$8007c1a8]
8007C0C8	slti   v0, s1, $0003
8007C0CC	beq    v0, zero, L7c0e4 [$8007c0e4]
8007C0D0	ori    v0, zero, $0001
8007C0D4	beq    s1, v0, L7c0f8 [$8007c0f8]

return -1;

L7c0e4:	; 8007C0E4
8007C0E4	ori    v0, zero, $0004
8007C0E8	beq    s1, v0, L7c258 [$8007c258]

return -1;

L7c0f8:	; 8007C0F8
8007C0F8	lw     t2, $0030(sp)
8007C0FC	nop
8007C100	sll    v1, t2, $03
8007C104	subu   v1, v1, t2
8007C108	sll    v1, v1, $01
8007C10C	addu   v1, v1, s5
8007C110	lh     v0, $0000(v1)
8007C114	nop
8007C118	sll    v0, v0, $03
8007C11C	addu   v0, v0, s6
8007C120	lhu    v0, $0000(v0)
8007C124	nop
8007C128	sh     v0, $0000(s7)
8007C12C	lh     v0, $0000(v1)
8007C130	nop
8007C134	sll    v0, v0, $03
8007C138	addu   v0, v0, s6
8007C13C	lhu    v0, $0002(v0)
8007C140	nop
8007C144	sh     v0, $0002(s7)
8007C148	lh     v0, $0000(v1)
8007C14C	nop
8007C150	sll    v0, v0, $03
8007C154	addu   v0, v0, s6
8007C158	lhu    v0, $0004(v0)
8007C15C	nop
8007C160	sh     v0, $0004(s7)
8007C164	lh     v0, $0002(v1)
8007C168	nop
8007C16C	sll    v0, v0, $03
8007C170	addu   v0, v0, s6
8007C174	lhu    v0, $0000(v0)
8007C178	nop
8007C17C	sh     v0, $0008(s7)
8007C180	lh     v0, $0002(v1)
8007C184	nop
8007C188	sll    v0, v0, $03
8007C18C	addu   v0, v0, s6
8007C190	lhu    v0, $0002(v0)
8007C194	nop
8007C198	sh     v0, $000a(s7)
8007C19C	lh     v0, $0002(v1)
8007C1A0	j      L7c308 [$8007c308]
8007C1A4	sll    v0, v0, $03

L7c1a8:	; 8007C1A8
8007C1A8	lw     t2, $0030(sp)
8007C1AC	nop
8007C1B0	sll    v1, t2, $03
8007C1B4	subu   v1, v1, t2
8007C1B8	sll    v1, v1, $01
8007C1BC	addu   v1, v1, s5
8007C1C0	lh     v0, $0002(v1)
8007C1C4	nop
8007C1C8	sll    v0, v0, $03
8007C1CC	addu   v0, v0, s6
8007C1D0	lhu    v0, $0000(v0)
8007C1D4	nop
8007C1D8	sh     v0, $0000(s7)
8007C1DC	lh     v0, $0002(v1)
8007C1E0	nop
8007C1E4	sll    v0, v0, $03
8007C1E8	addu   v0, v0, s6
8007C1EC	lhu    v0, $0002(v0)
8007C1F0	nop
8007C1F4	sh     v0, $0002(s7)
8007C1F8	lh     v0, $0002(v1)
8007C1FC	nop
8007C200	sll    v0, v0, $03
8007C204	addu   v0, v0, s6
8007C208	lhu    v0, $0004(v0)
8007C20C	nop
8007C210	sh     v0, $0004(s7)
8007C214	lh     v0, $0004(v1)
8007C218	nop
8007C21C	sll    v0, v0, $03
8007C220	addu   v0, v0, s6
8007C224	lhu    v0, $0000(v0)
8007C228	nop
8007C22C	sh     v0, $0008(s7)
8007C230	lh     v0, $0004(v1)
8007C234	nop
8007C238	sll    v0, v0, $03
8007C23C	addu   v0, v0, s6
8007C240	lhu    v0, $0002(v0)
8007C244	nop
8007C248	sh     v0, $000a(s7)
8007C24C	lh     v0, $0004(v1)
8007C250	j      L7c308 [$8007c308]
8007C254	sll    v0, v0, $03

L7c258:	; 8007C258
8007C258	lw     t2, $0030(sp)
8007C25C	nop
8007C260	sll    v1, t2, $03
8007C264	subu   v1, v1, t2
8007C268	sll    v1, v1, $01
8007C26C	addu   v1, v1, s5
8007C270	lh     v0, $0004(v1)
8007C274	nop
8007C278	sll    v0, v0, $03
8007C27C	addu   v0, v0, s6
8007C280	lhu    v0, $0000(v0)
8007C284	nop
8007C288	sh     v0, $0000(s7)
8007C28C	lh     v0, $0004(v1)
8007C290	nop
8007C294	sll    v0, v0, $03
8007C298	addu   v0, v0, s6
8007C29C	lhu    v0, $0002(v0)
8007C2A0	nop
8007C2A4	sh     v0, $0002(s7)
8007C2A8	lh     v0, $0004(v1)
8007C2AC	nop
8007C2B0	sll    v0, v0, $03
8007C2B4	addu   v0, v0, s6
8007C2B8	lhu    v0, $0004(v0)
8007C2BC	nop
8007C2C0	sh     v0, $0004(s7)
8007C2C4	lh     v0, $0000(v1)
8007C2C8	nop
8007C2CC	sll    v0, v0, $03
8007C2D0	addu   v0, v0, s6
8007C2D4	lhu    v0, $0000(v0)
8007C2D8	nop
8007C2DC	sh     v0, $0008(s7)
8007C2E0	lh     v0, $0000(v1)
8007C2E4	nop
8007C2E8	sll    v0, v0, $03
8007C2EC	addu   v0, v0, s6
8007C2F0	lhu    v0, $0002(v0)
8007C2F4	nop
8007C2F8	sh     v0, $000a(s7)
8007C2FC	lh     v0, $0000(v1)
8007C300	nop
8007C304	sll    v0, v0, $03

L7c308:	; 8007C308
8007C308	addu   v0, v0, s6
8007C30C	lhu    v0, $0004(v0)
8007C310	nop
8007C314	sh     v0, $000c(s7)
return -1;
////////////////////////////////



////////////////////////////////
// func81808()
struct_164 = A0;
animation_id = S0 = A1;
struct_5c = A2;

struct_138 = w[struct_5c + 4c];

if( ( hu[struct_5c + 58] & 0040 ) == 0 )
{
    return;
}

if( ( animation_id != 3 ) && ( h[800b1818] == 0 ) )
{
    [struct_138 + 0] = w(w[struct_138 + 0] & fffff7ff); // remove 0x00000800
}

if( animation_id == ff )
{
    animation_id = 0;
}

if( animation_id != h[800b181a] )
{
    [struct_138 + 0] = w(w[struct_138 + 0] & fffff7ff);
}

if( ( w[struct_138 + 4] & 00002000 ) == 0 )
{
    if( ( w[struct_138 + 4] & 00000100 ) == 0 )
    {
        A0 = struct_164;
        A1 = animation_id;
        func243e4(); // sprite animation
    }
    return;
}

model_id = (w[struct_138 + 12c] >> d) & 7

if( animation_id < 10 )
{
    A0 = model_id;
    A1 = 0;
    A2 = bu[800ad490 + animation_id];
    func1e8330(); // model animation

    [800b16b8 + model_id * 2] = h(bu[800ad490 + animation_id]);
}
else
{
    animation_id = animation_id - 10;
    A0 = model_id;
    A1 = 0;
    A2 = animation_id;
    func1e8330(); // model animation

    [800b16b8 + model_id * 2] = h(animation_id);
}
////////////////////////////////
