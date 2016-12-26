Entity = {}



Entity[ "1" ] = {
    on_start = function( self )
        self.entity:init_pc( 0 )
        return 0
    end,

    on_update = function( self )
        self.entity:input()
        return 0
    end,
}
