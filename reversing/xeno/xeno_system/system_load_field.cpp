////////////////////////////////
// func1b318()
field_id = S0 = A0;
S1 = A1;

if( ( w[8004e9d8] == S1 ) && ( w[8004e9d4] == field_id ) )
{
    return 0;
}



func284dc(); // cd sync
if( V0 != 0 )
{
    return -1;
}
A0 = 0;
func28870(); // ececute till cd sync



if( w[8004e9d8] != -1 )
{
    A0 = w[80059b70];
    [A0 - 4] = w(w[A0 - 4] & fdffffff);

    A0 = w[80059b70];
    func31f0c();
}



A0 = field_id;
func1b3d0();

[8004e9d8] = w(S1);
[8004e9d4] = w(field_id);

return -1;
////////////////////////////////



////////////////////////////////
// func284dc()
S0 = w[8004f4a0];
if( S0 == 0 )
{
    if( w[8004f4ec] == 0 )
    {
        A0 = 1;
        system_psyq_CdDataSync();
        if( V0 != 0 )
        {
            return 1; // error or transfer still being performed
        }
    }
    if( w[8004f4c0] != 0 )
    {
        return 1;
    }
}
return S0;
////////////////////////////////



////////////////////////////////
// func28870()
if( A0 == 0 )
{
    loop2887c:	; 8002887C
        func284dc();
    80028884	bgtz   v0, loop2887c [$8002887c]
}
func284dc();
////////////////////////////////



////////////////////////////////
// func1b3d0()
S0 = A0 + b8; // global file index for files in directory 11 (field)


A0 = S0;
func286fc(); // get filesize by global field id
[80059b50] = w(V0);

A0 = V0;
A1 = 1;
system_memory_allocate();
[80059b70] = w(V0);

A0 = V0;
[A0 - 4] = w(w[A0 - 4] | 02000000);

A0 = S0;
A1 = w[80059b70];
A2 = 0;
A3 = 80;
func293e8();
////////////////////////////////
