FFVII.Enemies = {}



FFVII.Enemies.MP = {
    unit_type = FFVII.Battle.Type.ENEMY,

    max_hp = 30,
    max_mp = 0,

    level = 2,
    physical_power = 6,
    physical_defense = 2,
    physical_dodge = 0,
    magic_power = 0,
    magic_defense = 0,
    speed = 50,
    luck = 4,

    reward_exp = 16,
    reward_ap = 2,
    reward_gil = 10,

    attacks = {
        MachineGun = {
            script_id = 3,
        },
        Tonfa = {
            script_id = 4,
        }
    },

    row = FFVII.Battle.Row.FRONT,

    battle_speed = 0,
    timer = 0,



    on_start = function( self )
        return 0
    end,

    on_action = function( self )
        local attack

        if FFVII.Battle.in_front_row( self ) == true then
            if math.random( 2 ) == 1 then
                attack = FFVII.Attacks.MachineGun
            else
                attack = FFVII.Attacks.Tonfa
            end
        else
            if math.random( 6 ) == 1 then
                attack = FFVII.Attacks.Tonfa
            else
                attack = FFVII.Attacks.MachineGun
            end
        end

        print( "Use \"" .. tostring( attack ) .. "\"." )

        FFVII.Battle.set_random_enemy_as_target()
        --battle:run_command(Battle.MONSTER_ACTION, attack_id)

        return 0
    end,



    action_idle = function( self )
        fighter_self:play_animation("0");

        return 0;
    end;

    action_hurt = function(self)
        fighter_self:play_animation("1");

        return 0;
    end;

    action_machine_gun = function(self)
        fighter_self:play_animation("2");
        script:play_hurt_action(fighters_target[1], 0.27);
        fighter_self:play_animation("3");
        fighter_self:play_animation("4");
        fighter_self:play_animation("5");

        return 0;
    end;

    action_tonfa = function(self)
        fighter_self:play_animation("6");
        fighter_self:play_animation("7");
        script:play_hurt_action(fighters_target[1], 0.13);
        fighter_self:play_animation("8");
        fighter_self:play_animation("9");

        return 0;
    end;
}
