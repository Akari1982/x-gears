////////////////////////////////
// system_gte_vector_perspective_transform()
VXY0 = w[A0 + 0];
VZ0 = w[A0 + 4];
gte_RTPS(); // Perspective transform
[A1] = w(SXY2);
[A2] = w(IR0);
[A3] = w(FLAG);
return SZ3 / 4;
////////////////////////////////



////////////////////////////////
// system_gte_square_of_vector()
IR1 = w[A0 + 0];
IR2 = w[A0 + 4];
IR3 = w[A0 + 8];
gte_SQR(); // Square of vector.
[A1 + 0] = w(MAC1);
[A1 + 4] = w(MAC2);
[A1 + 8] = w(MAC3);
return A1;
////////////////////////////////



////////////////////////////////
// system_gte_matrix_mult_and_trans()
R11R12 = w[A0 + 0];
R13R21 = w[A0 + 4];
R22R23 = w[A0 + 8];
R31R32 = w[A0 + c];
R33 = w[A0 + 10];

VXY0 = (w[A1 + 4] & ffff0000) | hu[A1 + 0];
VZ0 = w[A1 + c];
gte_rtv0(); // v0 * rotmatrix.
mul01 = IR1;
mul02 = IR2;
mul03 = IR3;

VXY0 = (w[A1 + 8] << 10) | hu[A1 + 2];
VZ0 = h[A1 + e];
gte_rtv0(); // v0 * rotmatrix
mul04 = IR1;
mul05 = IR2;
mul06 = IR3;

VXY0 = (w[A1 + 8] & ffff0000) | hu[A1 + 4];
VZ0 = w[A1 + 10];
gte_rtv0(); // v0 * rotmatrix
mul07 = IR1;
mul08 = IR2;
mul09 = IR3;

VXY0 = (w[A1 + 18] << 10) | hu[A1 + 14];
VZ0 = w[A1 + 1c];
gte_rtv0(); // v0 * rotmatrix

[A2 + 0] = w((mul04 << 10) | (mul01 & ffff));
[A2 + 4] = w((mul02 << 10) | (mul07 & ffff));
[A2 + 8] = w((mul08 << 10) | (mul05 & ffff));
[A2 + c] = w((mul06 << 10) | (mul03 & ffff));
[A2 + 10] = w(mul09);
[A2 + 14] = w(w[A0 + 14] + MAC1);
[A2 + 18] = w(w[A0 + 18] + MAC2);
[A2 + 1c] = w(w[A0 + 1c] + MAC3);
return A2;
////////////////////////////////



////////////////////////////////
// system_gte_matrix_multiplication()
R11R12 = w[A0 + 0];
R13R21 = w[A0 + 4];
R22R23 = w[A0 + 8];
R31R32 = w[A0 + c];
R33 = w[A0 + 10];

VXY0 = hu[A1 + 0] | hu[A1 + 6];
VZ0 = hu[A1 + c];
gte_rtv0(); // v0 * rotmatrix.
[A2 + 0] = h(IR1);
[A2 + 6] = h(IR2);
[A2 + c] = h(IR3);

VXY0 = hu[A1 + 2] | hu[A1 + 8];
VZ0 = hu[A1 + e];
gte_rtv0(); // v0 * rotmatrix.
[A2 + 2] = h(IR1);
[A2 + 8] = h(IR2);
[A2 + e] = w(IR3);

VXY0 = hu[A1 + 4] | hu[A1 + a];
VZ0 = hu[A1 + 10];
gte_rtv0(); // v0 * rotmatrix.
[A2 + 4] = h(IR1);
[A2 + a] = h(IR2);
[A2 + 10] = h(IR3);

return A2;
////////////////////////////////



////////////////////////////////
// system_gte_calculate_normals_color_by_3vectors_only
VXY0 = w[A0 + 0];
VZ0 = w[A0 + 4];
VXY1 = w[A1 + 0];
VZ1 = w[A1 + 4];
VXY2 = w[A2 + 0];
VZ2 = w[A2 + 4];
gte_NCCT(); // Normal color col.v0, v1, v2
[A3] = w(RGB0);
[A4] = w(RGB1)
[A5] = w(RGB2)
////////////////////////////////



////////////////////////////////
// system_gte_calculate_normals_color_by_3vectors_and_color
VXY0 = w[A0 + 0];
VZ0 = w[A0 + 4];
VXY1 = w[A1 + 0];
VZ1 = w[A1 + 4];
VXY2 = w[A2 + 0];
VZ2 = w[A2 + 4];
RGB = w[A3 + 0];
gte_NCCT(); // Normal color col.v0, v1, v2
[A4] = w(RGB0);
[A5] = w(RGB1)
[A6] = w(RGB2)
////////////////////////////////



////////////////////////////////
// system_gte_calculate_normal_color_by_vector_and_color
VXY0 = w[A0 + 0];
VZ0 = w[A0 + 4];
RGB = w[A1 + 0];
gte_NCCS(); // Normal color col. v0.
[A2 + 0] = w(RGB2);
////////////////////////////////



////////////////////////////////
// system_gte_calculate_normal_color_by_vector_only
VXY0 = w[A0 + 0];
VZ0 = w[A0 + 4];
gte_NCS(); // Normal color v0.
[A1 + 0] = w(RGB2);
////////////////////////////////



////////////////////////////////
// system_gte_calculate_and_set_lighting_matrix
V1 = 80059600;

R11R12 = w[V1 + 0];
R13R21 = w[V1 + 4];
R22R23 = w[V1 + 8];
R31R32 = w[V1 + c];
R33 = w[V1 + 10];

IR1 = hu[A0 + 0];
IR2 = hu[A0 + 6];
IR3 = hu[A0 + c];
gte_rtir12(); // ir * rotmatrix
[SP + 0] = h(IR1);
[SP + 6] = h(IR2);
[SP + c] = h(IR3);

IR1 = hu[A0 + 2];
IR2 = hu[A0 + 8];
IR3 = hu[A0 + e];
gte_rtir12(); // ir * rotmatrix
[SP + 2] = h(IR1);
[SP + 8] = h(IR2);
[SP + e] = h(IR3);

IR1 = hu[A0 + 4];
IR2 = hu[A0 + a];
IR3 = hu[A0 + 10];
gte_rtir12(); // ir * rotmatrix
[SP + 4] = h(IR1);
[SP + a] = h(IR2);
[SP + 10] = h(IR3);

L11L12 = w[SP + 0];
L13L21 = w[SP + 4];
L22L23 = w[SP + 8];
L31L32 = w[SP + c];
L33 = w[SP + 10];
////////////////////////////////



////////////////////////////////
// func49724
R11R12 = w[A0 + 0];
R13R21 = w[A0 + 4];
R22R23 = w[A0 + 8];
R31R32 = w[A0 + c];
R33 = w[A0 + 10];

VXY0 = (w[A1 + 4] & ffff0000) | hu[A1 + 0];
VZ0 = w[A1 + c];
gte_rtv0(); // v0 * rotmatrix
T3 = IR1;
T4 = IR2;
T5 = IR3;

VXY0 = (w[A1 + 8] << 10) | hu[A1 + 2];
VZ0 = h[A1 + e];
gte_rtv0(); // v0 * rotmatrix
T6 = IR1;
T7 = IR2;
T8 = IR3;

VXY0 = (w[A1 + 8] & ffff0000) | hu[A1 + 4];
VZ0 = w[A1 + 10];
gte_rtv0(); // v0 * rotmatrix

R11R12 = (T6 << 10) | (T3 & ffff);
R13R21 = (T4 << 10) | (IR1 & ffff);
R22R23 = (IR2 << 10) | (T7 & ffff);
R31R32 = (T8 << 10) | (T5 & ffff);
R33 = IR3;

return A0;
////////////////////////////////



////////////////////////////////
// func4a5e4
VXY0 = w[A0 + 0];
VZ0  = w[A0 + 4];
VXY1 = w[A1 + 0];
VZ1  = w[A1 + 4];
VXY2 = w[A2 + 0];
VZ2  = w[A2 + 4];
gte_RTPT; // Perspective transform on 3 points.
V1 = FLAG;

[A4] = w(SXY0);
[A5] = w(SXY1);
[A6] = w(SXY2);

VXY0 = w[A3 + 0];
VZ0 = w[A3 + 4];
gte_RTPS; // Perspective transform
V0 = FLAG;

[A7] = w(SXY2);
[A8] = w(IR0); // Interpolation value for depth queing.
[A9] = w(V0 | V1);

return SZ3 >> 2;
////////////////////////////////



////////////////////////////////
// system_gte_set_rotation_matrix()
R11R12 = w[A0 + 0];
R13R21 = w[A0 + 4];
R22R23 = w[A0 + 8];
R31R32 = w[A0 + c];
R33 = w[A0 + 10];
////////////////////////////////



////////////////////////////////
// system_gte_set_translation_vector()
TRX = w[A0 + 14];
TRY = w[A0 + 18];
TRZ = w[A0 + 1c];
////////////////////////////////



////////////////////////////////
// system_outer_product2_A0_A1_to_A2()
T5 = R11R12;
T6 = R22R23;
T7 = R33;
T0 = w[A0 + 0];
T1 = w[A0 + 4];
T2 = w[A0 + 8];

R11R12 = T0;
R22R23 = T2;
R33 = T3;

IR1 = w[A1 + 0];
IR2 = w[A1 + 4];
IR3 = w[A1 + 8];

gte_op12(); // Outer product

[A2 + 0] = w(MAC1);
[A2 + 4] = w(MAC2);
[A2 + 8] = w(MAC3);

R11R12 = T5;
R22R23 = T6;
R33 = T7;
////////////////////////////////



////////////////////////////////
// system_matrix_vector_multiply_GTE()
R11R12 = w[A0 + 0];
R13R21 = w[A0 + 4];
R22R23 = w[A0 + 8];
R31R32 = w[A0 + c];
R33 = w[A0 + 10];

VXY0 = w[A1 + 0];
VZ0 = w[A1 + 4];
gte_rtv0(); // v0 * rotmatrix.
[A2 + 0] = w(MAC1);
[A2 + 4] = w(MAC2);
[A2 + 8] = w(MAC3);

return A2;
////////////////////////////////



////////////////////////////////
// system_normalize_word_vector_T0_T1_T2_to_half()
T0 = w[A0 + 0];
T1 = w[A0 + 4];
T2 = w[A0 + 8];
system_normalize_vector_T0_T1_T2();
[A1 + 0] = h(T0);
[A1 + 2] = h(T1);
[A1 + 4] = h(T2);
////////////////////////////////



////////////////////////////////
// system_normalize_word_vector_T0_T1_T2_to_word()
T0 = w[A0 + 0];
T1 = w[A0 + 4];
T2 = w[A0 + 8];
system_normalize_vector_T0_T1_T2();
[A1 + 0] = w(T0);
[A1 + 4] = w(T1);
[A1 + 8] = w(T2);
////////////////////////////////



////////////////////////////////
// system_normalize_half_vector_T0_T1_T2_to_half()
T0 = h[A0 + 0];
T1 = h[A0 + 2];
T2 = h[A0 + 4];
system_normalize_vector_T0_T1_T2();
[A1 + 0] = h(T0);
[A1 + 2] = h(T1);
[A1 + 4] = h(T2);
////////////////////////////////



////////////////////////////////
// system_normalize_vector_T0_T1_T2()
VXY0 = T0;
VXY1 = T1;
VXY2 = T2;
gte_SQR(); // Square of vector.

T3 = MAC1;
T4 = MAC2;
T5 = MAC3;
V0 = T3 + T4 + T5;
LZCS = V0;
V1 = LZCS & fffffffe;
T6 = 1f - V1;
T3 = V1 - 18;
T6 = T6 >> 1;
if (T3 >= 0)
{
    T4 = V0 << T3;
}
else
{
    T3 = 18 - V1;
    T3 = V0 >> T3;
}

IR0 = h[80056234 + (T4 - 40) * 2];
IR1 = T0;
IR2 = T1;
IR3 = T2;

gte_GPF(); // General Purpose Interpolation.

T0 = MAC0 >> T6;
T1 = MAC1 >> T6;
T2 = MAC2 >> T6;
////////////////////////////////



////////////////////////////////
// system_outer_product_A0_A1_to_A2()
T5 = R11R12;
T6 = R22R23;
T7 = R33;

R11R12 = w[A0 + 0];
R22R23 = w[A0 + 4];
R33 = w[A0 + 8];

IR1 = w[A1 + 0];
IR2 = w[A1 + 4];
IR3 = w[A1 + 8];

OP(); // outer product

[A2 + 0] = w(MAC1);
[A2 + 4] = w(MAC2);
[A2 + 8] = w(MAC3);

R11R12 = T5;
R22R23 = T6;
R33 = T7;
////////////////////////////////