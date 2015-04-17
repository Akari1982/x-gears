EntityContainer = {}



EntityContainer[ "Entity_00" ] = {
    script_00 = function( self )
        MISSING OPCODE 0xbc
    end,

    script_01 = function( self )
        ConditionalJumpTo( value1=GetVar( 0x02c8 ), value2=(s16)0x0002, condition="value1 & value2", jump_if_false=0x0038 ); -- 0x0019 0x02
        MISSING OPCODE 0xfe
    end,

    script_02 = function( self )
        Return(); -- 0x0039 0x00
    end,

    script_03 = function( self )
        Return(); -- 0x0039 0x00
    end,

    script_04 = function( self )
        Wait( time=0x0014 ); -- 0x003a 0x26
        MISSING OPCODE 0xc7
    end,

    script_05 = function( self )
        Wait( time=0x000a ); -- 0x004d 0x26
        MISSING OPCODE 0xb5
    end,

}



EntityContainer[ "Entity_01" ] = {
    script_00 = function( self )
        MISSING OPCODE 0x16
    end,

    script_01 = function( self )
        MISSING OPCODE 0x0c
    end,

    script_02 = function( self )
        Return(); -- 0x0060 0x00
    end,

    script_03 = function( self )
        Return(); -- 0x0060 0x00
    end,

    script_04 = function( self )
        MISSING OPCODE 0x4a
    end,

    script_05 = function( self )
        MISSING OPCODE 0xd0
    end,

    script_06 = function( self )
        MISSING OPCODE 0x20
    end,

    script_07 = function( self )
        MISSING OPCODE 0xd0
    end,

    script_08 = function( self )
        MISSING OPCODE 0xd2
    end,

    script_09 = function( self )
        MISSING OPCODE 0x5d
    end,

    script_0a = function( self )
        Wait( time=0x000a ); -- 0x00e6 0x26
        MISSING OPCODE 0xf6
    end,

    script_0b = function( self )
        MISSING OPCODE 0x5d
    end,

    script_0c = function( self )
        MISSING OPCODE 0x2c
    end,

    script_0d = function( self )
        MISSING OPCODE 0x2c
    end,

    script_0e = function( self )
        Wait( time=0x0050 ); -- 0x011b 0x26
        MISSING OPCODE 0xb4
    end,

}



EntityContainer[ "Entity_02" ] = {
    script_00 = function( self )
        MISSING OPCODE 0x16
    end,

    script_01 = function( self )
        MISSING OPCODE 0x0c
    end,

    script_02 = function( self )
        Return(); -- 0x0131 0x00
    end,

    script_03 = function( self )
        Return(); -- 0x0131 0x00
    end,

}



EntityContainer[ "Entity_03" ] = {
    script_00 = function( self )
        MISSING OPCODE 0x16
    end,

    script_01 = function( self )
        MISSING OPCODE 0xa7
    end,

    script_02 = function( self )
        Return(); -- 0x013c 0x00
    end,

    script_03 = function( self )
        Return(); -- 0x013c 0x00
    end,

}



EntityContainer[ "Entity_04" ] = {
    script_00 = function( self )
        MISSING OPCODE 0x16
    end,

    script_01 = function( self )
        MISSING OPCODE 0xa7
    end,

    script_02 = function( self )
        Return(); -- 0x0147 0x00
    end,

    script_03 = function( self )
        Return(); -- 0x0147 0x00
    end,

}



EntityContainer[ "Entity_05" ] = {
    script_00 = function( self )
        MISSING OPCODE 0x16
    end,

    script_01 = function( self )
        MISSING OPCODE 0xa7
    end,

    script_02 = function( self )
        Return(); -- 0x0152 0x00
    end,

    script_03 = function( self )
        Return(); -- 0x0152 0x00
    end,

}



EntityContainer[ "Entity_06" ] = {
    script_00 = function( self )
        MISSING OPCODE 0x16
    end,

    script_01 = function( self )
        MISSING OPCODE 0xa7
    end,

    script_02 = function( self )
        Return(); -- 0x015d 0x00
    end,

    script_03 = function( self )
        Return(); -- 0x015d 0x00
    end,

}



EntityContainer[ "Entity_07" ] = {
    script_00 = function( self )
        MISSING OPCODE 0x16
    end,

    script_01 = function( self )
        MISSING OPCODE 0xa7
    end,

    script_02 = function( self )
        Return(); -- 0x0168 0x00
    end,

    script_03 = function( self )
        Return(); -- 0x0168 0x00
    end,

}



EntityContainer[ "Entity_08" ] = {
    script_00 = function( self )
        MISSING OPCODE 0x16
    end,

    script_01 = function( self )
        MISSING OPCODE 0xa7
    end,

    script_02 = function( self )
        Return(); -- 0x0173 0x00
    end,

    script_03 = function( self )
        Return(); -- 0x0173 0x00
    end,

}



EntityContainer[ "Entity_09" ] = {
    script_00 = function( self )
        MISSING OPCODE 0x0b
    end,

    script_01 = function( self )
        Return(); -- 0x0188 0x00
    end,

    script_02 = function( self )
        ConditionalJumpTo( value1=GetVar( 0x0402 ), value2=(s16)0x0000, condition="value1 == value2", jump_if_false=0x0194 ); -- 0x0189 0x02
        JumpTo( 0x0195 ); -- 0x0191 0x01
        Return(); -- 0x0194 0x00
        MISSING OPCODE 0x6f
    end,

    script_03 = function( self )
        Return(); -- 0x0278 0x00
    end,

    script_04 = function( self )
        MISSING OPCODE 0x6f
    end,

    script_05 = function( self )
        MISSING OPCODE 0x6f
    end,

    script_06 = function( self )
        MISSING OPCODE 0xf4
    end,

}



EntityContainer[ "Entity_0a" ] = {
    script_00 = function( self )
        MISSING OPCODE 0x2a
    end,

    script_01 = function( self )
        TriggerJumpTo( trigger_id=0x5c01, jump=0xfe02 ); -- 0x02a2 0xcb
        MISSING OPCODE 0x54
    end,

    script_02 = function( self )
        Return(); -- 0x02dd 0x00
    end,

    script_03 = function( self )
        Return(); -- 0x02dd 0x00
    end,

}



EntityContainer[ "Entity_0b" ] = {
    script_00 = function( self )
        MISSING OPCODE 0x0b
    end,

    script_01 = function( self )
        Return(); -- 0x0302 0x00
    end,

    script_02 = function( self )
        Return(); -- 0x0303 0x00
    end,

    script_03 = function( self )
        Return(); -- 0x0303 0x00
    end,

    script_04 = function( self )
        MISSING OPCODE 0x22
    end,

    script_05 = function( self )
        MISSING OPCODE 0x2c
    end,

    script_06 = function( self )
        MISSING OPCODE 0xd2
    end,

}



EntityContainer[ "Entity_0c" ] = {
    script_00 = function( self )
        MISSING OPCODE 0x0b
    end,

    script_01 = function( self )
        Return(); -- 0x03b8 0x00
    end,

    script_02 = function( self )
        MISSING OPCODE 0x36
    end,

    script_03 = function( self )
        Return(); -- 0x0411 0x00
    end,

    script_04 = function( self )
        Wait( time=0x0014 ); -- 0x0412 0x26
        MISSING OPCODE 0xa4
    end,

    script_05 = function( self )
        MISSING OPCODE 0xa4
    end,

    script_06 = function( self )
        ConditionalJumpTo( value1=GetVar( 0x0008 ), value2=(s16)0x0006, condition="value1 == value2", jump_if_false=0x042f ); -- 0x041f 0x02
        MISSING OPCODE 0xb5
    end,

    script_07 = function( self )
        MISSING OPCODE 0xf4
    end,

}



EntityContainer[ "Entity_0d" ] = {
    script_00 = function( self )
        MISSING OPCODE 0x0b
    end,

    script_01 = function( self )
        Wait( time=0x000a ); -- 0x0466 0x26
        Return(); -- 0x0469 0x00
    end,

    script_02 = function( self )
        ConditionalJumpTo( value1=GetVar( 0x0402 ), value2=(s16)0x0000, condition="value1 == value2", jump_if_false=0x0475 ); -- 0x046a 0x02
        JumpTo( 0x0476 ); -- 0x0472 0x01
        Return(); -- 0x0475 0x00
        MISSING OPCODE 0x6f
    end,

    script_03 = function( self )
        Return(); -- 0x0484 0x00
    end,

    script_04 = function( self )
        MISSING OPCODE 0xf4
    end,

}



EntityContainer[ "Entity_0e" ] = {
    script_00 = function( self )
        MISSING OPCODE 0x0b
    end,

    script_01 = function( self )
        MISSING OPCODE 0xfe
    end,

    script_02 = function( self )
        ConditionalJumpTo( value1=GetVar( 0x0402 ), value2=(s16)0x0000, condition="value1 == value2", jump_if_false=0x04a6 ); -- 0x049b 0x02
        JumpTo( 0x04a7 ); -- 0x04a3 0x01
        Return(); -- 0x04a6 0x00
        MISSING OPCODE 0xfe
    end,

    script_03 = function( self )
        Return(); -- 0x04bd 0x00
    end,

    script_04 = function( self )
        MISSING OPCODE 0xf4
    end,

}



EntityContainer[ "Entity_0f" ] = {
    script_00 = function( self )
        MISSING OPCODE 0x0b
    end,

    script_01 = function( self )
        MISSING OPCODE 0xa8
    end,

    script_02 = function( self )
        ConditionalJumpTo( value1=GetVar( 0x0402 ), value2=(s16)0x0000, condition="value1 == value2", jump_if_false=0x0542 ); -- 0x0537 0x02
        JumpTo( 0x0543 ); -- 0x053f 0x01
        Return(); -- 0x0542 0x00
        MISSING OPCODE 0x6f
    end,

    script_03 = function( self )
        Return(); -- 0x0554 0x00
    end,

    script_04 = function( self )
        MISSING OPCODE 0xf4
    end,

}



EntityContainer[ "Entity_10" ] = {
    script_00 = function( self )
        MISSING OPCODE 0x2a
    end,

    script_01 = function( self )
        TriggerJumpTo( trigger_id=GetVar( 0x6400 ), jump=0x9805 ); -- 0x055b 0xcb
        MISSING OPCODE 0x0e
    end,

    script_02 = function( self )
        Return(); -- 0x0565 0x00
    end,

    script_03 = function( self )
        Return(); -- 0x0565 0x00
    end,

}



EntityContainer[ "Entity_11" ] = {
    script_00 = function( self )
        MISSING OPCODE 0x46
    end,

    script_01 = function( self )
        Return(); -- 0x0568 0x00
    end,

    script_02 = function( self )
        MISSING OPCODE 0x15
    end,

    script_03 = function( self )
        Return(); -- 0x0574 0x00
    end,

    script_04 = function( self )
        MISSING OPCODE 0xc4
    end,

    script_05 = function( self )
        MISSING OPCODE 0xc5
    end,

}



EntityContainer[ "Entity_12" ] = {
    script_00 = function( self )
        MISSING OPCODE 0xbc
    end,

    script_01 = function( self )
        MISSING OPCODE 0xe1
    end,

    script_02 = function( self )
        Return(); -- 0x05b2 0x00
    end,

    script_03 = function( self )
        Return(); -- 0x05b2 0x00
    end,

}



EntityContainer[ "Entity_13" ] = {
    script_00 = function( self )
        MISSING OPCODE 0xbc
    end,

    script_01 = function( self )
        MISSING OPCODE 0xfe
    end,

    script_02 = function( self )
        Return(); -- 0x05c5 0x00
        MISSING OPCODE 0xe0
    end,

    script_03 = function( self )
        Return(); -- 0x05c5 0x00
        MISSING OPCODE 0xe0
    end,

}



