SpriteAnimation[ "timothy_father" ] = {
    anim1 = function( self )
        dir_frame_start( 3 )
        0x81
    end,

    anim2 = function( self )
        set_animation_move_speed( 20 )
        dir_frame_start( 5 )
        next_frame( 5 )
        next_frame( 5 )
        next_frame( 5 )
        next_frame( 5 )
        next_frame( 5 )
        next_frame( 5 )
        next_frame( 5 )
        0x82
    end,

    anim3 = function( self )
        dir_frame_start( 7 )
        next_frame( 9 )
        next_frame( 11 )
        prev_frame( 9 )
        prev_frame( 7 )
        0x80
    end,

    anim4 = function( self )
        dir_frame_start( 13 )
        next_frame( 13 )
        next_frame( 15 )
        next_frame( 0 )
        wait( 38 )
        next_frame( 0 )
        wait( 58 )
        set_dir_frame_id( -1 )
        dir_frame_start( 7 )
        0x80
    end,
}
