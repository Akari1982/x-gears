Entity = {}



Entity[ "1" ] = {
    on_start = function( self )
        self.entity:init_pc( 0 ) -- 0x0056 0x16
        -- 0xFE0D_SetAvatar( character_id=0 ); -- 0x0059 0xfe
        return 0 -- 0x005d 0x00
    end,

    on_update = function( self )
        self.entity:input()
        return 0 -- 0x005f 0x00
    end,

    on_talk = function( self )
        return 0 -- 0x0060 0x00
    end,

    on_push = function( self )
        return 0 -- 0x0060 0x00
    end,

    script_0x04 = function( self )
        -- MISSING OPCODE 0x4a
    end,

    script_0x05 = function( self )
        -- MISSING OPCODE 0xd0
    end,

    script_0x06 = function( self )
        -- MISSING OPCODE 0x20
    end,

    script_0x07 = function( self )
        -- MISSING OPCODE 0xd0
    end,

    script_0x08 = function( self )
        -- MISSING OPCODE 0xd2
    end,

    script_0x09 = function( self )
        -- MISSING OPCODE 0x5d
    end,

    script_0x0a = function( self )
        -- 0x26_Wait( time=10 ); -- 0x00e6 0x26
        -- MISSING OPCODE 0xf6
    end,

    script_0x0b = function( self )
        -- MISSING OPCODE 0x5d
    end,

    script_0x0c = function( self )
        -- MISSING OPCODE 0x2c
    end,

    script_0x0d = function( self )
        -- MISSING OPCODE 0x2c
    end,

    script_0x0e = function( self )
        -- 0x26_Wait( time=80 ); -- 0x011b 0x26
        -- MISSING OPCODE 0xb4
    end,

}




Entity[ "11" ] = {
    on_start = function( self )
        self.entity:init_npc( 2 ) -- 0x02de 0x0b
        -- 0x19_SetPosition( x=(vf80)0x010c, z=(vf40)0x0000, flag=(flag)0x69 ) -- 0x02e1 0x19
        -- MISSING OPCODE 0x69
        return 0
    end,

    on_update = function( self )
        return 0 -- 0x0302 0x00
    end,

    on_talk = function( self )
        return 0 -- 0x0303 0x00
    end,

    on_push = function( self )
        return 0 -- 0x0303 0x00
    end,

    script_0x04 = function( self )
        -- MISSING OPCODE 0x22
    end,

    script_0x05 = function( self )
        -- MISSING OPCODE 0x2c
    end,

    script_0x06 = function( self )
        -- MISSING OPCODE 0xd2
    end,

}



Entity[ "12" ] = {
    on_start = function( self )
        self.entity:init_npc( 4 ) -- 0x03aa 0x0b
        -- MISSING OPCODE 0x20
        return 0
    end,

    on_update = function( self )
        return 0 -- 0x03b8 0x00
    end,

    on_talk = function( self )
        -- MISSING OPCODE 0x36
    end,

    on_push = function( self )
        return 0 -- 0x0411 0x00
    end,

    script_0x04 = function( self )
        -- 0x26_Wait( time=20 ); -- 0x0412 0x26
        -- MISSING OPCODE 0xa4
    end,

    script_0x05 = function( self )
        -- MISSING OPCODE 0xa4
    end,

    script_0x06 = function( self )
        -- 0x02_ConditionalJumpTo( value1=GetVar( 0x0008 ), value2=(s16)0x0006, condition="value1 == value2", jump_if_false=0x042f ); -- 0x041f 0x02
        -- MISSING OPCODE 0xb5
    end,

    script_0x07 = function( self )
        -- MISSING OPCODE 0xf4
    end,

}



Entity[ "13" ] = {
    on_start = function( self )
        self.entity:init_npc( 0 ) -- 0x045c 0x0b
        -- MISSING OPCODE 0x20
        return 0
    end,

    on_update = function( self )
        -- 0x26_Wait( time=10 ); -- 0x0466 0x26
        return 0 -- 0x0469 0x00
    end,

    on_talk = function( self )
        -- 0x02_ConditionalJumpTo( value1=GetVar( 0x0402 ), value2=(s16)0x0000, condition="value1 == value2", jump_if_false=0x0475 ); -- 0x046a 0x02
        -- 0x01_JumpTo( 0x0476 ); -- 0x0472 0x01
        return 0 -- 0x0475 0x00
        -- MISSING OPCODE 0x6f
    end,

    on_push = function( self )
        return 0 -- 0x0484 0x00
    end,

    script_0x04 = function( self )
        -- MISSING OPCODE 0xf4
    end,

}



Entity[ "14" ] = {
    on_start = function( self )
        self.entity:init_npc( 1 ) -- 0x048c 0x0b
        -- MISSING OPCODE 0x20
        return 0
    end,

    on_update = function( self )
        -- MISSING OPCODE 0xFE45
        return 0
    end,

    on_talk = function( self )
        -- 0x02_ConditionalJumpTo( value1=GetVar( 0x0402 ), value2=(s16)0x0000, condition="value1 == value2", jump_if_false=0x04a6 ); -- 0x049b 0x02
        -- 0x01_JumpTo( 0x04a7 ); -- 0x04a3 0x01
        return 0 -- 0x04a6 0x00
        -- MISSING OPCODE 0xFE45
    end,

    on_push = function( self )
        return 0 -- 0x04bd 0x00
    end,

    script_0x04 = function( self )
        -- MISSING OPCODE 0xf4
    end,

}



Entity[ "15" ] = {
    on_start = function( self )
        self.entity:init_npc( 3 ) -- 0x04c5 0x0b
        return 0 -- 0x04c8 0x00
    end,

    on_update = function( self )
        -- MISSING OPCODE 0xa8
        return 0
    end,

    on_talk = function( self )
        -- 0x02_ConditionalJumpTo( value1=GetVar( 0x0402 ), value2=(s16)0x0000, condition="value1 == value2", jump_if_false=0x0542 ); -- 0x0537 0x02
        -- 0x01_JumpTo( 0x0543 ); -- 0x053f 0x01
        return 0 -- 0x0542 0x00
        -- MISSING OPCODE 0x6f
    end,

    on_push = function( self )
        return 0 -- 0x0554 0x00
    end,

    script_0x04 = function( self )
        -- MISSING OPCODE 0xf4
    end,

}
