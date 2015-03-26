entity = {
};

-- player
player = field:load_model(100);
field:set_model_to_character(0, player);
player:set_position_triangle(0, -100, 0, 1);
player:set_speed(300);
player:set_solid_range(30);

-- chaser slow
chaser_slow = field:load_model(30);
chaser_slow:set_position_triangle(0, -50, 0, 1);
chaser_slow:set_speed(50);
chaser_slow:set_solid_range(35);
chaser_slow:set_visible(true);

-- chaser1
chaser1 = field:load_model(40);
chaser1:set_position_triangle(0, 50, 0, 1);
chaser1:set_speed(500);
chaser1:set_solid_range(15);
chaser1:set_visible(true);
chaser1:set_solid(true);

-- chaser2
chaser2 = field:load_model(40);
chaser2:set_position_triangle(-100, 100, 0, 1);
chaser2:set_speed(500);
chaser2:set_solid_range(15);
chaser2:set_visible(true);
chaser2:set_solid(true);

-- chaser3
chaser3 = field:load_model(40);
chaser3:set_position_triangle(100, 100, 0, 1);
chaser3:set_speed(500);
chaser3:set_solid_range(15);
chaser3:set_visible(true);
chaser3:set_solid(true);

-- watcher1
watcher1 = field:load_model(100);
watcher1:set_position_triangle(750, 150, 200, 9);
watcher1:set_speed(150);
watcher1:set_solid_range(30);
watcher1:set_visible(true);
watcher1:set_solid(true);

-- lifter
lifter = field:load_model(100);
lifter:set_position_triangle(0, 0, 0, 0);
lifter:set_speed(150);
lifter:set_solid_range(30);
lifter:set_visible(true);
lifter:set_solid(false);
lifter:offset_to_position(0, 300, 0, Field.NONE, 1);
lifter:set_direction(180);



entity["Player"] = {
    setup = function(self)
        while true do
            local triangle_id = player:get_triangle();
            if triangle_id == 0 then
                field:lock_pc(true);
                -- move to ladder
                player:move_to_position(-100, 0, true);
                -- move to up platform 1
                player:set_direction(0);
                player:set_animation_default("6", 1);
                player:climb_to_position(-200, 350, 300, 23, Model.DOWN_TO_UP);
                -- move to jump position
                player:move_to_position(-200, 600, true);
                -- jump to platform 2
                player:set_direction(90);
                player:set_animation_default("5", 1);
                script:wait(0.5);
                player:jump_to_position(200, 600, 24, 0.567);
                script:wait(0.667);
                -- move to ladder
                player:move_to_position(200, 350, true);
                -- ladder down
                player:set_direction(0);
                player:set_animation_default("6", 1);
                player:climb_to_position(100, 0, 0, 4, Model.DOWN_TO_UP);
                field:lock_pc(false);
            end;

            script:wait(0.5);
        end;

        return 0;
    end;
};



entity["Chaser_Slow"] = {
    setup = function(self)
        script:wait(1);

        while true do
            chaser_slow:set_solid(true);
            chaser_slow:move_to_model(player, false);
            chaser_slow:set_solid(false);
            script:wait(5);
        end;

        return 0;
    end;
};



entity["Chasers_Speed1"] = {
    setup = function(self)
        script:wait(1);

        while true do
            chaser1:set_position_triangle(0, 50, 0, 1);
            chaser1:move_to_model(player, false);
        end;

        return 0;
    end;
};



entity["Chasers_Speed2"] = {
    setup = function(self)
        script:wait(1);

        while true do
            chaser2:set_position_triangle(-100, 100, 0, 1);
            chaser2:move_to_model(player, false);
        end;

        return 0;
    end;
};



entity["Chasers_Speed3"] = {
    setup = function(self)
        script:wait(1);

        while true do
            chaser3:set_position_triangle(100, 100, 0, 1);
            chaser3:move_to_model(player, false);
        end;

        return 0;
    end;
};



entity["Watcher1"] = {
    setup = function(self)
        script:wait(1);

        while true do
            watcher1:turn_to_model(player, Model.CLOSEST, 2);
            script:wait(0.5);
            watcher1:turn_to_direction(180, Model.CLOSEST, Field.SMOOTH, 2);
            script:wait(1);
            watcher1:move_to_position(750, -650, true);
            watcher1:turn_to_model(player, Model.CLOSEST, 2);
            script:wait(0.5);
            watcher1:turn_to_direction(0, Model.CLOSEST, Field.SMOOTH, 2);
            script:wait(1);
            watcher1:move_to_position(750, 150, true);
        end;

        return 0;
    end;
};



entity["Lifter"] = {
    setup = function(self)
        while true do
            script:wait(1);
            lifter:offset_to_position(0, 300, 0, Field.SMOOTH, 5);
            lifter:set_offset_wait();
            script:wait(1);
            lifter:offset_to_position(0, 300, 300, Field.SMOOTH, 5);
            lifter:set_offset_wait();
        end;

        return 0;
    end;
};